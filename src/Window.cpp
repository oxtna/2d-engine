#include "Window.h"

Window::Window(const char* title, int w, int h) {
	m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, 0);
	if (m_window == NULL) {
		SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "Unable to create a window: %s", SDL_GetError());
	}
}

Window::~Window() {
	if (m_window != NULL) {
		SDL_DestroyWindow(m_window);
	}
}
