#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <filesystem>
#include <string>

#include "m3u_playlist_file_text.hpp"

/*
	Initialise active instance data, historic instance data and data for inactive instances.
	So, how many currently exist...
	And how many have been created since execution...
	How many have been deleted since execution...
*/

/*
	Constructor
*/
m3u_playlist_file_text::m3u_playlist_file_text ()
:
	file_path {},
	file_folder {},
	input_file {}
{

}

/*
    Constructor - string parameter - file path
*/
m3u_playlist_file_text::m3u_playlist_file_text (const std::filesystem::path & input_path)
:
	file_path {input_path},
	file_folder {input_path},
	input_file {std::fstream (input_path, std::ios::in)}
{
	file_folder.remove_filename();
	//this->input_file = std::fstream (input_path, std::ios::in);
	this->scan_playlist_file ();
	this->generate_entries ();
}

/*
	Destructor
*/
m3u_playlist_file_text::~m3u_playlist_file_text ()
{
	if ( this->m3u_playlist_file_text::input_file . is_open () )
	{
		this->m3u_playlist_file_text::input_file . close ();
	}
}

/*
	Copy Constructor
*/
m3u_playlist_file_text::m3u_playlist_file_text (const m3u_playlist_file_text & other)
{

}

/*
	Copy Assignment
*/
m3u_playlist_file_text & m3u_playlist_file_text::operator = (const m3u_playlist_file_text & rhs)
{
	/*
		Exit if self-assignment.
	*/
	if (this == & rhs)
	{
		return * this;
	}

	/*
		Return the object by pointer.
	*/
	return * this;
}

/*
	Read in the file.
	Check if this file path is valid.
*/
bool m3u_playlist_file_text::read_file_path (std::string & path) const
{
	return 0;
}

bool m3u_playlist_file_text::delete_file_by_id (const size_t & id)
{
	return 0;
}

bool m3u_playlist_file_text::scan_playlist_file ()
{
    bool m3u_positive
    {
        this->scan_m3u_header ()
    };
    if (m3u_positive == 1)
    {
        bool gen_m3u_contents
        {
            this->probe_m3u_entries ()
        };
        if (gen_m3u_contents == 1)
        {
            this->display_m3u_contents ();
            return 1;
        }
    }
    return 0;
}

bool m3u_playlist_file_text::scan_m3u_header ()
{
    for (std::string buff {}; (input_file >> buff); )
    {
        if (buff == "#EXTM3U")
        {
            this->contents.push_back (buff);
            return 1;
        }
    }
    return 0;
}

bool m3u_playlist_file_text::probe_m3u_entries ()
{
	std::string buff {};
	std::getline (input_file, buff);
    for ( ; !(input_file.eof()); std::getline (input_file, buff) )
    {
        this->contents.push_back (buff);
    }
    return 1;
}

void m3u_playlist_file_text::display_m3u_contents ()
{
    std::for_each
    (
        this->contents.begin (),
        this->contents.end (),
        []
        (const std::string s)
        -> void
        {
            std::cout << s;
            std::cout << std::endl;
        }
    );
    std::cout << std::endl;
}

bool m3u_playlist_file_text::generate_entries ()
{
	/*
		Activate the flag to expect a new playlist entry by default.
	*/
    bool new_entry {1};

    /*
		Loop through line by line.
		"i" is the iterator for the line of the file contents.
		"j" is the iterator for the playlist entry in the program that is currently being handled for buffering data into.
		The file itself is not changed as it is opened for reading.
		The data being buffered is for the program to generate metadata about the playlist entries.
    */
    for (std::size_t i {0}, j {0}; i < this->contents.size(); ++i)
    {
		std::string s {this->contents.at(i)};
		/*
			Check if the header for a new playlist entry exists.
			Also check if a new entry flag is not already enabled.
			This is enabled by default as the first vector element is already initialised.
		*/
		std::string new_entry_header { "#EXTINF:" };
		std::size_t header_position {(s.find (new_entry_header))};
//		std::cout << header_position << std::endl;
		if ((header_position == 0))// && (new_entry == 0))
		{
			if (s.length () > 8)
			{
				if (new_entry == 0)
				{
					++j;
					new_entry = 1;
				}
				this->file_entry.emplace_back();
				/*
					After the "#EXTINF:", find the occurrence of a comma.
					Get the digits between to determine the track time.
				*/
				char metadata_delimiter { ',' };
				std::size_t time_delimiter {s.find (metadata_delimiter, 8)};
				if (time_delimiter < std::string::npos)
				{
					/*
						Process track time.
						locate the comma after the time digits.
						Between the "#EXTINF:" header and the comma should be the track time data string.
						Process this through a stringstream and typecast to the target double value.
					*/
					std::string timer_str {s.substr (8, time_delimiter - 8)};
					std::stringstream ss {};
					ss << timer_str;
					double timer_buffer {};
					ss >> timer_buffer;
					this->file_entry.at(j).set_timer (timer_buffer);
	//				std::cout << "Timer = " << this->file_entry.at(j).get_timer() << std::endl;

					/*
						Process the track title to display in the current playlist.
						First, get the length of the title.
						Next, use the substr command to then get the character string, after the comma and up to the end of the line.
					*/
					std::size_t title_placeholder_length {s.length() - s.rfind (metadata_delimiter)};
					//std::cout << title_placeholder_length << std::endl;
					std::string title_placeholder {s.substr (time_delimiter + 1, title_placeholder_length)};
					this->file_entry.at(j).set_display_title(title_placeholder);
					std::cout << this->file_entry.at(j).get_display_title() << std::endl;
				}
				new_entry = 0;
			}
		}
		else
		/*
			Check if this line is populated with a relative file path.
		*/
		{
			std::filesystem::path target {};

		}
    }
    return 0;
}
