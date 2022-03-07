#include "Vector2.h"

Vector2::Vector2(float x, float y)
	: X(x), Y(y) {
}

Vector2 Vector2::operator+(const Vector2& other) const {
	return Vector2(this->X + other.X, this->Y + other.Y);
}

Vector2& Vector2::operator+=(const Vector2& other) {
	this->X += other.X;
	this->Y += other.Y;
	return *this;
}

Vector2 Vector2::operator-(const Vector2& other) const {
	return Vector2(this->X - other.X, this->Y - other.Y);
}

Vector2& Vector2::operator-=(const Vector2& other) {
	this->X -= other.X;
	this->Y -= other.Y;
	return *this;
}

bool Vector2::operator==(const Vector2& other) const {
	return (this->X == other.X) && (this->Y == other.Y);
}
