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
	virtual EntityType GetEntityType() const = 0;
	virtual Vector2 GetPosition() const = 0;
	virtual Vector2 GetSize() const = 0;
	virtual SDL_Texture* GetTexture() const = 0;
	virtual SDL_Rect GetTextureFrame() const = 0;
	// TODO: Change this to a scripting update
	virtual void Update() = 0;
};
