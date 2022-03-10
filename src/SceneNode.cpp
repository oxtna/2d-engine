#include "SceneNode.h"
#include <algorithm>
#include <stdexcept>

SceneNode::SceneNode(const std::shared_ptr<SceneNode>& parent)
	: _parent(parent) {
}

SceneNode SceneNode::CreateRoot() {
	return SceneNode();
}

const std::vector<std::shared_ptr<SceneNode>>& SceneNode::GetChildren() const {
	return _children;
}

std::shared_ptr<Entity> SceneNode::GetEntity() const {
	return _entity;
}

std::shared_ptr<IBody> SceneNode::GetBody() const {
	return _body;
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

void SceneNode::AddBox(Box box, EntityManager& entityManager, PhysicsManager& physicsManager) {
	_box = std::make_shared<Box>(box);
	if (_entity != nullptr) {
		AddEntity(entityManager, _entity->GetTexture(), *_entity->GetTextureFrame());
	}
	if (_body != nullptr) {
		AddBody(physicsManager, _body->GetBodyType(), _body->GetVelocity());
	}
}

void SceneNode::AddEntity(EntityManager& entityManager, SDL_Texture* texture, SDL_Rect textureFrame) {
	if (_box == nullptr) {
		throw std::logic_error("SceneNode has no Box");
	}
	_entity = entityManager.CreateEntity(_box, texture, textureFrame);
}

void SceneNode::AddBody(PhysicsManager& physicsManager, BodyType bodyType, Vector2 velocity) {
	if (_box == nullptr) {
		throw std::logic_error("SceneNode has no Box");
	}
	switch (bodyType)
	{
	case BodyType::Static:
		_body = physicsManager.CreateStaticBody(_box);
		break;
	case BodyType::Kinematic:
		_body = physicsManager.CreateKinematicBody(_box, velocity);
		break;
	case BodyType::Dynamic:
		_body = physicsManager.CreateDynamicBody(_box, velocity);
		break;
	default:
		throw std::invalid_argument("Invalid body type");
	}
}

std::vector<std::shared_ptr<SceneNode>>& SceneNode::_GetChildren() {
	return _children;
}