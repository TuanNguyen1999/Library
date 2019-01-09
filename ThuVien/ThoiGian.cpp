#include "ThoiGian.h"

ThoiGian::ThoiGian() : timeinfo()
{
		timeinfo.tm_mday = 1;
		timeinfo.tm_mon = 0;
		timeinfo.tm_year = 0;
}
ThoiGian::ThoiGian(tm time)
{
		time_t tt = mktime(&time);
		timeinfo = time;
}

ThoiGian::ThoiGian(int _ngay, int _thang, int _nam) : timeinfo()
{
		//relative time, eg: 61/13/2000
		tm usertime = tm();
		usertime.tm_mday = _ngay;
		usertime.tm_mon = _thang - 1;
		usertime.tm_year = _nam - 1900;

		//To get precise time, eg:  2/3/2001
		//convert usertime to time_t tt, this will make usertime's values be modified
		//then assign usertime to timeinfo
		time_t tt = mktime(&usertime);
		timeinfo = usertime;

}

ThoiGian& ThoiGian::new_time(int _ngay, int _thang, int _nam)
{
		ThoiGian temp(_ngay, _thang, _nam);
		timeinfo = temp.time_tm();
		return *this;
}
ThoiGian& ThoiGian::new_time(tm time)
{
		time_t tt = mktime(&time);
		timeinfo = time;
		return *this;
}


std::string ThoiGian::ctime() const
{
		static char buffer[50];
		strftime(buffer, 50, "%a %d/%m/%Y", &timeinfo);
		return std::string(buffer,50);
}
int ThoiGian::distance_in_days(const ThoiGian& high, const ThoiGian& low)
{
		double ratio = 60.0 * 60.0 * 24.0;	//seconds of a day

		time_t end = mktime(&high.time_tm());
		time_t begin = mktime(&low.time_tm());

		double seconds = difftime(end, begin);
		return seconds / ratio;
}
int ThoiGian::distance_in_days(const ThoiGian& b)
{
		return ThoiGian::distance_in_days(*this, b);
}

std::ostream& operator<<(std::ostream& os, const ThoiGian& tg)
{
		os << tg.ctime();
		return os;
}