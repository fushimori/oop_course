#include "factory.h"

std::shared_ptr<NPC> NPCFactory::factory(NpcType type, const Point<int>& position) {
    std::shared_ptr<NPC> result;
    switch(type) {
        case NpcType::BearType:
            result = std::make_shared<Bear>(position);
            break;
        case NpcType::OrkType:
            result = std::make_shared<Ork>(position);
            break;
        case NpcType::SquirrelType:
            result = std::make_shared<Squirrel>(position);
            break;
        default:
            throw std::invalid_argument("Invalid type");
            break;
    }
    if(result){
        result->subscribe(ScreenObserver::get());
        result->subscribe(FileObserver::get("log.txt"));
    }
    return result;
}