#include <Entity.hpp> // < > angle brackets means search the include path that are specified in our project. (right click to classes properties -> c/c++ -> specify additional directories
// " " double quests means search the current directory
#include <iostream>

Entity::Entity(int hitPoints) : hitPoints(hitPoints) // compilers is smart enough to realise which variable is which
{
    std::cout << "Entity:Entity(); Hitpoints: " << this->hitPoints << std::endl;
}

Entity::Entity(const Entity& e) : hitPoints(e.hitPoints)
{
    std::cout << "Entity::Entity(const Entity& e); HP:" << hitPoints << std::endl;
}

void Entity::draw(int testParameter) const
{
    std::cout << "Entity::draw()" << std::endl;
}


Entity::~Entity()
{
    std::cout << "Entity::~Entity(); HP:" << hitPoints << ". Do somekind of cleanup" << std::endl;
}
