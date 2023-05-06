#include <system_error>
#include <filesystem>
#include <iostream>
#include <string>
#include <exception>
#include <vector>

#include "ext_list.hpp"
#include "file_not_found_exception.hpp"

ext_list::ext_list ()
:
	file_path {},
	input_file {},
	file_ext {}
{

}

ext_list::ext_list (const std::string & str)
:
	file_path {str},
	input_file {},
	file_ext {}
{
	this->load_input_file ();
	this->set_file_ext ();
}

ext_list::ext_list (const ext_list & list_b)
:
	file_path {list_b.file_path},
	input_file {},
	file_ext {list_b.file_ext}
{

}

ext_list::ext_list (ext_list && list_b)
:
	file_path {list_b.file_path},
	input_file {},
	file_ext {list_b.file_ext}
{

}

ext_list::ext_list (const ext_list & list_a, const ext_list & list_b)
:
	file_path {},
	input_file {},
	file_ext {list_a.file_ext}
{
	for (std::size_t i {0}; i < list_b.file_ext.size(); ++i)
	{
		this->file_ext.emplace_back (list_b.file_ext.at(i));
	}
}

/*
	Operator override for the "+" operator.
	Remember that this is not a member function, so it needs all objects to be passed as parameters.
	Returns an "ext_list" object.
	This also depends on the copy constructor!
*/
ext_list operator + (const ext_list & list_a, const ext_list & list_b)
{
	ext_list list_c
	{
		ext_list (list_a, list_b)
	};
	return list_c;
}

bool ext_list::set_file_path (const std::string & str)
{
	this->file_path = str;
	bool flag {0};
	(this->file_path == str) ? flag = 1 : flag = 0;
	return flag;
}

std::string ext_list::get_file_path ()
{
	return this->file_path;
}

void ext_list::load_input_file ()
{
	if (std::filesystem::exists (this->file_path))
	{
		this->input_file.open (this->file_path, std::ios::in);
		if (!(this->input_file))
		{
			throw std::exception {};
		}
	}
	else
	{
		throw file_not_found_exception {};
	}
}

void ext_list::set_file_ext ()
{
	if (input_file.is_open())
	{
		/*
			Declare the line buffer string before the loop.
			Skip the first line as it is blank anyway.
		*/
		std::string s {};
		std::getline (input_file, s);
		for (; !(input_file.eof()); std::getline (input_file, s) )
		{
			if (s.empty() || s == "\n" || s == "\r")
			{

			}
			else
			{
				this->file_ext.emplace_back (s);
			}
		}
	}
}

void ext_list::display_file_ext_list ()
{
	std::cout << std::endl;
	std::cout << "Displaying playlist file entry extensions..." << std::endl;
	for (std::size_t i {0}; i < this->file_ext.size(); ++i)
	{
		std::cout << this->file_ext.at(i) << std::endl;
	}
	std::cout << std::endl;
}

std::vector <std::string> ext_list::get_file_ext_list ()
{
	return this->file_ext;
}

ext_list::~ext_list ()
{
	input_file.close();
}
