#include <iostream>
#include <Player.hpp>

void printHitPoints(const Entity& e)
{
    std::cout << "Printing hitPoints: " << e.getHitpoints() << std::endl;
}

int main()
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
