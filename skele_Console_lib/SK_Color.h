#ifndef SK_COLOR_STRUCT
#define SK_COLOR_STRUCT
namespace Skele_lib {
	namespace Console {
		struct Color {
			int fgc, bgc;
			Color() = default;
			Color(int _f, int _b) {
				fgc = _f;
				bgc = _b;
			}
		};
	}
}
#endif