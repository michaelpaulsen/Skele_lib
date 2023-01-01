#ifndef SK_CONSOLE_CLASS_WIN 
#define SK_CONSOLE_CLASS_WIN 
#include "./SK_ConsoleBase.h"
#include <stdarg.h>
#include <windows.h>

namespace Skele_lib {
	namespace Console {
		class Console : public ConsoleBase {
			HANDLE hConsole;
			int printformmated(int attr, const char* fmnt, va_list valist){
				short x;
				GetColor(x);
				SetConsoleTextAttribute(this->hConsole, attr);
				auto ret_val = vfprintf(os, fmnt, valist);
				SetConsoleTextAttribute(this->hConsole, x);
				return ret_val;
			}
		public:
			Console(FILE* _os = stdout) {
				os = _os;
				this->ok_color = Skele_lib::Console::Color(14, 02);
				this->inform_color = Skele_lib::Console::Color(11, 01);
				this->warn_color = Skele_lib::Console::Color(07, 06);
				this->error_color = Skele_lib::Console::Color(07, 04);
				hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			}
			int Log(const char* fmnt, ...)override {
				int c = (16 * inform_color.bgc) + error_color.fgc;
				va_list valist;
				va_start(valist, fmnt);
				auto retval = printformmated(c, fmnt, valist);
				va_end(valist);
				return retval;

			};

			int Warn(const char* fmnt, ...)override {
				int c = (16 * warn_color.bgc) + error_color.fgc;
				va_list valist;
				va_start(valist, fmnt);
				auto retval = printformmated(c, fmnt, valist);
				va_end(valist);
				return retval;
			};

			int OK(const char* fmnt, ...)override {
				int c = (16 * ok_color.bgc) + error_color.fgc;
				va_list valist;
				va_start(valist, fmnt);
				auto retval = printformmated(c, fmnt, valist);
				va_end(valist);
				return retval;
			};

			int Error(const char* fmnt, ...)override {
				int c = (16 * error_color.bgc) + error_color.fgc;
				va_list valist;
				va_start(valist, fmnt);
				auto retval = printformmated(c, fmnt, valist);
				va_end(valist);
				return retval;
			};

			int Print(const char* fmnt, int fgc, int bgc, ...)override {
				int c = (16 * bgc) + fgc;
				va_list valist;
				va_start(valist, fmnt);
				auto retval = printformmated(c, fmnt, valist);
				va_end(valist);
				return retval;
			};
			void Setattr(short attr, short& oldval) {
				GetColor(oldval);
				SetConsoleTextAttribute(this->hConsole, attr);
			};
			bool GetColor(short &ret) {
				CONSOLE_SCREEN_BUFFER_INFO info;
				if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info))return false;
				ret = info.wAttributes;
				return true;
			}
		};
			
	}
}
#endif // SK_CONSOLE_CLASS_WIN 