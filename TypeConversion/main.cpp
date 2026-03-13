#include <iostream>

class Base
{
public:
	virtual ~Base() = default;
};

class Base2
{
public:
	virtual ~Base2() = default;
};


class Derived : public Base {
public:
    ~Derived() override = default;
};

class Derived2 : public Base {
public:
    ~Derived2() override = default;
};


int main()
{
	{
		std::cout << "Type Conversion Assigment" << std::endl;

		double d = 42.99;
		std::cout << d << std::endl;

		float f = static_cast<float>(d);
		std::cout << f << std::endl;

		int i = static_cast<int>(f);
		std::cout << i << std::endl;

		char c = static_cast<char>(i);
		std::cout << c << std::endl;

		std::cout << " -------------------------- " << std::endl;

		char cTest = '!';
		int iTest = cTest;

		std::cout << "iTest: " << iTest << std::endl;

		auto v = 3.14f + 7; // What type is v?
		std::cout << "v: " << v << std::endl;

		char c5 = '5';
		char c0 = '0';
		int i5 = static_cast<int>(c5);
		int i0 = static_cast<int>(c0);
		std::cout << "char 5 to int: " << i5 - c0   << std::endl;
	}

	unsigned char c = 'A'; // 8bits
	int i = c; //32 bits, widening conversioon

	c = static_cast<unsigned char>(i); // narowing conversion

	unsigned int ui = 3;
	i = static_cast<int>(ui); // narrowing conversion since its from 32 bit to 31 (int has only 31 bits, since on bit is used for sign (- or +), while unsigned int has 32 bits

	ui = i; // We loose that negative value, can result in unintentional behavior/

	float f = 3.14f; // 23 bits for the fraction (digits of the number) and 8bit for exponent (power of 2)
	double d = f; // 52 bits for the fraction and 11bits for exponent 
	f = static_cast<float>(d); // narrowing conversion (float max decimal percision if 7 digits)

	f = static_cast<float>(i);
	d = i; // no need for static cast? because int "decimnal percision" (it dosent have it but thats the max value) is 10 and double is 15

	i = static_cast<int>(f);

	// --- C STYLE CAST --- (allows to do anything what you want, but compiler with static_cast will stop you from doing bad stuff!)
	f = (float)(i);
	i = (int)(f);

	// --- other styles of casts --- 

	// const cast
	const float cf = 3.14f;
	float* pf = const_cast<float*>(&cf);
	*pf = 3.145f;

	// dynamic cast (safely cast a base pointer, to one of the derrived class)
	Base* b = new Derived(); // So the pointer looks like Base, but actually points to Derived.
	Derived* der = dynamic_cast<Derived*>(b);
	Derived2* der2 = dynamic_cast<Derived2*>(b);
	if (der != nullptr)
	{
		std::cout << "b is Derived" << std::endl;
	}
	if (der2 == nullptr)
	{
		std::cout<<"b is not derived2 " << std::endl;
	}
	// hovewer if Derived* d = new Derived();
	// b = d; (no need for dynamic cast, because ofcourse it derives from base class and no need to check)

	// reinterpret cast (the most dangerous cast, basically means Treat this memory as if it were another type)
	Base* base = new Base(); // BASE AND BASE2 ARE UNREALATED CLASS
	Base2* b2 = reinterpret_cast<Base2*>(b); // You essentially telling to compiler: This A object is actually a B
	//or
    int x = 65; //x = 65
	char* charr = reinterpret_cast<char*>(&x); // ASCII 65 = 'A', will print A
	// Rule by programmers? Avoid reinterpret_cast unless you are doing low - level memory programming.

	return 0;
}