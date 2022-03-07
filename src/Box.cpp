#include "Box.h"

Box::Box(float x, float y, float w, float h)
	: _position(x, y), _size(w, h) {
}

Box::Box(Vector2 position, Vector2 size)
	: _position(position), _size(size) {
}

float Box::GetX() const {
	return _position.GetX();
}

float Box::GetY() const {
	return _position.GetY();
}

float Box::GetW() const {
	return _size.GetX();
}

float Box::GetH() const {
	return _size.GetY();
}

Vector2 Box::GetPosition() const {
	return _position;
}

Vector2 Box::GetSize() const {
	return _size;
}

Vector2 Box::GetCenter() const {
	return Vector2(_position.GetX() + _size.GetX() / 2, _position.GetY() + _size.GetY() / 2);
}
