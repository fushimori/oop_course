#pragma once

#include <iostream>
#include "../npc/npc.h"
#include "../npc/ork.h"
#include "../npc/bear.h"
#include "../npc/squirrel.h"
#include "observer.h"


class FightVisitor : public NPCVisitor {
public:
    bool visit(Ork& defender, NPC& attacker) override;
    bool visit(Bear& defender, NPC& attacker) override;
    bool visit(Squirrel& defender, NPC& attacker) override;
};