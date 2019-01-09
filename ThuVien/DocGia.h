#ifndef _CL_DOCGIA_H_
#define _CL_DOCGIA_H_
#include <string>
#include "IO.h"
class DocGia : public IO
{
public:
		typedef std::string str;
		//Constructors, Destructor
		DocGia() {}
		DocGia(const str& _ho, const str& _dem, const str& _ten) :
				sHo(_ho), sDem(_dem), sTen(_ten) {}
		DocGia(const str& _ho_ten);
		DocGia& operator=(const DocGia&);
		virtual ~DocGia() {}

		//Setters
		inline str& ho() { return sHo; }
		inline str& ten() { return sTen; }
		inline str& dem() { return sDem; }

		//Getters
		inline const str& ho() const { return sHo; }
		inline const str& ten() const { return sTen; }
		inline const str& dem() const { return sDem; }
		str ho_ten() const;

		virtual std::istream& stream_read(std::istream&);
		virtual std::ifstream& stream_read(std::ifstream&);
		virtual std::ostream& stream_write(std::ostream&) const;

private:
		str sHo, sDem, sTen;
};

#endif