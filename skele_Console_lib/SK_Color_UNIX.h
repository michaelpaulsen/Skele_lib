#ifndef SK_COLOR_ENUM_U
#define SK_COLOR_ENUM_U
namespace Skele_lib {
	namespace Console {
		enum class FG_colors {
			BLACK = 30,
			RED,
			GREEN,
			YELLOW,
			BLUE,
			MAGENTA,
			CYAN,
			WHITE,
			RESET = 0,
		};
		//skele_lib::Console::BG_colors
		enum class BG_colors {
			BLACK = 40,
			RED,
			GREEN,
			YELLOW,
			BLUE,
			MAGENTA,
			CYAN,
			WHITE,
			RESET = 0,
		};
	}
}
#endif