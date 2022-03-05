#include "Circle.h"

Circle::Circle(Vector2 center, float radius, SDL_Texture* texture)
	: _center(center), _radius(radius), _texture(texture),
	_textureRect({ static_cast<int>(center.GetX() - radius), static_cast<int>(center.GetY() - radius),
		static_cast<int>(radius * 2), static_cast<int>(radius * 2) }) {
}

EntityType Circle::GetType() const {
	return _type;
}

Vector2 Circle::GetPosition() const {
	return Vector2(_center.GetX() - _radius, _center.GetY() - _radius);
}

Vector2 Circle::GetSize() const {
	return Vector2(_radius * 2, _radius * 2);
}

SDL_Texture* Circle::GetTexture() const {
	return _texture;
}

SDL_Rect Circle::GetTextureRect() const {
	return _textureRect;
}

bool Circle::CheckCollision(const IEntity& other) const {
	return (this->_center.GetX() + this->_radius >= other.GetPosition().GetX() &&
		this->_center.GetX() - this->_radius <= other.GetPosition().GetX() + other.GetSize().GetX() &&
		this->_center.GetY() + this->_radius >= other.GetPosition().GetY() &&
		this->_center.GetY() - this->_radius <= other.GetPosition().GetY() + other.GetSize().GetY());
}

void Circle::Update() {
}
