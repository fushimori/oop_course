#include "bear.h"

Bear::Bear(const Point<int>& position_) : NPC(position_, BearType) {}

void Bear::print() {
    std::cout << *this;
}

void Bear::print(std::ostream &os){
    os << *this;
}

void Bear::save(std::ostream &os) {
    os << BearType << std::endl;
    NPC::save(os);
}

bool Bear::accept(NPCVisitor& visitor, NPC& attacker) {
    return visitor.visit(*this, attacker);
}

std::ostream &operator<<(std::ostream &os, Bear &bear) {
    os << "Bear: " << *static_cast<NPC *>(&bear) << std::endl;
    return os;
}