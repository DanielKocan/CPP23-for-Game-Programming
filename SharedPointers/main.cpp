#include <iostream>
#include <Memory>

class Widget
{
public:
	Widget(int data = 0)
		: data{ data }
	{
		std::cout << "Widget::Widget(" << data << ")" << std::endl;
	}

	~Widget()
	{
		std::cout << "~Widget::Widget()" << std::endl;
	}

	void doSomething()
	{
		std::cout << "Widget::doSomething()" << std::endl;
	}

private:
	int data = 0;
};

struct WidgetDeleter // struct vs class: in struct everything is public, in class everything is private
{
	void operator()(Widget* w)
	{
		std::cout << "WidgetDeleter::operator()" << std::endl;
		delete w;
	}
};

// some interesting stuff you can do with it
template <typename T>
struct CustomAllocator
{
	using value_type = T;
	CustomAllocator() noexcept = default;

	template<typename U>
	CustomAllocator(const CustomAllocator<U>&) noexcept {}

	T* allocate(std::size_t n)
	{
		std::cout << "CustomAllocator::allocate( " << n << " )" << std::endl;
		return static_cast<T*>(::operator new(n * sizeof(T)));
	}

	void deallocate(T* p, std::size_t n) noexcept
	{
		std::cout << "CustomDeallocate::allocate( " << n << " )" << std::endl;
		::operator delete(p);
	}
};
template<typename T, typename U>
bool operator==(const CustomAllocator<T>&, const CustomAllocator<U>&) noexcept { return true; }
template<typename T, typename U>
bool operator!=(const CustomAllocator<T>&, const CustomAllocator<U>&) noexcept { return false; }
std::shared_ptr<Widget> make_widget2(int data = 0)
{
	return std::allocate_shared<Widget>(CustomAllocator<Widget>(), data);
}

std::shared_ptr<Widget> make_widget(int data = 0)
{
	return std::shared_ptr<Widget>(new Widget(data), WidgetDeleter()); // constructor for 
}

int main()
{
	// or use auto
	std::shared_ptr<Widget> widget = std::make_shared<Widget>(1); // shared ptr owns that object
	std::cout << "Use count : " << widget.use_count() << std::endl;

	{
		auto widget2 = widget; // widget2 doesn't point to widget the pointer, it points to the same object that widget points to. Two pointers, one object!
		std::cout << "Use count after assinging new pointer: " << widget.use_count() << std::endl;
	}

	std::cout << "Use count: " << widget.use_count() << std::endl;

	std::weak_ptr<Widget> wPtr;
	std::shared_ptr<Widget> sPtr;
	{
		auto widget = std::make_shared<Widget>(1);
		sPtr = widget;

		std::cout << "Use count before using weak pointer: " << widget.use_count() << std::endl;

		wPtr = widget; // weak pointer will not increatement the use count

		std::cout << "Use count after using weak pointer: " << widget.use_count() << std::endl;

	}

	if (!wPtr.expired()) // has the object I'm watching been deleted already?
	{
		// then we can use it
		auto widget = wPtr.lock(); // temporarily takes ownership, bumping the ref count — so the object is guaranteed to stay alive as long as you're using it.
	}

	std::cout << "--- Example with not using share pointer --- " << std::endl;
	// Example not using shared pointer:
	Widget* RawWidget = new Widget(2);
	delete RawWidget;
	RawWidget = nullptr;

	std::cout << " --- Custom deleter example --- " << std::endl;
	std::shared_ptr<Widget>CustomWidget = make_widget(0);

	return 0;
}

