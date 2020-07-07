#include "spotify.h"
#include "os.h"

#include <iostream>
#include <string>


int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Please provide a Spotify URI" << std::ends;
		return 1;
	}

	try
	{
		const std::string sporifyURL = spotify::convertURItoURL(argv[1]);
		os::openURL(sporifyURL);
	}
	catch (const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}

	return 0;
}
