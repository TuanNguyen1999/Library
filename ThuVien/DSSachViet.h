#ifndef _CL_DSSACHVIET_H_
#define _CL_DSSACHVIET_H_
#include "DanhSach.h"
#include "Sach.h"
#include <vector>
#include <string>
typedef class DSSachViet : public DanhSach
{
public:
		DSSachViet() {}
		DSSachViet(const std::vector<SachViet>& l) : m_list(l) {}
		virtual ~DSSachViet() {}
		virtual void sua();
		virtual void them();
		virtual void xoa();
		virtual void nhap_danh_sach();
		virtual void xuat() const;
		virtual void ghi_file(const char*) const;
		virtual std::vector<int> tim_kiem() const;
		virtual void nhap_tu_file(const char*);
private:
		std::vector<SachViet> m_list;
} DSSV;

#endif
