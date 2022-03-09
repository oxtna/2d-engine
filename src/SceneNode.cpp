#include "SceneNode.h"
#include <algorithm>
#include <iostream>

SceneNode::SceneNode(const std::shared_ptr<SceneNode>& parent)
	: _parent(parent) {
}

SceneNode::SceneNode(const std::shared_ptr<SceneNode>& parent, const std::shared_ptr<IEntity>& entity)
	: _parent(parent), _entity(entity) {
}

SceneNode::SceneNode(const std::shared_ptr<SceneNode>& parent, const std::shared_ptr<IBody>& body)
	: _parent(parent), _body(body) {
}

SceneNode::SceneNode(const std::shared_ptr<SceneNode>& parent,
	const std::shared_ptr<IEntity>& entity, const std::shared_ptr<IBody>& body)
	: _parent(parent), _entity(entity), _body(body) {
}

SceneNode SceneNode::CreateRoot() {
	return SceneNode();
}

const std::vector<std::shared_ptr<SceneNode>>& SceneNode::GetChildren() const {
	return _children;
}

std::shared_ptr<SceneNode> SceneNode::GetParent() const {
	return _parent.lock();
}

void SceneNode::AddChild(const SceneNode& child) {
	_children.push_back(std::make_shared<SceneNode>(child));
}

void SceneNode::RemoveChild(const SceneNode& child) {
	auto isEqual = [&child](const std::shared_ptr<SceneNode>& node) {
		return node.get() == &child;
	};
	_children.erase(std::remove_if(_children.begin(), _children.end(), isEqual), _children.end());
}

void SceneNode::Move(const std::shared_ptr<SceneNode>& parent) {
	if (parent == nullptr) {
		return;
	}
	parent->AddChild(std::make_shared<SceneNode>(*this));
	if (auto p = _parent.lock()) {
		p->RemoveChild(*this);
	}
	_parent = parent;
}

std::vector<std::shared_ptr<SceneNode>>& SceneNode::_GetChildren() {
	return _children;
}