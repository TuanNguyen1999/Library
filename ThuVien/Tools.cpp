#include "Tools.h"


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

