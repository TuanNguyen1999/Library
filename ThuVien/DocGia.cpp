#include "DocGia.h"
DocGia::DocGia(const str& _ho_ten)
{
		char sep[256] = " ";

		size_t nHoLast = _ho_ten.find_first_of(sep);
		size_t nTenFirst = _ho_ten.find_last_of(sep);
		
		if (nHoLast != nTenFirst)
		{
				//Full name
				sHo = _ho_ten.substr(0u, nHoLast);
				sTen = _ho_ten.substr(nTenFirst + 1, _ho_ten.length() - nTenFirst);
				sDem = _ho_ten.substr(nHoLast + 1, nTenFirst);
		}
		else if (nHoLast != std::string::npos)
		{
				//First name and Last name
				sHo = _ho_ten.substr(0u, nHoLast);
				sTen = _ho_ten.substr(nTenFirst + 1, _ho_ten.length() - nTenFirst);
		}
		else
				//name only
				sTen = _ho_ten;
}

std::string DocGia::ho_ten() const
{
		if (sHo.empty())
		{
				if (sDem.empty())
						return sTen;
				else
						return sDem + std::string(" ") + sTen;
		}
		else
				return  sHo + std::string(" ") + sDem + std::string(" ") + sTen;
}
