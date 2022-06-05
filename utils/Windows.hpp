#include <Windows.h>
namespace Skele_lib {
	namespace Utils {
		namespace Windows {
			char getChar() {
				/// read a single character from the console without echoing the character 
				/// windows only
				return _getch();
			}
			bool GetKeyDown(int key) {
				///returns if the key 'key' is pressed
				///windows only 
				return GetAsyncKeyState(key) >> 15;
			}
		}
	}
}