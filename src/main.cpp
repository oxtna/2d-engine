#include <iostream>
#include "SDL2/SDL.h"
#include "Window.h"

int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO)) {
		SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, "Unable to initialize SDL: %s", SDL_GetError());
	}
	Window window("Window", 1080, 720);
	bool running = true;
	SDL_Event event;
	while (running) {
		while (SDL_PollEvent(&event)) {
			// Log event timestamps in a `(minutes:seconds:milliseconds)` format
			SDL_Log("Event (%u:%02u:%03u)", event.common.timestamp / 60'000, event.common.timestamp / 1000 % 60, event.common.timestamp % 1000);
			if (event.type == SDL_QUIT) {
				running = false;
			}
		}
	}
	SDL_Quit();
	return 0;
}
