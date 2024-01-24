#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "../concepts.hpp"
#define SKC_consoleVA template<concepts::printable printType, concepts::printable... printTypes>

namespace SKC::Console {
	typedef unsigned char color_t;
	struct Color {
		color_t r, g, b;
		Color() : r(255), g(255), b(255){}
		Color(color_t _r, color_t _g, color_t _b): r(_r),g(_g),b(_b) {}
		Color(Color& c) : r(c.r), g(c.g), b(c.b){}
		Color(Color&& c) = default; 
		void operator = (Color c) {
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
		static inline char esc = 27;
	public:
		enum color_name_t {
			error,
			warn,
			ok,
			info,
			max
		};
		Color BG_pallet[color_name_t::max];
		Color FG_pallet[color_name_t::max];


		Console() {
			BG_pallet[error] = { 255,100,100 };
			BG_pallet[warn]  = { 193,156,  0 };
			BG_pallet[ok]    = { 100,255,100 };
			BG_pallet[info]  = { 100,100,255 };
			
			FG_pallet[error] = { 170,  0,  0};
			FG_pallet[warn]  = { 170, 85, 00};
			FG_pallet[ok]    = { 050,100,050};
			FG_pallet[info]  = { 050,050,100};
		};
		~Console() = default;
		Console(Console&) = delete; 
		Console(Console&&) = delete; 
		void  operator =(Console&) = delete;
		void  operator =(Console&&) = delete;
		
		
		
		auto&       Ok() {return *this;}
		auto&     Warn() {return *this;}
		auto&     Okln() {return *this;}
		auto&    Error() {return *this;}
		auto&    Print() {return *this;}
		auto&   Inform() {return *this;}
		auto&   Warnln() {return *this;}
		auto&  Errorln() {return *this;}
		auto&  Println() {return *this;}
		auto& Informln() {return *this;}

		auto& SetFGColor(color_t r, color_t g, color_t b);
		auto& SetBGColor(color_t r, color_t g, color_t b);
		auto& SetFGColor(Color c);
		auto& SetBGColor(Color c);
		
		auto& Reset();
		auto& Blink();

		auto&  Clear();
		auto&  Hide();
		auto&  Move(int x, int y) ;
		
		SKC_consoleVA auto&  Ok(printType msg, printTypes ...msgs);
		SKC_consoleVA auto&  Okln(printType msg, printTypes ...msgs);
		
		SKC_consoleVA auto&  Warn(printType msg, printTypes ...msgs);
		SKC_consoleVA auto&  Warnln (printType msg, printTypes ...msgs);
		
		SKC_consoleVA auto&  Print (printType msg1, printTypes... msg2);
		SKC_consoleVA auto&  Println(printType msg1, printTypes... msg2);
		
		SKC_consoleVA auto&  Error(printType msg, printTypes ...msgs);
		SKC_consoleVA auto&  Errorln(printType msg, printTypes ...msgs);
		
		SKC_consoleVA auto&  Inform(printType msg, printTypes ...msgs);
		SKC_consoleVA auto&  Informln(printType msg, printTypes ...msgs);
		
		SKC_consoleVA auto&  ErrorAndDie(int exitcode, printType msg, printTypes ...msgs);
	};
	
	auto& Console::SetFGColor(color_t r, color_t g, color_t b)  {
		printf("%c[38;2;%d;%d;%dm", esc, r, g, b);
		return *this;
	}
	auto& Console::SetBGColor(color_t r, color_t g, color_t b)  {
		printf("%c[48;2;%d;%d;%dm", esc, r, g, b);
		return *this; 
	}
	
	auto& Console::SetFGColor(Color c)  {
		printf("%c[38;2;%d;%d;%dm", esc, c.r, c.g, c.b);
		return *this;
	}
	auto& Console::SetBGColor(Color c)  {
		printf("%c[48;2;%d;%d;%dm", esc, c.r, c.g, c.b);
		return *this;
	}
	
	auto& Console::Reset() {
		printf("%c[%cm", esc, 0);
		return *this;
	}
	auto& Console::Blink() {
		printf("%c[%dm", esc, 5);
		return *this; 
	}
	
	auto&  Console::Hide () {
		printf("%c[%cm", esc,8);
		return *this; 
	}
	auto&  Console::Clear() {
		printf("%cc",esc); 
		return *this;
	}

	auto& Console::Move(int x, int y) {
		printf("%c[%d;%dH", esc, x, y);
		return *this;
	}
	
	SKC_consoleVA auto&  Console::Print(printType msg1, printTypes... msg2){
		using t = decltype(msg1); 
		if constexpr (concepts::parsable_cimple<t>) { 
			// if the type has a ToString method call it
			// and the rest of the function doesn't even exist... 
			std::cout << msg1.ToString();
		}
		else if constexpr (concepts::parsable_imple<t>) { 
			//else if it has a toString method call that
			std::cout << msg1.toString();
		}
		else {
			std::cout << msg1; // do nothing 
			
			//this should only be called for integral, floating point; and [c]strings
			//TODO make it so that any object that has an overloaded
			//stream inserion operator can be called here... 
		}
		Print(msg2...);
		return *this;
	}
	SKC_consoleVA auto&  Console::Println(printType msg1, printTypes... msg2) {
		Print(msg1, msg2..., '\n');
		return *this;
	}
	
	SKC_consoleVA auto&  Console::Ok(printType msg1, printTypes... msg2) {
		SetBGColor(BG_pallet[ok]);
		SetFGColor(FG_pallet[ok]);
		Print(msg1, msg2...);
		return *this;

	}
	SKC_consoleVA auto&  Console::Inform(printType msg1, printTypes... msg2) {
		SetBGColor(this->BG_pallet[info]);
		SetFGColor(this->FG_pallet[info]);
		Print(msg1, msg2...);
		return *this;

	}
	SKC_consoleVA auto&  Console::Warn(printType msg1, printTypes... msg2) {
		SetBGColor(this->BG_pallet[warn]);
		SetFGColor(this->FG_pallet[warn]);
		Print(msg1, msg2...);
		return *this;

	}
	SKC_consoleVA auto&  Console::Error(printType msg1, printTypes... msg2) {
		SetBGColor(this->BG_pallet[error]);
		SetFGColor(this->FG_pallet[error]);
		Print(msg1, msg2...);
		return *this;
	}

	SKC_consoleVA auto&  Console::Okln(printType msg1, printTypes... msg2)                       {
		Ok(msg1, msg2...);
		Reset();
		Print('\n');
		return *this;

	}
	SKC_consoleVA auto&  Console::Informln (printType msg1, printTypes... msg2)                  {
		Inform(msg1, msg2...);
		Reset();
		Print('\n');
		return *this;

	}
	SKC_consoleVA auto&  Console::Warnln(printType msg1, printTypes... msg2)                     {
		Warn(msg1, msg2...);
		Reset();
		Print('\n');
		return *this;

	}
	SKC_consoleVA auto&  Console::Errorln(printType msg1, printTypes... msg2)                    {
		Error(msg1, msg2...);
		Reset();
		Print('\n');
		return *this;

	}
	SKC_consoleVA auto&  Console::ErrorAndDie(int exitcode, printType msg1, printTypes... msg2)  {
		Error(msg1,msg2...);
		Reset();
		exit(exitcode);
		return *this; 
	}
	
}