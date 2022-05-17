#ifndef SK_CONSOLE
#define SK_CONSOLE
#include <fstream>
#include <iostream>
#include <string>
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
			void Print(const char* print_me) { fprintf(os, "%s", print_me); }
			void Print(const float   print_me) {
				auto temp = print_me; 
				if (temp - (int)temp == 0) {
					fprintf(os, "%d", (int)	print_me);
				}
				else {
					fprintf(os, "%f", print_me);

				}
			}
#ifndef WIN32
			
			void Warn(const char* print_me, bool bright = false) {
				char* b = const_cast<char*>("");
				if (bright) b = const_cast<char*>(";1");
				fprintf(os, "%s%d%sm%s %s%dm",
					color_code_start,
					Skele_lib::Console::FG_colors::YELLOW,
					b, print_me, color_code_start, 0
				);
			}
			void Warn(const float print_me, bool bright = false) {
				char b[3] = { 0 };
				if (bright) { b[0] = ';'; b[1] = '1'; b[2] = 0; }
				if (x - (int)x != 0) {
					fprintf(os, "%s%d%sm %f %s%dm",
						color_code_start,
						Skele_lib::Console::FG_colors::YELLOW,
						b, (int)print_me, color_code_start, 0
					);
				}else{
					fprintf(os, "%s%d%sm %d %s%dm",
						color_code_start,
						Skele_lib::Console::FG_colors::YELLOW,
						b, print_me, color_code_start, 0
					);
			}
			void Error(const char* print_me, bool bright = false) {
				char* b = const_cast<char*>("");
				if (bright) b = const_cast<char*>(";1");
				fprintf(os, "%s%d%sm%s%s%dm",
					color_code_start,
					Skele_lib::Console::FG_colors::RED,
					b, print_me, color_code_start, 0
				);
			}
			void Error(const float print_me, bool bright = false) {
				char* b = const_cast<char*>("");
				if (bright) b = const_cast<char*>(";1");
				if (x - (int)x != 0) {
					fprintf(os, "%s%d%sm %f %s%dm",
						color_code_start,
						Skele_lib::Console::FG_colors::RED,
						b, print_me, color_code_start, 0
					);
				}
				else {
					fprintf(os, "%s%d%sm %d %s%dm",
						color_code_start,
						Skele_lib::Console::FG_colors::RED,
                        b, (int)print_me, color_code_start, 0
					);
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
			void Warn(const char* print_me, bool bright = false){
				short x;
				this->GetColor(x);
				SetConsoleTextAttribute(this->hConsole, 110);
				fprintf(this->os, "%s", print_me);
				SetConsoleTextAttribute(this->hConsole, x);
			}
			void Warn(const float print_me, bool bright = false) {
				short x;
				this->GetColor(x);
				SetConsoleTextAttribute(this->hConsole, 110);
				if (print_me - (int)print_me == 0) {
					//printf("%f",print_me); 
					fprintf(this->os, "%d", (int)print_me);
				}
				else {
					fprintf(this->os, "%f", print_me);
				}
				SetConsoleTextAttribute(this->hConsole, x);
			}
			
			void Error(const char* print_me, bool bright = false) {
				short x;
				this->GetColor(x);
				SetConsoleTextAttribute(this->hConsole, 76);
				fprintf(this->os, "%s", print_me);
				SetConsoleTextAttribute(this->hConsole, x);
			}
			void Error(const float print_me, bool bright = false) {
				short x;
				this->GetColor(x);
				SetConsoleTextAttribute(this->hConsole, 76);
				if (print_me - (int)print_me == 0) {
					fprintf(this->os, "%d", (int)print_me);
				}
				else {
					fprintf(this->os, "%f", print_me);
				}
				SetConsoleTextAttribute(this->hConsole, x);
			}
		
#endif // !WIN32
			Console(FILE* _os = stdout, FILE* _is = stdin) {
				os = _os;
				is = _is;
#ifdef WIN32
				hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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