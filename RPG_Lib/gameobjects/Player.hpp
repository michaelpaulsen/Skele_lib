#pragma once
#include <SDL.h>
#include "GameObject.hpp"
namespace Skele_lib {
	namespace GameEngine {
		namespace GameObject {
			struct Player : public GameObject {
				Player() = default;
				double x; 
				Player(double x, double y, double w, double h) : GameObject(x, y, w, h){};
			};
		}
	}
}