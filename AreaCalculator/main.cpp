#include <iostream>
#include <string>
#include <cmath>// sqrt

const float PI = 3.141592653f;

int main()
{
    std::string input;

    std::cout << "Select a shape:" << std::endl;
    std::cout << "Circle (C or 1)" << std::endl;
    std::cout << "Square (S or 2)" << std::endl;
    std::cout << "Rectangle (R or 3)" << std::endl;
    std::cout << "Triangle (T or 4)" << std::endl;
    std::cout << "Enter choice: ";
    std::cin >> input;

    // convert to uppercase so for example c and C both work
    if (input.length() == 1)
        input[0] = toupper(input[0]);

    if (input == "1") input = "C";
    if (input == "2") input = "S";
    if (input == "3") input = "R";
    if (input == "4") input = "T";

    switch (input[0])
    {
    case 'C':
    {
        float r;

        std::cout << "Enter radius: ";
        std::cin >> r;

        std::cout << "Circumference: " << 2 * PI * r << std::endl;

        std::cout << "Area: " << PI * r * r << std::endl;
        break;
    }
    case 'S':
    {
        float s;

        std::cout << "Enter side length: ";
        std::cin >> s;

        std::cout << "Perimeter: " << 4 * s << std::endl;
        std::cout << "Area: " << s * s << std::endl;
        break;
    }
    case 'R':
    {
        float w, h;

        std::cout << "Enter width: ";
        std::cin >> w;

        std::cout << "Enter height: ";
        std::cin >> h;

        std::cout << "Perimeter: " << 2 * w + 2 * h << std::endl;
        std::cout << "Area: " << w * h << std::endl;
        break;
    }
    case 'T':
    {
        float b, h;

        std::cout << "Enter base: ";
        std::cin >> b;

        std::cout << "Enter height: ";
        std::cin >> h;

        float hypotenuse = sqrt(b * b + h * h);

        std::cout << "Perimeter: " << b + h + hypotenuse << std::endl;
        std::cout << "Area: " << (b * h) / 2 << std::endl;
        break;
    }
    default:
        std::cout << "Error: invalid input, please enter C, S, R or T" << std::endl;
        break;
    }

    return 0;
}