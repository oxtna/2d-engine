#pragma once
#include "SDL2/SDL.h"
#include "Entity.h"

class Window
{
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
public:
	Window(const char* name, int w, int h);
	~Window();
	SDL_Texture* loadTexture(const char* filepath);
	void clear();
	void render(Entity* entity);
	void display();
};
