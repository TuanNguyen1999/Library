#ifndef _CL_DSDOCGIA_H_
#define _CL_DSDOCGIA_H_

#include "DanhSach.h"
#include "DocGia.h"
typedef class DSDocGia : public DanhSach
{
public:
		DSDocGia() {}
		DSDocGia(const std::vector<DocGia>& l) : m_list(l) {}
		virtual ~DSDocGia() {}
		virtual void sua();
		virtual void them();
		virtual void xoa();
		virtual void nhap_danh_sach();
		virtual void xuat() const;
		virtual void ghi_file(const char*) const;
		virtual std::vector<int> tim_kiem() const;
		virtual void nhap_tu_file(const char*);
		const std::vector<DocGia>& danh_sach() const { return m_list; }
private:
		std::vector<DocGia> m_list;
} DSDG;

#endif