#include "Rect.h"

Rect::Rect(Vector2 position, Vector2 size, SDL_Texture* texture)
	: _position(position), _size(size), _texture(texture),
	_textureRect({ static_cast<int>(position.GetX()), static_cast<int>(position.GetY()),
		static_cast<int>(size.GetX()), static_cast<int>(size.GetY()) }) {
}

EntityType Rect::GetType() const {
	return _type;
}

Vector2 Rect::GetPosition() const {
	return _position;
}

Vector2 Rect::GetSize() const {
	return _size;
}

SDL_Texture* Rect::GetTexture() const {
	return _texture;
}

SDL_Rect Rect::GetTextureRect() const {
	return _textureRect;
}

bool Rect::CheckCollision(const IEntity& other) const {
	return (this->_position.GetX() + this->_size.GetX() >= other.GetPosition().GetX() &&
		this->_position.GetX() <= other.GetPosition().GetX() + other.GetSize().GetX() &&
		this->_position.GetY() + this->_size.GetY() >= other.GetPosition().GetY() &&
		this->_position.GetY() <= other.GetPosition().GetY() + other.GetSize().GetY());
}

void Rect::Update() {
}
