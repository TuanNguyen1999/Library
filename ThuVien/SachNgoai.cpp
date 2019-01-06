#include "SachNgoai.h"
#include <iostream>
#include <fstream>

std::ostream& SachNgoai::write(std::ostream& os) const
{
		this->SachViet::write(os);
		os << "Ma ISBN: " << isbn() << std::endl;
		return os;
}
std::istream& SachNgoai::read(std::istream& is)
{
		using std::getline;
		this->SachViet::read(is);
		std::cout << "Ma ISBN: ";
		getline(is, isbn());
		return is;
}
std::ifstream& SachNgoai::read(std::ifstream& ifs)
{
		this->SachViet::read(ifs);
		std::getline(ifs, isbn());
		return ifs;
}