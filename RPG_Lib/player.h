#include "./skele_RPG_Lib.h"
#pragma once
namespace Skele_lib {
	namespace RPG {
		class Player : public Entity {
		public:
			std::string name;
			Player(int speed = 2) {
				this->speed = speed;
			}
			bool move(int dir) override {
				switch (dir)
				{
				case 1: {
					this->dir = North;
					// up
					this->y -= this->speed;
					return true;
				}
				case 2: {
					// right
					this->dir = East;
					this->x += this->speed;
					return true;
				}
				case 3: {
					// down
					this->dir = South;
					this->y += this->speed;
					return true;
				}
				case 4: {
					// left
					this->dir = West;
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