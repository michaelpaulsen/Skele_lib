#pragma once
#include <Windows.h>
#include <math.h>
#include <conio.h>
namespace Skele_lib {
	namespace Utils {
		void ask(std::string prompt, std::string& out) {
			std::cout << prompt << " \n";
			std::getline(std::cin, out, '\n');
			std::cout << '\n';
		}
		int getNthdigit(int in, int pow) {
			return (in % pow) / (pow / 10);
		}
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
		char longToChar(long x){ /// returns the LSD of the passed in long as a char
			return (x % 10) + 48;
		}
		bool isIntegral(char c) {
			return c >= '0' && c <= '9';
		}
		int CharToInt(char c) {
			/*
			* this works because the chars are stored as numbers so you can cast (convert) from char to int
			* this also means that you can compare and do math on chars
			*/
			if (isIntegral(c)){
				return (c - '0'); 
			}
		}
		int stringToInt(const char* n) {
			bool isInt = true;
			int ret = 0; 
			int pow = 1;
			int x   = sizeof(n)/sizeof(char);
			/*
			* sizeof(char) should be 1 but it could be more 
			*/
			while (x >= 0 || n[x] == 0) {
				isInt = isIntegral(n[x]);
				if (isInt) {
					ret += (CharToInt(n[x]) * pow); 
					pow *= 10; 
				}
				else {
					if (n[x] != '\0') {
						break;
					}
				}
				x--;
			}
			return ret;
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
		char* intToString(int t) {
			int pow = 10;
			int d = ceil((log(t) / log(10)));
			/*
			* logY(x) = y means Y^x = y
			* there for the ceiling of log10 returns the number of digits a number has
			*/
			char* s = static_cast<char*>(calloc(d+1, sizeof(char)));
			for (int x = d-1; x > -1; x--) {
				s[x] = intToChar(getNthdigit(t,pow));
				/*get the powth number of the passed in int */
				pow *= 10; 
			}
			return s; 
		}
	}

}