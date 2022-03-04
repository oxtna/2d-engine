#pragma once
#include "Window.h"
#include "EntityManager.h"

class App
{
private:
	const int _windowWidth = 1280;
	const int _windowHeight = 720;
	Window _window;
	bool _running = true;
	EntityManager _entityManager;

public:
	App(const char* name);
	~App();
	void MainLoop();
};
