#pragma once
#include "Entity.h"
#include <vector>
#include <memory>

class EntityManager
{
private:
	static const size_t _defaultCollectionSize = 256;
	std::vector<std::weak_ptr<Entity>> _entityCollection;
public:
	EntityManager();
	// Create a dynamically allocated entity of the corresponding type
	std::shared_ptr<Entity> CreateEntity(std::shared_ptr<Box> box, SDL_Texture* texture, SDL_Rect textureFrame);
	const std::vector<std::weak_ptr<Entity>>& GetEntities() const;
	void Update();
};
