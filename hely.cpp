
#include <iostream>
#include "hely.hpp"

void Hely::foglal(){
    if (!foglalt){
        foglalt = true;
    }
    else{
        std::cout << "A hely mar foglalt!" << std::endl;
    }
}

void Hely::foglalas_torles(){
    if (foglalt){
        foglalt = false;
        std::cout << "Foglalas torolve!" << std::endl;
    }
    else{
        std::cout << "Nem volt foglalt!" << std::endl;
    }
}
std::ostream& operator<<(std::ostream& os, const Hely& h){
    os << "A " << h.getID()<< ", hely foglalt-e: "<< h.getFoglalt() << std::endl;
    return os; 
}

bool Hely::operator==(const Hely& rhs) const{
    if (this->hely_ID == rhs.hely_ID && this->foglalt == rhs.foglalt){
        return true;
    }
    else{
        return false;
    }
}

Hely& Hely::operator=(const Hely& rhs){
    if (this != &rhs){
        this->hely_ID = rhs.hely_ID;
        this->foglalt = rhs.foglalt;
    }
    return *this;
}

