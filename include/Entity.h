#pragma once
#include "SDL2/SDL.h"
#include "Box.h"
#include <memory>

// Should probably be renamed to something like Renderable
class Entity
{
private:
	SDL_Rect _textureFrame;
	SDL_Texture* _texture;
	std::shared_ptr<Box> _AABB;
public:
	Entity(std::shared_ptr<Box> box, SDL_Texture* texture, SDL_Rect textureFrame);
	Vector2 GetPosition() const;
	Vector2 GetSize() const;
	SDL_Texture* GetTexture() const;
	const SDL_Rect* GetTextureFrame() const;
	void Update();
};
