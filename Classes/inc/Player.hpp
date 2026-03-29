#pragma once
#include "Entity.hpp" // "" because they are in the same folder

class Player : public Entity // all public variables in Entity are public in Player, so we can invoke all function and members from entity (private = means all pbulic are private now, can reach and protected means that all public and protected members will be protected). Protected means outsdie of the class you cant modify, but inside the classes you can ( so in player i can in main i cant)
{
public:
    explicit Player(int hitPoints = 100);
    ~Player();

    void draw(int testArguemnt = 123) const override; // override is optional but compiler will let us know if the override function signature doesnt match here. 
    // We dont neet to mark virtual void draw, since we already using override;

    void update(float deltatime) override;
};

// example how to do it with struct. (started from basic C). Struct makes everything public by default. classes make everything private by default
/*struct Player : Entity
{
    explicit Player(int hitPoints = 100);
    ~Player();

    void draw(int testArguemnt = 123) const override; // override is optional but compiler will let us know if the override function signature doesnt match here.
    void update(float deltatime) override;
};*/
