#include "npc.h"

NPC::NPC(const Point<int>& position_, NpcType type_) : position(position_), type(type_) {}

void NPC::save(std::ostream &os) {
    os << position.x_ << std::endl;
    os << position.y_ << std::endl;
}

bool NPC::is_close(const std::shared_ptr<NPC> &other) {
    std::lock_guard<std::mutex> lck(mtx);
    size_t distance{0};
    if (this -> type == OrkType){
        distance = 10;
    } else if (this -> type == SquirrelType){
        distance = 5;
    } else if (this -> type == BearType){
        distance = 10;
    }
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

NpcType NPC::get_type(){
    return type;
}

bool NPC::is_alive()
{
    std::lock_guard<std::mutex> lck(mtx);
    return alive;
}

void NPC::must_die()
{
    std::lock_guard<std::mutex> lck(mtx);
    alive = false;
}

std::ostream &operator<<(std::ostream &os, NPC &npc) {
    os << npc.position << " ";
    return os;
}

void NPC::move(int shift_x, int shift_y, int max_x, int max_y) {
    std::lock_guard<std::mutex> lck(mtx);
    int move_distance = 0;

    if (this -> type == OrkType){
        move_distance = 20;
    } else if (this -> type == SquirrelType){
        move_distance = 5;
    } else if (this -> type == BearType){
        move_distance = 5;
    }

    shift_x = move_distance * shift_x;
    shift_y = move_distance * shift_y;

    if ((position.x_ + shift_x >= 0) && (position.x_ + shift_x <= max_x))
        position.x_ += shift_x;
    if ((position.y_ + shift_y >= 0) && (position.y_ + shift_y <= max_y))
        position.y_ += shift_y;
}