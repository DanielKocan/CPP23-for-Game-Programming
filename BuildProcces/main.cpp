#include "Config.hpp"
#include "Game.h"
#include <iostream>

int main()
{
	std::cout << "Jump Hegiht: " << JumpHeight << std::endl;
	std::cout << "Jump Duration: " << JumpDuration << std::endl;

	Update();
	
	return 0;
}