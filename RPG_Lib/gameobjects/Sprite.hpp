#pragma once
#include <SDL.h>
namespace Skele_lib {
	namespace GameEngine {
		namespace GameObject {
			struct Sprite
			{
				void SetTexture(const char* filename, SDL_Renderer* renderer) {
					if (!isStatic) {
						/*load sprite*/
						auto tempSurface = SDL_LoadBMP(filename);
						if (tempSurface == NULL)
						{
							printf("Unable to load image %s! SDL_image Error: %s\n", filename, SDL_GetError());
						}
						else
						{
							image_texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
						}
						SDL_FreeSurface(tempSurface); /// free can be used here?
					}
				}
				SDL_Texture* GetTexture() {
					if (!this->isStatic)return this->image_texture;
					return NULL;
				}
				SDL_Surface* GetSurface() {
					if (isStatic) return this->image_surface;
					return NULL;
				}
				void StoreImage(const char* filename) {
					if (isStatic) {
						image_surface = SDL_LoadBMP(filename);
						if (image_surface == NULL)
						{
							printf("Unable to load image %s! SDL Error: %s\n", filename, SDL_GetError());
						}
					}
				}
				Sprite() = default;
				Sprite(const char* file, int x, int y, int w, int h, bool isStatic = true, SDL_Renderer* renderer = NULL) {
					posSize->x = x;
					posSize->y = y;
					posSize->w = w;
					posSize->h = h;
					if (isStatic) {
						this->image_surface = SDL_LoadBMP(file);
						if (image_surface == NULL)
						{
							printf("Unable to load image %s! SDL Error: %s\n", file, SDL_GetError());
						}
					}
					else {
						this->isStatic = false;
						/*load sprite*/
						auto tempSurface = SDL_LoadBMP(file);

						if (tempSurface == NULL)
						{
							printf("Unable to load image %s! SDL_image Error: %s\n", file, SDL_GetError());
						}
						else
						{
							image_texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
						}
						SDL_FreeSurface(tempSurface); /// free can be used here? 
					}
				};
				SDL_Rect* posSize = new SDL_Rect;
				union {
					SDL_Texture* image_texture;
					SDL_Surface* image_surface;
				};
				bool isStatic = true;
			};

		}
	}
}
