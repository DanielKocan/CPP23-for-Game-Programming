#include <iostream>

/*void swap(int *a, int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

}*/

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;

}

int main()
{
    int a = 1;
    int b = 2;

    std::cout << "Before swap, a: " << a << " b:" << b << std::endl;
    swap(a, b);
    std::cout << "After swap, a: " << a << " b:" << b << std::endl;

    return 0;
}