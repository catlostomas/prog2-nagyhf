#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <cstdlib>
#include "dinTomb.hpp"
#include "vonat.hpp"
#include "jegy.hpp"
#include "fajlKezeles.hpp"

class Menu{
private:
    DinTomb<Vonat> vonatok;
    DinTomb<Jegy> jegyek;
public:
    void mainloop();
    void show();
    int get_func();
    void call_func();
    void uj_vonat();
    void vonat_torlese();
    size_t vonat_idx_keres(const String& vsz);
    void vonat_torol();
    void keses_beallit();
    void foglal();
    int randomJegyID();
};

#endif // DINTOMB_HPP
