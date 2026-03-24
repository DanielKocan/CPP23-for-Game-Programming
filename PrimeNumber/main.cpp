#include <iostream>
#include <cmath>//sqrt

// checks if a number is prime, returns true or false
bool isPrime(unsigned int n)
{
    // 0 and 1 are not prime by definition
    if (n <= 1) return false;
    // 2 and 3 are prime
    if (n <= 3) return true;

    // all primes greater than 3 can be written as 6k+1 or 6k-1, so if its divisible by 2 or 3 its not prime
    if (n % 2 == 0 || n % 3 == 0) return false;

    // only check up to square root of n, and only check 6k+-1 values exmples: 5, 7, 11, 13 and et.
    for (unsigned int i = 5; i <= sqrt(n); i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

int main()
{
    unsigned int number;

    std::cout << "Enter a natural number: ";
        std::cin >> number;

    while (std::cin.fail())
    {
        std::cin.clear();

        std::cout << "Invalid input, enter a natural number: ";
        std::cin >> number;
    }

    if (isPrime(number)) std::cout << number << " is prime" << std::endl;
    else std::cout << number << " isnt prime" << std::endl;

    unsigned int min, max;

    std::cout << std::endl;
    std::cout << "Enter min value: ";
    std::cin >> min;

    std::cout << "Enter max value: ";
    std::cin >> max;

    std::cout << "Prime numbers between " << min << " and " << max << ":" << std::endl;

    for (unsigned int i = min; i <= max; i++)
    {
        if (isPrime(i)) std::cout << i << " ";
    }

    return 0;
}