#include "EntityManager.h"
#include "Rect.h"
#include "Circle.h"
#include <stdexcept>

EntityManager::EntityManager()
	: _entityCollection() {
	_entityCollection.reserve(_defaultCollectionSize);
}

void EntityManager::CreateEntity(EntityType type, SDL_Texture* texture) {
	switch (type)
	{
	case EntityType::Rect:
		_entityCollection.push_back(
			std::make_shared<Rect>(0.0f, 0.0f, 64.0f, 64.0f, BodyType::Static, texture)
		);
		break;
	case EntityType::Circle:
		_entityCollection.push_back(
			std::make_shared<Circle>(0.0f, 0.0f, 0.0f, BodyType::Static, texture)
		);
		break;
	default:
		throw std::invalid_argument("Invalid entity type");
	}
}

const std::vector<std::shared_ptr<IEntity>>& EntityManager::GetEntities() const {
	return _entityCollection;
}

void EntityManager::Update() {
	for (const auto& entity : _entityCollection) {
		entity->Update();
	}
}
