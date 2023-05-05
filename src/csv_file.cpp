/*
	Include std libraries
*/
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iterator>

/*
	Include project libraries
*/
#include "csv_file.hpp"

/*
	Constructor
*/
csv_file::csv_file ()
:
	/*
		Delegated Constructor
	*/
	csv_file {"", ','}
{

}

/*
	Constructor - string parameter
*/
csv_file :: csv_file ( const std::string & input_path )
:
	/*
		Delegated Constructor.
		Assign path from parameter.
		Assign default parameter for delimiter as ','.
	*/
	csv_file
	{
		input_path,
		','
	}
{

}

/*
	Constructor - string parameter, character parameter
*/
csv_file::csv_file ( const std::string & input_path, const wchar_t & input_delimiter )
:
	path {input_path},
	input_file_fs {},
	field_delimiter {input_delimiter}
{
	/*
		Check if the file path can be opened.
	*/
	bool progress
	{
		/*
			Read the file and set the progress flag to the value returned from the function.
		*/
		this->csv_file::read_file ()
	};
	if (progress == 1)
	{
		/*
			Attempt to extract the records from the file and buffer to the object's member attribute, "file_contents".
		*/
		progress = this->csv_file::extract_records ();
		if (progress == 1)
		{
			/*
				If the contents have successfully been buffered into the object's member attribute "file_contents" then proceed further.
				Display the contents of the file afterwards for debugging purposes.
			*/
		}
	}
}

/*
	Destructor
*/
csv_file:: ~ csv_file ()
{
	/*
		Check if the fstream attribute remains open.
	*/
	if (this->csv_file::input_file_fs.is_open ())
	{
		/*
			If the fstream attribute is open, close before deallocating memory for the object.
		*/
		this->csv_file::input_file_fs.close ();
	}
}

/*
	Copy Constructor.
*/
csv_file::csv_file ( const csv_file & existing )
:
	path {existing.path},
	input_file_fs {},
	field_delimiter {existing.field_delimiter}
{
	this->csv_file::copy_file_contents_from (existing);
}

/*
	Member function to read the file path for the csv file.
	Returns a flag to signal successful file read.
*/
bool csv_file::read_file ()
{
	/*
		Declare a flag to indicate successful file read.
		Initialise to false by default as the file has not yet been read.
	*/
	bool flag {0};

	/*
		Assign the member attribute for the std::fstream object with the file path and stdin arguments.
	*/
	this->csv_file::input_file_fs = std::fstream {this->csv_file::path, std::ios::in};

	/*
		Check if the file was opened successfully.
	*/
	if (this->csv_file::input_file_fs.is_open ())
	{
		/*
			If the file did open successfully, assign the flag to true.
		*/
		flag = 1;
	}
	else
	{

	}

	/*
		Return the flag to indicate whether the file was read successfully.
	*/
	return flag;
}

/*
	Function to set the delimiter for reading fields.
	This can be set when declaring an object instance through the relevant Constructor, or this can be called afterwards with a specific character argument to assign it separately.
*/
bool csv_file::set_field_delimiter( const wchar_t & ch )
{
	/*
		Assign the member attribute for the delimiter to use the parameter value.
	*/
	this->csv_file::field_delimiter = ch;

	/*
		Return true to show the function has processed successfully.
	*/
	return 1;
}

/*
	This function outputs the current value that is stored in the field delimiter attrbiute for the current object instance.
*/
wchar_t csv_file::get_field_delimiter () const
{
	return this->csv_file::field_delimiter;
}

/*
	Function to extract the records from the file contents for the current object.
	This buffers the file contents into the member attribute "file_contents", which will store the raw strings for each record.
	Return a boolean value to indicate successful execution of function.
*/
bool csv_file::extract_records ()
{
	this->csv_file :: file_contents . clear ();
	/*
		Loop through the file contents line by line until the end of file is reached.
	*/
	for
	(
		std::string buffer {};
		this->csv_file::input_file_fs . eof () == 0;
		this->csv_file::input_file_fs >> buffer
	)
	{
		/*
			Reject empty lines.
		*/
		if ( buffer . empty () )
		{

		}

		/*
			Reject lines with no length.
		*/
		else if ( buffer . size () == 0)
		{

		}

		/*
			Reject lines with empty strings.
		*/
		else if (buffer == "")
		{

		}

		/*
			Reject records with only a carriage return.
		*/
		else if (buffer . at (0) == '\r')
		{

		}

		/*
			Record has passed initial checks.
			Progress to whitespace analysis.
		*/
		else
		{
			/*
				Check for leading spaces.
				Continue checking until a non-space character is found.
			*/

			/*
				Declare and initialise the character validation flag to false.
				When a valid character is found in the record, assign to true and buffer.
			*/
			bool character_flag {0};

			/*
				The loop declares a temporary index variable, which points to the character in the records currently being buffered.
				Cycle through characters until either the end of the record is reached, or a valid charater is found.
			*/
			for (size_t index {0} ; index < buffer.length () || character_flag == 0; ++ index)
			{
				if (buffer.at (index) == ' ')
				{

				}
				else
				{
					character_flag = 1;
				}
			}

			/*
				If the record has passed the character validation, proceed further.
			*/
			if (character_flag == 1)
			{
				/*
					Add the record to the member attribute for storing the file contents.
				*/
				this->csv_file::file_contents . push_back (buffer);
			}
		}
	}
	/*
		Return true for successful file parsing.
	*/
	return 1;
}

/*
	This function displays the file contents.
	After reading the file and copying the contents into the object's member attribute "file_contents", this function can be called.
*/
bool csv_file::display_contents () const
{
	/*
		Declare a temporary index variable.
		Initialise to 1 as this will be used for displaying to the output stream.
	*/
	size_t counter {1};

	/*
		Use a std algorithm function for processing the std container.
	*/
	std::for_each
	(
		this->csv_file::file_contents . begin (),
		this->csv_file::file_contents . end (),

		/*
			Stateful lambda function.
			Capture the earlier temporary variable and pass in the reference to the lambda function to allow read-write access.
		*/
		[& counter]

		/*
			Pass in the container's element as a strign variable.
		*/
		(std::string s)

		/*
			Explicitly declare the output as void, so no output required here, as the purpose of the parent function is to output to the output stream.
		*/
		-> void

		/*
			Lambda function definition.
		*/
		{

			/*
				Display the index of the record, starting from 1.
				Display the record stored in the object's vector container.
				For each object, increment the temporary variable index in order to prepare for the next element in the loop.
			*/
			std::cout << counter;
			std::cout << " - ";
			std::cout << s;
			std::cout << std::endl;
			++ counter;
		}
	);

	/*
		As the method has progressed this far, consider the method successfully run.
	*/
	return 1;
}

/*
	Clear attributes for current object.
	Necessary in case attributes need to be overwritten.
*/
bool csv_file::clear_attributes ()
{
	this->csv_file::path . clear ();
	this->csv_file::input_file_fs . clear ();
	this->csv_file::field_delimiter = ',';
	this->csv_file::file_contents . clear ();
	this->csv_file::raw_data . clear ();

	return 1;
}

/*
		Copies the file contents from a source csv_file object and overwrites the current object's file_contents.
		This is a member function for the target object.
*/
bool csv_file::copy_file_contents_from (const csv_file & source)
{
	/*
		Lambda function for iterating through each string value in the file contents for the source file.
		Each item is then pushed into the target object.
		Note that the vector elements are appended, not overwritten.
		So, if there is already data for the target object then the data will not be overwritten.
	*/
	std::for_each
	(
		source.file_contents.begin (),
		source.file_contents.end (),
		[this]
		(std::string s)
		-> void
		{
			this -> csv_file :: file_contents . push_back (s);
		}
	);
	return 1;
}

/*
	Non-member function.
	Adds two csv_file objects together.
	Creates a new csv_file object.
	This takes the data of the first, and appends the second.
*/
csv_file operator + (const csv_file & file_1, const csv_file & file_2)
{

	csv_file result {};

	result . copy_file_contents_from (file_1);
	result . copy_file_contents_from (file_2);

	return result;
}

bool csv_file :: generate_raw_data ()
{
	this -> csv_file :: raw_data . clear ();
	size_t index {0};
	std::for_each
	(
		this -> csv_file :: file_contents . begin (),
		this -> csv_file :: file_contents . end (),
		[& index, this]
		(std::string s)
		-> void
		{
			bool literal_quoted {0};
			bool double_quoted {0};
			bool escape_character_flag {0};
			std::vector <std::string> row_values {};
			std::string buffer {};

			for (size_t sub_index {0}; sub_index < s.length (); ++ sub_index)
			{
				bool delimiter_reached {0};

				if ( s . at (sub_index) == '\\' )
				{
					if ( escape_character_flag == 0 )
					{
						escape_character_flag = 1;
					}
					else
					{
						escape_character_flag = 0;
					}
				}
				else if ( s . at (sub_index) == '\'' )
				{
					if ( literal_quoted == 0 )
					{
						literal_quoted = 1;
					}
					else
					{
						literal_quoted = 0;
					}
				}
				else if ( s . at (sub_index) == '"' )
				{
					if ( double_quoted == 0 )
					{
						double_quoted = 1;
					}
					else
					{
						double_quoted = 0;
					}
				}

				if ( escape_character_flag == 0 )
				{
					if ( literal_quoted == 0 )
					{
						if ( double_quoted == 0 )
						{
							if ( s . at (sub_index) == this->csv_file::field_delimiter )
							{
								delimiter_reached = 1;
							}
							else if ( sub_index == ( s . length () - 1) )
							{
								buffer . push_back ( s . at ( sub_index ) );
								delimiter_reached = 1;
							}
						}
					}
				}

				if ( delimiter_reached == 1 )
				{
					row_values . push_back ( buffer );
					buffer . clear ();
				}
				else
				{
					buffer . push_back ( s . at ( sub_index ) );
				}
			}
			this -> csv_file :: raw_data . push_back ( row_values );
			row_values . clear ();
		}
	);

	return 1;
}

std::vector <std::vector <std::string> > csv_file :: get_raw_data () const
{
	return this -> csv_file :: raw_data;
}

bool csv_file :: display_raw_data () const
{
	size_t index {0};
	std::for_each
	(
		this -> csv_file :: raw_data . begin (),
		this -> csv_file :: raw_data . end (),
		[& index, this]
		(std::vector <std::string> v)
		-> bool
		{
			size_t sub_index {0};
			std::for_each
			(
				v . begin (),
				v . end (),
				[& sub_index]
				(std::string s)
				-> bool
				{
					if (sub_index > 0)
					{
						std::cout << ", ";
					}

					std::cout << s;
					++ sub_index;

					return 1;
				}
			);
			sub_index = 0;
			std::cout << std::endl;
			++ index;
			return 1;
		}
	);
	std::cout << std::endl;
	return 1;
}
