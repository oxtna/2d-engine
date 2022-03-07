#pragma once
#include "Vector2.h"
#include "Box.h"

enum class BodyType {
	Static,
	Kinematic,
	Dynamic
};

class IBody
{
public:
	virtual ~IBody() = default;
	virtual BodyType GetBodyType() const = 0;
	virtual Vector2 GetPosition() const = 0;
	virtual Vector2 GetSize() const = 0;
	virtual Vector2 GetCenter() const = 0;
	virtual Vector2 GetVelocity() const = 0;
	virtual void SetVelocity(Vector2 velocity) = 0;
	virtual Box GetAABB() const = 0;
	// Check collision using AABBs of the entities
	virtual bool CheckCollision(const IBody& other) const = 0;
	// TODO: Change this to a physics only update
	virtual void Update() = 0;
};
