#pragma once // Compiler include header file once!

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