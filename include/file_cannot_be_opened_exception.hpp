#pragma once

#include <exception>

class file_cannot_be_opened_exception : public std::exception
{
	public:
		file_cannot_be_opened_exception () noexcept;
		virtual ~ file_cannot_be_opened_exception () noexcept;
		virtual const char * what () const noexcept override;
};
