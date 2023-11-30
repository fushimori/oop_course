#pragma once

#include <iostream>
#include <string>
#include "npc.h"

class Bear : public NPC {

    friend std::ostream &operator<<(std::ostream &os, Bear &bear);

public:
    Bear() = default;
    Bear(const Point<int>& position_);

    void print() override;
    virtual void print(std::ostream &os) override;
    
    virtual void save(std::ostream &os) override;
    virtual bool accept(NPCVisitor& visitor, NPC& attacker) override;
};

std::ostream &operator<<(std::ostream &os, Bear &bear);