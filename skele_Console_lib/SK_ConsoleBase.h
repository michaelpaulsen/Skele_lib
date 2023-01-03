#ifndef SK_CONSOLE_STRUCT
#define SK_CONSOLE_STRUCT
#include <stdarg.h>
#include <fstream>
#include <iostream>
#include <string>
#include <stdint.h>
#include "SK_Color.h"
#define stocs(t) t.c_str() 
/*this is a helper to make using string objects eiser*/
namespace Skele_lib {
	namespace Console {
		struct ConsoleBase {
			FILE* os;
			//FILE* is;
			Color   warn_color;
			Color     ok_color;
			Color inform_color;
			Color  error_color;
			virtual int Log(const char* fmnt, ...) = 0;
			virtual int Warn(const char* fmnt, ...) = 0;
			virtual int OK(const char* fmnt, ...) = 0;
			virtual int Error(const char* fmnt, ...) = 0;
			virtual int Print(int fgc, int bgc, const char* fmnt, ...) = 0;
			virtual int Log  (std::string fmnt, ...) = 0;
			virtual int Warn (std::string fmnt, ...) = 0;
			virtual int OK   (std::string fmnt, ...) = 0;
			virtual int Error(std::string fmnt, ...) = 0;
			virtual int Print(int fgc, int bgc, std::string fmnt, ...) = 0;
		};
	}
}
#endif // !SK_CONSOLE_STRUCT
