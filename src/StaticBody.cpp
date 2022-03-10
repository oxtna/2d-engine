#include "StaticBody.h"

StaticBody::StaticBody(std::shared_ptr<Box> box)
	: _AABB(box) {
}

BodyType StaticBody::GetBodyType() const {
	return _bodyType;
}

Vector2 StaticBody::GetPosition() const {
	return _AABB->GetPosition();
}

Vector2 StaticBody::GetSize() const {
	return _AABB->GetSize();
}

Vector2 StaticBody::GetCenter() const {
	return _AABB->GetCenter();
}

Vector2 StaticBody::GetVelocity() const {
	return Vector2(0.0f, 0.0f);
}

void StaticBody::SetVelocity(Vector2 velocity) {
	// TODO: throw a better exception
	throw;
}

Box StaticBody::GetAABB() const {
	return *_AABB;
}

bool StaticBody::CheckCollision(const IBody& other) const {
	return (this->_AABB->GetX() + this->_AABB->GetW() >= other.GetAABB().GetX() &&
		this->_AABB->GetX() <= other.GetAABB().GetX() + other.GetAABB().GetW() &&
		this->_AABB->GetY() + this->_AABB->GetH() >= other.GetAABB().GetY() &&
		this->_AABB->GetY() <= other.GetAABB().GetY() + other.GetAABB().GetH());
}

void StaticBody::UpdatePhysics(float deltaTime) {
}
