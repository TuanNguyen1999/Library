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
		str cache;

		getline(ifs, cache);
		ten() = cache;

		getline(ifs, cache);
		ma_sach() = cache;

		getline(ifs, cache);
		tac_gia() = cache;

		getline(ifs, cache);
		nxb() = cache;

		getline(ifs, cache);
		gia_sach() = cache;
		return ifs;
}

std::istream& SachViet::read(std::istream& is)
{
		using std::getline;
		using std::cout;
		str cache;

		cout << "Ten sach: ";
		getline(is, cache);
		ten() = cache;

		cout << "Ma sach: ";
		getline(is, cache);
		ma_sach() = cache;

		cout << "Tac gia: ";
		getline(is, cache);
		tac_gia() = cache;

		cout << "Nha xuat ban: ";
		getline(is, cache);
		nxb() = cache;

		cout << "Gia sach: ";
		getline(is, cache);
		gia_sach() = cache;
		return is;
}