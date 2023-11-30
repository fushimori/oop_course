#pragma once

#include <iostream>
#include <fstream>
#include <memory>
#include "../npc/npc.h"


class FileObserver : public Observer {
private:
    std::string filename_;
    std::ofstream file_;

    FileObserver(std::string flname);
    ~FileObserver();
    
public:
    static std::shared_ptr<Observer> get(std::string filename);
    
    void on_fight(NPC& attacker, NPC& defender, bool win) override; 
};

class ScreenObserver : public Observer {
private:
    ScreenObserver(){};

public:
    static std::shared_ptr<Observer> get();
    void on_fight(NPC& attacker, NPC& defender, bool win) override;
};