#pragma once
#include "Window.h"
#include "Renderer.h"
#include "EntityManager.h"
#include "PhysicsManager.h"
#include "SceneNode.h"

class App
{
private:
	const int _windowWidth = 1280;
	const int _windowHeight = 720;
	const Uint64 _updateTimeStep = 16;
	Window _window;
	Renderer _renderer;
	EntityManager _entityManager;
	PhysicsManager _physicsManager;
	SceneNode _sceneRoot;
	bool _running = true;
public:
	App(const char* name);
	~App();
	void Test();
	void MainLoop();
};
