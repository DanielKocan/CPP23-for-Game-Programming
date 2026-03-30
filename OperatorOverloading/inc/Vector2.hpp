#pragma once

struct Vector2
{
	Vector2() = default;
	explicit Vector2(float x); // initialize both compoennts to x. Explicit to make sure you are using vector to create not jsut = flaotValue
	Vector2(float x, float y); 

	Vector2 operator+(const Vector2& rhs) const; // one way.
	Vector2 operator-(const Vector2& rhs) const; 

	Vector2 operator*(float rhs) const;

	float x = 0.0f;
	float y = 0.0f;
};

// Vector2 operator+(const Vector2& lhs, const Vector2& rhs); // free functions, means oustside the class. Second way

Vector2 operator*(float lhs, const Vector2& rhs);