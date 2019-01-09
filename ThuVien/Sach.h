#ifndef CL_SACH_H_
#define CL_SACH_H_
#include <string>
#include "IO.h"
class SachViet : public IO
{
protected:
		typedef std::string str;
public:
		//Constructors, Destructor
		SachViet() {}
		SachViet(
				const str& _ten,
				const str& _ma_sach,
				const str& _tac_gia,
				const str& _nxb,
				const str& _gia_sach
		) : sTen(_ten), sMaSach(_ma_sach), sTacGia(_tac_gia), sNXB(_nxb), sGiaSach(_gia_sach) {}
		virtual ~SachViet(){}

		//Read, Write data
		virtual std::ostream& stream_write(std::ostream& os) const;
		virtual std::istream& stream_read(std::istream& is);
		virtual std::ifstream& stream_read(std::ifstream& ifs);

		//Setters
		inline str& ten() { return sTen; }
		inline str& ma_sach() { return sMaSach; }
		inline str& tac_gia() { return sTacGia; }
		inline str& nxb() { return sNXB; }
		inline str& gia_sach() { return sGiaSach; }

		//Getters
		inline const str& ten() const { return sTen; }
		inline const str& ma_sach() const { return sMaSach; }
		inline const str& tac_gia() const { return sTacGia; }
		inline const str& nxb() const { return sNXB; }
		inline const str& gia_sach() const { return sGiaSach; }


private:
		str sTen, sMaSach, sTacGia, sNXB, sGiaSach;
};
#endif