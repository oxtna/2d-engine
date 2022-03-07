#include "Box.h"

Box::Box(float x, float y, float w, float h)
	: _position(x, y), _size(w, h) {
}

Box::Box(Vector2 position, Vector2 size)
	: _position(position), _size(size) {
}

float Box::GetX() const {
	return _position.X;
}

float Box::GetY() const {
	return _position.Y;
}

float Box::GetW() const {
	return _size.X;
}

float Box::GetH() const {
	return _size.Y;
}

Vector2 Box::GetPosition() const {
	return _position;
}

Vector2 Box::GetSize() const {
	return _size;
}

Vector2 Box::GetCenter() const {
	return Vector2(_position.X + _size.X / 2, _position.Y + _size.Y / 2);
}
