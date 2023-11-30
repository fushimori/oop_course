#include <gtest/gtest.h>
#include "./npc/npc.h"
#include "./npc/ork.h"
#include "./npc/bear.h"
#include "./npc/squirrel.h"
#include "./patterns/factory.h"

TEST(factory_pattern, test1 ){
    std::vector<std::shared_ptr<NPC>> vector;
    std::shared_ptr<NPC> ork = NPCFactory::factory(NpcType(0), Point(std::rand() % 100, std::rand() % 100));
    std::shared_ptr<NPC> bear = NPCFactory::factory(NpcType(1), Point(std::rand() % 100, std::rand() % 100));
    std::shared_ptr<NPC> squirrel = NPCFactory::factory(NpcType(2), Point(std::rand() % 100, std::rand() % 100));

    EXPECT_TRUE(dynamic_cast<Ork*>(ork.get()) != nullptr);
    EXPECT_TRUE(dynamic_cast<Bear*>(bear.get()) != nullptr);
    EXPECT_TRUE(dynamic_cast<Squirrel*>(squirrel.get()) != nullptr);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 
