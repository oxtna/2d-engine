#pragma once
#include "IEntity.h"
#include "IBody.h"

class Circle : public IEntity, public IBody
{
private:
	static const EntityType _entityType = EntityType::Circle;
	Box _AABB;
	Vector2 _velocity;
	const BodyType _bodyType;
	SDL_Texture* _texture;
public:
	Circle(Box box, BodyType bodyType, SDL_Texture* texture);
	Circle(Vector2 center, float radius, BodyType bodyType, SDL_Texture* texture);
	// Creates a circle with its center in (`x`, `y`) and a radius of `radius`
	Circle(float x, float y, float radius, BodyType bodyType, SDL_Texture* texture);
	EntityType GetEntityType() const override;
	BodyType GetBodyType() const override;
	float GetRadius() const;
	Vector2 GetPosition() const override;
	Vector2 GetSize() const override;
	Vector2 GetCenter() const override;
	Vector2 GetVelocity() const override;
	void SetVelocity(Vector2 velocity) override;
	Box GetAABB() const override;
	SDL_Texture* GetTexture() const override;
	bool CheckCollision(const IBody& other) const override;
	void Update() override;
};
