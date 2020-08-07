///INPUT HANDLING FOR TRIPLE DES
#include "../include/User_Input.h"
#include <string>
#include <iostream>
#include <fstream>  ///ifstream
#include <bitset>   ///bitset

void User_Input::valid_input(std::string in)
{
    in[0] = tolower(in[0]);
	if (in[0] == 'e' or in[0] == 'd')
    {
        user_E_D = in[0];
		get_U_IN("the file name: ", 1, 0);
    }

	else
		get_U_IN("either 'E' or 'D'", 0, 0);
}

///This may not be needed
void User_Input::valid_file(std::string in)
{
    std::ifstream binFile(in.c_str(), std::ifstream::in);
    if(binFile)
    {
        file_name = in;
        get_U_IN("key", 2, 0);
    }
    else
        get_U_IN("the file name: ", 1,0);
}

void User_Input::valid_key(long long int in, int i)
{ ///NEED TO ERROR CHECK KEY TO MAKE SURE THERE ARE ONLY HEX CHARS
	if (i <= 2)
    {
		keys[i] = std::bitset<64>(in);
		get_U_IN("key", 2, i+1);
	}
	else
		get_U_IN("\"", 3, 3);
}

/**
    purpose: Gets users input for the type of action to be taken :: return -1 when finished input collection
    out - is the sentance I want to send to the user to be displayed to prompt input
    state - the variable which controls which loop/checks need to be engaged, can be either 0, 1, 2 (> 2 for exit)
    i - the index for the keys array
**/
void User_Input::get_U_IN(std::string out, unsigned int state, int i)
{
	std::string in;
	unsigned long long int hexIn;

    if(state > 2)
    {
        std::cout<< "Well will begin working on your file shortly..." << std::endl;
        return;
    }

    if (state == 2 and i <= 2)
	{
	    std::cout << "Please enter " << out << " no. " << i+1 << std::endl;
		std::cin >> std::hex >> hexIn;
		valid_key(hexIn, i);
	}
    else if (state < 2)
    {
        std::cout << "Please enter " << out << std::endl;
        std::cin >> in;
    }

	if (state == 1)
		valid_file(in);

    if ( state == 0 )
		valid_input(in);
}


/**
--ios--

::in	-- Open for input operations.
ios::out --	Open for output operations.
ios::binary	-- Open in binary mode.
ios::ate --	Set the initial position at the end of the file.
If this flag is not set, the initial position is the beginning of the file.
ios::app	All output operations are performed at the end of the file, appending the content to the current content of the file.
ios::trunc	If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.

*/
