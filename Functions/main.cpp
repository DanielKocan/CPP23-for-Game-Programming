#include <iostream>

int add(int a, int b)
{
	return a + b;
}

double add(double a, double b)
{
	return a + b;
}

float add(float a, float b)
{
	return a + b;
}

int pass_by_value(int a) // primitive data types are okay
{
	a += 5;
	return a;
}

int pass_by_reference(int& a) // more for classes for complex structure or classes
{
	a += 5;
	return a;
}

int pass_by_const_reference(const int& a)
{
	// a += 5; // cannot modify a cost ref!
	return a;
}

int pass_by_pointer(int* p)
{
	if (p)
		*p += 5;

	return *p;
}

double pow(double base, int exponent = 1)
{
	return std::pow(base, exponent);
}

using add_funcUsing = int(*)(int, int); //anothjer way of making poitner to function
// using -  just creates a nickname for a type,

int main()
{
	int one = add(0, 1);
	int two = add(1, 1);
	double d1 = add(0.0, 1.0); // function overloading, only on argument types, BUT NOT RETURN VALUES
	float f1 = add(0.0f, 0.0f);

	int v = pow(10);

	int a = 0;
	//a = pass_by_reference(5); // wont work because it expectes memory address :0
	pass_by_reference(a);
	std::cout << "a: " << a << std::endl;

	pass_by_const_reference(10); // literals are llowed when passed by const reference!

	// pass_by_pointer(10); // again cant use it because it is expecting memoryadress!
	int b = 0;
	pass_by_pointer(&b);
	std::cout << "b: " << b << std::endl;

	// INTERESTING

	int(*add_func)(int, int);
	add_func = &add;

	int j = add_func(5, 6);

	// another way of using function pointers

	add_funcUsing f = &add;
	int h = f(5, 6);

	return 0;
}