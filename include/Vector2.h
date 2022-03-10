#pragma once

class Vector2
{
public:
	float X;
	float Y;
	Vector2(float x, float y);
	Vector2 Normalize() const;
	Vector2 operator+(const Vector2& other) const;
	Vector2& operator+=(const Vector2& other);
	Vector2 operator-(const Vector2& other) const;
	Vector2& operator-=(const Vector2& other);
	bool operator==(const Vector2& other) const;
	Vector2 operator*(float f) const;
	Vector2& operator*=(float f);
	Vector2 operator/(float f) const;
	Vector2& operator/=(float f);
};
