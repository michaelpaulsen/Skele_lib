#pragma once
namespace Skele_lib{
	namespace GameEngine {
		namespace Physics {
			enum GravityDirection {
				UP = 1,
				DOWN = 3,
				RIGHT = 2,
				LEFT = 4
			};
			enum CollisionType {
				BOUNCE = 1,
				REFLECT = 2,
				PUSH = 3,
				DAMPEN = 4,
				INTERACT = 5
			};
			enum physicsMode {
				ignore, /*skip this in the physics loop */
				dynamic,/* fully act on this object */
				collide,/*make it so that this object collides with other objects but not move*/
			};
			struct Physics_rect {
				double x, y, w, h;
			};
			struct movable {
				double velx, vely, accx, accy;  
			};
		}
	}
}	

