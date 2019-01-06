#ifndef CL_SACHNGOAI_H_
#define CL_SACHNGOAI_H_

#include "Sach.h"

class SachNgoai : public SachViet
{
public:
		SachNgoai() : SachViet() {}
		SachNgoai(
				const str& _ten,
				const str& _ma_sach,
				const str& _tac_gia,
				const str& _nxb,
				const str& _gia_sach,
				const str& _isbn
		) : SachViet(_ten, _ma_sach, _tac_gia, _nxb, _gia_sach), sISBN(_isbn) {}
		virtual ~SachNgoai() {}

		//Setters
		inline str& isbn() { return sISBN; }

		//Getters
		inline const str& isbn() const { return sISBN; }

		//Read, Write data
		virtual std::ostream& write(std::ostream& os) const;
		virtual std::istream& read(std::istream& is);
		virtual std::ifstream& read(std::ifstream& ifs);

private:
		str sISBN;
};
#endif
