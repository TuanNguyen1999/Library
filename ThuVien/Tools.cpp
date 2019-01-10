#include "Tools.h"
#include <Windows.h>
#include <chrono>
#include <thread>
std::string Tools::tolower(std::string str)
{
		for (size_t i = 0; i < str.length(); i++)
				str[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + ('a' - 'A') : str[i];
		return str;
}
std::string Tools::title(std::string str)
{
		char ch = ' ';
		size_t pos = 0;
		for (size_t i = 1; i < str.length(); i++)
		{
				if (str[i] >= 'a' && str[i] <= 'z' && str[i-1] == ' ')
						str[i] = str[i] - ('a' - 'A');
				else
						str[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + ('a' - 'A') : str[i];
		}
		str[0] = (str[0] >= 'a' && str[0] <= 'z') ? str[0] - ('a' - 'A') : str[0];
		return str;
}
std::string Tools::toupper(std::string str)
{
		for (size_t i = 0; i < str.length(); i++)
				str[i] = (str[i] >= 'a' && str[i] <= 'z') ? str[i] - ('a' - 'A') : str[i];
		return str;
}

void Tools::pause()
{
		std::cout << "Press Enter to continue...";
		std::string cache;
		std::getline(std::cin, cache);
}
void Tools::sleep_for_milliseconds(int ms)
{
		std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
void Tools::clear()
{
		HANDLE                     hStdOut;
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		DWORD                      count;
		DWORD                      cellCount;
		COORD                      homeCoords = { 0, 0 };

		hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hStdOut == INVALID_HANDLE_VALUE) return;

		//Get the number of cells in the current buffer 
		if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
		cellCount = csbi.dwSize.X *csbi.dwSize.Y;

		//Fill the entire buffer with spaces
		if (!FillConsoleOutputCharacter(
				hStdOut,
				(TCHAR) ' ',
				cellCount,
				homeCoords,
				&count
		)) return;

		//Fill the entire buffer with the current colors and attributes
		if (!FillConsoleOutputAttribute(
				hStdOut,
				csbi.wAttributes,
				cellCount,
				homeCoords,
				&count
		)) return;

		//Move the cursor home
		SetConsoleCursorPosition(hStdOut, homeCoords);
}