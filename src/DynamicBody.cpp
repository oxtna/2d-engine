#include "DynamicBody.h"

DynamicBody::DynamicBody(std::shared_ptr<Box> box, Vector2 velocity)
	: _AABB(box), _velocity(velocity) {
}

BodyType DynamicBody::GetBodyType() const {
	return _bodyType;
}

Vector2 DynamicBody::GetPosition() const {
	return _AABB->GetPosition();
}

Vector2 DynamicBody::GetSize() const {
	return _AABB->GetSize();
}

Vector2 DynamicBody::GetCenter() const {
	return _AABB->GetCenter();
}

Vector2 DynamicBody::GetVelocity() const {
	return _velocity;
}

void DynamicBody::SetVelocity(Vector2 velocity) {
	_velocity = velocity;
}

Box DynamicBody::GetAABB() const {
	return *_AABB;
}

bool DynamicBody::CheckCollision(const IBody& other) const {
	return (this->_AABB->GetX() + this->_AABB->GetW() >= other.GetAABB().GetX() &&
		this->_AABB->GetX() <= other.GetAABB().GetX() + other.GetAABB().GetW() &&
		this->_AABB->GetY() + this->_AABB->GetH() >= other.GetAABB().GetY() &&
		this->_AABB->GetY() <= other.GetAABB().GetY() + other.GetAABB().GetH());
}

void DynamicBody::UpdatePhysics(float deltaTime) {
	_AABB->Translate(_velocity * deltaTime);
}
