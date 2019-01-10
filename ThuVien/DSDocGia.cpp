#include "DSDocGia.h"

#include "Tools.h"
#include <fstream>
#include <algorithm>

void DSDocGia::ghi_file(const char* file) const
{
		std::ofstream wf(file);
		int i = 1;
		for (auto obj : m_list)
				wf << i++ << "\\\n" << obj << std::endl;
}

void DSDocGia::xuat() const
{
		if (m_list.empty())
		{
				std::cout << "Danh sach trong.\n";
				return;
		}
		int i = 1;
		for (auto obj : m_list)
				std::cout << i++ << "\\. " << obj << std::endl;
}
void DSDocGia::nhap_danh_sach()
{
		m_list.clear();
		them();
}
void DSDocGia::nhap_tu_file(const char* file)
{
		std::ifstream rf(file);
		std::string cache;
		DocGia temp;
		while (rf.good())
		{
				rf >> temp;
				m_list.push_back(temp);
		}
		if (!rf.eof())
				std::cout << "Da co loi xay ra khi nhap tu file\n";
}
void DSDocGia::them()
{
		DocGia temp;
		std::cout << "/*Bo trong neu muon ngung nhap*/\n";
		while (1)
		{
				std::cin >> temp;
				//Check if user input nothing
				if (temp.ten().empty())
						return;
				m_list.push_back(temp);
		}
}
std::vector<int> DSDocGia::tim_kiem() const
{
		std::string noiDung;
		std::vector<std::string> vTags = { "Ho","Dem","Ten","All" };
		std::vector<bool> bTags = { 0,0,0,0,0 };
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
		for (auto docgia : m_list)
		{
				//Check if noiDung is a substring in at least one member of element in list
				if (Tools::tolower(docgia.ho_ten()).find(noiDung) != std::string::npos && bTags[0])
						//push sach's index in m_list
						vIndex.push_back(i);
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
void DSDocGia::sua()
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

		DocGia temp;
		std::cout << "Nhap gia tri cho cac muc ben duoi (de trong neu khong muon thay doi):\n";
		std::cin >> temp;

		if (!temp.ho_ten().empty())		m_list[iPos] = temp;
		std::cout << "Sua thanh cong!!\n";
}
void DSDocGia::xoa()
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

