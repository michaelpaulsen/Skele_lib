#pragma once
#include ".\Sprite.h"
namespace Skele_lib {
    namespace GameEngine {
        namespace Physics {
            enum GravityDirection {
                UP = 1,
                DOWN = 3,
                RIGHT = 2,
                LEFT = 4
            };
            struct RigidBody {
#if vector2d
                V2dD velocity;
                V2dD acceleration;
                V2dD targetSpeed;
                V2dD location;
                V2dD worldGravity;
#else 
                double velocityx, velocityy, accelerationx, accelerationy, targetSpeedx, targetSpeedy, worldGravityx, worldGravityy, x, y;
#endif
                Sprite sprite;
                void LoadSprite(const char* file, int x, int y, int w, int h) {
                    sprite = Sprite(file, x, y, w, h);

                }
                void SetGravityDir(GravityDirection newGravityDir) {
#if vector2d

                    if (newGravityDir == GravityDirection::UP) {
                        worldGravity.y = -1;
                        return;
                    }
                    if (newGravityDir == GravityDirection::DOWN) {
                        worldGravity.y = 1;
                        return;
                    }
                    if (newGravityDir == GravityDirection::LEFT) {
                        worldGravity.x = -1;
                        return;
                    }
                    if (newGravityDir == GravityDirection::RIGHT) {
                        worldGravity.x = -1;
                        return;
                    }
                    
#else 

                    if (newGravityDir == GravityDirection::UP) {
                        worldGravityy = -1;
                        return;
                    }
                    if (newGravityDir == GravityDirection::DOWN) {
                        worldGravityy = 1;
                        return;
                    }
                    if (newGravityDir == GravityDirection::LEFT) {
                        worldGravityx = -1;
                        return;
                    }
                    if (newGravityDir == GravityDirection::RIGHT) {
                        worldGravityx = -1;
                        return;
                    }
#endif
                }
                virtual void Tick(float FelapsedTime, int W_w, int W_h) = 0;
                virtual void CaculateVelocity(float FelapsedTime, double t) {
                    //PARAMA: t doesn't need to be used so I put it in here for delayed lerp and cubic interpolation types of acceleration curves 
                    // I also made implemented a delayed learp 
#if vector2d 
                    if (velocity.x / targetSpeed.x < t / targetSpeed.x) {
                        velocity.x += acceleration.x;
                    }
                    else {
                        if (acceleration.x > 0) {
                            velocity.x += --acceleration.x;
                        }
                    }
                    velocity.x += worldGravity.x;
                    if (velocity.y / targetSpeed.y < t / targetSpeed.y) {
                        velocity.y -= acceleration.y;
                    }
                    else {
                        if (acceleration.y > 0) {
                            velocity.y -= --acceleration.y;
                        }
                        else {
                            velocity.y -= ++acceleration.y;

                        }
                    }
                    velocity.y += worldGravity.y; 
#else 
                    if (velocityx / targetSpeedx < t / targetSpeedx) {
                        velocityx +=   accelerationx;
                    }
                    else {
                        if (accelerationx > 0){
                            velocityx += --accelerationx;
                        }
                        else {
                            velocityx += ++accelerationx;
                        }
                    }
                    velocityx += worldGravityx;
                    if (velocityy / targetSpeedy < t / targetSpeedy) {
                        velocityy +=   accelerationy;
                    }
                    else {
                        if (accelerationy > 0) {
                            velocityy += --accelerationy;
                        }
                        else {
                            velocityy += ++accelerationy;
                        }
                    }


#endif
                }
            };

        }
    }
}