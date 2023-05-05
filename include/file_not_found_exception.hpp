#pragma once

#include <exception>

class file_not_found_exception : public std::exception
{
	public:
		file_not_found_exception () noexcept;
		virtual ~ file_not_found_exception () noexcept;
		virtual const char * what () const noexcept override;
};
