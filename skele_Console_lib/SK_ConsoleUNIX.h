#ifndef SK_CONSOLE_CLASS_UNIX
#define SK_CONSOLE_CLASS_UNIX
#include "./SK_ConsoleBase.h"
#include "./SK_Color_UNIX.h"
#include <stdarg.h>
namespace Skele_lib {
	namespace Console {
		//SEE: https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797 for more details

		class Console : public ConsoleBase {
			const char color_code_start[5] = "\033[0;";
			const char reset_code[5] = "\033[0m";
			typedef char PRINTEX_FLAGS;
			
		public:
			const static PRINTEX_FLAGS PRINTEX_BLINK           = 0b00000001;
			const static PRINTEX_FLAGS PRINTEX_STRIKETHOUGH    = 0b00000010;
			const static PRINTEX_FLAGS PRINTEX_OVERLINE        = 0b00000100;
			const static PRINTEX_FLAGS PRINTEX_THICK_OVERLINE  = 0b00001000;
			const static PRINTEX_FLAGS PRINTEX_UNDERLINE       = 0b00010000;
			const static PRINTEX_FLAGS PRINTEX_THICK_UNDERLINE = 0b00100000;
			const static PRINTEX_FLAGS PRINTEX_BRIGHT          = 0b01000000;
			const static PRINTEX_FLAGS PRINTEX_DARK            = 0b10000000;

			Console(FILE* _os = stdout) {
				os = _os;
				this->warn_color =  Color((int)FG_colors::YELLOW,(int)BG_colors::BLACK);
				this->ok_color =    Color((int)FG_colors::GREEN, (int)BG_colors::BLACK);
				this->inform_color =  Color((int)FG_colors::BLUE,  (int)BG_colors::BLACK);
				this->error_color = Color((int)FG_colors::RED,   (int)BG_colors::BLACK);
			}
			int Log(const char* fmnt, ...)  override{
				va_list args; 
				va_start(args, fmnt);
				int ret_val = fprintf( os, "%s%dm", color_code_start, inform_color.fgc);
				ret_val += vfprintf(os, fmnt, args);
				ret_val += fprintf(os, reset_code);
				va_end(args); 
				return ret_val; 
			}
			int Warn(const char* fmnt, ...) override{
				va_list args;
				va_start(args, fmnt);
				int ret_val = fprintf(os, "%s%dm", color_code_start, warn_color.fgc);
				ret_val +=vfprintf(os, fmnt, args);
				va_end(args);
				return ret_val; 
			}
			int OK(const char* fmnt, ...)   override{
				va_list args;
				va_start(args, fmnt);
				int ret_val = fprintf(os, "%s%dm", color_code_start, ok_color.fgc);
				ret_val +=vfprintf(os, fmnt, args);
				va_end(args);
				return ret_val; 
			}
			int Error(const char* fmnt, ...)override{
				va_list args;
				va_start(args, fmnt);
				int ret_val = fprintf(os, "%s%dm", color_code_start, error_color.fgc);
				ret_val += vfprintf(os, fmnt, args);
				va_end(args);
				return ret_val; 
			}
			int Print(const char* fmnt, int fgc, int bgc, ...)override {
				va_list args;
				va_start(args, fmnt);
				int ret_val = fprintf(os, "%s%d;%dm", color_code_start, fgc,bgc);
				ret_val += vfprintf(os, fmnt, args);
				va_end(args);
				return ret_val;
			};
			int vPrintEX(PRINTEX_FLAGS flags, int fgc, int bgc, const char* msg, va_list valist) {
				int retval = fprintf(os, "%s", color_code_start);
				bool br = flags & PRINTEX_BRIGHT;
				auto rbgc = bgc;
				auto rfgc = fgc;
				if (flags & PRINTEX_BLINK) { retval += fprintf(os, ";%d", 06); }
				if (flags & PRINTEX_UNDERLINE) { retval += fprintf(os, ";%d", 04); }
				if (flags & PRINTEX_THICK_UNDERLINE) { retval += fprintf(os, ";%d", 21); }
				if (flags & PRINTEX_OVERLINE) { retval += fprintf(os, ";%d", 53); }
				if (flags & PRINTEX_THICK_OVERLINE) { retval += fprintf(os, ";%d", 27); }
				if (flags & PRINTEX_STRIKETHOUGH) { retval += fprintf(os, ";%d", 27); }
				if (flags & PRINTEX_DARK) { retval += fprintf(os, ";%d", 02); }
				if (fgc < 39 && br) { rfgc += 60; }
				if (bgc < 49 && br) { rbgc += 60; }
				retval += fprintf(os, "%d;%dm", rfgc, rbgc);
				retval += vfprintf(os, msg, valist);
				return retval;
			}
			int PrintEX(PRINTEX_FLAGS flags, int fgc, int bgc, const char* fmnt, ...) {
				va_list valist; 
				va_start(valist, fmnt); 
				return vPrintEX(flags, fgc, bgc, fmnt, valist);
			}
			int EndLine() {
				return fprintf(os, "%s\n", reset_code);
			}
			int Setattr(int attr) {
				return fprintf(os, "%s%dm", color_code_start, attr);
			}
		};
	}
}
#endif