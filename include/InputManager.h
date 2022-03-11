#pragma once
#include "SDL2/SDL.h"
#include "Vector2.h"

// Ordered so that they have the same value as SDL scancodes
enum class Key {
	_0 = SDL_SCANCODE_0,
	_1, _2, _3, _4, _5, _6, _7, _8, _9,
	A = SDL_SCANCODE_A,
	B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
	Escape = SDL_SCANCODE_ESCAPE,
	Tab = SDL_SCANCODE_TAB,
	Space = SDL_SCANCODE_SPACE,
	Right = SDL_SCANCODE_RIGHT,
	Left, Down, Up
};

enum class Mod {
	Ctrl = KMOD_CTRL,
	Shift = KMOD_SHIFT,
	Alt = KMOD_ALT
};

class InputManager
{
private:
	static const Uint8* _keyboardState;
public:
	static Vector2 GetMousePosition();
	// TODO: Mouse buttons
	static bool IsKeyPressed(Key key);
	static bool IsModPressed(Mod mod);
};
