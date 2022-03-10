#include "Entity.h"

Entity::Entity(std::shared_ptr<Box> box, SDL_Texture* texture, SDL_Rect textureFrame)
	: _textureFrame(textureFrame),
	_AABB(box), _texture(texture) {
}

Vector2 Entity::GetPosition() const {
	return _AABB->GetPosition();
}

Vector2 Entity::GetSize() const {
	return _AABB->GetSize();
}

SDL_Texture* Entity::GetTexture() const {
	return _texture;
}

const SDL_Rect* Entity::GetTextureFrame() const {
	return &_textureFrame;
}

void Entity::Update() {
}
