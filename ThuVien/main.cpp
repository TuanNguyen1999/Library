#include "Sach.h"
#include "SachNgoai.h"
#include "DocGia.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
		SachViet h;
		SachNgoai k;
		DocGia dg("Nguyen    Tran Dang  Tuan");
		ifstream rf("Books.txt");
		rf >> h;
		cout << h;
		rf >> k;
		cout << endl << k << endl;
		return 0;
}