#pragma once
#ifndef M3U_PLAYLIST_FILE_TEXT_HPP
#define M3U_PLAYLIST_FILE_TEXT_HPP

#include <fstream>
#include <string>
#include <vector>

#include "playlist_entry.hpp"

class m3u_playlist_file_text
{
	public:

		/*
			Constructor - No Parameters
		*/
		m3u_playlist_file_text ();

		/*
            Constructor - string parameter - file path
		*/
		m3u_playlist_file_text (const std::string input_path);

		/*
			Destructor
		*/
		virtual ~ m3u_playlist_file_text () noexcept;

		/*
			Copy Constructor.
		*/
		m3u_playlist_file_text (const m3u_playlist_file_text & other);

		/*
			Copy Assignment.
		*/
		m3u_playlist_file_text & operator = (const m3u_playlist_file_text & other);

		/*
			Get the number of active instances for the class.
		*/
		virtual size_t get_counter () const
		{
			return m_counter;
		}

		/*
			Set the counter of the class.
		*/
		void set_counter (size_t & val)
		{
			m_counter = val;
		}

		/*
			Check the file path of the input file.
		*/
		virtual bool read_file_path (std::string & path) const;

		virtual bool delete_file_by_id (const size_t & id);

		/*
            General function to read the playlist file and to buffer the file contents to a vector of string objects.
		*/
		virtual bool scan_playlist_file ();

		/*
            Check for the "#EXTM3U" file header within the file.
            Return 1 if this exists, otherwise return 0.
		*/
		virtual bool scan_m3u_header ();

		/*
            If there is an M3U header present within the file, this function gets called.
            When called, this will add to the vector of strings for each line.
		*/
		virtual bool probe_m3u_entries ();

		/*
            Displays the contents of the file using the vector of strings that has been generated.
		*/
		virtual void display_m3u_contents ();

		/*
            General function to generate playlist entry objects using the file contents string vector.
		*/
		virtual bool generate_entries ();

	protected:

		/*
			Number of active instances for current class.
		*/
		static size_t m_counter;

		/*
			Number of total historic instances created for this class since program execution.
		*/
		static size_t m_total;

		/*
			Number of total instances that have been deleted from this class.
		*/
		static size_t m_deleted;

		/*
            File path for m3u playlist
		*/
		std::string file_path;

		/*
            Folder of playlist file
		*/
		std::string file_folder;

		/*
            Input file - fstream object
		*/
		std::fstream input_file;

		/*
            File contents
		*/
		std::vector <std::string> contents {};

		/*
            List of playlist entries
		*/
		std::vector <playlist_entry> list_entry {};

		/*
            Functor object - algorithm for generating playlist entries from file contents.
		*/
        class m3u_entry_processor
        {
            public:
                m3u_entry_processor ();
                ~ m3u_entry_processor ();

                /*
                    Functor object function override.
                */
                void operator () (const std::string s);
        };
};

#endif // M3U_PLAYLIST_FILE_TEXT_HPP
