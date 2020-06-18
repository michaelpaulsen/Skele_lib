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
			Player player;
			int range = -1;
			int type;
			virtual bool use() = 0; // override this to implement a use 
		};
		class Sword : public Item {
			Sword() {
				this->range = 1;
			}
			Sword(int r) {
				this->range = r;
			}
			bool use() {
				for (int xoff = -this->range; xoff <= this->range; xoff++) {
					for (int yoff = -this->range; yoff <= this->range; yoff++) {

					}
				}
			}
		};
		class Player : public Entity {
		public: 
			std::string name;
			Player(int speed = 2){
				this->speed = speed;
			}
			bool move(int dir) override {
				switch (dir)
				{
				case 1 : {
					// up
					this->y -= this->speed;
					return true;
				}
				case 2 : {
					// right
					this->x += this->speed;
					return true;
				}
				case 3: {
					// down
					this->y += this->speed;
					return true;
				}
				case 4: {
					// left
					this->x -= this->speed;
					return true;
				}
				default:
					return false;
				}
			}
		};

	}
}
#ifdef DEBUG

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}
#endif // DEBUG
