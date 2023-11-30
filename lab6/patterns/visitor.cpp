#include "visitor.h"
#include "../npc/npc.h"

bool FightVisitor::visit(Ork& defender, NPC& attacker) {
    bool win = (attacker.type == OrkType);
    attacker.fight_notify(defender, win);
    return win;
}

bool FightVisitor::visit(Bear& defender, NPC& attacker) {
    bool win = (attacker.type == OrkType);
    attacker.fight_notify(defender, win);
    return win;
}

bool FightVisitor::visit(Squirrel& defender, NPC& attacker) {
    bool win = !(attacker.type == SquirrelType);
    attacker.fight_notify(defender, win);
    return win;
}