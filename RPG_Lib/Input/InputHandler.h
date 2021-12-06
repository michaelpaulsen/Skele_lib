#pragma once
#include <SDL.h>
#include "..\..\Skele_lib\RPG_Lib\Input\CNTRL_KEY_STATES.hpp"
#include "..\gameobjects\Player.hpp"
namespace Skele_lib {
    namespace GameEngine {
        namespace Input {
            static struct input_t {
                long UP_K     = SDLK_w;
                long LEFT_K   = SDLK_a;
                long RIGHT_K  = SDLK_d;
                long DOWN_K   = SDLK_s;
                long ACTION_K = SDLK_KP_ENTER;
                long state; 
                void setState(SDL_Event eventHandler) {
                    state = eventHandler.type; 
                }
                bool RequestExit(SDL_Event eventHandler, bool& exit) {
                    setState(eventHandler); 
                    //User requests quit
                    exit = (state == SDL_QUIT);
                    return exit;
                }
                virtual void Move (SDL_Event eventHandler,GameObject::Player& player) {
                    setState(eventHandler);
                    if (state == SDL_KEYDOWN) {
                        auto ksym = eventHandler.key.keysym; // wft why does this have to be so verbose  
                        auto keycode = ksym.sym;
                        auto keymod = ksym.mod;
                        // alows us to chek if the key has modifyers 
                        ctrl_keys.set(keymod);
                        if (keycode == SDLK_w) {
                            /// move the player left 
                            player.rect.y--;
                        }
                        if (keycode == SDLK_s) {
                            /// move the player left 
                            player.rect.y++;
                        }
                        if (keycode == SDLK_a) {
                            /// move the player left 
                            player.rect.x--; 
                        }
                        if (keycode == SDLK_d) {
                            player.rect.x++;
                            // move the player right    
                        }
                        printf(" key code: %i \t modifyers : keymod = %d  lalt %d ralt %d lctrl %d rctrl %d\n ",
                            keycode, keymod, ctrl_keys.lalt, ctrl_keys.ralt,ctrl_keys.lctrl, ctrl_keys.rctrl);
                    }
                }
                virtual void OnMousePress(SDL_Event eventHandler) {
                    setState(eventHandler); 
                    if (state == SDL_MOUSEBUTTONDOWN) {
                        auto x = eventHandler.button.x;
                        auto y = eventHandler.button.y;
                        printf("x: %d, y:%d, atan(x/y) %f \n", x, y, atan((double)x / (double)y));
                    }

                }
            } InputHandler;
        }
    }
}