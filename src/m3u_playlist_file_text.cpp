#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

#include "m3u_playlist_file_text.hpp"

/*
	Initialise static variables.
*/

/*
	Initialise active instance data, historic instance data and data for inactive instances.
	So, how many currently exist...
	And how many have been created since execution...
	How many have been deleted since execution...
*/
size_t m3u_playlist_file_text::m_counter {0};
size_t m3u_playlist_file_text::m_total {0};
size_t m3u_playlist_file_text::m_deleted {0};

/*
	Constructor
*/
m3u_playlist_file_text::m3u_playlist_file_text ()
{
	++m3u_playlist_file_text::m_counter;
	++m3u_playlist_file_text::m_total;
}

/*
    Constructor - string parameter - file path
*/
m3u_playlist_file_text::m3u_playlist_file_text (const std::string input_path)
{
    ++m3u_playlist_file_text::m_counter;
	++m3u_playlist_file_text::m_total;

	this->input_file = std::fstream (input_path, std::ios::in);
	this->scan_playlist_file ();
	this->generate_entries ();
}

/*
	Destructor
*/
m3u_playlist_file_text::~m3u_playlist_file_text ()
{
	--m3u_playlist_file_text::m_counter;
	++m3u_playlist_file_text::m_deleted;

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
	++m3u_playlist_file_text::m_counter;
	++m3u_playlist_file_text::m_total;
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
    for (std::string buff {}; (input_file >> buff); )
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

m3u_playlist_file_text::m3u_entry_processor::m3u_entry_processor ()
{

};

m3u_playlist_file_text::m3u_entry_processor::~m3u_entry_processor ()
{

};

/*
void m3u_playlist_file_text::m3u_entry_processor::operator () (const std::string s)
{
    std::string title {};
    double length {};
    if (s.find ("#EXTINF") )
    {

    }
}
*/

bool m3u_playlist_file_text::generate_entries ()
{
	/*
		Activate the flag to expect a new playlist entry by default.
	*/
    bool new_entry {1};

    /*
		Playlist file extension
	*/
	std::vector <std::string> file_extension_list
	{
		{
			".mp3",
			".ogg",
			".flac",
			".wav",
			".aac",
			".aiff",
			".mid",
			".mod",
			".wma",
			".psf",
			".usf",
			".minipsf",
			".spc",
			".gym",
			".vgm",
			".miniusf"
		}
	};

	std::vector <std::string> playlist_extension_list
	{
		{
			".m3u"
		}
	};

    /*
		Loop through line by line.
    */
    for (const std::string & s : this->contents)
    {
		/*

		*/
		std::string new_entry_header { "#EXTINF:" };

		/*
			File extension delimiter
		*/
		wchar_t ext_delim { '.' };

		/*
			Check length of the line before checking for any headers.
		*/
		if (s.length () >= 8)
		{
			/*
				Check for a new entry line that opens a new entry in the playlist.
			*/
			std::string meta_check {s.substr (0, 8)};

			/*
				Check for the header for a new playlist entry.
			*/
			if (meta_check == new_entry_header)
			{
				if (s.length () > 8)
				{
					new_entry == 1;
				}
				else
				{
					new_entry == false;
				}
			}

			else
			{

			}
		}
		if ( new_entry == 1)
		{
			wchar_t metadata_delimiter { ',' };
			size_t time_delim {s.find (metadata_delimiter, 8)};
			if (time_delim < std::string::npos)
			{
				std::string timer_str {s.substr (8, time_delim - 8)};
				size_t file_ext_pos { s.rfind (".") };
				//std::cout << file_ext_pos << std::endl;
				std::stringstream ss {};
				for (size_t index {file_ext_pos}; index < s.length (); ++index)
				{
					ss << s.at (index);
				}
				for (const std::string & ext : file_extension_list)
				{
					std::cout << ext << std::endl;
					if (ss.str () == ext)
					{
						std::cout << "YEY" << std::endl;
						std::string track_title { s.substr (time_delim + 1, s.length () ) };
						std::cout << track_title << std::endl;
					}
				}
			}
		}
		else
		{

		}
    }
    return 0;
}
