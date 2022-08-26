#ifndef SK_CONSOLE_STRUCT
#define SK_CONSOLE_STRUCT
#include <fstream>
#include <iostream>
#include <string>
#include <stdint.h>
#include "SK_Color.h"
namespace Skele_lib {
	namespace Console {
		struct ConsoleBase {
			FILE* os;
			FILE* is;
			Color   warn_color;
			Color     ok_color;
			Color inform_color;
			Color  error_color;
			virtual int PrintColor(const char* print_me, int color, int BG_color) = 0;
			virtual int PrintColor(float print_me, int color, int BG_color) = 0;
			virtual int PrintCharAsHex(char print_me) = 0;
			virtual int PrintnumebrAsHex(long print_me) = 0;
			int Print(const char* print_me) { return fprintf(os, "%s", print_me); }
			int Print(const float print_me) {
				auto temp = print_me;
				if (temp - static_cast<int>(temp)== 0) {return fprintf(os, "%d", static_cast<int>(print_me));}
				return fprintf(os, "%f", print_me);
			}

			int Inform(const float print_me) {
				return PrintColor(print_me,
					this->inform_color.fgc,
					this->inform_color.bgc
				);
			}
			int Inform(const char* print_me) {
				return PrintColor(print_me,
					this->inform_color.fgc,
					this->inform_color.bgc
				);
			}
			
			int Ok(const float print_me) {
				return PrintColor(print_me,
					this->ok_color.fgc,
					this->ok_color.bgc
				);
			}
			int Ok(const char* print_me) {
				return PrintColor(print_me,
					this->ok_color.fgc,
					this->ok_color.bgc
				);
			}
			
			int Warn(const float print_me) {
				return PrintColor(print_me,
					this->warn_color.fgc,
					this->warn_color.bgc
				);
			}
			int Warn(const char* print_me) {
				return PrintColor(print_me,
					this->warn_color.fgc,
					this->warn_color.bgc
				);
			}
			
			int Error(const float print_me) {
				return PrintColor(print_me,
					this->error_color.fgc,
					this->error_color.bgc
				);
			}
			int Error(const char* print_me) {
				return PrintColor(print_me,
					this->error_color.fgc,
					this->error_color.bgc
				);
			}
			
			int WLineNumber(int lineNumber) {
				int t = this->Warn("Warning on line ");
				t += this->Warn(lineNumber);
				t += this->Warn(": ");
				return t; 
			}
			int ELineNumebr(int lineNumber) {
				/// @params 
				///hl -> highlight line high lights the "line" part of the warning
				///hn -> highlight number it highlights the line number
				///hc -> highlight colon it higligts the colon that seperates the line number and the warning text
				int t = this->Error("Warning on line ");
				t += this->Error(lineNumber);
				t += this->Error(": ");
				return t;

			}
		};
	}
}
#endif // !SK_CONSOLE_STRUCT
