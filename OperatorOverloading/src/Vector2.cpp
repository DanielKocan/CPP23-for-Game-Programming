#include <Vector2.hpp>

Vector2::Vector2(float x)
	: x {x}
	, y {x}
{

}

Vector2::Vector2(float x, float y)
	: x{ x }
	, y{ y }
{

}

Vector2 Vector2::operator+(const Vector2& rhs) const // first way of doing it (not free function)
{
	return { x + rhs.x, y + rhs.y };
}

Vector2 Vector2::operator-(const Vector2& rhs) const
{
	return { x - rhs.x, y - rhs.y };
}

Vector2 Vector2::operator*(float rhs) const
{
	return { x * rhs,  y * rhs };
}

//Vector2 operator+(const Vector2& lhs, const Vector2& rhs) // second way of using free functions
//{
//	return { lhs.x + rhs.x, lhs.y + rhs.y };
//}

Vector2 operator*(float lhs, const Vector2& rhs)
{
	return { lhs * rhs.x,  lhs * rhs.y };
}
