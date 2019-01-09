#ifndef _CL_DSPHIEU_H_
#define _CL_DSPHIEU_H_
#include "DanhSach.h"
#include "Phieu.h"
#include "DSDocGia.h"
#include "DSSachNgoai.h"
#include "DSSachViet.h"
typedef class DSPhieu : public DanhSach
{
public:
		DSPhieu() {}
		DSPhieu(const std::vector<Phieu>& l) : m_list(l) {}
		virtual ~DSPhieu() {}
		virtual void xuat() const;
		virtual void ghi_file(const char*) const;
		virtual void them(const DSDG&, const DSSV& dssv, const DSSN& dssn);
		virtual void xoa();
		const std::vector<Phieu>& danh_sach() const { return m_list; }
private:
		std::vector<Phieu> m_list;

		virtual void sua() {}
		virtual void them() {}
		virtual std::vector<int> tim_kiem() const { return std::vector<int>(); }
		virtual void nhap_tu_file(const char*) {}
		virtual void nhap_danh_sach() {}
} DSP;

#endif