#pragma once

#include <iostream>
#include <memory>
#include "../npc/npc.h"
#include "../npc/bear.h"
#include "../npc/ork.h"
#include "../npc/squirrel.h"
#include "observer.h"

class NPCFactory {
public:
    static std::shared_ptr<NPC> factory(NpcType type, const Point<int>& position);
};