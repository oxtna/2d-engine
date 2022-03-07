#include "Window.h"
#include "SDL2/SDL_image.h"

Window::Window(const char* title, int w, int h) {
	_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, 0);
	if (_window == NULL) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR,
			"Unable to create a window: %s", SDL_GetError());
	}
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (_renderer == NULL) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR,
			"Unable to create a renderer: %s", SDL_GetError());
	}
}

Window::~Window() {
	if (_renderer != NULL) {
		SDL_DestroyRenderer(_renderer);
	}
	if (_window != NULL) {
		SDL_DestroyWindow(_window);
	}
}

SDL_Texture* Window::LoadTexture(const char* filepath) {
	SDL_Texture* texture = IMG_LoadTexture(_renderer, filepath);
	if (texture == NULL) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR,
			"Unable to load a texture: %s", IMG_GetError());
	}
	return texture;
}

void Window::Clear() {
	if (SDL_RenderClear(_renderer)) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR,
			"Unable to clear the rendering target: %s", SDL_GetError());
	}
}

void Window::Render(const IEntity& entity) {
	SDL_Rect src = {};
	SDL_Rect dst = src;
	if (SDL_RenderCopy(_renderer, entity.GetTexture(), &src, &dst)) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR,
			"Unable to render a texture: %s", SDL_GetError());
	}
}

void Window::Display() {
	SDL_RenderPresent(_renderer);
}
