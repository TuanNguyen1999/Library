#ifndef _CL_PHIEU_H_
#define _CL_PHIEU_H_

#include "DocGia.h"
#include "SachNgoai.h"
#include "ThoiGian.h"
#include <list>
class Phieu
{
public:
		const size_t SoNgayMuonToiDa = 7;
		const size_t PhiSachViet = 10000;
		const size_t PhiSachNgoai = 20000;

		//Constructors, Destructor
		Phieu();
		Phieu(const DocGia&, const std::list<SachViet>&, const std::list<SachNgoai>&, const ThoiGian&, size_t);
		~Phieu() {}

		//Setters
		inline size_t& so_ngay_da_muon() { return nSoNgayMuon; }

		//Getters
		inline const DocGia& doc_gia() const { return m_DocGia; }
		inline const std::list<SachViet>& sach_viet() const { return lSachViet; }
		inline const std::list<SachNgoai>& sach_ngoai() const { return lSachNgoai; }
		inline const ThoiGian& ngay_bat_dau() const { return m_NgayMuon; }
		inline const ThoiGian ngay_ket_thuc() const;
		inline size_t so_ngay_da_muon() const { return nSoNgayMuon; }
		size_t phi_tre_han() const;

		//static members
		static size_t phi_tre_han(const Phieu&);
private:
		DocGia m_DocGia;
		std::list<SachNgoai> lSachNgoai;
		std::list<SachViet> lSachViet;
		ThoiGian m_NgayMuon;
		size_t nSoNgayMuon;
};

#endif