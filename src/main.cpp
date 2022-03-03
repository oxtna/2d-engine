#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Window.h"
#include "Entity.h"

int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO)) {
		SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, "Unable to initialize SDL: %s", SDL_GetError());
	}
	if (!IMG_Init(IMG_INIT_PNG)) {
		SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, "Unable to initialize SDL_image: %s", IMG_GetError());
	}
	Window window("Window", 1080, 720);
	SDL_Texture* texture = window.loadTexture("x.png");
	Entity entity(0, 0, texture, 64, 64);
	bool running = true;
	SDL_Event event;
	while (running) {
		while (SDL_PollEvent(&event)) {
			// Log event timestamps in a `(minutes:seconds:milliseconds)` format
			SDL_Log("Event (%u:%02u:%03u)", event.common.timestamp / 60'000,
				event.common.timestamp / 1000 % 60, event.common.timestamp % 1000);
			if (event.type == SDL_QUIT) {
				running = false;
			}
		}
		window.clear();
		window.render(&entity);
		window.display();
	}
	SDL_Quit();
	return 0;
}
