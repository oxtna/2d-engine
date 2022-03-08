#include "Window.h"
#include "SDL2/SDL_image.h"

Window::Window(const char* title, int w, int h) {
	_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, 0);
	if (_window == NULL) {
		SDL_Log("Unable to create a window: %s", SDL_GetError());
	}
}

Window::~Window() {
	if (_window != NULL) {
		SDL_DestroyWindow(_window);
	}
}

SDL_Window* Window::GetWindow() const {
	return _window;
}
