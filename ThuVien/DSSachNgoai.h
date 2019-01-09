#ifndef _CL_DSSACHNGOAI_H_
#define _CL_DSSACHNGOAI_H_
#include "DanhSach.h"
#include "SachNgoai.h"
typedef class DSSachNgoai : public DanhSach
{
public:
		DSSachNgoai() {}
		virtual ~DSSachNgoai() {}
		DSSachNgoai(const std::vector<SachNgoai>& l) : m_list(l) {}
		virtual void sua();
		virtual void them();
		virtual void xoa();
		virtual void nhap_danh_sach();
		virtual void xuat() const;
		virtual void ghi_file(const char*) const;
		virtual std::vector<int> tim_kiem() const;
		virtual void nhap_tu_file(const char*);
		const std::vector<SachNgoai>& danh_sach() const { return m_list; }
private:
		std::vector<SachNgoai> m_list;
} DSSN;


#endif