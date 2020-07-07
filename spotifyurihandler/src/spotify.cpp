#include "spotify.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std::string_literals;

// unnamed namespace, to keep contents local to this translation unit (https://stackoverflow.com/a/4422554/3931225)
namespace
{

std::vector<std::string> splitString(const std::string& input, const char token)
{
	std::vector<std::string> vec;
	std::istringstream uriStream(input);
	std::string s;
	while (getline(uriStream, s, token))
	{
		vec.push_back(s);
	}
	return vec;
}

}

namespace spotify
{

const std::string SPOTIFY_ID = "spotify"s;
const std::vector<std::string> SPOTIFY_KEYS = { "album"s, "artist"s, "playlist"s, "track"s, "user"s };

/*
examples:

spotify:album:27ftYHLeunzcSzb33Wk1hf
https://open.spotify.com/album/27ftYHLeunzcSzb33Wk1hf

spotify:artist:3mvkWMe6swnknwscwvGCHO
https://open.spotify.com/artist/3mvkWMe6swnknwscwvGCHO

spotify:track:7lEptt4wbM0yJTvSG5EBof
https://open.spotify.com/track/7lEptt4wbM0yJTvSG5EBof

spotify:user:1185903410
https://open.spotify.com/user/1185903410

spotify:user:1185903410:playlist:6YAnJeVC7tgOiocOG23Dd
https://open.spotify.com/user/1185903410/playlist/6YAnJeVC7tgOiocOG23Dd

*/

enum parseState
{
	URI_ID,		// "spotify"
	URI_KEY,	// "track"
	URI_VALUE	// "7lEptt4wbM0yJTvSG5EBof"
};

std::string convertURItoURL(const std::string& uri)
{
	const std::vector<std::string> uriParts = splitString(uri, ':');

	std::string url("https://open.spotify.com");
	parseState state = URI_ID;
	for (const std::string& part : uriParts)
	{
		switch (state)
		{
			case URI_ID:
				// match id
				if (part.compare(SPOTIFY_ID) != 0)
				{
					throw new std::runtime_error("Unknown ID: "s + part);
				}
				state = URI_KEY;
				break;

			case URI_KEY:
				// match key
				if (std::find(SPOTIFY_KEYS.begin(), SPOTIFY_KEYS.end(), part) == SPOTIFY_KEYS.end())
				{
					throw new std::runtime_error("Unknown Key: "s + part);
				}

				// Add key
				url += "/"s + part;
				state = URI_VALUE;
				break;

			case URI_VALUE:
				// Add value
				url += "/"s + part;
				state = URI_KEY;
				break;
		}
	}

	return url;
}

} // namespace Spotify
