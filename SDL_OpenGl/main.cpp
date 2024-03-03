#include <format>
#include <iostream>
#include "headers\gl\GL_main.hpp"
#include <glad\glad.h>
//Screen dimension constants
//TODO make these not constant
//TODO make these not global 

constexpr          int SCREEN_WIDTH = 640;
constexpr          int SCREEN_HEIGHT = 480;
constexpr          int W_POS_UNDIFINED = SDL_WINDOWPOS_UNDEFINED;
constexpr unsigned int W_USE_GL = SDL_WINDOW_OPENGL;

void PANIC(size_t type, std::string msg, size_t line, const char file[]) {
	std::cout << std::format("in file {} -> ", file);
	if (type == 1) {
		std::cout << std::format("Fatal SDL ERROR : {} ", msg);
	}
	if (type == 2) {
		std::cout << std::format("Fatal OpenGL ERROR : {} ", msg);

	}
	std::cout << std::format("-> line {}\n", line);

}
void init_SDL() {
	auto init_val = SDL_Init(SDL_INIT_VIDEO);
	if (init_val < 0)
	{
		std::cout << std::format("SDL could not initialize! SDL_Error: {}\n", SDL_GetError());
		exit(init_val);
	}
}
void CreateGLWindow(SDL_Window* window, SDL_GLContext& glctx) {
	window = SDL_CreateWindow("SDL OGL base",
		W_POS_UNDIFINED, W_POS_UNDIFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		W_USE_GL);
	if (window == nullptr) {
		PANIC(1, SDL_GetError(), __LINE__, __FILE__);
		SDL_Quit();
		exit(1);
	}
	//create a OGL context 
	glctx = SDL_GL_CreateContext(window);
	if (glctx == nullptr) {
		PANIC(1, SDL_GetError(), __LINE__, __FILE__);
		SDL_DestroyWindow(window);
		SDL_Quit();
		exit(2);
	}
	if (!gladLoadGLLoader(SDL_GL_GetProcAddress)) {
		PANIC(2, "glad Failed to load!", __LINE__, __FILE__);
	}
	DUMP_VENDOR_INFO();
}

int main(int argc, char* args[])
{
//--init--
	init_SDL();
	//set the OGL attrib 
	glSetGlAttr(); 
	//Create window 
	//type -> SDL_Window*
	SDL_Window* window = nullptr;
	SDL_GLContext gl_ctx = {};
	CreateGLWindow(window, gl_ctx); 
//--Event Loop -- 
	
	// SDL_Event  is a union of all of the events that SDL can handle 
	SDL_Event e;
	//should we close the window 
	// TODO RENAME : quit -> shouldExitProgram 
	bool quit = false; 
	while (quit == false) { 
		while (SDL_PollEvent(&e)) {
	//While there is events to poll get the 
	//current even and put it into e 
			switch (e.type) { 
			//switch on the type of event
			case SDL_QUIT: {
				//if the event is a quit event then set quit to true
				quit = true;
				break; 
			}
			}
		}
	}
//Destroy window
	SDL_DestroyWindow(window);
	
//Quit SDL subsystems
	SDL_Quit();
	return 0;
}
