/*
	Block Guards and pragma shortcut
*/
#pragma once
#ifndef TEXT_DATA_TYPE_PARSER_HPP
#define TEXT_DATA_TYPE_PARSER_HPP

/*
	Include STL libraries
*/
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <iostream>

/*
	Declare class template.
	Abstract generic data type to 'A'.
*/
template <typename A>
class text_data_type_parser
{
	protected:
		/*
			This should store the value of the original text to convert.
		*/
		std :: string plain_text;

		/*
			This should store the new converted data type.
		*/
		A reformatted;

		/*
			This stores the data type detected by the method used to determine target data type.
		*/
		std :: string type_detected;

		/*
			List of numeric characters and corresponding mapped integer values.
		*/
		std::map < char, short int > numerics
		{
			{
				'1', 1
			},
			{
				'2', 2
			},
			{
				'3', 3
			},
			{
				'4', 4
			},
			{
				'5', 5
			},
			{
				'6', 6
			},
			{
				'7', 7
			},
			{
				'8', 8
			},
			{
				'9', 9
			},
			{
				'0', 0
			}
		};

		/*
			Check for prefixes that may infer numeric data types and not strings.
		*/
		std :: vector < char > numeric_prefix
		{
			{
				'u',
				'-',
				'+'
			}
		};

		/*
			Suffixes that may indicate a numeric value instead of a string value
		*/
		std :: vector < char > numeric_suffix
		{
			{
				'e',
				'E'
			}
		};

	public:

		text_data_type_parser ()
		{

		}

		text_data_type_parser ( std::string resource )
		{

		}

		virtual ~ text_data_type_parser ()
		{

		}

		text_data_type_parser ( const text_data_type_parser & other );

		/*
			Assignment operator, =
		*/
		text_data_type_parser operator = ( const text_data_type_parser & rhs )
		{
			/*
				Self-assignment.
			*/
			if ( this == & rhs )
			{
				return * this;
			}

			return * this;
		}

		/*
			Filter input string
		*/
		virtual bool filter_str ( std :: string resource )
		{
			if ( resource . empty ())
			{
				return 0;
			}
			else if ( resource == "" )
			{
				return 0;
			}
			else if ( resource . at ( 0 ) == '\r' )
			{
				return 0;
			}
			else if ( resource . at ( 0 ) == '\n' )
			{
				return 0;
			}
			else if ( resource . at ( 0 ) == '\0' )
			{
				return 0;
			}
			else
			{
				bool not_spaces { 0 };
				for ( size_t index { 0 } ; index < resource . size () ; ++ index )
				{
					if ( resource . at ( index ) == ' ')
					{

					}
					else
					{
						not_spaces = 1;
					}
				}
				if ( not_spaces == 0 )
				{
//					std::cout << "Whitespace-only string found!" << std::endl;
					return 0;
				}
//				std::cout << resource << " is OK" << std::endl;
				return 1;
			}
		}

		/*
			Data type autodetection algorithm
		*/
		virtual std :: string data_type_detect ( std :: string & resource )
		{
			/*
				Determines whether there is a character in the string (A - Z, a - z, etc.)
			*/
			bool character_exists { 0 };

			/*
				Flag to determine whether there is a numerical character in the string.
			*/
			bool number_exists { 0 };

			/*
				Flag to determine whether the string contains a character prefix for a numeric value.
			*/
			bool numeric_prefix_character { 0 };

			/*
				Flag to determine whether the string contains a character suffix for a numerical value.
			*/
			bool numeric_suffix_character { 0 };

			/*
				Flags whether the input is explcitly signed.
			*/
			bool sign_exists { 0 };

			/*
				Flags whether there is a positive '+' prefix.
			*/
			bool positive_sign { 0 };

			/*
				Flags whether there is an explicit negative sign for the input string.
			*/
			bool negative_sign { 0 };

			/*
				Flag to determine leading spaces in the input string.
			*/
			bool leading_spaces { 0 };

			/*
				Flags whether there are intermediate spaces in the input string between other characters.
			*/
			bool intermediate_spaces { 0 };

			/*
				Flag to determine whether the input string ends in one or more spaces.
			*/
			bool trailing_spaces { 0 };

			/*
				Buffer flag - used during the string parser loop to store whether the loop is currently pointing to whitespace.
			*/
			bool currently_spaced { 0 };

			/*
				Index to locate first non-whitespace character
			*/
			size_t index_non_space_first { std :: string :: npos };

			/*
				Index to locate last non-whitespace character
			*/
			size_t index_non_space_last { std :: string :: npos };

//			/*
//				Counter to determine the number of continuous whitespace blocks in the string.
//			*/
//			size_t whitespace_block_counter { 0 };

			/*
				Parser loop.
			*/
			for ( size_t index { 0 } ; index < resource . size () ; ++index )
			{
				/*
					Check for whitespace character at current index position.
				*/
				if ( resource . at ( index ) == ' ')
				{
					if ( currently_spaced == 0 )
					{
						currently_spaced == 1;
					}
					if ( ( resource . at ( index ) ) == ( resource . size () - 1 ) )
					{
						trailing_spaces = 1;
					}
					else if ( index == 0 )
					{
						leading_spaces = 1;
					}
				}
				else
				{
					currently_spaced = 0;
					if (currently_spaced == 1)
					{
						currently_spaced = 0;

					}
					else
					{

					}
				}
			}
			return "NULL";
		}
};

#endif // TEXT_DATA_TYPE_PARSER_HPP
