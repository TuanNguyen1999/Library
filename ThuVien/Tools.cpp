#include "Tools.h"


std::string Tools::tolower(const std::string& str)
{
		std::string lowerStr = str;
		for (size_t i = 0; i < str.length(); i++)
				lowerStr[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + ('a' - 'A') : str[i];
		return lowerStr;
}
std::string Tools::title(const std::string& str)
{
		std::string titleStr = tolower(str);
		titleStr[0] = (str[0] >= 'a' && str[0] <= 'z') ? str[0] - ('a' - 'A') : str[0];
		return titleStr;
}
std::string Tools::toupper(const std::string& str)
{
		std::string upper = str;
		for (size_t i = 0; i < str.length(); i++)
				upper[i] = (str[i] >= 'a' && str[i] <= 'z') ? str[i] - ('a' - 'A') : str[i];
		return upper;
}

