#include "InputManager.h"

const Uint8* InputManager::_keyboardState = SDL_GetKeyboardState(nullptr);

Vector2 InputManager::GetMousePosition() {
	int x, y;
	SDL_GetMouseState(&x, &y);
	return Vector2(static_cast<float>(x), static_cast<float>(y));
}

bool InputManager::IsKeyPressed(Key key) {
	return _keyboardState[static_cast<int>(key)];
}

bool InputManager::IsModPressed(Mod mod) {
	return SDL_GetModState() & static_cast<int>(mod);
}
