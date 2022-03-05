#pragma once
#include "IEntity.h"

class Rect : public IEntity
{
private:
	static const EntityType _type = EntityType::Rect;
	Vector2 _position;
	Vector2 _size;
	SDL_Texture* _texture;
	SDL_Rect _textureRect;
public:
	Rect(Vector2 position, Vector2 size, SDL_Texture* texture);
	EntityType GetType() const override;
	Vector2 GetPosition() const override;
	Vector2 GetSize() const override;
	SDL_Texture* GetTexture() const override;
	SDL_Rect GetTextureRect() const override;
	bool CheckCollision(const IEntity& other) const override;
	void Update() override;
};
