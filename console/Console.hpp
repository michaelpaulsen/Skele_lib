#pragma once
//import std; 
#include <iostream> 
namespace SKC::Console {
	class Console
	{
	public:
		Console();
		~Console();
		void Print()
		{
		}
		template<typename printType, typename... printTypes>
		void Print(printType msg1, printTypes... msg2);
		void SetFGColor(int color);
		void SetBGColor(int color);
		void SetFGColor(int r, int g, int b);
		void SetBGColor(int r, int g, int b);
		void Reset(); 
		void Clear(); 
		void Hide(); 
		void Blink(); 
		void Move(int x, int y); 
		void Ok(auto msg);
		void Inform(auto msg);
		void Warn(auto msg);
		void Error(auto msg);
		void ErrorAndDie(auto msg, int exitcode);
	private:
		static inline char esc = 27; 
	};
	Console::Console()
	{
	}

	Console::~Console()
	{
	}
	
	template<typename printType, typename... printTypes>
	void Console::Print(printType msg1, printTypes... msg2) {
		std::cout << msg1;
		Print(msg2...); 
	}
	

	void Console::SetFGColor(int color) {
		printf("%c[38;5;%dm", esc, color); 

	};
	void Console::SetBGColor(int color) {
		printf("%c[48;5;%dm", esc, color);


	};
	void Console::SetFGColor(int r, int g, int b) {
		printf("%c[38;2;%d;%d;%dm", esc, r, g, b);

	}
	void Console::SetBGColor(int r, int g, int b) {
		printf("%c[48;2;%d;%d;%dm", esc, r, g, b);

	}
	void Console::Reset() {
		printf("%c[%cm", esc,0);
	}
	void Console::Hide() {
		printf("%c[%cm", esc,8);
	}
	void Console::Blink() {
		printf("%c[%dm", esc,5);
	}
	void Console::Clear() {
		printf("%cc",esc); 
	}
	void Console::Move(int x, int y) {
		printf("%c[%d;%dH", esc, x, y);
	}
	void Console::Ok(auto msg) {
		SetFGColor(0,255,0); 
		SetBGColor(25,100,25);
		std::cout << msg; 
	}
	void Console::Inform(auto msg) {
		SetBGColor(100,100,255); 
		SetFGColor(0,0,200);
		std::cout << msg;
	}
	void Console::Warn(auto msg) {
		SetBGColor(200,100,0); 
		SetFGColor(100, 50, 0);
		std::cout << msg;
	}
	void Console::Error(auto msg) {
		SetBGColor(255,100,100); 
		SetFGColor(255, 0, 0);
		std::cout << msg;
	}
	void Console::ErrorAndDie(auto msg, int exitcode) {
		Error(msg); 
		Reset();
		Print("\npress enter to exit");
		std::cin.ignore(); 
		exit(exitcode);
	}
	
}