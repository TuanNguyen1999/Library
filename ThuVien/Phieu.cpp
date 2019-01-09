#include "Phieu.h"
#include <iostream>

Phieu::Phieu() :nSoNgayMuon(0), bDaTra(false), m_DocGia("null", "null", "null") {}
Phieu::Phieu(const DocGia& _dg,
		const std::list<SachViet>& _dssv,
		const std::list<SachNgoai>& _dssn,
		const ThoiGian& _tg,
		size_t _songay,
		bool _datra
) : nSoNgayMuon(_songay), bDaTra(_datra), m_DocGia(_dg), dsSachViet(_dssv), dsSachNgoai(_dssn),m_NgayMuon(_tg) {}

Phieu& Phieu::operator=(const Phieu& p)
{
		if (this == &p)
				return *this;
		m_DocGia = p.m_DocGia;
		dsSachNgoai = p.dsSachNgoai;
		dsSachViet = p.dsSachViet;
		m_NgayMuon = p.m_NgayMuon;
		nSoNgayMuon = p.nSoNgayMuon;
		bDaTra = p.bDaTra;
		return *this;
}

size_t Phieu::phi_tre_han() const
{
		if (nSoNgayMuon <= SoNgayMuonToiDa)
				return 0;
		size_t n = nSoNgayMuon - SoNgayMuonToiDa;
		return n * (dsSachNgoai.size() * PhiSachNgoai + dsSachViet.size() * PhiSachViet);
}
size_t Phieu::phi_tre_han(const Phieu& p)
{
		return p.phi_tre_han();
}
ThoiGian Phieu::ngay_het_han() const
{
		ThoiGian expire = m_NgayMuon;
		expire.new_time(expire.ngay() + 7, expire.thang(), expire.nam());
		return expire;
}

std::ostream& Phieu::stream_write(std::ostream& os) const
{
		os << "Doc gia: " << doc_gia() << std::endl
				<< "Ngay muon: " << ngay_bat_dau() << std::endl
				<< "Ngay het han: " << ngay_het_han() << std::endl
				<< "So ngay da muon: " << so_ngay_da_muon() << std::endl
				<< (da_tra_sach() ? "Da" : "Chua") << " tra" << std::endl;

		if (phi_tre_han())
				os << "Phi tre han: " << phi_tre_han() << std::endl;

		os << "Danh sach sach viet:";
		if (!sach_viet().empty())
		{
				int i = 0;
				for (const SachViet& sv : sach_viet())
						os << std::endl << ++i << "\\\n" << sv << std::endl;
		}
		else
				os << " Trong\n";

		os << "Danh sach sach ngoai:";
		if (!sach_ngoai().empty())
		{
				int i = 0;
				for (const SachNgoai& sv : sach_ngoai())
						os << std::endl << ++i << "\\\n" << sv << std::endl;
		}
		else
				os << " Trong\n";

		return os;
}
