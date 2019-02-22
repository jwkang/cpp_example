#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include "_macro.hpp"
#include "AbstractFactory.hpp"

int main()
{
    std::unique_ptr<HyperActorFactory> hyperActorFactory;
    hyperActorFactory.reset(new HyperActorFactory());

    std::unique_ptr<Actor> actor(hyperActorFactory->createActor("player", 1));
    // same as actor.reset(hyperActorFactory->createActor("player", 1));    
}
