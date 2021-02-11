#pragma once
#include <vector>
#include <Windows.h>
#include <WinUser.h>
namespace Skele_lib {
	namespace CustomWinAPI{
		namespace screen {
			class Screen {
				DWORD dwBytesWritten = 0;
				HANDLE hConsole;
				HWND Console;
				int w, h;
			public:
				wchar_t* screen;
								
				void SetScreenSize(short w, short h) {
					SetConsoleScreenBufferSize(this->hConsole, { w,h });
					MoveWindow(this->Console, 0, 0, w, h, true);
				}
				void setActive() {
					SetConsoleActiveScreenBuffer(this->hConsole);
				}
				void writeScreen() {
					WriteConsoleOutputCharacter(this->hConsole, this->screen, this->h * this->w, { 0,0 }, &this->dwBytesWritten);
				}
				int getScreenWidth() {
					return this->w; 
				}
				int getScreenHeight() {
					return this->h;
				}
				Screen(int w, int h) {
					Console = GetConsoleWindow();
					hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
					SetScreenSize(w, h);
					SetConsoleActiveScreenBuffer(this->hConsole);
					screen = new wchar_t[w * h];
					this->w = w;
					this->h = h;
				}
			};
		}
	}
}