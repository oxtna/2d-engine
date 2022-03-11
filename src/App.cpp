#include "App.h"
#include "SDL2/SDL_image.h"
#include "InputManager.h"

App::App(const char* name)
	: _window(name, _windowWidth, _windowHeight), _renderer(_window.GetWindow()),
	_sceneRoot(SceneNode::CreateRoot()) {
	if (SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
	}
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		SDL_Log("Unable to initialize SDL_image: %s", IMG_GetError());
	}
	
#ifdef _DEBUG
	Test();
#endif
}

App::~App() {
	SDL_Quit();
}

void App::Test() {
	_sceneRoot.AddBox({ 100.0f, 100.0f, 200.0f, 200.0f }, _entityManager, _physicsManager);
	_sceneRoot.AddBody(_physicsManager, BodyType::Kinematic, Vector2(0.0f, 0.0f));
	SDL_Texture* texture = _renderer.LoadTexture("test/test.png");
	SDL_Point point{ 0, 0 };
	if (SDL_QueryTexture(texture, nullptr, nullptr, &point.x, &point.y)) {
		SDL_Log("Unable to query texture: %s", SDL_GetError());
	}
	_sceneRoot.AddEntity(_entityManager, texture, { 0, 0, point.x, point.y });
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

		// Test input
		Vector2 velocity(0.0f, 0.0f);
		float speed = 100.0f;
		if (InputManager::IsKeyPressed(Key::W) || InputManager::IsKeyPressed(Key::Up)) {
			velocity.Y -= speed;
		}
		if (InputManager::IsKeyPressed(Key::S) || InputManager::IsKeyPressed(Key::Down)) {
			velocity.Y += speed;
		}
		if (InputManager::IsKeyPressed(Key::A) || InputManager::IsKeyPressed(Key::Left)) {
			velocity.X -= speed;
		}
		if (InputManager::IsKeyPressed(Key::D) || InputManager::IsKeyPressed(Key::Right)) {
			velocity.X += speed;
		}
		_sceneRoot.GetBody()->SetVelocity(velocity.Normalize() * speed);

		while (elapsedTime >= _updateTimeStep) {
			_physicsManager.UpdatePhysics();
			_entityManager.Update();
			elapsedTime -= _updateTimeStep;
		}
		_renderer.Clear();
		auto& entities = _entityManager.GetEntities();
		for (const auto& entity : entities) {
			if (auto e = entity.lock()) {
				_renderer.RenderEntity(*e);
			}
		}
		_renderer.Display();
	}
}
