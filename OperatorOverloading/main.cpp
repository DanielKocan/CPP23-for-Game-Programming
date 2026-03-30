#include <iostream>
#include <cassert>
#include <Vector2.hpp>

int main()
{
    Vector2 a{ 1,2 };
    Vector2 b{ 3,4 };

    Vector2 c = a + b;
    assert(c.x == 4.0f && c.y == 6.0f);

    Vector2 d = a - b;

    std::cout << d.x << " " << d.y;
}