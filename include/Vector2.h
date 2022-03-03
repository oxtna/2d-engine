#pragma once

class Vector2
{
private:
	float _x;
	float _y;
public:
	Vector2(float x, float y);
	float GetX() const;
	float GetY() const;
	Vector2 operator+(const Vector2& other) const;
	Vector2& operator+=(const Vector2& other);
	Vector2 operator-(const Vector2& other) const;
	Vector2& operator-=(const Vector2& other);
	bool operator==(const Vector2& other) const;
};
