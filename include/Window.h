#pragma once
#include "SDL2/SDL.h"
#include "IEntity.h"

class Window
{
private:
	SDL_Window* _window;
public:
	Window(const char* name, int w, int h);
	~Window();
	SDL_Window* GetWindow() const;
};
