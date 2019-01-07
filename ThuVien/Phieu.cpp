#include "Phieu.h"

Phieu::Phieu() :nSoNgayMuon(0), m_DocGia("null", "null", "null") {}
Phieu::Phieu(const DocGia& _dg,
		const std::list<SachViet>& _dssv,
		const std::list<SachNgoai>& _dssn,
		const ThoiGian& _tg,
		size_t _songay) : nSoNgayMuon(_songay), m_DocGia(_dg), lSachViet(_dssv), lSachNgoai(_dssn) {}

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