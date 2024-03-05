#pragma once 
#include <glad/glad.h>
#include <format>
#include <iostream>
#include <SDL.h>
static void glSetGlAttr() {
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(
		SDL_GL_CONTEXT_PROFILE_MASK,
		SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
}
static void DUMP_VENDOR_INFO() {
	std::string v_info = "";
	v_info += std::format("vendor        : {}\n", (char*)glGetString(GL_VENDOR));
	v_info += std::format("render device : {}\n", (char*)glGetString(GL_RENDERER));
	v_info += std::format("version       : {}\n", (char*)glGetString(GL_VERSION));
	v_info += std::format("language      : {}\n", (char*)glGetString(GL_SHADING_LANGUAGE_VERSION));
	std::cout << v_info;

}
