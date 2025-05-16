#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <cstdlib>
#include "dinTomb.hpp"
#include "vonat.hpp"
#include "jegy.hpp"
#include "fajlKezeles.hpp"
#include "test_esetek.hpp"

class Menu{
private:
    DinTomb<Vonat> vonatok;
    DinTomb<Jegy> jegyek;
public:
    void mainloop();
    void showAdmin();
    void AdminMainloop();
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
    void vonatAdatok();
    Vonat getVonat(size_t idx) const;
    Jegy getJegy(size_t idx) const;
    const DinTomb<Jegy>& getJegyek() const;
    const DinTomb<Vonat>& getVonatok() const;
};

#endif // DINTOMB_HPP
