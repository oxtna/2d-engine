#pragma once
#include "IBody.h"
#include <vector>
#include <memory>

class PhysicsManager
{
private:
	static const size_t _defaultCollectionSize = 256;
	static const uint64_t _physicsTimeStep = 16;
	std::vector<std::weak_ptr<IBody>> _bodyCollection;
public:
	PhysicsManager();
	std::shared_ptr<IBody> CreateStaticBody(std::shared_ptr<Box> box);
	std::shared_ptr<IBody> CreateKinematicBody(std::shared_ptr<Box> box, Vector2 velocity);
	std::shared_ptr<IBody> CreateDynamicBody(std::shared_ptr<Box> box, Vector2 velocity);
	void UpdatePhysics();
};
