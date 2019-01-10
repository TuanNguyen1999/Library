#include "DSPhieu.h"
#include "Tools.h"
#include <iostream>
#include <sstream>
#include <list>
#include <algorithm>

void DSPhieu::ghi_file(const char* file) const
{
		std::ofstream wf(file);
		int i = 1;
		for (auto obj : m_list)
				wf << i++ << "\\\n" << obj << std::endl;
}
void DSPhieu::nhap_danh_sach(const DSDG& dsdg, const DSSV& dssv, const DSSN& dssn)
{
		m_list.clear();
		them(dsdg, dssv, dssn);
}

void DSPhieu::xuat() const
{
		int i = 0;
		if (m_list.empty())
		{
				std::cout << "Danh sach trong.\n";
				return;
		}
		for (auto obj : m_list)
		{
				std::cout << ++i << ").\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n" << obj << std::endl;
				std::cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";
		}
}
void DSPhieu::them(const DSDG& dsdg, const DSSV& dssv, const DSSN& dssn)
{

		//Preparing
		//Get a list of books' names and reader
		std::vector<std::string> vSach;
		std::vector<std::string> vDocGia;

		for (auto obj : dssv.danh_sach())
				vSach.push_back(obj.ten());
		for (auto obj : dssn.danh_sach())
				vSach.push_back(obj.ten());
		for (auto obj : dsdg.danh_sach())
				vDocGia.push_back(obj.ho_ten());

		int nSachViet = dssv.danh_sach().size();
		int nSachNgoai = dssn.danh_sach().size();

		int time[3];
		std::string cache;

		int nSoNgayMuon;
		bool bDaTra;

		while (1)
		{
				Tools::clear();
				//Choose books and reader
				std::cout << "Chon 1 doc gia tu danh sach:\n";
				int iDocGia = Tools::menu(vDocGia)[0] - 1;
				std::cout << "Chon cac sach tu danh sach:\n";
				std::vector<int> iSach = Tools::menu(vSach, true);
				//Push chosen books to lists
				std::list<SachViet> dsSachViet;
				std::list<SachNgoai> dsSachNgoai;
				for (int i : iSach)
				{
						//sv có 3 phần tử và sn có 6 phần tử
						//menu có dạng 1 2 3 4 5 6 7 8 9
						i--;
						//iSach chứa   0 1 2 3 4 5 6 7 8
						//phần tử nhỏ hơn kích thước sv thuộc về sách việt
						//còn lại là sách ngoại
						if (i - (int)dssv.danh_sach().size() < 0)
								dsSachViet.push_back(dssv.danh_sach()[i]);
						else
								dsSachNgoai.push_back(dssn.danh_sach()[i - (int)dssv.danh_sach().size()]);
				}


				//Date
				while (true)
				{
						std::cout << "Ngay muon (dd/mm/yyyy): ";
						std::getline(std::cin, cache);
						std::stringstream ss(cache);
						ss >> time[0]; ss.get();
						ss >> time[1]; ss.get();
						ss >> time[2]; ss.get();
						if (ss.good() || (!ss.good() && ss.eof()))
								break;
				}
				ThoiGian tg(time[0], time[1], time[2]);

				//Borrowing time
				while (true)
				{
						std::cout << "So ngay muon: ";
						std::getline(std::cin, cache);
						std::stringstream ss(cache);
						ss >> nSoNgayMuon;
						if (ss)
						{
								nSoNgayMuon = (nSoNgayMuon >= 0) ? nSoNgayMuon : -nSoNgayMuon;
								break;
						}

				}

				std::cout << "Da tra?(y/n):";
				std::getline(std::cin, cache);
				bDaTra = (cache[0] == 'Y' || cache[0] == 'y') ? true : false;

				m_list.push_back(Phieu(dsdg.danh_sach()[iDocGia], dsSachViet, dsSachNgoai, tg, nSoNgayMuon, bDaTra));

				std::cout << "Nhap thanh cong!\n";
				std::cout << "Tiep tuc?(y/n):";
				std::getline(std::cin, cache);
				if (cache[0] != 'y' && cache[0] != 'Y')
						return;
		}


		
}


void DSPhieu::xoa()
{

		int flagAbort = -1;

		//Print out list
		xuat();

		//Assumpt that tim_kiem() return all elements' indexes in m_list
		std::vector<int> vIndexes(m_list.size());
		for (size_t i = 0; i < vIndexes.size(); i++)
				vIndexes[i] = i;

		//Ask user to choose what to delete
		std::vector<int> vCmds(vIndexes.size() + 1, 0);
		for (size_t i = 0; i < vCmds.size(); i++)
				vCmds[i] = i + 1;
		vCmds[vCmds.size() - 1] = flagAbort;
		std::cout << "Chon cac vi tri can xoa (chon vi tri co gia tri " << flagAbort << " neu khong muon xoa):\n";
		std::vector<int> vChoices = Tools::menu(vCmds, true);

		//Abort if flagAbort is chosen
		for (auto choice : vChoices)
		{
				if (vCmds[choice - 1] == flagAbort)
						return;
		}

		//Preparing to delete
		std::vector<int> vPosToDelete;
		for (auto choice : vChoices)
				vPosToDelete.push_back(vIndexes[choice - 1]);		//User choose 2, vIndexes[2 - 1] = 4

		//Sort vPosToDelete then start deleting elements from biggest to smallest
		std::sort(vPosToDelete.begin(), vPosToDelete.end());
		for (int i = vPosToDelete.size() - 1; i >= 0; i--)
		{
				m_list.erase(m_list.begin() + vPosToDelete[i]);
		}
		std::cout << "Xoa thanh cong!!\n";
}
void DSPhieu::danh_sach_tre_han() const
{
		int i = 0;
		for (const Phieu& phieu : m_list)
		{
				int nTien = phieu.phi_tre_han();
				if (nTien)
				{
						std::cout << ++i << "\\\n" << "Doc gia: " << phieu.doc_gia() << std::endl
								<< "Ngay muon: " << phieu.ngay_bat_dau() << std::endl
								<< "So ngay da muon: " << phieu.so_ngay_da_muon() << std::endl
								<< (phieu.da_tra_sach() ? "Da" : "Chua") << "tra sach" << std::endl
								<< "Phi tre han: " << nTien << std::endl;
				}
		}
}
