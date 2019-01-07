#include "ThoiGian.h"

std::string ThoiGian::thoi_gian(char sep) const
{
		using std::string;
		using std::to_string;
		return to_string(nNgay) + string(1, sep) +
				to_string(nThang) + string(1, sep) +
				to_string(nNam);
}

