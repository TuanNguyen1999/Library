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
		Phieu(const DocGia&, const std::list<SachViet>&, const std::list<SachNgoai>&,
				const ThoiGian&, size_t, bool = false);
		~Phieu() {}
		Phieu& operator=(const Phieu&);
		Phieu(const Phieu& p) :
				m_DocGia(p.m_DocGia),
				lSachNgoai(p.lSachNgoai),
				lSachViet(p.lSachViet),
				m_NgayMuon(p.m_NgayMuon),
				nSoNgayMuon(p.nSoNgayMuon),
				bDaTra(p.bDaTra) {}

		//Setters
		inline size_t& so_ngay_da_muon() { return nSoNgayMuon; }
		inline bool& da_tra_sach() { return bDaTra; }

		//Getters
		inline bool da_tra_sach() const { return bDaTra; }
		inline const DocGia& doc_gia() const { return m_DocGia; }
		inline const std::list<SachViet>& sach_viet() const { return lSachViet; }
		inline const std::list<SachNgoai>& sach_ngoai() const { return lSachNgoai; }
		inline const ThoiGian& ngay_bat_dau() const { return m_NgayMuon; }
		ThoiGian ngay_het_han() const;
		inline size_t so_ngay_da_muon() const { return nSoNgayMuon; }
		size_t phi_tre_han() const;

		//static members functions
		static size_t phi_tre_han(const Phieu&);

		//Non-member functions
		friend std::ostream& operator<<(std::ostream&, const Phieu&);

private:
		DocGia m_DocGia;
		std::list<SachNgoai> lSachNgoai;
		std::list<SachViet> lSachViet;
		ThoiGian m_NgayMuon;
		size_t nSoNgayMuon;
		bool bDaTra;
};

#endif