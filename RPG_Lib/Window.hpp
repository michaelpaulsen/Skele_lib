#pragma once 
#include <stdio.h>
#include <SDL.h>
#include <vector>
#include "../Color.hpp"
#include "Physics.hpp"
#include <chrono>
#include <math.h>
namespace Skele_lib {
    namespace GameEngine {

        class Window {
            SDL_Surface* screenSurface = NULL;
            SDL_Window* window = NULL;
            SDL_Rect* screenRect = NULL; 
            std::chrono::time_point<std::chrono::system_clock> t1 = std::chrono::system_clock::now();
            static void errormsg(int error) {
                printf("error code %d reached", error);
            }
            std::vector<Physics::RigidBody*> actors; 
        public:
            Window(const char* name, const int size_w, const int size_h) {
                screenRect = new SDL_Rect; 
                screenRect->x = 0; 
                screenRect->y = 0; 
                screenRect->h = size_h;
                screenRect->w = size_w;
                if (SDL_Init(SDL_INIT_VIDEO) < 0)
                {
                    errormsg(-1);
                }
                else
                {
                    //Create window
           
                    window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                              screenRect->w,screenRect->h, SDL_WINDOW_SHOWN);
                    if (window == NULL)
                    {
                        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
                    }
                    else
                    {
                        //Get window surface
                        screenSurface = SDL_GetWindowSurface(window);
                    }
                }
            }
            void UpdateAll() {
                auto t2 = std::chrono::system_clock::now();
                std::chrono::duration<float> FelapsedTime = std::chrono::duration_cast<std::chrono::seconds>(t1-t2);
                for (auto x : actors) {
                    t2 = std::chrono::system_clock::now();
                    FelapsedTime = (t2.time_since_epoch() - t1.time_since_epoch());
                    x->Tick(FelapsedTime.count()    , screen_width, screen_hieght);
                }
                t1 = t2;


            }
            /*bool DrawFilledRect(const SDL_Rect* rect, Uint32 color) {
                Color::Color_t c = Color::Color_t(color);
                if (screenSurface != NULL) {
                    SDL_FillRect(screenSurface, rect, SDL_MapRGB(screenSurface->format, c.r, c.g, c.b));
                }
                return screenSurface != NULL; 
            }
            bool DrawFilledRectChord(int x, int y, int w, int h, Uint32 color) {
                SDL_Rect* rect = new SDL_Rect; 
                rect->x = x; 
                rect->y = y; 
                rect->w = w; 
                rect->h = h; 

                if (screenSurface != NULL) {
                    SDL_FillRect(screenSurface, rect, SDL_MapRGB(screenSurface->format, color & 0xFF << 16, color & 0xFF << 8, color & 0xFF));                   
                }
                return screenSurface != NULL; 
            }
            */
            void UpdateScreen() {
                SDL_UpdateWindowSurface(window);
            }
            auto DrawSurface(SDL_Surface* sin, SDL_Rect* rin = NULL) {
                SDL_BlitSurface(sin, rin, screenSurface, screenRect);
            }
            void AddRigidBody(Physics::RigidBody* rb) {
                actors.push_back(rb);
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