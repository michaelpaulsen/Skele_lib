#ifndef SK_CONSOLE_CLASS_UNIX
#define SK_CONSOLE_CLASS_UNIX
#include "./SK_ConsoleBase.h"
#include "./SK_Color_UNIX.h"
namespace Skele_lib {
	namespace Console {
		class Console : public ConsoleBase {
			Console(FILE* _os = stdout, FILE* _is = stdin) {
				os = _os;
				is = _is;
				this->warn_color = Skele_lib::Console::Color(Skele_lib::Console::FG_colors::YELLOW,
					Skele_lib::Console::FG_colors::BLACK);
				this->error_color = Skele_lib::Console::Color(
					skele_lib::Console::FG_colors::RED,
					Skele_lib::Console::FG_colors::BLACK);
			}
			int PrintColor(const char* print_me, int color, int BG_color = 0) override {
				int ret_val = fprintf(this->os, "%s%d;%dm%s", color_code_start, BG_color, color, print_me);

			}
			int PrintColor(const float print_me, int color, int BG_color = 0, bool bright = false) override {
				int ret_val = fprintf(
					this->os,
					"%s%d;%dm",
					color_code_start,
					BG_color,
					color
				);
				if (print_me - static_cast<int>print_me == 0) {
					return ret_val + ret_val += fprintf(this->os, "%d", static_cast<int>(print_me));
				}
				else {
					return ret_val + fprintf(this->os, "%f", print_me);
				}
			}
		private: 
			const char* color_code_start = "\u001b[";
		};
	}
}
#endif