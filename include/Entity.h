#pragma once
#include "SDL2/SDL.h"

class Entity
{
private:
	SDL_Texture* m_texture;
	SDL_Rect m_boundingBox;
public:
	Entity(int x, int y, SDL_Texture* texture, int textureWidth, int textureHeight);
	SDL_Texture* getTexture() const;
	SDL_Rect getBoundingBox() const;
};
