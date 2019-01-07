#ifndef _CL_DANHSACHPHIEU_H_
#define _CL_DANHSACHPHIEU_H_
#include <list>
#include "Phieu.h"
class DanhSachPhieu
{
public:
		typedef std::list<Phieu> Container;
		typedef Container::value_type value_type;
		typedef Container::reference reference;
		typedef Container::const_reference const_reference;
		typedef Container::iterator iterator;
		typedef Container::const_iterator const_iterator;

		DanhSachPhieu() : m_DanhSach() {}
		DanhSachPhieu(const Container& ds) : m_DanhSach(ds) {}
		DanhSachPhieu(const_iterator begin, const_iterator end) : m_DanhSach(begin, end) {}
		~DanhSachPhieu() {}

		void them(const value_type& ph) { m_DanhSach.push_back(ph); }
		void xoa(const_iterator pos) { m_DanhSach.erase(pos); }
		void sua(size_t pos, const_reference _new);
		const_reference tim_kiem(size_t pos) const;
		void xuat_danh_sach() const;
		void ghi_file(const char*);

private:
		Container m_DanhSach;
};

#endif