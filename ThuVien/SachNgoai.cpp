#include "SachNgoai.h"
#include <iostream>
#include <fstream>
#include "Tools.h"
std::ostream& SachNgoai::stream_write(std::ostream& os) const
{
		this->SachViet::stream_write(os);
		os << "\nMa ISBN: " << Tools::toupper(isbn()) << std::endl;
		return os;
}
std::istream& SachNgoai::stream_read(std::istream& is)
{
		using std::getline;
		this->SachViet::stream_read(is);
		std::cout << "Ma ISBN: ";
		getline(is, isbn());
		return is;
}
std::ifstream& SachNgoai::stream_read(std::ifstream& ifs)
{
		this->SachViet::stream_read(ifs);
		std::getline(ifs, isbn());
		return ifs;
}