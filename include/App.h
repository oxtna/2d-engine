#pragma once
#include "Window.h"
#include "Renderer.h"
#include "EntityManager.h"

class App
{
private:
	const int _windowWidth = 1280;
	const int _windowHeight = 720;
	const Uint64 _updateTimeStep = 16;
	Window _window;
	Renderer _renderer;
	EntityManager _entityManager;
	bool _running = true;
public:
	App(const char* name);
	~App();
	void MainLoop();
};
