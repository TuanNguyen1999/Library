#include "Sach.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
		SachViet h;
		h.ten() = "New";
		std::string a = h.ten();
		ifstream rf("Books.txt");
		rf >> h;
		cout << h;
		return 0;
}