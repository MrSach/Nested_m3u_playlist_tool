#include "file_cannot_be_opened_exception.hpp"

file_cannot_be_opened_exception::file_cannot_be_opened_exception () noexcept
{

}

file_cannot_be_opened_exception::~file_cannot_be_opened_exception () noexcept
{

}

const char * file_cannot_be_opened_exception::what () const noexcept
{
	return "File cannot be opened";
}
