// THIS FILE IS EXCLUDED FROM BUILD SO I CAN VIEW IT IN VISUAL STUDIO
#include <iostream>
class Entity // base class
{
public:
    //Entity(); // invoked when the new instance is created, dosent return anything! Now we created default constructor
    explicit Entity(int hitPoints = 100); // parameterizeds constructor withg defaultarguments:  hitPoints = 100

    ~Entity(); // doesnt return anything and doesnt take anything. Called when it goes of the scope or gets ecxplicitly deleted

    Entity(const Entity& e); // Copy constructor

    virtual void draw(int testParameter = 123) const; // const means immutable, nothing will be chagned in class;

    virtual void update(float deltatime) = 0; // Mark as pure virtual by = 0. Pure virtual means we have to defined class! by doint this we are making it absract class and now we cant use it as a just in class

    int getHitpoints() const //dosent modifieds the class
    {
        return hitPoints;
    }

    int score = 0;

private:
    int hitPoints = 0;
};

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
    std::cout << "Player::update(" << deltatime <<")" << std::endl;
}

void printHitPoints(const Entity& e)
{
    std::cout << "Printing hitPoints: " << e.getHitpoints() << std::endl;
}

int mainBefore()
{
    //{ // because we make entity abstract class we cant use it now as in class (delete virtual = 0 classes then we can use it again)
    //    Entity entity{ 50 };

    //    Entity entityCopy{ entity }; // copy of entity

    //    printHitPoints(entity);

    //    // printHitPoints(10); // this will create an entity withouth adding explicit

    //    // Entity entity2 = 100; // valid withoth explicit keyword in class because we have a constructor with int if we dont modify class with explicit

    //    Entity entity2 = Entity{ 100 };
    //}

    Player player = Player();

    std::cout << "--- Draw Test ---" << std::endl;

    player.draw();

    Entity* e = &player;
    e->update(0.1f);
    e->draw(); // withouth virtual keyword it will invoke enity draw! with virtual keyword it will invoke player draw!

    return 0;
}