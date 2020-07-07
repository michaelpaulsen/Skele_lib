#pragma once
#include <Windows.h>
#include <winuser.h>
#include <conio.h>

namespace Skele_lib {
	namespace Utils {
		char getChar() {
			/// read a single character from the console without echoing the character
			return _getch();
		}
		bool GetKeyDown(int key) {///returns if the key 'key' is pressed 
			return GetAsyncKeyState(key) >> 15;
		}
		char intToChar(int x){ /// returns the LSD of the passed in int as a char
			return (x%10)+48;
		}
		char longToChar(long x){ /// returns the LSD of the passed in int as a char
			return (x%10)+48;
		}
	}
}