#include "Renderer.h"
#include "SDL2/SDL_image.h"

Renderer::Renderer(SDL_Window* window) {
	_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (_renderer == NULL) {
		SDL_Log("Unable to create a renderer: %s", SDL_GetError());
	}
}

Renderer::~Renderer() {
	if (_renderer != NULL) {
		SDL_DestroyRenderer(_renderer);
	}
}

SDL_Texture* Renderer::LoadTexture(const char* filepath) {
	SDL_Texture* texture = IMG_LoadTexture(_renderer, filepath);
	if (texture == NULL) {
		SDL_Log("Unable to load a texture: %s", IMG_GetError());
	}
	return texture;
}

void Renderer::Clear() {
	if (SDL_RenderClear(_renderer)) {
		SDL_Log("Unable to clear the rendering target: %s", SDL_GetError());
	}
}

void Renderer::RenderEntity(const IEntity& entity) {
	SDL_Rect src = entity.GetTextureFrame();
	SDL_Rect dst = {
		static_cast<int>(entity.GetPosition().X),
		static_cast<int>(entity.GetPosition().Y),
		static_cast<int>(entity.GetSize().X),
		static_cast<int>(entity.GetSize().Y)
	};
	if (SDL_RenderCopy(_renderer, entity.GetTexture(), &src, &dst)) {
		SDL_Log("Unable to render a texture: %s", SDL_GetError());
	}
}

void Renderer::Display() {
	SDL_RenderPresent(_renderer);
}
