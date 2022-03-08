#include "Rect.h"

Rect::Rect(Box box, BodyType bodyType, SDL_Texture* texture)
	: _AABB(box), _bodyType(bodyType), _texture(texture), _velocity(0, 0) {
}

Rect::Rect(Vector2 position, Vector2 size, BodyType bodyType, SDL_Texture* texture)
	: _AABB(position, size), _bodyType(bodyType), _texture(texture), _velocity(0, 0) {
}

Rect::Rect(float x, float y, float w, float h, BodyType bodyType, SDL_Texture* texture)
	: _AABB(x, y, w, h), _bodyType(bodyType), _texture(texture), _velocity(0, 0) {
}

EntityType Rect::GetEntityType() const {
	return _entityType;
}

BodyType Rect::GetBodyType() const {
	return _bodyType;
}

Vector2 Rect::GetPosition() const {
	return _AABB.GetPosition();
}

Vector2 Rect::GetSize() const {
	return _AABB.GetSize();
}

Vector2 Rect::GetCenter() const {
	return _AABB.GetCenter();
}

Vector2 Rect::GetVelocity() const {
	return _velocity;
}

void Rect::SetVelocity(Vector2 velocity) {
	_velocity = velocity;
}

Box Rect::GetAABB() const {
	return _AABB;
}

SDL_Texture* Rect::GetTexture() const {
	return _texture;
}

SDL_Rect Rect::GetTextureFrame() const {
	SDL_Rect frame = {
		static_cast<int>(_AABB.GetX()),
		static_cast<int>(_AABB.GetY()),
		static_cast<int>(_AABB.GetW()),
		static_cast<int>(_AABB.GetH())
	};
	return frame;
}

bool Rect::CheckCollision(const IBody& other) const {
	return (this->_AABB.GetX() + this->_AABB.GetW() >= other.GetAABB().GetX() &&
		this->_AABB.GetX() <= other.GetAABB().GetX() + other.GetAABB().GetW() &&
		this->_AABB.GetY() + this->_AABB.GetH() >= other.GetAABB().GetY() &&
		this->_AABB.GetY() <= other.GetAABB().GetY() + other.GetAABB().GetH());
}

void Rect::Update() {
}
