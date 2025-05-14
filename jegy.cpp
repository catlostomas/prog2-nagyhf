#include "jegy.hpp"

void Jegy::print(){
    std::cout << "Vonatszam: " << vonatszam << std::endl;
    std::cout << "Indulasi allomas: " << ind_all << " indulasi ido: " << ind_ido << std::endl;
    std::cout << "Erkezesi allomas:" << erk_all << " erkezesi ido: " << erk_ido << std::endl;
    std::cout << "Kocsi: " << kocsiszam << ", hely: " << helyszam << std::endl;
    std::cout << "Azonosito: " << Jegy_ID << std::endl;
}

// Jegy_ID random szam, tehat eleg azt osszehasonlitani
bool Jegy::operator==(const Jegy& masik) const{
    return (Jegy_ID == masik.Jegy_ID);
}
