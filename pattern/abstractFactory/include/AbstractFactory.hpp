#ifndef _ABSTRACT_FACTORY_
#define _ABSTRACT_FACTORY_

#include "_macro.hpp"
#include <string>
#include <cassert>

class Actor {
public:
    virtual ~Actor() {}
};

class Player : public Actor {
public:
    Player(int arg_other) { LOG("Player construct called"); }
    virtual ~Player() { LOG("Player destuctor called"); }
};

class HyperPlayer : public Player {
public:
    HyperPlayer(int arg_other) : Player(arg_other) { LOG("HyperPlayer construct called"); }
    virtual ~HyperPlayer() { LOG("HyperPlayer destuctor called"); }
};

class Enermy : public Actor {
public:
    Enermy(int arg_other) { LOG("Enermy construct called"); }
    virtual ~Enermy() { LOG("Enermy destuctor called"); }
};

class HyperEnermy : public Enermy {
public:
    HyperEnermy(int arg_other) : Enermy(arg_other) { LOG("HyperEnermy construct called"); }
    virtual ~HyperEnermy() { LOG("HyperEnermy destuctor called"); }
};

class ActorAbstractFactory {
public:
    virtual ~ActorAbstractFactory() {}
    virtual Actor* createActor(const std::string& name, int arg_other) = 0;
};

class ActorFactory : public ActorAbstractFactory {
public:
    virtual Actor* createActor(const std::string& name, int arg_other) override {
        if ( name == "player" ) return new Player(arg_other);
        if ( name == "enermy") return new Enermy(arg_other);

        assert(!"name is not valid");
        return nullptr;
    }
};

class HyperActorFactory : public ActorAbstractFactory {
public:
    virtual Actor* createActor(const std::string& name, int arg_other) override {
        if ( name == "player" ) return new HyperPlayer(arg_other);
        if ( name == "enermy") return new HyperEnermy(arg_other);

        assert(!"name is not valid");
        return nullptr;
    }
};

#endif