#pragma once
#include <SDL.h>
namespace Skele_lib {
	namespace GameEngine {
		class Sprite
		{
		public:

			SDL_Surface* getSurface() {
				return this->image;
			}
			auto StoreImage(const char* filename) {
				image = SDL_LoadBMP(filename);
				if (image == NULL)
				{
					printf("Unable to load image %s! SDL Error: %s\n", filename, SDL_GetError());
					return false; 
				}
				return true;
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

		private:
			SDL_Rect* posSize;
			SDL_Surface* image = NULL;
		};
	}
}
