#pragma once
#include "IEntity.h"
#include <vector>
#include <memory>

class EntityManager
{
private:
	const size_t _defaultCollectionSize = 256;
	std::vector<std::shared_ptr<IEntity>> _entityCollection;
public:
	EntityManager();
	// Create a dynamically allocated entity of the corresponding type
	void CreateEntity(EntityType type);
};
