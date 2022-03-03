#include "Entity.h"

Entity::Entity(int x, int y, SDL_Texture* texture, int textureWidth, int textureHeight)
	:m_boundingBox({x, y, textureWidth, textureHeight}), m_texture(texture) {
}

SDL_Texture* Entity::getTexture() const {
	return m_texture;
}

SDL_Rect Entity::getBoundingBox() const {
	return m_boundingBox;
}
