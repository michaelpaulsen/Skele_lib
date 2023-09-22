#pragma once
#include <iostream>
#include <string>
#include <sstream>
#define SKC_consoleVA template<typename printType, typename... printTypes>

namespace SKC::Console {
	typedef unsigned char color_t;
	struct Color {
		color_t r, g, b;
		Color() : r(255), g(255), b(255){}
		Color(color_t _r, color_t _g, color_t _b): r(_r),g(_g),b(_b) {}
		Color(Color& c) : r(c.r), g(c.g), b(c.b){}
		Color(Color&& c) = default; 
		void operator =(Color c) {
			r = c.r;
			b = c.b;
			g = c.g;
		}
		auto toString() {
			std::stringstream str; 
			str << '#'; 
			if (r < 0x10) { str << '0'; }
			str << std::hex << static_cast<int>(r);
			if (g < 0x10) { str << '0'; }
			str << std::hex << static_cast<int>(g);
			if (b < 0x10) { str << '0'; }
			str << std::hex << static_cast<int>(b);
			return str.str();
		}
	};
	class Console
	{
	public:
		Console() = default;
		~Console() = default;
		void       Ok()const {}
		void     Warn()const {}
		void     Okln()const {}
		void    Error()const {}
		void    Print()const {}
		void   Inform()const {}
		void   Warnln()const {}
		void  Errorln()const {}
		void  Println()const {}
		void Informln()const {}


		auto SetFGColor(int color);
		auto SetBGColor(int color);
		auto SetFGColor(color_t r, color_t g, color_t b);
		auto SetBGColor(color_t r, color_t g, color_t b);
		auto Reset() const;
		auto Blink() const;

		void Clear() const;
		void Hide() const;
		void Move(int x, int y) const;
		SKC_consoleVA void Print (printType msg1, printTypes... msg2) const;
		SKC_consoleVA void Println(printType msg1, printTypes... msg2) const;
		SKC_consoleVA void Ok(printType msg, printTypes ...msgs) const;
		SKC_consoleVA void Inform(printType msg, printTypes ...msgs) const;
		SKC_consoleVA void Warn(printType msg, printTypes ...msgs) const;
		SKC_consoleVA void Error(printType msg, printTypes ...msgs) const;
		SKC_consoleVA void Okln(printType msg, printTypes ...msgs) const;
		SKC_consoleVA void Informln(printType msg, printTypes ...msgs) const;
		SKC_consoleVA void Warnln (printType msg, printTypes ...msgs) const;
		SKC_consoleVA void Errorln(printType msg, printTypes ...msgs) const;
		SKC_consoleVA void ErrorAndDie(int exitcode, printType msg, printTypes ...msgs) const;
	private:
		static inline char esc = 27; 
	};
	
	auto Console::SetFGColor(int color)            {
		printf("%c[38;5;%dm", esc, color);
		return "";
	};
	auto Console::SetFGColor(color_t r, color_t g, color_t b)  {
		printf("%c[38;2;%d;%d;%dm", esc, r, g, b);
		return "";
	}
	auto Console::SetBGColor(int color)            {
		printf("%c[48;5;%dm", esc, color);
		return ""; 

	};
	auto Console::SetBGColor(color_t r, color_t g, color_t b)  {
		printf("%c[48;2;%d;%d;%dm", esc, r, g, b);
		return "";
	}
	
	auto Console::Reset() const {
		printf("%c[%cm", esc, 0);
		return "";
	}
	auto Console::Blink() const {
		printf("%c[%dm", esc, 5);
		return ""; 
	}

	void Console::Hide()const  {
		printf("%c[%cm", esc,8);
	}
	void Console::Clear() const {
		printf("%cc",esc); 
	}
	void Console::Move(int x, int y) const {
		printf("%c[%d;%dH", esc, x, y);
	}
	SKC_consoleVA void Console::Print(printType msg1, printTypes... msg2)const{
		std::cout << msg1;
		Print(msg2...);
	}
	SKC_consoleVA void Console::Ok(printType msg1, printTypes... msg2) const {
		SetFGColor(0,255,0); 
		SetBGColor(25,100,25);
		Print(msg1, msg2...);
	}
	SKC_consoleVA void Console::Inform(printType msg1, printTypes... msg2) const {
		SetBGColor(100,100,255); 
		SetFGColor(0,0,200);
		Print(msg1, msg2...);
	}
	SKC_consoleVA void Console::Warn(printType msg1, printTypes... msg2) const {
		SetBGColor(200,100,0); 
		SetFGColor(100, 50, 0);
		Print(msg1, msg2...);
	}
	SKC_consoleVA void Console::Error(printType msg1, printTypes... msg2) const {
		SetBGColor(255,100,100); 
		SetFGColor(255, 0, 0);
		Print(msg1, msg2...);
	}

	SKC_consoleVA void Console::Println(printType msg1, printTypes... msg2) const {
		Print(msg1, msg2..., '\n');
	}
	SKC_consoleVA void Console::Okln(printType msg1, printTypes... msg2) const {
		Ok(msg1, msg2...);
		Reset();
		Print('\n');
	}
	SKC_consoleVA void Console::Informln (printType msg1, printTypes... msg2) const {
		Inform(msg1, msg2...);
		Reset();
		Print('\n');
	}
	SKC_consoleVA void Console::Warnln(printType msg1, printTypes... msg2) const {
		Warn(msg1, msg2...);
		Reset();
		Print('\n');
	}
	SKC_consoleVA void Console::Errorln(printType msg1, printTypes... msg2) const {
		Error(msg1, msg2...);
		Reset();
		Print('\n');
	}
	SKC_consoleVA void Console::ErrorAndDie(int exitcode, printType msg1, printTypes... msg2) const {
		Error(msg1,msg2...);
		Reset();
		exit(exitcode);
	}
	
}