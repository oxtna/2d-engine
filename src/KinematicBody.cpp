#include "KinematicBody.h"

KinematicBody::KinematicBody(std::shared_ptr<Box> box, Vector2 velocity)
	: _AABB(box), _velocity(velocity) {
}

BodyType KinematicBody::GetBodyType() const {
	return _bodyType;
}

Vector2 KinematicBody::GetPosition() const {
	return _AABB->GetPosition();
}

Vector2 KinematicBody::GetSize() const {
	return _AABB->GetSize();
}

Vector2 KinematicBody::GetCenter() const {
	return _AABB->GetCenter();
}

Vector2 KinematicBody::GetVelocity() const {
	return _velocity;
}

void KinematicBody::SetVelocity(Vector2 velocity) {
	_velocity = velocity;
}

Box KinematicBody::GetAABB() const {
	return *_AABB;
}

bool KinematicBody::CheckCollision(const IBody& other) const {
	return (this->_AABB->GetX() + this->_AABB->GetW() >= other.GetAABB().GetX() &&
		this->_AABB->GetX() <= other.GetAABB().GetX() + other.GetAABB().GetW() &&
		this->_AABB->GetY() + this->_AABB->GetH() >= other.GetAABB().GetY() &&
		this->_AABB->GetY() <= other.GetAABB().GetY() + other.GetAABB().GetH());
}

void KinematicBody::UpdatePhysics(float deltaTime) {
	_AABB->Translate(_velocity * deltaTime);
}
