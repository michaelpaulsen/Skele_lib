namespace Skele_lib {
	namespace Color {
		enum Color_values
		{
			Red = 0xff0000,
			Green = 0x00ff00,
			Blue = 0x0000ff
		};
		struct Color_t {
			uint8_t r, g, b;
			Color_t(uint8_t _r, uint8_t _g, uint8_t _b) {
				r = _r; g = _g; b = _b;
			}
			Color_t(uint32_t color) {
				r = color & (int)Color_values::Red;
				g = color & (int)Color_values::Green;
				b = color & (int)Color_values::Blue;
			}
			Color_t(Color::Color_values x) {
				Color_t((int)x);
			}
		};
	}
}