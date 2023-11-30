#include "npc.h"

NPC::NPC(const Point<int>& position_, NpcType type_) : position(position_), type(type_) {}

void NPC::save(std::ostream &os) {
    os << position.x_ << std::endl;
    os << position.y_ << std::endl;
}

bool NPC::is_close(const std::shared_ptr<NPC> &other, size_t distance) const {
    if (std::pow(position.x_ - other->position.x_, 2) + std::pow(position.y_ - other->position.y_, 2) <= std::pow(distance, 2))
        return true;
    else
        return false;
}

void NPC::subscribe(std::shared_ptr<Observer> observer){
    observers.push_back(observer);
}

void NPC::fight_notify(NPC& defender, bool win){
    for (auto &o : observers)
        o->on_fight(*this, defender, win);
}

std::ostream &operator<<(std::ostream &os, NPC &npc) {
    os << npc.position << " ";
    return os;
}