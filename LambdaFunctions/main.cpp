#include <vector>
#include <iostream>

template<typename T, typename FUNC>
void removeIf(std::vector<T>& vec, FUNC func)
{
    auto it = std::remove_if(vec.begin(), vec.end(), func);
    vec.erase(it, vec.end());
}

int main()
{
    std::vector<int> vec {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // A lambda must be assigned to a variable (or passed directly). It can't exist as a standalone named thing like a regular function. That's what makes it a lambda — it's an expression, not a declaration.
    auto isOdd = [](int num) { return num % 2 != 0; };

    auto it = std::remove_if(vec.begin(), vec.end(), isOdd);
    vec.erase(it, vec.end());

    for (int oneVec : vec)
    {
        std::cout << oneVec << " ";
    }
    std::cout << std::endl << std::endl;

    // 2 assigments

    std::vector<int> vec2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    removeIf(vec2, isOdd);

    for (int oneVec : vec2)
    {
        std::cout << oneVec << " ";
    }

    return 0;
}