#pragma once
#include <string>
namespace Skele_lib {
	namespace RPG {
		class Entity {
		public:
			enum direction { East, West, North, South }; 
			int x, y, speed,type;
			Entity() {}
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