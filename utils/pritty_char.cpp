#define ASCII_ESC (char)0x1b
#include <sstream>
#include <string> 

namespace Skele_lib {
	namespace Utils {
		namespace C_string{ 
			enum Colors{ 
				BLACK      = 30,
				RED        = 31,
				GREEN      = 32,
				YELLOW     = 33,
				BLUE       = 34,
				MAGENTA    = 35,
				CYAN       = 36,
				WHITE      = 37,
				BG_BLACK   = 40,
				BG_RED     = 41,
				BG_GREEN   = 42,
				BG_YELLOW  = 43,
				BG_BLUE    = 44,
				BG_MAGENTA = 45,
				BG_CYAN    = 46,
				BG_WHITE   = 47

			};
			void escape(std::string& r){ 
				std::stringstream ss; 
				ss << ASCII_ESC << '[';
				ss >> r; 
			}
			void MoveXLines(std::string& r, int i){ 
				escape(r); 
				std::stringstream ss; 
				ss<<r; 
				if(i < 0 ){
					ss << (i*i)/i << 'B';
				}
				else{
					ss << i << 'A'; 
				}
				ss >> r;
			}
			void changeColor(std::string& r, Colors color){ 
				escape(r);
				std::stringstream ss;
				ss<<r;
				ss<<color<<'m'; 
				ss>>r; 
			}

		}
	}
}
