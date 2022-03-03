#pragma once
#include "IEntity.h"

class Rect : public IEntity
{
private:
	Vector2 _position;
	Vector2 _size;
	SDL_Texture* _texture;
	SDL_Rect _textureRect;
public:
	Rect(Vector2 position, Vector2 size, SDL_Texture* texture);
	Vector2 getPosition() const override;
	Vector2 getSize() const override;
	SDL_Texture* getTexture() const override;
	SDL_Rect getTextureRect() const override;
	bool checkCollision(const IEntity& other) const override;
};
