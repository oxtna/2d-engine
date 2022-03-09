#pragma once
#include "IBody.h"
#include "IEntity.h"
#include <vector>
#include <memory>

class SceneNode
{
private:
	std::vector<std::shared_ptr<SceneNode>> _children;
	std::weak_ptr<SceneNode> _parent;
	std::shared_ptr<IEntity> _entity;
	std::shared_ptr<IBody> _body;
public:
	SceneNode(const std::shared_ptr<SceneNode>& parent);
	SceneNode(const std::shared_ptr<SceneNode>& parent, const std::shared_ptr<IEntity>& entity);
	SceneNode(const std::shared_ptr<SceneNode>& parent, const std::shared_ptr<IBody>& body);
	SceneNode(const std::shared_ptr<SceneNode>& parent,
		const std::shared_ptr<IEntity>& entity, const std::shared_ptr<IBody>& body);

	static SceneNode CreateRoot();
	
	const std::vector<std::shared_ptr<SceneNode>>& GetChildren() const;
	std::shared_ptr<SceneNode> GetParent() const;
	void AddChild(const SceneNode& child);
	void RemoveChild(const SceneNode& child);
	void Move(const std::shared_ptr<SceneNode>& parent);
protected:
	SceneNode() = default;
	std::vector<std::shared_ptr<SceneNode>>& _GetChildren();
};
