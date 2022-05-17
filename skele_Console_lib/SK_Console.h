#ifndef SK_CONSOLE
#define SK_CONSOLE
#include <fstream>
#include <iostream>
#include <string>
#include <stdint.h>
#ifdef  WIN32
#include <windows.h>
#endif //  WIN32

/*Black: \u001b[30m
Red: \u001b[31m
Green: \u001b[32m
Yellow: \u001b[33m
Blue: \u001b[34m
Magenta: \u001b[35m
Cyan: \u001b[36m
White: \u001b[37m
Reset: \u001b[0m*/
namespace Skele_lib {
	namespace Console {
#ifndef WIN32
		//skele_lib::Console::FG_colors
	enum class FG_colors {
			BLACK = 30,
			RED,
			GREEN,
			YELLOW,
			BLUE,
			MAGENTA,
			CYAN,
			WHITE,
			RESET = 0,
		};
	//skele_lib::Console::BG_colors
	enum class BG_colors {
			BLACK = 40,
			RED,
			GREEN,
			YELLOW,
			BLUE,
			MAGENTA,
			CYAN,
			WHITE,
			RESET = 0,
		};
#endif // !WIN32
	struct Color {
		int fgc, bgc;
		Color() = default; 
#ifdef WIN32
		Color(uint8_t _f, uint8_t _b) {
			fgc = _f;
			bgc = _b;
		}
#else 
		Color(skele_lib::Console::FG_colors _f, skele_lib::Console::BG_colors _b) {
			fgc = _f;
			bgc = _b;
		}
#endif // WIN32
	};
	class Console {
#ifdef WIN32
		HANDLE hConsole;
#endif
		FILE* os;
		FILE* is;
#ifndef WIN32
		const char* color_code_start = "\u001b[";
#endif // 		
	public:
		Color   warn_color;
		Color     ok_color; 
		Color inform_color;
		Color  error_color;
		void Print(const char* print_me) { fprintf(os, "%s", print_me); }
		void Print(const float   print_me) {
			auto temp = print_me;
			if (temp - (int)temp == 0) {
				fprintf(os, "%d", (int)print_me);
			}
			else {
				fprintf(os, "%f", print_me);

			}
		}
#ifndef WIN32

		auto PrintColor(const char * print_me, int color, int BGcolor = 0) {
			int ret_val = 0; 
			ret_val += fprintf(this->os, "%s%dm %s%d%sm", color_code_start, BGcolor, color_code_start, color, b);
			ret_val += fprintf(os, "%s", print_me);
			ret_val += fprintf(this->os, "%s%dm", color_code_start, 0); 
			return ret_val; 
		}
		auto PrintColor(const float print_me, int color, int BGcolor = 0) {
			char b[3] = { 0 };
			if (bright) { b[0] = ';'; b[1] = '1'; b[2] = 0; }
			fprintf(this->os, "%s%dm %s%d%sm", color_code_start, BGcolor, color_code_start, color, b);
			if (print_me - (int)print_me == 0) {
				//printf("%f",print_me); 
				fprintf(this->os, "%d", (int)print_me);
			}
			else {
				fprintf(this->os, "%f", print_me);
			}
			return fprintf(this->os, "%s%dm", color_code_start, 0)
		}
		auto Inform(const char* print_me, bool bright) {
			int clr = skele_lib::Console::FG_colors::Blue;
			if (bright) {
				clr += 60;
			}
			return printColor(print_me, clr);
		}
		auto Inform(const float print_me, bool bright) {
			int clr = skele_lib::Console::FG_colors::Blue;
			if (bright) {
				clr += 60;
			}
			return printColor(print_me, clr);
		}
		auto Ok(const char* print_me, bool bright) {
			int clr = skele_lib::Console::FG_colors::GREEN;
			if (bright) {
				clr += 60;
			}
			return printColor(print_me, clr);
		}
		auto Ok(const float print_me, bool bright) {
			int clr = skele_lib::Console::FG_colors::GREEN;
			if (bright) {
				clr += 60;
			}
			return printColor(print_me, clr);
		}
		auto Warn(const char* print_me, bool bright = false) {
			int clr = skele_lib::Console::FG_colors::YELLOW;
			if (bright) {
				clr += 60;
			}
			return printColor(print_me, clr);
		}
		auto Warn(const float print_me, bool bright = false) {
			int clr = skele_lib::Console::FG_colors::YELLOW;
			if (bright) {
				clr += 60;
			}
			return printColor(print_me, clr);
		}
		auto Error(const char* print_me, bool bright = false) {
			int clr = skele_lib::Console::FG_colors::RED;
			if (bright) {
				clr += 60;
			}
			return printColor(print_me, clr);
		}
		auto Error(const float print_me, bool bright = false) {
			int clr = skele_lib::Console::FG_colors::RED;
			if (bright) {
				clr += 60;
			}
			return printColor(print_me, clr);
		}
	}


#else
		bool GetColor(short &ret) {
			CONSOLE_SCREEN_BUFFER_INFO info;
			if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info))
				return false;
			ret = info.wAttributes;
			return true;
		}
		HANDLE GetHandle() {
			return this->hConsole;
		}
		auto PrintColor(const char * print_me, int color, int BG_color = 0) {
			int c = (16 * BG_color) + color;
			short x;
			this->GetColor(x);
			SetConsoleTextAttribute(this->hConsole, c);
			auto ret_val = fprintf(this->os, "%s", print_me);
			SetConsoleTextAttribute(this->hConsole, x);
			return ret_val; 
		}
		auto PrintColor(const float print_me, int color, int BG_color = 0) {
			int c = (16 * BG_color) + color;
			short x;
			this->GetColor(x);
			SetConsoleTextAttribute(this->hConsole, c);
			int ret_val; 
			if (print_me - (int)print_me == 0) {
				//printf("%f",print_me); 
				ret_val = fprintf(this->os, "%d", (int)print_me);
			}
			else {
				ret_val = fprintf(this->os, "%f", print_me);
			}
			SetConsoleTextAttribute(this->hConsole, x);
			return ret_val; 
		}
		auto Inform(const char* print_me, bool bright = false) {
			return PrintColor(print_me, Skele_lib::Console::Console::inform_color.fgc, Skele_lib::Console::Console::inform_color.bgc);
		}
		auto  Inform(const float print_me, bool bright = false) {
			return PrintColor(print_me, Skele_lib::Console::Console::inform_color.fgc, Skele_lib::Console::Console::inform_color.bgc);
		}
		auto Ok(const char* print_me, bool bright = false) {
			return PrintColor(print_me, Skele_lib::Console::Console::ok_color.fgc, Skele_lib::Console::Console::ok_color.bgc);

		}
		auto Ok(const float print_me, bool bright = false) {
			return PrintColor(print_me, Skele_lib::Console::Console::ok_color.fgc, Skele_lib::Console::Console::ok_color.bgc);
		}
		auto Warn(const char* print_me, bool bright = false) {
			return PrintColor(print_me, Skele_lib::Console::Console::warn_color.fgc, Skele_lib::Console::Console::warn_color.bgc);
		}
		auto Warn(const float print_me, bool bright = false) {
			return PrintColor(print_me, Skele_lib::Console::Console::warn_color.fgc, Skele_lib::Console::Console::warn_color.bgc);
		}
		auto Error(const char* print_me, bool bright = false) {
			return PrintColor(print_me, Skele_lib::Console::Console::error_color.fgc, Skele_lib::Console::Console::error_color.bgc);
		}
		auto Error(const float print_me, bool bright = false) {
			return PrintColor(print_me, Skele_lib::Console::Console::error_color.fgc, Skele_lib::Console::Console::error_color.bgc);
		}	
			
		
#endif // !WIN32
			Console(FILE* _os = stdout, FILE* _is = stdin) {
				os = _os;
				is = _is;
#ifdef WIN32
				this->ok_color     = Skele_lib::Console::Color(14, 02); 
				this->inform_color = Skele_lib::Console::Color(11, 01); 
				this->warn_color   = Skele_lib::Console::Color(07, 06); 
				this->error_color  = Skele_lib::Console::Color(07, 04); 
				hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#else
				this->warn_color  = Skele_lib::Console::Color(skele_lib::Console::FG_colors::YELLOW, skele_lib::Console::BG_colors::BLACK);
				this->error_color = Skele_lib::Console::Color(skele_lib::Console::FG_colors::RED,    skele_lib::Console::BG_colors::BLACK);
#endif // WIN32

			}
			void WLineNumber(int lineNumber, bool hl = false, bool hn = false, bool hc = false) {
				/// @params 
				///hl -> highlight line high lights the "line" part of the warning
				///hn -> highlight number it highlights the line number
				///hc -> highlight colon it higligts the colon that seperates the line number and the warning text
				this->Warn("Warning on line ", hl);
				this->Warn(lineNumber, hn);
				this->Warn(": ", hc);
			}
			void ELineNumebr(int lineNumber, bool hl = false, bool hn = false, bool hc = false) {
				/// @params 
				///hl -> highlight line high lights the "line" part of the warning
				///hn -> highlight number it highlights the line number
				///hc -> highlight colon it higligts the colon that seperates the line number and the warning text
				this->Error("Error on line ", hl);
				this->Error(lineNumber, hn);
				this->Error(": ", hc);
			}
		};
	}
}
#endif // !SK_CONSOLE