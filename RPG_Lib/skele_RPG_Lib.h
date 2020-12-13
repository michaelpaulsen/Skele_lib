#pragma once
#include <string>
namespace Skele_lib {
	namespace RPG {
		enum Direction { East = 2, West = 4, North = 1, South = 3 }; 
		class Entity {
		public:
			Direction dir = North; 
			int x, y, speed,type;
			Entity() {
				x = 5; 
				y = 5; 
			};
			virtual bool move(int dir) {
				return false;
				/*not pure because there is entities that I don't want to move*/
			}
			virtual bool interact(int interactionType) {
				return false; 
			};
		};
	}
}