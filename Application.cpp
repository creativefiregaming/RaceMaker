#include "Application.h"

#include <Windows.h>
#include <shellapi.h>

#include <iostream>

Application::Application()
{

}
void Application::OpenURL(const std::string url)
{
	
	ShellExecute(0, 0, std::wstring(url.begin(), url.end()).c_str(), 0, 0, SW_SHOW);
	std::cout << "open\n";
}