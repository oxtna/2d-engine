#include "Window.h"
#include "SDL2/SDL_image.h"

Window::Window(const char* title, int w, int h) {
	m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, 0);
	if (m_window == NULL) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Unable to create a window: %s", SDL_GetError());
	}
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (m_renderer == NULL) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Unable to create a renderer: %s", SDL_GetError());
	}
}

Window::~Window() {
	if (m_renderer != NULL) {
		SDL_DestroyRenderer(m_renderer);
	}
	if (m_window != NULL) {
		SDL_DestroyWindow(m_window);
	}
}

SDL_Texture* Window::loadTexture(const char* filepath) {
	SDL_Texture* texture = IMG_LoadTexture(m_renderer, filepath);
	if (texture == NULL) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Unable to load a texture: %s", IMG_GetError());
	}
	return texture;
}

void Window::clear() {
	if (SDL_RenderClear(m_renderer)) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Unable to clear the rendering target: %s", SDL_GetError());
	}
}

void Window::render(Entity* entity) {
	SDL_Rect src = entity->getBoundingBox();
	SDL_Rect dst = src;
	if (SDL_RenderCopy(m_renderer, entity->getTexture(), &src, &dst)) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Unable to render a texture: %s", SDL_GetError());
	}
}

void Window::display() {
	SDL_RenderPresent(m_renderer);
}
