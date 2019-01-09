#include "DSSachViet.h"
#include "DSSachNgoai.h"
#include "DSDocGia.h"
using namespace std;

int main()
{
		//ThoiGian tg(30, 12, 2000);
		//ThoiGian tg1(-66, 12, 2000);
		//cout << "tg = " << tg.ctime() << endl;
		//cout << "tg1 = " <<tg1.ctime() << endl;
		//cout << "tg1 - tg = " << ThoiGian::distance_in_days(tg1, tg) << endl;
		//DocGia dg("Le Van");
		////cout << "Nhap ho ten:\n";
		////cin >> dg;
		//cout << dg;
		//DanhSach<Phieu> a;
		//a.nhap_danh_sach(cin);
		//a.xuat_danh_sach(cout);
		vector<string> v = {
				"a","b","c"
		};
		DSSV ds;
		ds.nhap_tu_file("SachViet.txt");
		ds.xuat();
		ds.xoa();
		ds.xuat();
		//DocGia dg("nguyen manh tuan");
		//cout << dg;
		return 0;
}
