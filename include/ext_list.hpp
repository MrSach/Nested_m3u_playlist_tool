#pragma once
#ifndef EXT_LIST_HPP
#define EXT_LIST_HPP

#include <string>
#include <fstream>
#include <vector>
#include <filesystem>

class ext_list
{
	protected:
		std::filesystem::path file_path;
		std::fstream input_file;
		std::vector <std::string> file_ext;

	public:
		ext_list (void);
		ext_list (const std::string & str);
		ext_list (const ext_list & list_b);
		ext_list (ext_list && list_b);
		ext_list (const ext_list & list_a, const ext_list & list_b);

		virtual bool set_file_path (const std::string & str);
		virtual std::string get_file_path (void);
		virtual void load_input_file (void);
		virtual void set_file_ext (void);
		virtual void display_file_ext_list (void);
		virtual ~ ext_list (void);
};

ext_list operator + (const ext_list & list_a, const ext_list & list_b);

#endif // EXT_LIST_HPP
