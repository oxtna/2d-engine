#pragma once
#include "SDL2/SDL.h"

class Window
{
private:
	SDL_Window* m_window;
public:
	Window(const char* name, int w, int h);
	~Window();
};
