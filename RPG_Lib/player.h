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
					this->dir = Skele_lib::RPG::Direction::North;
					// up
					this->y -= this->speed;
					return true;
				}
				case 2: {
					// right
					this->dir = Skele_lib::RPG::Direction::East;
					this->x += this->speed;
					return true;
				}
				case 3: {
					// down
					this->dir = Skele_lib::RPG::Direction::South;
					this->y += this->speed;
					return true;
				}
				case 4: {
					// left
					this->dir = Skele_lib::RPG::Direction::West;
					this->x -= this->speed;
					return true;
				}
				default:
					return false;
				}
			}
			virtual wchar_t getSprite() {
				switch (this->dir) {
					/*
					change what "sprite" is shown based off of what direction the player is facing
					*/
					case Skele_lib::RPG::Direction::North: {
						return 0x31d;
					}
					case Skele_lib::RPG::Direction::East: {
						return 0x319;
					}
					case Skele_lib::RPG::Direction::South: {
						return 0x31e;
					}
					case Skele_lib::RPG::Direction::West: {
						 return 0x31f;
					}
				}
				return ' '; 
			}
		};
	}
}