#pragma once
#include "SDL2/SDL.h"
#include "Vector2.h"

class IEntity
{
public:
	virtual ~IEntity() = default;
	virtual Vector2 getPosition() const = 0;
	virtual Vector2 getSize() const = 0;
	virtual SDL_Texture* getTexture() const = 0;
	virtual SDL_Rect getTextureRect() const = 0;
	virtual bool checkCollision(const IEntity& other) const = 0;
};
