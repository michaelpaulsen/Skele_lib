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
		public:
			std::ostream* os;
			std::istream* is;
			//in stream and out stream 
			template<typename T> bool Print(T print_me) {
				*(this->os)<< print_me;
				return !os->bad(); 
			}
			//template<typename T> static 
			Console(std::ostream* _os = &std::cout, std::istream* _is = &std::cin) {
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