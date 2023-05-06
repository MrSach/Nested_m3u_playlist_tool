#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

#include "ext_list.hpp"
#include "m3u_playlist_file_text_entry.hpp"

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
		m3u_playlist_file_text (const std::filesystem::path & input_path);

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
            File path for m3u playlist
		*/
		std::filesystem::path file_path;

		/*
            Folder of playlist file
		*/
		std::filesystem::path file_folder;

		/*
            Input file - fstream object
		*/
		std::fstream input_file;

		/*
			File extension lists.
			One for multimedia, one for nested playlist files and a combined list with both.
		*/
		ext_list multimedia_file_extension {"resource/multimedia_file_extension.txt"};
		ext_list playlist_file_extension {"resource/playlist_file_extension.txt"};
		ext_list aggregate_list {multimedia_file_extension + playlist_file_extension};

		/*
            File contents
		*/
		std::vector <std::string> contents {};

		/*
            List of playlist entries
		*/
		std::vector <m3u_playlist_file_text_entry> file_entry {};

};
