#pragma once
#include <string>
namespace Skele_lib {
	namespace RPG {
		enum class Direction { East = 2, West = 4, North = 1, South = 3 }; 
		class Entity {
		public:
			Direction dir;
			int x, y, speed,type;
			Entity() {
				x = 5; 
				y = 5; 
				speed = 0;
				type = 0;
				dir = Direction::North;

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