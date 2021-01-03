#pragma once
#include "skele_RPG_Lib.h" 
namespace Skele_lib {
	namespace RPG {
		class Item : public Entity {
		public:
			Item() {
				type = NULL; 
			};
			Item(int x, int y) {
				this->x = x; 
				this->y = y; 
			}
			std::string name;
			int range = -1;
		};
	}
}