#pragma once
#include "SDL2/SDL.h"
#include "Entity.h"

class Renderer
{
private:
	SDL_Renderer* _renderer;
public:
	Renderer(SDL_Window* window);
	~Renderer();
	// Create a new texture using the specified file and return a pointer to it or NULL
	// Specified files should be in one of the formats initialized by the App object
	SDL_Texture* LoadTexture(const char* filepath);
	void Clear();
	void RenderEntity(const Entity& entity);
	void Display();
};
