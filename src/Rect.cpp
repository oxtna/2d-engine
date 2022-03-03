#include "Rect.h"

Rect::Rect(Vector2 position, Vector2 size, SDL_Texture* texture)
	: _position(position), _size(size), _texture(texture) {
}

SDL_Texture* Rect::getTexture() const {
	return _texture;
}

SDL_Rect Rect::getTextureRect() const {
	SDL_Rect tr = {
		static_cast<int>(_position.getX()),
		static_cast<int>(_position.getY()),
		static_cast<int>(_size.getX()),
		static_cast<int>(_size.getY())
	};
	return tr;
}

bool Rect::checkCollision(const IEntity& other) const {
	SDL_Rect result;
	SDL_Rect a = this->getTextureRect();
	SDL_Rect b = other.getTextureRect();
	return SDL_IntersectRect(&a, &b, &result);
}
