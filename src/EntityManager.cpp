#include "EntityManager.h"
#include "Rect.h"
#include "Circle.h"
#include <stdexcept>

EntityManager::EntityManager()
	: _entityCollection() {
	_entityCollection.reserve(_defaultCollectionSize);
}

void EntityManager::CreateEntity(EntityType type) {
	switch (type)
	{
	case EntityType::Rect:
		_entityCollection.push_back(
			std::make_shared<Rect>(0.0f, 0.0f, 0.0f, 0.0f, BodyType::Static, nullptr)
		);
		break;
	case EntityType::Circle:
		_entityCollection.push_back(
			std::make_shared<Circle>(0.0f, 0.0f, 0.0f, BodyType::Static, nullptr)
		);
		break;
	default:
		throw std::invalid_argument("Invalid entity type");
	}
}

void EntityManager::Update() {
	for (const auto& entity : _entityCollection) {
		entity->Update();
	}
}
