
#include "vonat.hpp"

void Vonat::print(){
    std::cout << "Vonatszam: " << vonatszam << std::endl;
    std::cout << "Indulasi allomas: " << ind_allomas << ", indulasi idopont: " << ind_ido << std::endl;
    std::cout << "Erkezi allomas: " << erk_allomas << ", erkezesi idopont: " << erk_ido << std::endl;
    std::cout << "Aktualis keses: " << keses << std::endl;
    std::cout << "Kocsik szama: " << kocsi_db << std::endl;
    for (size_t i = 0; i < kocsi_db; i++){
        kocsik[i].get_helyDB();
    }
    return;
}

void Vonat::setKeses(int k){
    this->keses = k;
}

bool Vonat::operator==(const Vonat& other) const{
    return this->vonatszam == other.vonatszam;
}

bool Vonat::operator==(const String& vsz) const{
    return this->vonatszam == vsz;
}

int Vonat::getKeses() const{
    return this->keses;
}

size_t Vonat::getKocsiDB() const{
    return this->kocsi_db;
}

size_t Vonat::getKocsiHelyDB(size_t keresett){
    if (keresett >= kocsik.getSiz()){
        std::cout << "invalid idx" << std::endl;
        return -1;
    }
    return kocsik[keresett].get_helyDB();
}

const Kocsi& Vonat::getKocsi(size_t keresett) const{
    if (keresett >= kocsik.getSiz()){
        std::cout << "bad idx" << std::endl;
    }
    return kocsik[keresett];
}
Kocsi& Vonat::getKocsi(size_t keresett){
    if (keresett >= kocsik.getSiz()){
        std::cout << "bad idx" << std::endl;
    }
    return kocsik[keresett];
}
String Vonat::get_Vonatszam() const{
    return this->vonatszam;
}
String Vonat::get_indAll() const{
    return this->ind_allomas;
}
String Vonat::get_erkAll() const{
    return this->erk_allomas;
}
Ido Vonat::get_indIdo() const{
    return this->ind_ido;
}
Ido Vonat::get_erkIdo() const{
    return this->erk_ido;
}