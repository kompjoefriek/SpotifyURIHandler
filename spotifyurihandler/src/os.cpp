#include "os.h"

namespace os
{

#if defined(_MSC_VER)

#include <windows.h>
#include <shellapi.h>

void openURL(const std::string& url)
{
	ShellExecuteA(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

#elif defined(__unix__)

#include <cstdlib>

void openURL(const std::string& url)
{
	system(("open "s + url).c_str());
}

#else

void openURL(const std::string& url)
{
	std::cerr << "Could not execute system call on this platform. URL = "<< url << std::endl;
}

#endif // _MSC_VER or __unix__ or default

} // namespace OS
