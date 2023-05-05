#include "playlist_entry.hpp"

/*
	Constructor
*/
playlist_entry::playlist_entry ()
{
	++playlist_entry::m_counter;
	++playlist_entry::m_total;
}

/*
	Destructor
*/
playlist_entry::~playlist_entry ()
{
	--playlist_entry::m_counter;
	++playlist_entry::m_deleted;
}

/*
	Copy Constructor
*/
playlist_entry::playlist_entry (const playlist_entry & other)
{
	++playlist_entry::m_counter;
	++playlist_entry::m_total;
}

/*
	Copy Assignment
*/
playlist_entry & playlist_entry::operator = (const playlist_entry & rhs)
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
	Number of current instances.
*/
size_t playlist_entry::get_counter () const
{
	return playlist_entry::m_counter;
}

void playlist_entry::set_counter (const std::size_t & val)
{
	m_counter = val;
}
