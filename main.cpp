
#include <iostream>
#include "string5.h"
#include "menu.hpp"
#include "hely.hpp"
#include "kocsi.hpp"
#include "vonat.hpp"
#include "dinTomb.hpp"
#include "gtest_lite.h"
#include "memtrace.h"

int main(){

    //Test::futtatas();
    //return 0;

    Menu main;
    bool fut = true;
    while(fut){
        try {
            main.mainloop();
            fut = false;
        } catch (std::out_of_range& err){
            std::cout << "HIBA: " << err.what() << std::endl;
            fut = true;
        } catch (...){
            std::cout << "KRITIKUS HIBA!" << std::endl;
        }
    }
    return 0;
}

