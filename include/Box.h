#pragma once
#include "Vector2.h"

class Box
{
private:
	Vector2 _position;
	Vector2 _size;
public:
	Box(float x, float y, float w, float h);
	Box(Vector2 position, Vector2 size);
	float GetX() const;
	float GetY() const;
	float GetW() const;
	float GetH() const;
	Vector2 GetPosition() const;
	Vector2 GetSize() const;
	Vector2 GetCenter() const;
	void Translate(Vector2 vec);
};
