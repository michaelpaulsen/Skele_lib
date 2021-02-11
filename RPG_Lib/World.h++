#pragma once
#include "../utils/Array.h"
#include "./skele_RPG_Lib.h"
namespace Skele_lib {
	namespace RPG {
		class Wall {
			int startX, startY;
			int endX, endY; 
			
		public :
			Wall(int sx, int sy, int ex, int ey) {
				startX = sx; 
				startY = sy; 
				endX = ex; 
				endY = ey; 
			}
			Wall() {}
		};
		class Room {
			Skele_lib::Utils::Array<Skele_lib::RPG::Entity> ent;
			Skele_lib::Utils::Array<Skele_lib::RPG::Wall> walls; 
		public:
			Room() {

			}
			~Room() {
				walls.~Array();
				ent.~Array();
			}
			void Push(Skele_lib::RPG::Entity newE) {
				this->ent.Push(newE); 
			}
			Skele_lib::RPG::Entity Pop() {
				return this->ent.Pop(); 
			} 
			void addWall(int startx, int starty, int endx, int endy) {
				this->walls.Push(Wall());
			}
			int roomIds[4]; 
		};
		struct World{
			Skele_lib::Utils::Array<Room> rooms;
			void pushRoom(Room r) {
				rooms.Push(r); 
			}
		};
	}
}