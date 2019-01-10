#ifndef _CL_THUVIEN_H_
#define _CL_THUVIEN_H_
#include "DSDocGia.h"
#include "DSSachNgoai.h"
#include "DSSachViet.h"
#include "DSPhieu.h"
#include "Tools.h"
class ThuVien
{
public:
		//Constructors, Destructor
		ThuVien() {}
		ThuVien(
				const DSSN& dssn,
				const DSSV& dssv,
				const DSDG& dsdg,
				const DSP& dsp) : dsSachNgoai(dssn), dsSachViet(dssv), dsDocGia(dsdg), dsPhieu(dsp) {}
		ThuVien(const ThuVien& tv) :
				dsSachNgoai(tv.dsSachNgoai),
				dsSachViet(tv.dsSachViet),
				dsDocGia(tv.dsDocGia),
				dsPhieu(tv.dsPhieu) {}
		ThuVien& operator=(const ThuVien& tv);
		~ThuVien() {}

		//Getters
		inline const DSSN& ds_sach_ngoai() { return dsSachNgoai; }
		inline const DSSV& ds_sach_viet() { return dsSachViet; }
		inline const DSDG& ds_doc_gia() { return dsDocGia; }
		inline const DSP& ds_phieu() { return dsPhieu; }

		void run();


private:
		DSSN dsSachNgoai;
		DSSV dsSachViet;
		DSDG dsDocGia;
		DSP dsPhieu;

		void xu_ly_doc_gia();
		void xu_ly_danh_sach();
		void xu_ly_phieu();


};

#endif