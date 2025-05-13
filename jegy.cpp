#include "jegy.hpp"

void Jegy::print(){
    std::cout << "Vonatszam: " << vonatszam << std::endl;
    std::cout << "Indulasi allomas: " << ind_all << " indulasi ido: " << ind_ido << std::endl;
    std::cout << "Erkezesi allomas:" << erk_all << " erkezesi ido: " << erk_ido << std::endl;
    std::cout << "Kocsi: " << kocsiszam << ", hely: " << helyszam << std::endl;
    std::cout << "Azonosito: " << Jegy_ID << std::endl;
}
