#include "App.h"
#include "SDL2/SDL_image.h"

App::App(const char* name)
	: _window(name, _windowWidth, _windowHeight), _renderer(_window.GetWindow()) {
	if (SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
	}
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		SDL_Log("Unable to initialize SDL_image: %s", IMG_GetError());
	}
}

App::~App() {
	SDL_Quit();
}

void App::MainLoop() {
	SDL_Event event;
	Uint64 previousTime = SDL_GetTicks64();
	Uint64 elapsedTime = 0;
	while (_running) {
		Uint64 currentTime = SDL_GetTicks64();
		elapsedTime += currentTime - previousTime;
		previousTime = currentTime;
		while (SDL_PollEvent(&event)) {
			// Log event timestamps in a `(minutes:seconds:milliseconds)` format
			SDL_Log("Event (%u:%02u:%03u)", event.common.timestamp / 60'000,
				event.common.timestamp / 1000 % 60, event.common.timestamp % 1000);
			if (event.type == SDL_QUIT) {
				_running = false;
			}
		}
		while (elapsedTime >= _updateTimeStep) {
			_entityManager.Update();
			elapsedTime -= _updateTimeStep;
		}
		_renderer.Clear();
		auto& entities = _entityManager.GetEntities();
		for (const auto& entity : entities) {
			_renderer.RenderEntity(*entity);
		}
		_renderer.Display();
	}
}
