#pragma once
#include "PhysicsTypes.hpp"
#include <chrono>
namespace Skele_lib {
	namespace GameEngine {
		namespace Physics {
			class RigidBody {
			private:
				Physics_rect rect;
				movable objectSpeed = { 0,0,0,0 };
				movable drag = { 2,0,0,0 };
			public:
				RigidBody(double x, double y, double w, double h) {
					rect = { x,y,w,h }; 
				}
				Physics_rect getPosition() {
					return this->rect;
				}
				void addForce(double xcomp, double ycomp) {
					objectSpeed.accx = xcomp;
					objectSpeed.accy = ycomp; 
				}
				virtual void tick(std::chrono::duration<float> FelapsedTime, int h, int w) {
					this->objectSpeed.velx += this->objectSpeed.accx--;
					this->objectSpeed.velx -= this->drag.velx;
					this->rect.x += this->objectSpeed.velx - this->drag.velx;
				}
			};
		}
	}
}