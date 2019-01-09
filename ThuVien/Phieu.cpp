#include "Phieu.h"
#include <iostream>

Phieu::Phieu() :nSoNgayMuon(0), bDaTra(false), m_DocGia("null", "null", "null") {}
Phieu::Phieu(const DocGia& _dg,
		const std::list<SachViet>& _dssv,
		const std::list<SachNgoai>& _dssn,
		const ThoiGian& _tg,
		size_t _songay,
		bool _datra
) : nSoNgayMuon(_songay), bDaTra(_datra), m_DocGia(_dg), ds_SachViet(_dssv), ds_SachNgoai(_dssn) {}

Phieu& Phieu::operator=(const Phieu& p)
{
		if (this == &p)
				return *this;
		m_DocGia = p.m_DocGia;
		ds_SachNgoai = p.ds_SachNgoai;
		ds_SachViet = p.ds_SachViet;
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
		return n * (ds_SachNgoai.size() * PhiSachNgoai + ds_SachViet.size() * PhiSachViet);
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
		os << doc_gia() << std::endl
				<< "Ngay muon: " << ngay_bat_dau() << std::endl
				<< "Ngay het han: " << ngay_het_han() << std::endl
				<< "So ngay da muon: " << so_ngay_da_muon() << std::endl
				<< "Da tra: " << (da_tra_sach() ? "Da tra" : "Chua tra") << std::endl;

		if (phi_tre_han())
				os << "Phi tre han: " << phi_tre_han() << std::endl;

		os << "Danh sach sach viet:";
		if (!sach_viet().empty())
		{
				for (auto sv : sach_viet())
						os << "\n- " << sv << ", ";
				os << "\b\b\n";		//delete ", " at the end 
		}
		else
				os << " Empty\n";

		os << "Danh sach sach ngoai:";
		if (!sach_ngoai().empty())
		{
				for (auto sv : sach_ngoai())
						os << "\n- " << sv << ", ";
				os << "\b\b\n";
		}
		else
				os << " Empty\n";

		return os;
}



//std::istream& operator>>(std::istream& is, Phieu& p)
//{
//		using std::cout;
//		static int time[3];
//		cout << "Ho ten doc gia (vd Nguyen Van A): ";
//		is >> p.m_DocGia;
//		cout << "Ngay muon sach (dd-mm-yyyy): ";
//		is >> time[0] >> time[1] >> time[2];
//		cout << "Nhap danh sach sach viet:\n";
//		p.ds_SachViet.nhap_danh_sach(is);
//		cout << "Nhap danh sach sach ngoai:\n";
//		p.ds_SachNgoai.nhap_danh_sach(is);
//		return is;
//}
