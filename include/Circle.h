#pragma once
#include "IEntity.h"

class Circle : public IEntity
{
private:
	Vector2 _center;
	float _radius;
	SDL_Texture* _texture;
	SDL_Rect _textureRect;
public:
	Circle(Vector2 center, float radius, SDL_Texture* texture);
	Vector2 getPosition() const override;
	Vector2 getSize() const override;
	SDL_Texture* getTexture() const override;
	SDL_Rect getTextureRect() const override;
	bool checkCollision(const IEntity& other) const override;
};
