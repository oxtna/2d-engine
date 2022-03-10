#include "Vector2.h"
#include <cmath>

Vector2::Vector2(float x, float y)
	: X(x), Y(y) {
}

Vector2 Vector2::Normalize() const {
	float magnitude = std::sqrtf((this->X * this->X) + (this->Y * this->Y));
	if (magnitude == 0.0f) {
		return *this;
	}
	return *this / magnitude;
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

Vector2 Vector2::operator*(float f) const {
	return Vector2(this->X * f, this->Y * f);
}

Vector2& Vector2::operator*=(float f) {
	this->X *= f;
	this->Y *= f;
	return *this;
}

Vector2 Vector2::operator/(float f) const {
	return Vector2(this->X / f, this->Y / f);
}

Vector2& Vector2::operator/=(float f) {
	this->X /= f;
	this->Y /= f;
	return *this;
}
