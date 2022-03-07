#include "Circle.h"

Circle::Circle(Box box, BodyType bodyType, SDL_Texture* texture)
	: _AABB(box), _bodyType(bodyType), _texture(texture), _velocity(0, 0) {
}

Circle::Circle(Vector2 center, float radius, BodyType bodyType, SDL_Texture* texture)
	: _AABB(center.GetX() - radius, center.GetY() - radius, radius * 2, radius * 2),
	_bodyType(bodyType), _texture(texture), _velocity(0, 0) {
}

Circle::Circle(float x, float y, float radius, BodyType bodyType, SDL_Texture* texture)
	: _AABB(x - radius, y - radius, radius * 2, radius * 2),
	_bodyType(bodyType), _texture(texture), _velocity(0, 0) {
}

EntityType Circle::GetEntityType() const {
	return _entityType;
}

BodyType Circle::GetBodyType() const {
	return _bodyType;
}

float Circle::GetRadius() const {
	return _AABB.GetW() / 2;
}

Vector2 Circle::GetPosition() const {
	return _AABB.GetPosition();
}

Vector2 Circle::GetSize() const {
	return _AABB.GetSize();
}

Vector2 Circle::GetCenter() const {
	return _AABB.GetCenter();
}

Vector2 Circle::GetVelocity() const {
	return _velocity;
}

void Circle::SetVelocity(Vector2 velocity) {
	_velocity = velocity;
}

Box Circle::GetAABB() const {
	return _AABB;
}

SDL_Texture* Circle::GetTexture() const {
	return _texture;
}

bool Circle::CheckCollision(const IBody& other) const {
	return (this->_AABB.GetX() + this->_AABB.GetW() >= other.GetAABB().GetX() &&
		this->_AABB.GetX() <= other.GetAABB().GetX() + other.GetAABB().GetW() &&
		this->_AABB.GetY() + this->_AABB.GetH() >= other.GetAABB().GetY() &&
		this->_AABB.GetY() <= other.GetAABB().GetY() + other.GetAABB().GetH());
}

void Circle::Update() {
}
