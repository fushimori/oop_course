#include "ork.h"

Ork::Ork(const Point<int>& position_) : NPC(position_, OrkType) {}

void Ork::print() {
    std::cout << *this;
}

void Ork::print(std::ostream &os){
    os << *this;
}

void Ork::save(std::ostream &os) {
    os << OrkType << std::endl;
    NPC::save(os);
}

bool Ork::accept(NPCVisitor& visitor, NPC& attacker) {
    return visitor.visit(*this, attacker);
}

std::ostream &operator<<(std::ostream &os, Ork &ork) {
    os << "Ork: " << *static_cast<NPC *>(&ork) << std::endl;
    return os;
}