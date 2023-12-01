#include <gtest/gtest.h>
#include "./npc/npc.h"
#include "./npc/ork.h"
#include "./npc/bear.h"
#include "./npc/squirrel.h"
#include "./patterns/factory.h"
#include "./patterns/visitor.h"
#include "./patterns/observer.h"

TEST(factory_pattern, Create){
    //std::vector<std::shared_ptr<NPC>> vector;
    std::shared_ptr<NPC> ork = NPCFactory::factory(NpcType(0), Point(std::rand() % 100, std::rand() % 100));
    std::shared_ptr<NPC> bear = NPCFactory::factory(NpcType(1), Point(std::rand() % 100, std::rand() % 100));
    std::shared_ptr<NPC> squirrel = NPCFactory::factory(NpcType(2), Point(std::rand() % 100, std::rand() % 100));

    ASSERT_TRUE(dynamic_cast<Ork*>(ork.get()) != nullptr);
    ASSERT_TRUE(dynamic_cast<Bear*>(bear.get()) != nullptr);
    ASSERT_TRUE(dynamic_cast<Squirrel*>(squirrel.get()) != nullptr);
}

TEST(factory_pattern, Exception){
    ASSERT_THROW( ( NPCFactory::factory(NpcType(3), Point(std::rand() % 100, std::rand() % 100)) ), std::invalid_argument);
}

TEST(visitor_pattern, Ork){

    FightVisitor visitor;

    std::shared_ptr<NPC> ork = std::make_shared<Ork>(Point(1, 1));
    std::shared_ptr<NPC> ork1 = std::make_shared<Ork>(Point(2, 2));
    std::shared_ptr<NPC> bear = std::make_shared<Bear>(Point(3, 3));
    std::shared_ptr<NPC> squirrel = std::make_shared<Squirrel>(Point(5, 5));

    ASSERT_TRUE(ork->accept(visitor, *ork1));
    ASSERT_FALSE(ork->accept(visitor, *bear));
    ASSERT_FALSE(ork->accept(visitor, *squirrel));

}

TEST(visitor_pattern, Bear){

    FightVisitor visitor;

    std::shared_ptr<NPC> ork = std::make_shared<Ork>(Point(1, 1));
    std::shared_ptr<NPC> bear = std::make_shared<Bear>(Point(3, 3));
    std::shared_ptr<NPC> bear1 = std::make_shared<Bear>(Point(4, 4));
    std::shared_ptr<NPC> squirrel = std::make_shared<Squirrel>(Point(5, 5));

    ASSERT_TRUE(bear->accept(visitor, *ork));
    ASSERT_FALSE(bear->accept(visitor, *bear1));
    ASSERT_FALSE(bear->accept(visitor, *squirrel));
}

TEST(visitor_pattern, Squirrel){

    FightVisitor visitor;

    std::shared_ptr<NPC> ork = std::make_shared<Ork>(Point(1, 1));
    std::shared_ptr<NPC> bear = std::make_shared<Bear>(Point(3, 3));
    std::shared_ptr<NPC> squirrel = std::make_shared<Squirrel>(Point(5, 5));
    std::shared_ptr<NPC> squirrel1 = std::make_shared<Squirrel>(Point(6, 6));

    ASSERT_TRUE(squirrel->accept(visitor, *ork));
    ASSERT_TRUE(squirrel->accept(visitor, *bear));
    ASSERT_FALSE(squirrel->accept(visitor, *squirrel1));
}

TEST(observer_pattern, screen_observer) {
    std::shared_ptr<NPC> attacker = std::make_shared<Ork>(Point(1, 1));
    std::shared_ptr<NPC> defender = std::make_shared<Bear>(Point(3, 3));
    std::shared_ptr<Observer> observer = ScreenObserver::get();
    
    testing::internal::CaptureStdout();
    observer->on_fight(*attacker, *defender, true);
    std::string output = testing::internal::GetCapturedStdout();
    
    ASSERT_EQ(output, "\nMurder --------\nKiller: Ork: (x: 1; y: 1) \nVictim: Bear: (x: 3; y: 3) \n");
}

TEST(observer_pattern, file_observer) {
    std::shared_ptr<NPC> attacker = std::make_shared<Ork>(Point(1, 1));
    std::shared_ptr<NPC> defender = std::make_shared<Bear>(Point(3, 3));
    std::string filename = "log.txt";
    std::shared_ptr<Observer> observer = FileObserver::get(filename);
    
    observer->on_fight(*attacker, *defender, true);

    std::ifstream file(filename);
    std::string content((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());
    file.close();
    ASSERT_TRUE(content.find("Murder --------") != std::string::npos);
    ASSERT_TRUE(content.find("Killer: Ork: (x: 1; y: 1)") != std::string::npos);
    ASSERT_TRUE(content.find("Victim: Bear: (x: 3; y: 3)") != std::string::npos);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 
