#pragma once
#include "SDL2/SDL.h"
#include "IEntity.h"

class Window
{
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
public:
	Window(const char* name, int w, int h);
	~Window();
	// Create a new texture using the specified file and return a pointer to it or NULL
	// Specified files should be in one of the formats initialized by the App object
	SDL_Texture* LoadTexture(const char* filepath);
	void Clear();
	void Render(const IEntity& entity);
	void Display();
};
