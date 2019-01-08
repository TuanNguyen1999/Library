#ifndef _CL_DANHSACH_H_
#define _CL_DANHSACH_H_

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

class DanhSach
{
public:
		virtual void sua() = 0;
		virtual void them() = 0;
		virtual void xoa() = 0;
		virtual void nhap_danh_sach() = 0;
		virtual void xuat() const = 0;
		virtual void ghi_file(const char*) const = 0;
		virtual void tim_kiem() { return; }
protected:
		static int menu(const std::vector<std::string>& cmds)
		{
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
						ss >> option;
						if (ss.eof() && option >= 1 && option < i)
								return option;
						std::cout << "Loi! chon lai: ";
				}
		}

};

#endif