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
		public:
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