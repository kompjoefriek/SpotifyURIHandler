# Spotify URI Handler

![Logo](spotifyurihandler.png)

This project builds a Windows installer (.exe and .msi) for 64bit versions of Windows.

It will install a URI handler (links that start with "spotify:") and open them in your default browser.

Please note that this may conflict with the Spotify desktop client, do not install both!


## Sample URI:

album: `spotify:album:27ftYHLeunzcSzb33Wk1hf`

artist: `spotify:artist:3mvkWMe6swnknwscwvGCHO`

track: `spotify:track:7lEptt4wbM0yJTvSG5EBof`

user: `spotify:user:1185903410`

playlist: `spotify:user:1185903410:playlist:6YAnJeVC7tgOiocOG23Dd`


## URI Handler in registry

:file_folder: `HKEY_CLASSES_ROOT`

&nbsp;&#9492; :file_folder: `<uri name>`

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&#9500; :ab: `REG_SZ`  `(Default)`     `<name>`

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&#9500; :ab: `REG_SZ`  DefaultIcon   `"<path to .ico file>"`

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&#9500; :ab: `REG_SZ`  URL Protocol  `<empty>`

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&#9492; :file_folder: shell

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&#9492; :file_folder: open

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&#9492; :file_folder: command

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&#9492; :ab: `REG_SZ`  `(Default)`  `"<path to .exe file>" %1`

## Disclaimer

All product and company names are trademarks™ or registered® trademarks of their respective holders. Use of them does not imply any affiliation with or endorsement by them.

Spotify is a trademark of Spotify AB.
