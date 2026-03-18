#include "Window.hpp"
#include <iostream>

class WindowImpl
{
public:
	WindowImpl() = default;
	virtual ~WindowImpl() = default; // minimum required for abstract base class

	virtual void showWindow() = 0; // any dervied class must impement this function
};

#if _WIN32 //check platform on compile time
class WindowWin32 : public WindowImpl
{
public:
	void showWindow() override {
		std::cout << "WindowWin32::showWindow()" << std::endl;
	}
};
using WindowType = WindowWin32;
#else
class WindowLinux : public WindowImpl
{
public:
	void showWindow() override {
		std::cout << "WindowLinux::showWindow()" << std::endl;
	}
};
using WindowType = WindowLinux;
#endif

Window::Window()
{
	pImpl = std::make_unique<WindowType>();
}

Window::~Window() = default;

void Window::showWindow()
{
	pImpl->showWindow();
}
