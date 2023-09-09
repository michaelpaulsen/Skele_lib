#pragma once
//import std; 
#include <iostream> 
namespace SKC::Console {
	class Console
	{
	public:
		Console();
		~Console();
		void       Ok() {}
		void     Warn() {}
		void    Error() {}
		void    Print() {}
		void   Inform() {}
		
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
		template<typename printType, typename... printTypes>
		void Ok(printType msg, printTypes ...msgs);
		template<typename printType, typename... printTypes>
		void Inform(printType msg, printTypes ...msgs);
		template<typename printType, typename... printTypes>
		void Warn(printType msg, printTypes ...msgs);
		template<typename printType, typename... printTypes>
		void Error(printType msg, printTypes ...msgs);
		template<typename printType, typename... printTypes>
		void Okln(printType msg, printTypes ...msgs);
		template<typename printType, typename... printTypes>
		void Informln(printType msg, printTypes ...msgs);
		template<typename printType, typename... printTypes>
		void Warnln (printType msg, printTypes ...msgs);
		template<typename printType, typename... printTypes>
		void Errorln(printType msg, printTypes ...msgs);
		template<typename printType, typename... printTypes>
		void ErrorAndDie(int exitcode, printType msg, printTypes ...msgs);
	private:
		static inline char esc = 27; 
	};
	Console::Console()
	{
	}
	Console::~Console()
	{
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
	template<typename printType, typename... printTypes>
	void Console::Print(printType msg1, printTypes... msg2) {
		std::cout << msg1;
		Print(msg2...);
	}
	template<typename printType, typename... printTypes>
	void Console::Ok(printType msg1, printTypes... msg2) {
		SetFGColor(0,255,0); 
		SetBGColor(25,100,25);
		Print(msg1, msg2...);
	}
	template<typename printType, typename... printTypes>
	void Console::Inform(printType msg1, printTypes... msg2) {
		SetBGColor(100,100,255); 
		SetFGColor(0,0,200);
		Print(msg1, msg2...);
	}
	template<typename printType, typename... printTypes>
	void Console::Warn(printType msg1, printTypes... msg2) {
		SetBGColor(200,100,0); 
		SetFGColor(100, 50, 0);
		Print(msg1, msg2...);
	}
	template<typename printType, typename... printTypes>
	void Console::Error(printType msg1, printTypes... msg2) {
		SetBGColor(255,100,100); 
		SetFGColor(255, 0, 0);
		Print(msg1, msg2...);
	}
	template<typename printType, typename... printTypes>
	void Console::ErrorAndDie(int exitcode, printType msg1, printTypes... msg2) {
		Error(msg1,msg2...);
		Reset();
		exit(exitcode);
	}
	
}