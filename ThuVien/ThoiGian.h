#ifndef _CL_THOIGIAN_H_
#define _CK_THOIGIAN_H_

#include <string>

class ThoiGian
{
		/*Class thời gian đơn giản*/
public:
		//Constructors, Destructor
		ThoiGian() : nNgay(1u), nThang(1u), nNam(1900u) {}
		ThoiGian(size_t _ngay, size_t _thang, size_t _nam) :
				nNgay(_ngay), nThang(_thang), nNam(_nam) {}
		~ThoiGian() {}

		//Setters
		inline size_t& ngay() { return nNgay; }
		inline size_t& thang() { return nThang; }
		inline size_t& nam() { return nNam; }
		
		//Getters
		inline const size_t& ngay() const { return nNgay; }
		inline const size_t& thang()const { return nThang; }
		inline const size_t& nam() const { return nNam; }

		std::string thoi_gian(char sep) const;

		//static members
		int distance_in_days(const ThoiGian&, const ThoiGian&);
		
private:
		size_t nNgay, nThang, nNam;
};

#endif