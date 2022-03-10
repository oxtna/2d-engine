#pragma once
#include "EntityManager.h"
#include "PhysicsManager.h"
#include <vector>
#include <memory>

class SceneNode
{
private:
	std::vector<std::shared_ptr<SceneNode>> _children;
	std::weak_ptr<SceneNode> _parent;
	std::shared_ptr<Box> _box;
	std::shared_ptr<Entity> _entity;
	std::shared_ptr<IBody> _body;
public:
	SceneNode(const std::shared_ptr<SceneNode>& parent);
	static SceneNode CreateRoot();
	const std::vector<std::shared_ptr<SceneNode>>& GetChildren() const;
	std::shared_ptr<Entity> GetEntity() const;
	std::shared_ptr<IBody> GetBody() const;
	std::shared_ptr<SceneNode> GetParent() const;
	void AddChild(const SceneNode& child);
	void RemoveChild(const SceneNode& child);
	void Move(const std::shared_ptr<SceneNode>& parent);

	// If this node already has a box, all members using it will be recreated using the new box
	void AddBox(Box box, EntityManager& entityManager, PhysicsManager& physicsManager);

	// If this node has no box, this method will throw
	void AddEntity(EntityManager& entityManager, SDL_Texture* texture, SDL_Rect textureFrame);

	// If `bodyType` is equal to `BodyType::Static`, `velocity` will be ignored
	// If this node has no box, this method will throw
	void AddBody(PhysicsManager& physicsManager, BodyType bodyType, Vector2 velocity);
protected:
	SceneNode() = default;
	std::vector<std::shared_ptr<SceneNode>>& _GetChildren();
};
