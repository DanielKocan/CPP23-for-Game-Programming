#include <iostream>

double max(const double arr[], size_t n) //const float* arr would be the same as double arr[]
{
    double temp = std::numeric_limits<double>::lowest();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > temp) temp = arr[i];
    }
    return temp;
}

double min(const double arr[], size_t n) //const float* arr would be the same as double arr[]
{
    double temp = std::numeric_limits<double>::max();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < temp) temp = arr[i];
    }
    return temp;
}

double sum(const double arr[], size_t n) //const float* arr would be the same as double arr[]
{
    double temp = 0.0;
    for (int i = 0; i < n; i++)
    {
        temp += arr[i];
    }
    return temp;
}

double mean(const double arr[], size_t n) //const float* arr would be the same as double arr[]
{
    double sumTemp = sum(arr, n);
    return sumTemp / n;
}

double var(const double arr[], size_t n)
{
    double tempMean = mean(arr, n);
    double tempSum = 0.0;

    for (int i = 0; i < n; i++)
    {
        tempSum += std::pow(arr[i] - tempMean, 2);
    }

    return tempSum / n;  // just variance
}

double stdDev(const double arr[], size_t n)
{
    return sqrt(var(arr, n));
}

void buble_sort(double arr[], size_t n)
{
    for (int s = 0; s < n; s++)
    {
        for (int i = 0; i < n - 1 - s; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                std::swap(arr[i], arr[i + 1]);
            }
        }
    }
}

double median(const double arr[], size_t n)
{
    double* sorted = new double[n];
    std::copy(arr, arr + n, sorted);
    buble_sort(sorted, n);

    double result;
    if (n == 1)
    {
        result = sorted[0];
    }
    else if (n % 2 == 0)
    {
        result = (sorted[n / 2] + sorted[n / 2 - 1]) / 2.0;
    }
    else 
    {
        result = sorted[n / 2];
    }

    delete[] sorted;
    return result;
}

int main()
{
    size_t n;
    std::cout << "How many number of elements in array?: " << std::endl;
    std::cin >> n;

    while (std::cin.fail() || n == 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard everything up to the newline
        std::cout << "Invalid input, try again: ";
        std::cin >> n;
    }

    double* arr = new double[n];

    for (size_t i = 0; i < n; i++)
    {
        std::cout <<"Write to the array[" << i << "]: " << std::endl;
        std::cin >> arr[i];

        while (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard everything up to the newline
            std::cout << "Invalid input, try again: ";
            std::cin >> arr[i];
        }
    }
    std::cout << std::endl;

    std::cout << "max: " << max(arr, n) << std::endl;
    std::cout << "min: " << min(arr, n) << std::endl;
    std::cout << "sum: " << sum(arr, n) << std::endl;
    std::cout << "mean: " << mean(arr, n) << std::endl;
    std::cout << "var: " << var(arr, n) << std::endl;
    std::cout << "stdDev: " << stdDev(arr, n) << std::endl;

    std::cout << "bubble sort: ";
    buble_sort(arr, n);
    for (size_t i = 0; i < n; i++)
    {
        std::cout << arr[i] << ", ";
    }

    std::cout << "median: " << median(arr, n) << std::endl;

    delete[] arr;
}
