#pragma once
#include "IEntity.h"
#include "Vector2.h"

class Rect : public IEntity
{
private:
	Vector2 _position;
	Vector2 _size;
	SDL_Texture* _texture;
public:
	Rect(Vector2 position, Vector2 size, SDL_Texture* texture);
	SDL_Texture* getTexture() const override;
	SDL_Rect getTextureRect() const override;
	bool checkCollision(const IEntity& other) const override;
};
