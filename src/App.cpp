#include "App.h"
#include "SDL2/SDL_image.h"

App::App(const char* name)
	: _window(name, _windowWidth, _windowHeight) {
	if (SDL_Init(SDL_INIT_VIDEO)) {
		SDL_LogCritical(SDL_LOG_CATEGORY_ERROR,
			"Unable to initialize SDL: %s", SDL_GetError());
	}
	if (!IMG_Init(IMG_INIT_PNG)) {
		SDL_LogCritical(SDL_LOG_CATEGORY_ERROR,
			"Unable to initialize SDL_image: %s", IMG_GetError());
	}
}

App::~App() {
	SDL_Quit();
}

void App::MainLoop() {
	SDL_Event event;
	while (_running) {
		while (SDL_PollEvent(&event)) {
			// Log event timestamps in a `(minutes:seconds:milliseconds)` format
			SDL_Log("Event (%u:%02u:%03u)", event.common.timestamp / 60'000,
				event.common.timestamp / 1000 % 60, event.common.timestamp % 1000);
			if (event.type == SDL_QUIT) {
				_running = false;
			}
		}
		_window.Clear();
		_window.Display();
	}
}
