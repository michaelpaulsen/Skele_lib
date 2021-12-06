#pragma once
#include <SDL.h>
#include "Sprite.hpp"
#include "..\Physics\Physics.hpp"
namespace Skele_lib {
	namespace GameEngine {
		namespace GameObject {
			
			struct GameObject : public Physics::RigidBody {
				Sprite sp; 
				GameObject(const char* file, double x, double y, double w, double h, SDL_Renderer* renderer) {
					sp = Sprite(file, x, y, w, h, false, renderer); 
					this->rect = { x,y,w,h }; 
				}
				GameObject(double x, double y, double w, double h) {
					//sp = Sprite(file, x, y, w, h, false, renderer);
					this->rect = { x,y,w,h };
				}
			};
		}
	}
}