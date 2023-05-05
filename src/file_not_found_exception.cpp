#include "file_not_found_exception.hpp"

file_not_found_exception::file_not_found_exception () noexcept
{

}

file_not_found_exception::~file_not_found_exception () noexcept
{

}

const char * file_not_found_exception::what () const noexcept
{
	return "File not found";
}
