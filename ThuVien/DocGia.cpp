#include "DocGia.h"
#include "Tools.h"
#include <iostream>
#include <fstream>
DocGia::DocGia(const str& _ho_ten)
{
		char sep[256] = " -,._";

		size_t nHoPos = _ho_ten.find_first_of(sep);
		size_t nTenPos = _ho_ten.find_last_of(sep);
		
		if (nHoPos != nTenPos)
		{
				//Full name
				sHo = _ho_ten.substr(0u, nHoPos);
				sTen = _ho_ten.substr(nTenPos + 1u, _ho_ten.length() - nTenPos);
				sDem = _ho_ten.substr(nHoPos + 1u, nTenPos - nHoPos - 1);
		}
		else if (nHoPos != std::string::npos)
		{
				//First name and Last name
				sHo = _ho_ten.substr(0u, nHoPos);
				sTen = _ho_ten.substr(nTenPos + 1u, _ho_ten.length() - nTenPos);
		}
		else
				//name only
				sTen = _ho_ten;
}

std::string DocGia::ho_ten() const
{
		std::string s1, s2, s3;
		if (!sHo.empty())
				s1 = sHo + " ";
		if (!sDem.empty())
				s2 = sDem + " ";
		if (!sTen.empty())
				s3 = sTen + " ";
		return s1 + s2 + s3;
	
}
std::istream& DocGia::stream_read(std::istream& is)
{
		std::string cache;
		std::cout << "Nhap ho ten (vd: Nguyen Manh Tuan): ";
		std::getline(is, cache);
		*this = DocGia(cache);
		return is;
}
std::ifstream& DocGia::stream_read(std::ifstream& ifs)
{
		std::string cache;
		std::getline(ifs, cache);
		*this = DocGia(cache);
		return ifs;
}
std::ostream& DocGia::stream_write(std::ostream& os) const
{
		os << Tools::title(ho_ten());
		return os;
}

