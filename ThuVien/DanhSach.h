#ifndef _CL_DANHSACH_H_
#define _CL_DANHSACH_H_

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

class DanhSach
{
public:
		virtual void sua() { return; }
		virtual void xoa() { return; }
		virtual void nhap_tu_file(const char*) { return; }
		virtual void ghi_file(const char*) { return; }
		virtual std::vector<int> tim_kiem() const { return std::vector<int>(); }
		virtual void them() = 0;
		virtual void nhap_danh_sach() = 0;
		virtual void xuat() const = 0;
};

#endif