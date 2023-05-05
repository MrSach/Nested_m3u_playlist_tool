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

		/*

		*/
		virtual size_t get_counter () const;

		virtual void set_counter (const std::size_t & val);

	protected:

		/*
			Number of active instances in playlist.
		*/
		inline static size_t m_counter {0};

		/*
			Number of total instances in playlist since execution.
		*/
		inline static size_t m_total {0};

		/*
			Number of deleted instances from playlist since execution.
		*/
		inline static size_t m_deleted {0};

		/*
			Title of the soundtrack to be displayed in the playlist.
		*/
		std::string display_title;

		/*
			File name.
		*/
		std::filesystem::path filename;

		/*
			Length of soundtrack.
		*/
		long double time;
};

#endif // PLAYLIST_ENTRY_HPP
