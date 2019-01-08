#ifndef _CL_THOIGIAN_H_
#define _CL_THOIGIAN_H_
#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <ctime>
class ThoiGian
{
public:
		//Constructors, Destructor
		ThoiGian();
		ThoiGian(int _ngay, int _thang, int _nam);
		ThoiGian(tm);
		~ThoiGian() {}

		//Setters
		ThoiGian& new_time(int _ngay, int _thang, int _nam);
		ThoiGian& new_time(tm);
		
		//Getters
		inline int ngay() const { return timeinfo.tm_mday; }
		inline int thang()const { return timeinfo.tm_mon + 1; }
		inline int nam() const { return timeinfo.tm_year + 1900; }

		std::string ctime() const;
		int distance_in_days(const ThoiGian&);

		//static members
		static int distance_in_days(const ThoiGian&, const ThoiGian&);

		//Non-member functions
		friend std::ostream& operator<<(std::ostream&, const ThoiGian&);

private:
		tm timeinfo;

		tm time_tm() const { return timeinfo; }
};

#endif