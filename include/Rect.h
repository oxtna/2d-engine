#pragma once
#include "IEntity.h"
#include "IBody.h"

class Rect : public IEntity, public IBody
{
private:
	static const EntityType _entityType = EntityType::Rect;
	Box _AABB;
	Vector2 _velocity;
	const BodyType _bodyType;
	SDL_Texture* _texture;
public:
	Rect(Box box, BodyType bodyType, SDL_Texture* texture);
	Rect(Vector2 position, Vector2 size, BodyType bodyType, SDL_Texture* texture);
	Rect(float x, float y, float w, float h, BodyType bodyType, SDL_Texture* texture);
	EntityType GetEntityType() const override;
	BodyType GetBodyType() const override;
	Vector2 GetPosition() const override;
	Vector2 GetSize() const override;
	Vector2 GetCenter() const override;
	Vector2 GetVelocity() const override;
	void SetVelocity(Vector2 velocity) override;
	Box GetAABB() const override;
	SDL_Texture* GetTexture() const override;
	SDL_Rect GetTextureFrame() const override;
	bool CheckCollision(const IBody& other) const override;
	void Update() override;
};
