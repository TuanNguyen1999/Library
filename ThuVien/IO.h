#ifndef _CL_IO_H_
#define _CL_IO_H_
#include <iostream>
#include <fstream>
typedef class InputOutput
{
		/*Abstract Base class for input and output*/
protected:
		virtual std::istream& stream_read(std::istream&) = 0;
		virtual std::ifstream& stream_read(std::ifstream&) = 0;
		virtual std::ostream& stream_write(std::ostream&) const = 0;
public:
		inline friend std::ostream& operator<<(std::ostream& os, const InputOutput& io) { return io.stream_write(os); }
		inline friend std::istream& operator>>(std::istream& is, InputOutput& io) { return io.stream_read(is); }
		inline friend std::ifstream& operator>>(std::ifstream& ifs, InputOutput& io) { return io.stream_read(ifs); }

} IO;

#endif