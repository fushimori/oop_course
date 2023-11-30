#include "squirrel.h"

Squirrel::Squirrel(const Point<int>& position_) : NPC(position_, SquirrelType) {}

void Squirrel::print() {
    std::cout << *this;
}
void Squirrel::print(std::ostream &os){
    os << *this;
}

void Squirrel::save(std::ostream &os) {
    os << SquirrelType << std::endl;
    NPC::save(os);
}

bool Squirrel::accept(NPCVisitor& visitor, NPC& attacker) {
    return visitor.visit(*this, attacker);
}

std::ostream &operator<<(std::ostream &os, Squirrel &squirrel) {
    os << "Squirrel: " << *static_cast<NPC *>(&squirrel) << std::endl;
    return os;
}