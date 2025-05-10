

#include "kocsi.hpp"

Hely Kocsi::get_hely(int id){
    return helyTomb[id];
}
Hely Kocsi::get_hely(size_t id){
    return helyTomb[id];
}
const Hely Kocsi::get_hely(size_t id) const{
    return helyTomb[id];
}
bool Kocsi::is_tele(){
    if (foglalt_db >= hely_db){
        return false;
    }
    else{
        return true;
    }
}

void Kocsi::foglal_hely(int idx){
    if (idx < 0 || idx >= hely_db){
        std::cout << "rossz idx" << std::endl;
        return;
    }
    if (!helyTomb[idx].getFoglalt()){
        helyTomb[idx].foglal();
        foglalt_db++;
    }
    else{
        std::cout << "mar foglalt" << std::endl;
    }
}

int Kocsi::get_helyDB() const{
    return hely_db;
}

Kocsi& Kocsi::operator=(const Kocsi& rhs){
    if (this != &rhs){
        this->hely_db = rhs.hely_db;
        this->kocsi_szam = rhs.kocsi_szam;
        this->foglalt_db = rhs.foglalt_db;
        this->helyTomb = rhs.helyTomb;
    }
    return *this;
}

size_t Kocsi::getSzabadHely() const{
    return this->hely_db - this->foglalt_db;
}