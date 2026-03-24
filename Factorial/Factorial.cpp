#include <iostream>

unsigned int factorial(unsigned int number)
{
    if (number == 1 || number == 0) 
        return 1;
    else 
        return number * factorial(number - 1);
}


unsigned int Fibonacci(unsigned int number)
{
    if (number == 0) return 0; //hits the base
    if (number == 1) return 1;

    return Fibonacci(number - 1) + Fibonacci(number - 2);
}

int main()
{
    unsigned int number;
    std::cout << "Write number! ";
    std::cin >> number;

    while (std::cin.fail())
    {
        std::cin.clear(); // resets the error flags 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush bad input

        std::cout << "Wrong! try again" << std::endl;
        std::cin >> number;
    }

    std::cout << "Factorial: " << factorial(number) << std::endl;

    std::cout << "Write number for fibonaci! ";
    std::cin >> number;
    while (std::cin.fail())
    {
        std::cin.clear(); // resets the error flags 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush bad input

        std::cout << "Wrong! try again" << std::endl;
        std::cin >> number;
    }

    std::cout << "fibonaci: " << Fibonacci(number) << std::endl;
    return 0;
}
