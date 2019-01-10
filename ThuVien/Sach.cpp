#include "Sach.h"
#include "Tools.h"
#include <iostream>
#include <fstream>
std::ostream& SachViet::stream_write(std::ostream& os) const
{
		//sTen, sMaSach, sTacGia, sNXB, sGiaSach;
		using std::endl;
		os << "Ten sach: " << Tools::title(ten()) << endl
				<< "Ma sach: " << Tools::toupper(ma_sach()) << endl
				<< "Tac gia: " << Tools::title(tac_gia()) << endl
				<< "Nha xuat ban: " << Tools::title(nxb()) << endl
				<< "Gia sach: " << Tools::title(gia_sach());
		return os;
}
std::ifstream& SachViet::stream_read(std::ifstream& ifs)
{
		using std::getline;

		getline(ifs, ten());
		getline(ifs, ma_sach());
		getline(ifs, tac_gia());
		getline(ifs, nxb());
		getline(ifs, gia_sach());

		if (
				ten().empty() || ma_sach().empty() || tac_gia().empty() ||
				nxb().empty() || gia_sach().empty()
				)
				*this = SachViet();

		return ifs;
}

std::istream& SachViet::stream_read(std::istream& is)
{
		using std::getline;
		using std::cout;

		cout << "Ten sach: ";
		getline(is, ten());

		cout << "Ma sach: ";
		getline(is, ma_sach());

		cout << "Tac gia: ";
		getline(is, tac_gia());

		cout << "Nha xuat ban: ";
		getline(is, nxb());

		cout << "Gia sach: ";
		getline(is, gia_sach());

		if (
				ten().empty() || ma_sach().empty() || tac_gia().empty() ||
				nxb().empty() || gia_sach().empty()
				)
				*this = SachViet();

		return is;
}