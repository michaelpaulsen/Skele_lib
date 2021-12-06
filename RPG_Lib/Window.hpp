#pragma once 
#include <stdio.h>
#include <SDL.h>
#include <vector>
#include "../Color.hpp"
#include "./Physics/Physics.hpp"
#include <chrono>
#include <math.h>
namespace Skele_lib {
    namespace GameEngine {

        class Window {
            SDL_Surface* screenSurface = NULL;
            SDL_Window* window = NULL;
            SDL_Rect* screenRect = NULL;
            SDL_Renderer* screenRenderer = NULL;
            std::chrono::time_point<std::chrono::system_clock> t1 = std::chrono::system_clock::now();
            std::vector<Physics::RigidBody*> actors; 
        public:
            Window(const char* name, const int size_w, const int size_h) {
                screenRect = new SDL_Rect; 
                screenRect->x = 0; 
                screenRect->y = 0; 
                screenRect->h = size_h;
                screenRect->w = size_w;
                if(SDL_Init(SDL_INIT_VIDEO) >= 0) {
                    //Create window
                    window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                              screenRect->w,screenRect->h, SDL_WINDOW_SHOWN);
                    screenRenderer = SDL_CreateRenderer(window, 1, SDL_RENDERER_ACCELERATED);
                    if (window == NULL)
                    {
                        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
                    }
                    else
                    {
                        //Get window surface
                        screenSurface = SDL_GetWindowSurface(window);
                    }
                    if (screenRenderer == NULL)
                    {
                        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
                    }
                    else {
                        SDL_SetRenderDrawColor(screenRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                    }
               }
            }
            void UpdateAll() {
                auto t2 = std::chrono::system_clock::now();
                auto FelapsedTime = (t1-t2);
                for (auto x : actors) {
                    t2 = std::chrono::system_clock::now();
                    FelapsedTime = (t2 - t1);
                    x->tick(FelapsedTime, screenRect->w, screenRect->h);
                }
                t1 = t2;


            }
            void ClearScreen(Uint32 color = 0xffffff) {
                SDL_FillRect(this->screenSurface, this->screenRect, color);
            }
            void DrawSurface(SDL_Surface* sin, SDL_Rect* rin = NULL) {
                SDL_BlitSurface(sin, rin, screenSurface, screenRect);
            }
            void AddRigidBody(Physics::RigidBody* rb) {
                actors.push_back(rb);
            }
            void UpdateScreen() {
                SDL_UpdateWindowSurface(window);
            }
            SDL_Surface* GetScreenSurface() {
                return this->screenSurface;
            }
            ~Window() {
                //Destroy window
                SDL_DestroyWindow(window);

                //Quit SDL subsystems
                SDL_Quit();
            }
            
        };

    }
}