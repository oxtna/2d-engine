#pragma once
#include "IBody.h"
#include <memory>

class DynamicBody : public IBody
{
private:
	static const BodyType _bodyType = BodyType::Dynamic;
	std::shared_ptr<Box> _AABB;
	Vector2 _velocity;
public:
	DynamicBody(std::shared_ptr<Box> box, Vector2 velocity);
	BodyType GetBodyType() const override;
	Vector2 GetPosition() const override;
	Vector2 GetSize() const override;
	Vector2 GetCenter() const override;
	Vector2 GetVelocity() const override;
	void SetVelocity(Vector2 velocity) override;
	Box GetAABB() const override;
	bool CheckCollision(const IBody& other) const override;
	void UpdatePhysics(float deltaTime) override;
};
