#include "m3u_playlist_file_text_entry.hpp"

m3u_playlist_file_text_entry::m3u_playlist_file_text_entry ()
:
	relative_path {},
	relative_dir {},
	display_title {},
	timer {}
{

}

m3u_playlist_file_text_entry::m3u_playlist_file_text_entry
(
	const std::filesystem::path & input_path,
	const std::string & input_title,
	const double & input_timer
)
:
	relative_path {input_path},
	relative_dir {input_path},
	display_title {input_title},
	timer {input_timer}
{
	relative_dir.remove_filename();
}

m3u_playlist_file_text_entry::~m3u_playlist_file_text_entry ()
{

}

m3u_playlist_file_text_entry::m3u_playlist_file_text_entry (const m3u_playlist_file_text_entry & other)
{

}

m3u_playlist_file_text_entry & m3u_playlist_file_text_entry::operator = (const m3u_playlist_file_text_entry & rhs)
{
	if (this == & rhs)
	{
		return * this;
	}
	return * this;
}

void m3u_playlist_file_text_entry::set_timer (const double & value)
{
	this->timer = value;
}

double m3u_playlist_file_text_entry::get_timer ()
{
	return this->timer;
}

void m3u_playlist_file_text_entry::set_display_title (const std::string & value)
{
	this->display_title = value;
}

std::string m3u_playlist_file_text_entry::get_display_title ()
{
	return this->display_title;
}
