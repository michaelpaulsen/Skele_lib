#ifndef SK_CONSOLE_STRUCT
#define SK_CONSOLE_STRUCT
#include <stdarg.h>
#include <fstream>
#include <iostream>
#include <string>
#include <stdint.h>
#include "SK_Color.h"
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
			virtual int Print(const char* fmnt, int fgc, int bgc, ...) = 0;
		};
	}
}
#endif // !SK_CONSOLE_STRUCT
