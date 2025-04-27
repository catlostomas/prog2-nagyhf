
#include <iostream>
#include "string5.h"
#include "menu.hpp"
#include "hely.hpp"
#include "kocsi.hpp"
#include "vonat.hpp"
#include "dinTomb.hpp"

int main(){
    /*
    DinTomb<Hely> helyTomb;
    Hely hely1(12);
    Hely hely2(13);
    helyTomb.clear();
    helyTomb.push_back(hely1);
    helyTomb.push_back(hely2);
    std::cout << helyTomb[0] << helyTomb[1] << std::endl;
    helyTomb[1].foglal();
    helyTomb.del_element(hely1);
    std::cout << helyTomb[0];

    Kocsi kocsi(1,5);
    for (int i = 0; i < 5; i++){
        std::cout << kocsi.get_hely(i);
    }
    kocsi.foglal_hely(0);
    std::cout << kocsi.get_hely(0) << std::endl;
    */
    Menu menu;
    menu.mainloop();
    return 0;
}
