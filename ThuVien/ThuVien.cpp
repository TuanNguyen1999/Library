#include "ThuVien.h"
#include <chrono>
#include <thread>
ThuVien& ThuVien::operator=(const ThuVien& tv)
{
		if (this == &tv)
				return *this;
		dsSachNgoai = tv.dsSachNgoai;
		dsSachViet = tv.dsSachViet;
		dsDocGia = tv.dsDocGia;
		dsPhieu = tv.dsPhieu;
		return *this;
}

void ThuVien::run()
{
		static std::vector<std::string> vCmds = {
				"Danh sach cac doc gia", "Danh sach cac sach", "Danh sach cac phieu", "Thoat"
		};
		const int iExit = vCmds.size();
		int option;
		while (1)
		{
				Tools::clear();
				option = Tools::menu(vCmds)[0];
				if (1 == option)
						xu_ly_doc_gia();
				else if (2 == option)
						xu_ly_danh_sach();
				else if (3 == option)
						xu_ly_phieu();
				else
						exit(0);
		}
}

void ThuVien::xu_ly_doc_gia()
{
		static std::vector<std::string> vCmds = {
				"Xem danh sach doc gia", "Ghi vao file", "Them doc gia", "Xoa doc gia", "Sua doc gia",
				"Nhap danh sach moi tu ban phim", "Quay lai"
		};
		const int iExit = vCmds.size();
		int option;
		while (1)
		{
				Tools::clear();
				option = Tools::menu(vCmds)[0];
				if (1 == option)
				{
						dsDocGia.xuat();
						Tools::pause();
				}
				else if (2 == option)
				{
						std::cout << "Nhap duong dan (khong can duoi): ";
						std::string cache;
						std::getline(std::cin, cache);
						if (cache.find(".txt") == std::string::npos)
								cache += ".txt";
						dsDocGia.ghi_file(cache.c_str());
						std::cout << "Ghi xong. Quay ve trang truoc...";
						Tools::sleep_for_milliseconds(297);
				}
				else if (3 == option)
				{
						dsDocGia.them();
						std::cout << "Da them! Quay ve trang truoc...";
						Tools::sleep_for_milliseconds(297);
				}
				else if (4 == option)
				{
						dsDocGia.xoa();
						Tools::sleep_for_milliseconds(297);
				}
				else if (5 == option)
				{
						dsDocGia.sua();
						Tools::sleep_for_milliseconds(297);
				}
				else if (6 == option)
				{
						std::cout << "Ban chac chan muon tao moi danh sach?(y/n):";
						std::string sConfirm;
						std::getline(std::cin, sConfirm);
						if (sConfirm[0] == 'y' || sConfirm[0] == 'Y')
								dsDocGia.nhap_danh_sach();
						std::cout << "Quay ve trang truoc...";
						Tools::sleep_for_milliseconds(297);
				}
				else
						return;
		}
}

void ThuVien::xu_ly_danh_sach()
{
		static std::vector<std::string> vCmds = {
				"Xem danh sach sach viet", "Xem danh sach sach ngoai", "Xem tat ca sach",
				"Ghi danh sach sach viet vao file", "Ghi danh sach sach ngoai vao file",
				"Them sach", "Xoa sach", "Sua sach",
				"Nhap danh sach sach viet moi tu ban phim", "Nhap danh sach sach viet moi tu ban phim",
				"Quay lai"
		};
		const int iExit = vCmds.size();
		int option;
		while (1)
		{
				Tools::clear();
				option = Tools::menu(vCmds)[0];
				if (1 == option)
				{
						dsSachViet.xuat();
						Tools::pause();
				}
				else if (2 == option)
				{
						dsSachNgoai.xuat();
						Tools::pause();
				}
				else if (3 == option)
				{
						std::cout << "Danh sach sach viet:\n";
						dsSachViet.xuat();
						std::cout << "Danh sach sach ngoai:\n";
						dsSachNgoai.xuat();
						Tools::pause();
				}
				else if (4 == option || 5 == option)
				{
						std::cout << "Nhap duong dan (khong can duoi): ";
						std::string cache;
						std::getline(std::cin, cache);
						if (cache.find(".txt") == std::string::npos)
								cache += ".txt";
						if(4 == option)
								dsSachViet.ghi_file(cache.c_str());
						else
								dsSachNgoai.ghi_file(cache.c_str());
						std::cout << "Ghi xong. Quay ve trang truoc...";
						Tools::sleep_for_milliseconds(297);
				}
				else if (6 == option)
				{
						std::string sConfirm;
						std::cout << "Them sach viet?(y/n): ";
						std::getline(std::cin, sConfirm);
						if (sConfirm[0] == 'y' || sConfirm[0] == 'Y')
								dsSachViet.them();
						std::cout << "Them sach ngoai?(y/n): ";
						std::getline(std::cin, sConfirm);
						if (sConfirm[0] == 'y' || sConfirm[0] == 'Y')
								dsSachNgoai.them();
						std::cout << "Da them! Quay ve trang truoc...";
						Tools::sleep_for_milliseconds(297);
				}
				else if (7 == option)
				{
						std::string sConfirm;
						std::cout << "Xoa sach viet?(y/n): ";
						std::getline(std::cin, sConfirm);
						if (sConfirm[0] == 'y' || sConfirm[0] == 'Y')
								dsSachViet.xoa();
						std::cout << "Xoa sach ngoai?(y/n): ";
						std::getline(std::cin, sConfirm);
						if (sConfirm[0] == 'y' || sConfirm[0] == 'Y')
								dsSachNgoai.xoa();
						std::cout << "Quay ve trang truoc...";
						Tools::sleep_for_milliseconds(297);
				}
				else if (8 == option)
				{
						std::string sConfirm;
						std::cout << "Xoa sach viet?(y/n): ";
						std::getline(std::cin, sConfirm);
						if (sConfirm[0] == 'y' || sConfirm[0] == 'Y')
								dsSachViet.sua();
						std::cout << "Xoa sach ngoai?(y/n): ";
						std::getline(std::cin, sConfirm);
						if (sConfirm[0] == 'y' || sConfirm[0] == 'Y')
								dsSachNgoai.sua();
						std::cout << "Quay ve trang truoc...";
						Tools::sleep_for_milliseconds(297);
				}
				else if (9 == option || 10 == option)
				{
						std::string sConfirm;

						std::cout << "Ban co muon tao moi danh sach sach viet?(y/n):";
						std::getline(std::cin, sConfirm);
						if (sConfirm[0] == 'y' || sConfirm[0] == 'Y')
								dsSachViet.nhap_danh_sach();

						std::cout << "Ban co muon tao moi danh sach sach ngoai?(y/n):";
						std::getline(std::cin, sConfirm);
						if (sConfirm[0] == 'y' || sConfirm[0] == 'Y')
								dsSachNgoai.nhap_danh_sach();

						std::cout << "Quay ve trang truoc...";
						Tools::sleep_for_milliseconds(297);
				}
				else
						return;
		}
}

void ThuVien::xu_ly_phieu()
{
		static std::vector<std::string> vCmds = {
		"Xem danh sach phieu", "Ghi vao file",
		"Them phieu", "Xoa phieu",
		"Danh sach doc gia tra han", "Quay lai"
		};
		const int iExit = vCmds.size();
		int option;
		while (1)
		{
				Tools::clear();
				option = Tools::menu(vCmds)[0];
				if (1 == option)
				{
						dsPhieu.xuat();
						Tools::pause();
				}
				else if (2 == option)
				{
						std::cout << "Nhap duong dan (khong can duoi): ";
						std::string cache;
						std::getline(std::cin, cache);
						if (cache.find(".txt") == std::string::npos)
								cache += ".txt";
						dsPhieu.ghi_file(cache.c_str());
						std::cout << "Ghi xong. Quay ve trang truoc...";
						Tools::sleep_for_milliseconds(297);
				}
				else if (3 == option)
				{
						dsPhieu.them(dsDocGia, dsSachViet, dsSachNgoai);
						std::cout << "Da them! Quay ve trang truoc...";
						Tools::sleep_for_milliseconds(297);
				}
				else if (4 == option)
				{
						dsPhieu.xoa();
						Tools::sleep_for_milliseconds(297);
				}
				else if (5 == option)
				{
						dsPhieu.danh_sach_tre_han();
						Tools::pause();
				}
				else
						return;
		}
}
