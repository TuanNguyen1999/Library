#ifndef _CL_DANHSACH_H_
#define _CL_DANHSACH_H_

#include <list>
#include <iostream>
#include <string>

template<typename value_type>
class DanhSach : public std::list<value_type>
{
		typedef std::list<value_type> BaseClass;
public:
		DanhSach() : BaseClass() {}
		DanhSach(const BaseClass& ds) : BaseClass(ds) {}
		template<typename InputIterator>
		DanhSach(InputIterator first, InputIterator last) : BaseClass(first, last) {}
		DanhSach(const std::initializer_list<value_type>& ds) : BaseClass(ds) {}
		virtual ~DanhSach() {}

		std::istream& nhap_danh_sach(std::istream& is = std::cin)
		{
				std::string ch;
				value_type cache;
				while (1)
				{
						is >> cache;
						this->BaseClass::push_back(cache);
						std::cout << "thoat?(y/n): ";
						std::getline(is, ch);
						if (ch[0] == 'Y' || ch[0] == 'y')
								return is;
				}

		}
		std::ostream& xuat_danh_sach(std::ostream& os = std::cout) const
		{
				int i = 1;
				for (auto it = this->BaseClass::begin(); it != BaseClass::end(); it++)
				{
						os << i++ << "\\...\n" << *it << std::endl;
				}
				return os;
		}
};

template<typename value_type>
class DanhSach : public std::list<value_type>
{
		typedef std::list<value_type> BaseClass;
public:
		DanhSach() : BaseClass() {}
		DanhSach(const BaseClass& ds) : BaseClass(ds) {}
		template<typename InputIterator>
		DanhSach(InputIterator first, InputIterator last) : BaseClass(first, last) {}
		DanhSach(const std::initializer_list<value_type>& ds) : BaseClass(ds) {}
		virtual ~DanhSach() {}

		std::istream& nhap_danh_sach(std::istream& is = std::cin)
		{
				std::string ch;
				value_type cache;
				while (1)
				{
						is >> cache;
						this->BaseClass::push_back(cache);
						std::cout << "thoat?(y/n): ";
						std::getline(is, ch);
						if (ch[0] == 'Y' || ch[0] == 'y')
								return is;
				}

		}
		std::ostream& xuat_danh_sach(std::ostream& os = std::cout) const
		{
				int i = 1;
				for (auto it = this->BaseClass::begin(); it != BaseClass::end(); it++)
				{
						os << i++ << "\\...\n" << *it << std::endl;
				}
				return os;
		}
};




#endif