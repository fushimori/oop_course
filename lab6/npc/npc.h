#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <cmath>
#include <algorithm>
#include "../point/point.h"

class NPC;
class Squirrel;
class Bear;
class Ork;

enum NpcType
{
    OrkType = 0,
    BearType = 1,
    SquirrelType = 2,
};

class NPCVisitor {
public:
    virtual bool visit(Ork& Ork, NPC& attacker) = 0;
    virtual bool visit(Bear& Bear, NPC& attacker) = 0;
    virtual bool visit(Squirrel& Squirrel, NPC& attacker) = 0;

};

class Observer {
public:
    virtual void on_fight(NPC& attacker, NPC& defender, bool win) = 0;
};

class NPC {

    friend std::ostream &operator<<(std::ostream &os, NPC &npc);

public:
    Point<int> position;
    NpcType type;
    std::vector<std::shared_ptr<Observer>> observers;

    NPC() = default;
    NPC(const Point<int>& position_, NpcType type_);

    virtual void print() = 0;
    virtual void print(std::ostream &os) = 0;
    virtual void save(std::ostream &os);

    virtual bool accept(NPCVisitor& visitor, NPC& attacker) = 0;
    virtual bool is_close(const std::shared_ptr<NPC> &other, size_t distance) const;

    void subscribe(std::shared_ptr<Observer> observer );
    void fight_notify(NPC& defender, bool win);
};

std::ostream &operator<<(std::ostream &os, NPC &npc);