#pragma once
#include "PhysicsTypes.hpp"
#include <chrono>
namespace Skele_lib {
	namespace GameEngine {
		namespace Physics {
			struct RigidBody {
				Physics_rect rect = { 0,0,0,0 };
				movable objectSpeed = { 0,0,0,0 };
				movable drag = { 2,0,0,0 };
				physicsMode pm = ignore;
				RigidBody() = default; 
				RigidBody(double x, double y, double w, double h, physicsMode pn) {
					rect = { x,y,w,h }; 
					pm = pn; 
				}
				Physics_rect getPosition() {
					return this->rect;
				}
				void addForce(double xcomp, double ycomp) {
					objectSpeed.accx = xcomp;
					objectSpeed.accy = ycomp; 
				}
				virtual void tick(std::chrono::duration<float> FelapsedTime, int ScreenH, int ScreenW) {
					if(this->pm == dynamic){ 
						this->objectSpeed.velx += this->objectSpeed.accx--;
						this->objectSpeed.velx -= this->drag.velx;
						this->rect.x += this->objectSpeed.velx - this->drag.velx;
					}
				}
			};
		}
	}
}