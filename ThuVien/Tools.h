#ifndef _CL_TOOLS_H_
#define _CL_TOOLS_H_
#include <vector>
#include <sstream>
#include <iostream>
class Tools
{
public:
		template<typename _Ty>
		static std::vector<int> menu(const std::vector<_Ty>& cmds, bool multiple_options = false)
		{
				//Print menu
				std::vector<int> vOptions(cmds.size(), 0);
				int i = 1;
				int option = -1;
				std::string cache;
				for (auto cmd : cmds)
						std::cout << i++ << ". " << cmd << std::endl;
				std::cout << "Chon: ";
				while (true)
				{
						std::stringstream ss;
						std::getline(std::cin, cache);
						ss << cache;
						int i = 0;
						//Checking for valid input
						while (ss.good() && i < cmds.size())
						{
								//Check if number is in set of valid options
								int n;
								ss >> n;
								if (n >= 1 && n <= cmds.size())
										vOptions[i++] = n;;
						}
						//if(vOption[0] == 0) => true => No input or fail
						if ((ss.eof() || i == cmds.size()) && vOptions[0] != 0)			//Succesfull input
						{
								multiple_options ? vOptions.resize(i) : vOptions.resize(1);
								return vOptions;
						}
						std::cout << "Loi! chon lai: ";
				}
		}
		static std::string tolower(std::string);
		static std::string toupper(std::string);
		static std::string title(std::string);

		static void pause();
		static void clear();

};

#endif