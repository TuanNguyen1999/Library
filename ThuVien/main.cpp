#define _CRT_SECURE_NO_WARNINGS
#include "Sach.h"
#include "SachNgoai.h"
#include "DocGia.h"
#include "ThoiGian.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;
int main()
{
		ThoiGian tg(30, 12, 2000);
		ThoiGian tg1(-66, 12, 2000);
		cout << "tg = " << tg.ctime() << endl;
		cout << "tg1 = " <<tg1.ctime() << endl;
		cout << "tg1 - tg = " << ThoiGian::distance_in_days(tg1, tg) << endl;
		DocGia dg("Le Van");
		//cout << "Nhap ho ten:\n";
		//cin >> dg;
		cout << dg;
		return 0;
}
