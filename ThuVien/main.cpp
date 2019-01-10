#include "ThuVien.h"
using namespace std;

int main()
{
		//Initialize data
		//LƯU Ý: nhớ đỗi đường dẫn phù hơp
		const string wd = "E:\\Visual Studio\\ThuVien\\ThuVien\\Data\\";
		const string pSachViet = wd + "SachViet.txt";
		const string pSachNgoai= wd + "SachNgoai.txt";
		const string pDocGia = wd + "DocGia.txt";
		DSDG dsdg;
		dsdg.nhap_tu_file(pDocGia.c_str());
		DSSV dssv;
		dssv.nhap_tu_file(pSachViet.c_str());
		DSSN dssn;
		dssn.nhap_tu_file(pSachNgoai.c_str());

		std::vector<Phieu> vPhieu = {
				Phieu(
						dsdg.danh_sach()[0],
						std::list<SachViet>({dssv.danh_sach()[0],dssv.danh_sach()[1],dssv.danh_sach()[2]}),
						std::list<SachNgoai>(),
						ThoiGian(10,1,2019),
						15,
						false
						),
				Phieu(
						dsdg.danh_sach()[1],
						std::list<SachViet>({dssv.danh_sach()[1]}),
						std::list<SachNgoai>({dssn.danh_sach()[1]}),
						ThoiGian(1,7,2018),
						5,
						true
							),
				Phieu(
						dsdg.danh_sach()[2],
						std::list<SachViet>({dssv.danh_sach()[2]}),
						std::list<SachNgoai>({dssn.danh_sach()[1],dssn.danh_sach()[2]}),
						ThoiGian(28,12,2018),
						10,
						false
						),
				Phieu(
						dsdg.danh_sach()[4],
						std::list<SachViet>({dssv.danh_sach()[2], dssv.danh_sach()[3]}),
						std::list<SachNgoai>({dssn.danh_sach()[0],dssn.danh_sach()[3]}),
						ThoiGian(25,12,2018),
						6,
						true
						),
				Phieu(
						dsdg.danh_sach()[3],
						std::list<SachViet>(),
						std::list<SachNgoai>({dssn.danh_sach()[0]}),
						ThoiGian(1,1,2018),
						10,
						false
						)
		};

		DSP dsp(vPhieu);

		ThuVien a(dssn, dssv, dsdg, dsp);
		a.run();
		return 0;
}