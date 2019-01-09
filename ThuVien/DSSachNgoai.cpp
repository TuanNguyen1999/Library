#include "DSSachNgoai.h"

#include "Tools.h"
#include <fstream>
#include <algorithm>

void DSSachNgoai::ghi_file(const char* file) const
{
		std::ofstream wf(file);
		int i = 1;
		for (auto obj : m_list)
				wf << i++ << "\\\n" << obj << std::endl;
}

void DSSachNgoai::xuat() const
{
		int i = 1;
		for (auto obj : m_list)
				std::cout << i++ << "\\\n" << obj << std::endl;
}
void DSSachNgoai::nhap_danh_sach()
{
		std::string cache;
		SachNgoai temp;
		m_list.clear();
		while (true)
		{
				them();
				std::cout << "Tiep tuc?(y/n):";
				std::getline(std::cin, cache);
				if (cache[0] == 'n' || cache[0] == 'N')
						return;
		}
}
void DSSachNgoai::nhap_tu_file(const char* file)
{
		std::ifstream rf(file);
		std::string cache;
		SachNgoai temp;
		while (rf.good())
		{
				std::getline(rf, cache);
				rf >> temp;
				m_list.push_back(temp);
		}
		if (!rf.eof())
				std::cout << "Da co loi xay ra khi nhap tu file\n";
}
void DSSachNgoai::them()
{
		SachNgoai temp;
		std::cin >> temp;
		m_list.push_back(temp);
}
std::vector<int> DSSachNgoai::tim_kiem() const
{
		std::string noiDung;
		std::vector<std::string> vTags = { "Ten sach", "Ma sach", "Tac gia", "NXB", "Gia sach","ISBN", "All" };
		std::vector<bool> bTags = { 0,0,0,0,0,0 };
		std::cout << "Chon cac gia tri ung voi tag ban muon tim kiem, vd: 1 2 3\n";
		std::vector<int> vChosenTags = Tools::menu(vTags, true);
		//Check if tag All is chosen
		for (auto i : vChosenTags)
		{
				if (i == vTags.size())
				{
						//set all bTags's elements to true
						for (int k = 0; k < bTags.size(); k++)
								bTags[k] = true;
						break;
				}
				else
						bTags[i - 1] = true;
		}
		std::cout << "Nhap noi dung tim kiem: ";
		std::getline(std::cin, noiDung);
		noiDung = Tools::tolower(noiDung);

		std::vector<int> vIndex;		//vIndex is sorted
		int i = 0;
		for (auto sach : m_list)
		{
				//Check if noiDung is a substring in atleast one member of element sach
				if (
						Tools::tolower(sach.ten()).find(noiDung) != std::string::npos && bTags[0] ||
						Tools::tolower(sach.ma_sach()).find(noiDung) != std::string::npos && bTags[1] ||
						Tools::tolower(sach.tac_gia()).find(noiDung) != std::string::npos && bTags[2] ||
						Tools::tolower(sach.nxb()).find(noiDung) != std::string::npos && bTags[3] ||
						Tools::tolower(sach.gia_sach()).find(noiDung) != std::string::npos && bTags[4] ||
						Tools::tolower(sach.isbn()).find(noiDung) != std::string::npos && bTags[5]
						)
				{
						//push sach's index in m_list
						vIndex.push_back(i);
				}
				i++;
		}
		//print out result
		if (!vIndex.empty())
		{
				std::cout << "=> Tim thay " << vIndex.size() << " ket qua\n";
				for (size_t pos = 0; pos < vIndex.size(); pos++)
						std::cout << pos + 1 << "\\.\n" << m_list[vIndex[pos]] << std::endl;
		}
		else
				std::cout << "=> Khong tim thay\n";
		return vIndex;
}
void DSSachNgoai::sua()
{
		int flagAbort = -1;

		//Ask user to choose what to delete
		std::vector<int> vIndexes = tim_kiem();							//3 4 8
		if (vIndexes.empty())
				return;
		std::vector<int> vCmds(vIndexes.size() + 1, 0);			//1 2 3 -1
		for (size_t i = 0; i < vCmds.size(); i++)
				vCmds[i] = i + 1;
		vCmds[vCmds.size() - 1] = flagAbort;
		std::cout << "Chon cac vi tri can xoa (chon vi tri co gia tri " << flagAbort << " neu khong muon xoa):\n";
		int choice = Tools::menu(vCmds)[0];									//Choice by user

		//Abort if flagAbort is chosen
		if (vCmds[choice - 1] == flagAbort)
				return;

		//Ask for new data
		int iPos = vIndexes[choice - 1];			//User choose 2, vIndexes[2 - 1] = 4

		SachNgoai temp;
		std::cout << "Nhap gia tri cho cac muc ben duoi (de trong neu khong muon thay doi):\n";
		std::cin >> temp;

		if (!temp.gia_sach().empty())		m_list[iPos].gia_sach() = temp.gia_sach();
		if (!temp.ma_sach().empty())		m_list[iPos].ma_sach() = temp.ma_sach();
		if (!temp.ten().empty())		m_list[iPos].ten() = temp.ten();
		if (!temp.nxb().empty())		m_list[iPos].nxb() = temp.nxb();
		if (!temp.tac_gia().empty())		m_list[iPos].tac_gia() = temp.tac_gia();
		if (!temp.isbn().empty())		m_list[iPos].isbn() = temp.isbn();
		std::cout << "Sua thanh cong!!\n";
}
void DSSachNgoai::xoa()
{
		int flagAbort = -1;

		//Ask user to choose what to delete
		std::vector<int> vIndexes = tim_kiem();							//3 4 8
		if (vIndexes.empty())
				return;
		std::vector<int> vCmds(vIndexes.size() + 1, 0);			//1 2 3 -1
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

