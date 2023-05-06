#pragma once
#ifndef PLAYLIST_ENTRY_HPP
#define PLAYLIST_ENTRY_HPP

#include <string>
#include <filesystem>

class playlist_entry
{
	public:

		/*
			Constructor - No Parameters.
		*/
		playlist_entry ();

		/*
			Constructor - 2 String Parameters.
		*/
		playlist_entry (const std::string input_title, const std::string input_time);

		/*
			Destructor.
		*/
		virtual ~ playlist_entry () noexcept;

		/*
			Copy Constructor.
		*/
		playlist_entry (const playlist_entry & other);

		/*
			Copy Assignment.
		*/
		playlist_entry & operator = (const playlist_entry & other);

	protected:

		/*
			Title of the soundtrack to be displayed in the playlist.
		*/
		std::string display_title;

		/*
			File name.
		*/
		std::filesystem::path filename;

};

#endif // PLAYLIST_ENTRY_HPP
