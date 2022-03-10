#include "EntityManager.h"
#include <stdexcept>
#include <algorithm>

EntityManager::EntityManager() {
	_entityCollection.reserve(_defaultCollectionSize);
}

std::shared_ptr<Entity> EntityManager::CreateEntity(std::shared_ptr<Box> box, SDL_Texture* texture, SDL_Rect textureFrame) {
	auto entity = std::make_shared<Entity>(box, texture, textureFrame);
	_entityCollection.push_back(entity);
	return entity;
}

const std::vector<std::weak_ptr<Entity>>& EntityManager::GetEntities() const {
	return _entityCollection;
}

void EntityManager::Update() {
	auto isExpired = [](const std::weak_ptr<Entity>& entity) {
		return entity.expired();
	};
	auto& v = _entityCollection;
	v.erase(std::remove_if(v.begin(), v.end(), isExpired), v.end());
	for (auto it = v.begin(); it != v.end(); it++) {
		if (auto entity = it->lock()) {
			entity->Update();
		}
	}
}
