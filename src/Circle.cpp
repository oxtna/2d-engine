#include "Circle.h"

Circle::Circle(Vector2 center, float radius, SDL_Texture* texture)
	: _center(center), _radius(radius), _texture(texture),
	_textureRect({ static_cast<int>(center.getX() - radius), static_cast<int>(center.getY() - radius),
		static_cast<int>(radius * 2), static_cast<int>(radius * 2) }) {
}

EntityType Circle::getType() const {
	return _type;
}

Vector2 Circle::getPosition() const {
	return Vector2(_center.getX() - _radius, _center.getY() - _radius);
}

Vector2 Circle::getSize() const {
	return Vector2(_radius * 2, _radius * 2);
}

SDL_Texture* Circle::getTexture() const {
	return _texture;
}

SDL_Rect Circle::getTextureRect() const {
	return _textureRect;
}

bool Circle::checkCollision(const IEntity& other) const {
	return (this->_center.getX() + this->_radius >= other.getPosition().getX() &&
		this->_center.getX() - this->_radius <= other.getPosition().getX() + other.getSize().getX() &&
		this->_center.getY() + this->_radius >= other.getPosition().getY() &&
		this->_center.getY() - this->_radius <= other.getPosition().getY() + other.getSize().getY());
}
