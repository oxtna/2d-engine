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
	// Get the entity type specific for each class implementing this interface
	virtual EntityType GetType() const = 0;
	virtual Vector2 GetPosition() const = 0;
	virtual Vector2 GetSize() const = 0;
	virtual SDL_Texture* GetTexture() const = 0;
	// Get the AABB of the entity as an SDL_Rect
	virtual SDL_Rect GetTextureRect() const = 0;
	// Check collision using AABBs of the entities
	virtual bool CheckCollision(const IEntity& other) const = 0;
};
