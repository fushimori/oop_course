#include "observer.h"


FileObserver::FileObserver(std::string flname) {
    this->filename_ = flname;
    this->file_ = std::ofstream(flname);
    if (!(file_.is_open())) {
        std::cout << "Observer's file opening error!" << std::endl;
    }
}

FileObserver::~FileObserver() {
    this->file_.close();
}

std::shared_ptr<Observer> FileObserver::get(std::string filename) {
    static FileObserver instance(filename);
    return std::shared_ptr<Observer>(&instance, [](Observer *) {});
}
    
void FileObserver::on_fight(NPC& attacker, NPC& defender, bool win){
    if (win){
        if(file_.is_open()){
            file_ << std::endl
                << "Murder --------" << std::endl;
            file_ << "Killer: ";
            attacker.print(file_);
            // file_ << attacker;
            file_ << "Victim: ";
            // file_ << defender;
            defender.print(file_);
        }
        else{
            std::cerr << "Observer's file opening error!" << std::endl;
        }
    }
        
}



std::shared_ptr<Observer> ScreenObserver::get(){
    static ScreenObserver instance;
    return std::shared_ptr<Observer>(&instance, [](Observer *) {});
}

void ScreenObserver::on_fight(NPC& attacker, NPC& defender, bool win) {
    if (win){
        std::cout << std::endl
                << "Murder --------" << std::endl;
        std::cout << "Killer: ";
        attacker.print();
        std::cout << "Victim: ";
        defender.print();
    }
}