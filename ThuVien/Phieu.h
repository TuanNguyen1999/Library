#ifndef _CL_PHIEU_H_
#define _CL_PHIEU_H_

#include "IO.h"
#include "DocGia.h"
#include "SachNgoai.h"
#include "Sach.h"
#include "ThoiGian.h"
#include <list>
class Phieu : public IO
{
public:
		//Constructors, Destructor
		Phieu();
		Phieu(const DocGia&, const std::list<SachViet>&, const std::list<SachNgoai>&,
				const ThoiGian&, size_t, bool = false);
		~Phieu() {}
		Phieu& operator=(const Phieu&);
		Phieu(const Phieu& p) :
				m_DocGia(p.m_DocGia),
				dsSachNgoai(p.dsSachNgoai),
				dsSachViet(p.dsSachViet),
				m_NgayMuon(p.m_NgayMuon),
				nSoNgayMuon(p.nSoNgayMuon),
				bDaTra(p.bDaTra) {}

		//Setters
		inline size_t& so_ngay_da_muon() { return nSoNgayMuon; }
		inline bool& da_tra_sach() { return bDaTra; }

		//Getters
		inline bool da_tra_sach() const { return bDaTra; }
		inline const DocGia& doc_gia() const { return m_DocGia; }
		inline const std::list<SachViet>& sach_viet() const { return dsSachViet; }
		inline const std::list<SachNgoai>& sach_ngoai() const { return dsSachNgoai; }
		inline const ThoiGian& ngay_bat_dau() const { return m_NgayMuon; }
		ThoiGian ngay_het_han() const;
		inline size_t so_ngay_da_muon() const { return nSoNgayMuon; }
		size_t phi_tre_han() const;

		//static members
		static const size_t SoNgayMuonToiDa = 7;
		static const size_t PhiSachViet = 10000;
		static const size_t PhiSachNgoai = 20000;
		static size_t phi_tre_han(const Phieu&);

		//Read, write
		virtual std::ostream& stream_write(std::ostream&) const;

private:
		DocGia m_DocGia;
		std::list<SachNgoai> dsSachNgoai;
		std::list<SachViet> dsSachViet;
		ThoiGian m_NgayMuon;
		size_t nSoNgayMuon;
		bool bDaTra;
		virtual std::istream& stream_read(std::istream& is) { return is; }
		virtual std::ifstream& stream_read(std::ifstream& ifs) { return ifs; }
};

#endif