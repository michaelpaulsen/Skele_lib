#ifndef SK_CONSOLE_CLASS_WIN 
#define SK_CONSOLE_CLASS_WIN 
#include "./SK_ConsoleBase.h"
#include <windows.h>

namespace Skele_lib {
	namespace Console {
		struct Console : public ConsoleBase {
			Console(FILE* _is = stdin, FILE* _os = stdout) {
				os = _os;
				is = _is;
				this->ok_color = Skele_lib::Console::Color(14, 02);
				this->inform_color = Skele_lib::Console::Color(11, 01);
				this->warn_color = Skele_lib::Console::Color(07, 06);
				this->error_color = Skele_lib::Console::Color(07, 04);
				hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			}
			HANDLE hConsole;
			bool GetColor(short &ret) {
				CONSOLE_SCREEN_BUFFER_INFO info;
				if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info))return false;
				ret = info.wAttributes;
				return true;
			}
			HANDLE GetHandle() {
				return this->hConsole;
			}
			int PrintColor(const char* print_me, int color, int BG_color = 0) override{
				int c = (16 * BG_color) + color;
				short x;
				this->GetColor(x);
				SetConsoleTextAttribute(this->hConsole, c);
				auto ret_val = fprintf(this->os, "%s", print_me);
				SetConsoleTextAttribute(this->hConsole, x);
				return ret_val;
			}			
			int PrintColor(const float print_me, int color, int BG_color = 0) override{
				int c = (16 * BG_color) + color;
				short x;
				this->GetColor(x);
				SetConsoleTextAttribute(this->hConsole, c);
				int ret_val;
				if (print_me - static_cast<int>(print_me) == 0) {
					ret_val = fprintf(this->os, "%d", static_cast<int>(print_me));
				}
				else {
					ret_val = fprintf(this->os, "%f", print_me);
				}
				SetConsoleTextAttribute(this->hConsole, x);
				return ret_val;
			}
		};
	}
}
#endif // SK_CONSOLE_CLASS_WIN 