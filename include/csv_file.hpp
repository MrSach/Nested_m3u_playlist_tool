#pragma once
#ifndef CSV_FILE_HPP
#define CSV_FILE_HPP

#include <vector>
#include <string>
#include <iostream>

class csv_file
{
	protected:

		/*
			Universal Resource Locator - file path as text string.
		*/
		std::string path;

		/*
			Fstream object for the file path.
		*/
		std::fstream input_file_fs;

		/*
			Delimiter for fields in the csv file.
			Default is ','.
		*/
		wchar_t field_delimiter;

		/*
			Contents of the file, all in text format.
		*/
		std::vector <std::string> file_contents { };

		/*
			Two-dimensional vector of the file contents.
		*/
		std::vector <std::vector <std::string> > raw_data { { } };

		/*
			Determine whether the data has headers.
		*/
		bool headered;

	public:
		csv_file ();
		csv_file ( const std::string & input_path );
		csv_file ( const std::string & input_path, const wchar_t & input_delimiter );
		csv_file ( const csv_file & existing );
		virtual ~ csv_file ();
		virtual bool read_file ();
		virtual bool set_field_delimiter ( const wchar_t & ch );
		virtual wchar_t get_field_delimiter () const;
		virtual bool extract_records ();
		virtual bool display_contents () const;
		virtual bool clear_attributes ();
		virtual bool copy_file_contents_from (const csv_file & source);
		virtual bool generate_raw_data ();
		virtual std::vector <std::vector <std::string> > get_raw_data () const;
		virtual bool display_raw_data () const;
		//virtual bool append_raw_data ();
};

csv_file operator + (const csv_file & file_1, const csv_file & file_2);

#endif // CSV_FILE_HPP
