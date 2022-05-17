#ifndef SK_CONSOLE
#define SK_CONSOLE
#include <fstream>
#include <iostream>
#include <string>
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
		enum class colors {
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
		class Console {
			FILE* os;
			FILE* is;
			const char* color_code_start = "\u001b["; 
		public: 
			void Print(const char* print_me) {fprintf(os,"%s", print_me);}
			void Print(int print_me) {fprintf(os,"%d", print_me);}
			void Print(float print_me) {fprintf(os,"%f", print_me);}
			void Warn(const char* print_me, bool bright = false) {
				char* b = const_cast<char*>(""); 
				if (bright) b = const_cast<char*>(";1");
				fprintf(os,"%s%d%sm%s %s%dm",
					color_code_start,
					Skele_lib::Console::colors::YELLOW,
					b,
					print_me,
					color_code_start,
					0); 
			}
			void Warn(const int print_me, bool bright = false) {
				char b[3] = { 0 };
				if (bright) { b[0] = ';'; b[1] = '1'; b[2] = 0; }
				fprintf(os,"%s%d%sm %d %s%dm",
					color_code_start,
					Skele_lib::Console::colors::YELLOW,
					b,
					print_me,
					color_code_start,
					0); 
			}
			void Warn(const float print_me, bool bright = false) {
				char b[3] = { 0 };
				if (bright) { b[0] = ';'; b[1] = '1'; b[2] = 0; }
				fprintf(os,"%s%d%sm %f %s%dm",
					color_code_start,
					Skele_lib::Console::colors::YELLOW,
					b,
					print_me,
					color_code_start,
					0); 
			}
				
			//template<typename T> static 
			Console(FILE* _os = stdout, FILE* _is = stdin) {
				os = _os;
				is = _is;
			}
			//~Console() {
		//		delete os;
			//	delete is; 
			//};
			//Console(Console &)  = delete;
			//Console(Console &&) = delete;
		};
	}
}
#endif // !SK_CONSOLE