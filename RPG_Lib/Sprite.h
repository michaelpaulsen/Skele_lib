#pragma once
#include <SDL.h>
namespace Skele_lib {
	namespace GameEngine {
		struct Sprite
		{
		public:

			SDL_Surface* getSurface() {
				if(isStatic) return this->image_surface;
				return NULL; 
			}
			void StoreImage(const char* filename) {
				if(isStatic){
					image_surface = SDL_LoadBMP(filename);
					if (image_surface == NULL)
					{
						printf("Unable to load image %s! SDL Error: %s\n", filename, SDL_GetError()); 
					}
				}
				else {

				}
			}
			Sprite() = default;
			Sprite(const char* file, int x, int y, int w, int h) {
				posSize->x = x;
				posSize->y = y;
				posSize->w = w;
				posSize->h = h;
				this->image = SDL_LoadBMP(file);
				if (image == NULL)
				{
					printf("Unable to load image %s! SDL Error: %s\n", file, SDL_GetError());
				}
			};
			SDL_Rect* posSize = new SDL_Rect;
			SDL_Surface* image = NULL;
			union{
				SDL_Texture* image_texture; 
				SDL_Surface* image_surface;
			};
			bool isStatic = true; 
		};
	}
}
