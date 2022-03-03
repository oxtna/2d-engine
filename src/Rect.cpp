#include "Rect.h"

Rect::Rect(Vector2 position, Vector2 size, SDL_Texture* texture)
	: _position(position), _size(size), _texture(texture),
	_textureRect({ static_cast<int>(position.getX()), static_cast<int>(position.getY()),
		static_cast<int>(size.getX()), static_cast<int>(size.getY()) }) {
}

Vector2 Rect::getPosition() const {
	return _position;
}

Vector2 Rect::getSize() const {
	return _size;
}

SDL_Texture* Rect::getTexture() const {
	return _texture;
}

SDL_Rect Rect::getTextureRect() const {
	return _textureRect;
}

bool Rect::checkCollision(const IEntity& other) const {
	return (this->_position.getX() + this->_size.getX() >= other.getPosition().getX() &&
		this->_position.getX() <= other.getPosition().getX() + other.getSize().getX() &&
		this->_position.getY() + this->_size.getY() >= other.getPosition().getY() &&
		this->_position.getY() <= other.getPosition().getY() + other.getSize().getY());
}
