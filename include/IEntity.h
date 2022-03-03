#pragma once
#include "SDL2/SDL.h"
#include "Vector2.h"

enum class EntityType
{
	Rect,
	Circle
};

class IEntity
{
public:
	virtual ~IEntity() = default;
	virtual EntityType getType() const = 0;
	virtual Vector2 getPosition() const = 0;
	virtual Vector2 getSize() const = 0;
	virtual SDL_Texture* getTexture() const = 0;
	virtual SDL_Rect getTextureRect() const = 0;
	virtual bool checkCollision(const IEntity& other) const = 0;
};
