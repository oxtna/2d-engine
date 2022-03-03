#include "Vector2.h"

Vector2::Vector2(float x, float y)
	: _x(x), _y(y) {
}

float Vector2::getX() const {
	return _x;
}

float Vector2::getY() const {
	return _y;
}

Vector2 Vector2::operator+(const Vector2& other) const {
	return Vector2(this->_x + other._x, this->_y + other._y);
}

Vector2& Vector2::operator+=(const Vector2& other) {
	this->_x += other._x;
	this->_y += other._y;
	return *this;
}

Vector2 Vector2::operator-(const Vector2& other) const {
	return Vector2(this->_x - other._x, this->_y - other._y);
}

Vector2& Vector2::operator-=(const Vector2& other) {
	this->_x -= other._x;
	this->_y -= other._y;
	return *this;
}

bool Vector2::operator==(const Vector2& other) const {
	return (this->_x == other._x) && (this->_y == other._y);
}
