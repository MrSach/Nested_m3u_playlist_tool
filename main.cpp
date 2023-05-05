/*
	Load std libraries
*/
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <string>
#include <filesystem>

/*
	Load project header files
*/
#include "m3u_playlist_file_text.hpp"
//#include "csv_file.hpp"
//#include "text_data_type_parser.hpp"
#include "ext_list.hpp"
#include "file_not_found_exception.hpp"
#include "file_cannot_be_opened_exception.hpp"

/*
	Main program.
	Accept arguments.
	Take number of arguments.
	Also take the string values of the arguments.
*/
int main ( int argc, char * * argv )
{
	std::cout << "m3u playlist reader test";
	std::cout << std::endl;
	std::cout << "By SSGV";
	std::cout << std::endl;

	/*
		Debug - for reference.
	*/
    //m3u_playlist_file_text pls_1 {"/home/user/otheraudio/general-pls.m3u"};

    /*
		Test - media file extension list.
    */
//    csv_file entry_extension_list
//    (
//		"playlist_entry_extension.txt",
//		','
//	);

		try
		{
			/*
				Generate file extension lists for audio files and nested playlist files.
			*/
			ext_list playlist_entry_extension {"resource/playlist_entry_extension.txt"};
			std::cout << "playlist entry list extension file: " << playlist_entry_extension.get_file_path() << std::endl;
			playlist_entry_extension.display_file_ext_list();

			ext_list nested_playlist_entry_extension {"resource/playlist_extension.txt"};
			std::cout << "playlist extension list file: " << nested_playlist_entry_extension.get_file_path() << std::endl;
			nested_playlist_entry_extension.display_file_ext_list();

			ext_list agg_list {playlist_entry_extension + nested_playlist_entry_extension};
			agg_list.display_file_ext_list();
		}

		catch (const std::filesystem::filesystem_error & e)
		{
			std::cerr << "Error: File not loaded! " << "Details: " << e.what () << std::endl;
		}
		catch (const file_not_found_exception & e)
		{
			std::cerr << "Error: File not loaded! " << "Details: " << e.what () << std::endl;
		}
		catch (const file_cannot_be_opened_exception & e)
		{
			std::cerr << "Error: File not loaded! " << "Details: " << e.what () << std::endl;
		}

	return 0;
}
