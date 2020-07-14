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
			return (x % 10) + 48;
		}
		char longToChar(long x){ /// returns the LSD of the passed in int as a char
			return (x % 10) + 48;
		}
		bool isIntegral(char c) {
			return c >= '0' && c <= '9';
		}
		int CharToInt(char c) {
			/*
			* this works because the chars are stored as numbers so you can cast (convert) from char to int
			* this also means that you can compare and to math on chars
			*/
			if (isIntegral(c)){
				return (c - '0'); 
			}
		}
		bool isPrintfSafe(const char* s) {
			int i = 0; 
			while(s[i] != '\0') {
				if (s[i] == '%') { 
				/* 
				* doing it this way prevents it from having
				* to do the check for the second char if the first char isn't a %
				* in theory this is faster though I wouldn't be suprised if the compiler is sees this as
				* the same as having two seperate if statments 
				* I also like this better because it repersents the flow of the algorithom better
				*/
					if (s[i + 1] == '%') {
						i += 2;
						continue;
					}
					if (s[i + 1] != '%') {
						return false;
					}
				}
				i++;
			}
			return true; 
		}
	}
}