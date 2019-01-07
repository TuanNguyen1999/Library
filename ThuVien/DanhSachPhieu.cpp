#include "DanhSachPhieu.h"
#include <iostream>
#include <fstream>
void DanhSachPhieu::sua(size_t pos, const_reference _new)
{
		if (pos >= m_DanhSach.size())
		{
				std::cout << "Method DanhSachPhieu::sua(size_t pos, const_reference _new): Index out of range\n";
				return;
		}

		iterator it = m_DanhSach.begin();
		while (pos != 0) it++;
		*it = _new;
}
DanhSachPhieu::const_reference DanhSachPhieu::tim_kiem(size_t pos) const
{
		if (pos >= m_DanhSach.size())
		{
				std::cout << "Method DanhSachPhieu::tim_kiem(size_t pos): Index out of range\nFirst element is returned instead'\n";
				return *m_DanhSach.cbegin();
		}

		const_iterator it = m_DanhSach.cbegin();
		while (pos != 0) it++;
		return *it;
}
void DanhSachPhieu::xuat_danh_sach() const
{
		int i = 1;
		for(auto obj : m_DanhSach)
		{
				std::cout << i++ << "\\\n" << obj << std::endl;
		}
}
void DanhSachPhieu::ghi_file(const char* file)
{
		std::ofstream wf(file);
		int i = 1;
		for (auto obj : m_DanhSach)
		{
				wf << i++ << "\\\n" << obj << std::endl;
		}
}