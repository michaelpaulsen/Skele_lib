#pragma once
#include <vector>
#include <Windows.h>
namespace Skele_lib {
	namespace CustomWinAPI{
		namespace screen {
			class Screen {
				DWORD dwBytesWritten = 0;
				wchar_t* screen;
				HANDLE hConsole; 
				int w, h;
			public:
				Screen(int w, int h) {
					hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
					SetConsoleActiveScreenBuffer(this->hConsole);
					screen = new wchar_t[w * h];
					this->w = w;
					this->h = h;
				}
				void setActive() {
					SetConsoleActiveScreenBuffer(this->hConsole);
				}
				void writeScreen() {
					WriteConsoleOutputCharacter(this->hConsole, this->screen, this->h * this->w, { 0,0 }, &this->dwBytesWritten);
				}
				
			};
		}
	}
}