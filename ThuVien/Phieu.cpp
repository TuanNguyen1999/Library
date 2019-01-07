#include "Phieu.h"

Phieu::Phieu() :nSoNgayMuon(0), bDaTra(false), m_DocGia("null", "null", "null") {}
Phieu::Phieu(const DocGia& _dg,
		const std::list<SachViet>& _dssv,
		const std::list<SachNgoai>& _dssn,
		const ThoiGian& _tg,
		size_t _songay,
		bool _datra
) : nSoNgayMuon(_songay), bDaTra(_datra), m_DocGia(_dg), lSachViet(_dssv), lSachNgoai(_dssn) {}

Phieu& Phieu::operator=(const Phieu& p)
{
		if (this == &p)
				return *this;
		m_DocGia = p.m_DocGia;
		lSachNgoai = p.lSachNgoai;
		lSachViet = p.lSachViet;
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
		return n * (lSachNgoai.size() * PhiSachNgoai + lSachViet.size() * PhiSachViet);
}
size_t Phieu::phi_tre_han(const Phieu& p)
{
		return p.phi_tre_han();
}

std::ostream& operator<<(std::ostream& os, const Phieu& p)
{
		os << p.doc_gia() << std::endl
				<< "Ngay muon: " << p.ngay_bat_dau() << std::endl
				<< "Ngay het han: " << p.ngay_het_han() << std::endl
				<< "So ngay da muon: " << p.so_ngay_da_muon() << std::endl
				<< "Da tra: " << (p.da_tra_sach() ? "Da tra" : "Chua tra") << std::endl;

		if (p.phi_tre_han())
				os << "Phi tre han: " << p.phi_tre_han() << std::endl;
		os << "Danh sach sach viet:\n";

		for (auto sv : p.sach_ngoai())
				os << "- " << sv << ", ";
		os << "\b\b\n";		//delete ", " at the end 
		os << "Danh sach sach ngoai:\n";
		for (auto sv : p.sach_ngoai())
				os << "- " << sv << ", ";
		os << "\b\b\n";

		return os;
}
ThoiGian Phieu::ngay_het_han() const
{
		ThoiGian expire = m_NgayMuon;
		expire.new_time(expire.ngay() + 7, expire.thang(), expire.nam());
		return expire;
}

