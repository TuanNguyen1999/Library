#include "Sach.h"
#include <iostream>
#include <fstream>
std::ostream& SachViet::write(std::ostream& os) const
{
		//sTen, sMaSach, sTacGia, sNXB, sGiaSach;
		using std::endl;
		os << "Ten sach: " << ten() << endl
				<< "Ma sach: " << ma_sach() << endl
				<< "Tac gia: " << tac_gia() << endl
				<< "Nha xuat ban: " << nxb() << endl
				<< "Gia sach: " << gia_sach() << endl;
		return os;
}
std::ifstream& SachViet::read(std::ifstream& ifs)
{
		using std::getline;

		getline(ifs, ten());
		getline(ifs, ma_sach());
		getline(ifs, tac_gia());
		getline(ifs, nxb());
		getline(ifs, gia_sach());

		return ifs;
}

std::istream& SachViet::read(std::istream& is)
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

		return is;
}