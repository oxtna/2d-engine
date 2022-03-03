#pragma once
#include "SDL2/SDL.h"

class IEntity
{
public:
	virtual ~IEntity() = default;
	virtual SDL_Texture* getTexture() const = 0;
	virtual SDL_Rect getTextureRect() const = 0;
	virtual bool checkCollision(const IEntity& other) const = 0;
};
