#include <Player.hpp>
#include <iostream>

Player::Player(int hitPoints)
    : Entity(hitPoints)
{
    std::cout << "Player::Player(" << getHitpoints() << ")" << std::endl; //hitpoints is private in entity so we cant use this. we need to use getters and setters
}

Player::~Player()
{
    std::cout << "Player::~Player()" << std::endl;
}

void Player::draw(int testArguemnt) const
{
    // score += 10; // cant do it since its marked const
    std::cout << "Player::draw();" << std::endl;
}

void Player::update(float deltatime)
{
    score += 10;
    std::cout << "Player::update(" << deltatime << ")" << std::endl;
}
