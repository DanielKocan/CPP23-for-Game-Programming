#include <iostream>
#include <functional>

int call_func(auto f, int a, int b)
{
    return f(a, b);
}

int call_func_with_function_pointer(int(*f)(int, int), int a, int b)
{
    return f(a, b);
}

// using add_func = std::function<int(int, int)>
// int call_func_with_functional_std_library(add_func f, int a, int b) // could be also like this
int call_func_with_functional_std_library(std::function<int(int, int)> f, int a, int b)
{
    return f(a, b);
}

int main()
{
    auto f = [](int a, int b) { return a + b; };
    //auto f = [](int a, int b) -> int { return a + b; }; // optionolly specify return type for lambda

    int c = f(5, 10);

    int l = call_func(f, 5, 10);
    int l = call_func_with_function_pointer(f, 5, 10);
    std::cout << "l: " << l << std::endl;

    int a = 5;
    int b = 10;
    int e = 0;

    auto g = [=]() {return a + b; }; // capture from local scope
    // auto g = [a, b]() {return a + b; }; // can be also like that

    auto gRef = [&]() {return a + b; }; // capture from local scope
    // auto gRef = [&a, &b]() {return a + b; }; // can be also like that

    auto g2 = [=, &a, &b] { return a + e + b; }; // = capture everything by value, & capture everythign by reference (cant then use specific  reference values)

    a = 10;
    b = 15;
    e = 5;

    int d = g();
    int d2 = gRef();

    std::cout << "g(): " << d << std::endl;
    std::cout << "gRef(): " << d2 << std::endl; //lambda is aware of what is captured
    std::cout << "g2(): " << g2() << std::endl; //lambda is aware of what is captured

    // C++ 14 Generic lambdas.
    auto h = [](auto a, auto b) { return a + b; };

    auto i = h(5, 10);
    auto j = h(5.0f, 10.0f);
    auto k = h(5, 10.0f); // dosent prevent from mixing types

    //C++ 20 Explicit template paramaters  (
    auto h2 = []<typename T, typename U> (T a, U b) { return a + b; };
    // prevents from mixing types
    auto h2_1 = []<typename T> (T a, T b) { return a + b; };

    return 0;
}
