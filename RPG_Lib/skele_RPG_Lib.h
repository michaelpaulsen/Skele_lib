#pragma once
#include <string>
namespace Skele_lib {
	namespace RPG {
		enum class Direction { North = 1, East = 2, South = 3, West = 4};
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
				/*not pure because there is entities that don't want to move*/
			}
			virtual bool interact(int interactionType) {
				return false; 
			};
			virtual bool use(int type) {
				return false;
			}
			virtual bool useOnEntity(int type, Entity other) {
				return false;
			}
		};
	}
}