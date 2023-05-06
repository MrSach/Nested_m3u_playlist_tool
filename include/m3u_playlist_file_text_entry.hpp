#pragma once

#include <filesystem>
#include <string>

class m3u_playlist_file_text_entry
{
	public:
		m3u_playlist_file_text_entry ();
		m3u_playlist_file_text_entry
		(
			const std::filesystem::path & input_path,
			const std::string & input_title,
			const double & input_timer
		);
		virtual ~ m3u_playlist_file_text_entry ();
		m3u_playlist_file_text_entry (const m3u_playlist_file_text_entry & other);
		m3u_playlist_file_text_entry & operator = (const m3u_playlist_file_text_entry & other);
		virtual void set_timer (const double & value);
		virtual double get_timer ();
		virtual void set_display_title (const std::string & value);
		virtual std::string get_display_title ();

	protected:
		std::filesystem::path relative_path;
		std::filesystem::path relative_dir;
		std::string display_title;
		double timer;

};
