#include "PhysicsManager.h"
#include "StaticBody.h"
#include "KinematicBody.h"
#include "DynamicBody.h"
#include <stdexcept>

PhysicsManager::PhysicsManager() {
	_bodyCollection.reserve(_defaultCollectionSize);
}

std::shared_ptr<IBody> PhysicsManager::CreateStaticBody(std::shared_ptr<Box> box) {
	auto body = std::make_shared<StaticBody>(box);
	_bodyCollection.push_back(body);
	return body;
}

std::shared_ptr<IBody> PhysicsManager::CreateKinematicBody(std::shared_ptr<Box> box, Vector2 velocity) {
	auto body = std::make_shared<KinematicBody>(box, velocity);
	_bodyCollection.push_back(body);
	return body;
}

std::shared_ptr<IBody> PhysicsManager::CreateDynamicBody(std::shared_ptr<Box> box, Vector2 velocity) {
	auto body = std::make_shared<DynamicBody>(box, velocity);
	_bodyCollection.push_back(body);
	return body;
}

void PhysicsManager::UpdatePhysics() {
	auto& v = _bodyCollection;
	auto isExpired = [](const std::weak_ptr<IBody>& body) {
		return body.expired();
	};
	v.erase(std::remove_if(v.begin(), v.end(), isExpired), v.end());
	for (auto it = v.begin(); it != v.end(); it++) {
		if (auto body = it->lock()) {
			body->UpdatePhysics(static_cast<float>(_physicsTimeStep) / 1000.0f);
		}
	}
}
