#pragma once
#include <string>
namespace Skele_lib {
	namespace RPG {
		class Entity {
		public:
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
		class Item {
		public: 
			Item() {
			};
			std::string name;
			int range = -1;
			int type;
			virtual bool use() = 0; // override this to implement a use 
		};
		};

	}
}