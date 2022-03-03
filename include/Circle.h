#pragma once
#include "IEntity.h"

class Circle : public IEntity
{
private:
	static const EntityType _type = EntityType::Circle;
	Vector2 _center;
	float _radius;
	SDL_Texture* _texture;
	SDL_Rect _textureRect;
public:
	Circle(Vector2 center, float radius, SDL_Texture* texture);
	EntityType GetType() const override;
	Vector2 GetPosition() const override;
	Vector2 GetSize() const override;
	SDL_Texture* GetTexture() const override;
	SDL_Rect GetTextureRect() const override;
	bool CheckCollision(const IEntity& other) const override;
};
