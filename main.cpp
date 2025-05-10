
#include <iostream>
#include "string5.h"
#include "menu.hpp"
#include "hely.hpp"
#include "kocsi.hpp"
#include "vonat.hpp"
#include "dinTomb.hpp"
#include "gtest_lite.h"

int main(){
// helyes filename - vonatokBeolvasasa
    TEST(NoThrow, VonatokBeolvasasa){
        Fajl file;
        DinTomb<Vonat> vonatok;
        String test = "vonatok.txt";
        try {
            file.beolvasVonatok(test.c_str(), vonatok);
            EXPECT_NO_THROW("Nem jott kivetel");
        } catch (std::runtime_error & err) {}
    } END;
// helytelen filename - vonatokBeolvasasa
    TEST(Throw, VonatokBeolvasasa){
        Fajl file;
        DinTomb<Vonat> vonatok;
        String test = "random123456789.txt";
        try {
            file.beolvasVonatok(test.c_str(), vonatok);
            EXPECT_THROW(test, std::runtime_error);
        } catch(const std::runtime_error & err) {}
    } END;
// helyes filename - jegyekBeolvasasa
    TEST(NoThrow, JegyekBeolvasasa){
        Fajl file;
        DinTomb<Jegy> jegyek;
        String test = "jegyek.txt";
        try {
            file.beolvasJegyek(test.c_str(), jegyek);
            EXPECT_NO_THROW();
        } catch (std::runtime_error& err) {}
    } END;
// helytelen filename - jegyekBeolvasasa
    TEST(Throw, JegyekBeolvasasa){
        Fajl file;
        DinTomb<Jegy> jegyek;
        String test = "random123456789.txt";
        try {
            file.beolvasJegyek(test.c_str(), jegyek);
            EXPECT_THROW(test, std::runtime_error);
        } catch (const std::runtime_error& err) {};
    } END;


// VONATOK - Konstruktorok

// default construktor
    TEST(Default_Construktor, VonatClass){
        Vonat test;
        EXPECT_EQ(strcmp(test.get_Vonatszam().c_str(), ""), 0);
        EXPECT_EQ(strcmp(test.get_indAll().c_str(), ""), 0);
        EXPECT_EQ(strcmp(test.get_erkAll().c_str(), ""), 0);
        EXPECT_TRUE(test.get_indIdo().ora == 0 && test.get_indIdo().perc == 0);
        EXPECT_TRUE(test.get_erkIdo().ora == 0 && test.get_erkIdo().perc == 0);
        EXPECT_TRUE(test.getKeses() == 0);
        EXPECT_TRUE(test.getKocsiDB() == 0);
    } END;
// parameteres construktor
    TEST(Param_Construktor, VonatClass){
        Ido ind (12, 12);
        Ido erk (13, 13);
        Vonat test("vonatszam", "ind_allomas", "erk_allomas", ind, erk, 60, 5);
        EXPECT_EQ(strcmp(test.get_Vonatszam().c_str(), "vonatszam"), 0);
        EXPECT_EQ(strcmp(test.get_indAll().c_str(), "ind_allomas"), 0);
        EXPECT_EQ(strcmp(test.get_erkAll().c_str(), "erk_allomas"), 0);
        EXPECT_TRUE(test.get_indIdo().ora == ind.ora && test.get_indIdo().perc == ind.perc);
        EXPECT_TRUE(test.get_erkIdo().ora == erk.ora && test.get_erkIdo().perc == erk.perc);
        EXPECT_TRUE(test.getKeses() == 60);
        EXPECT_TRUE(test.getKocsiDB() == 5);
    } END;
// masolo konstruktor
    TEST(Copy_Construktor, VonatClass){
        Ido ind (12, 12);
        Ido erk (13, 13);
        Vonat test("vonatszam", "ind_allomas", "erk_allomas", ind, erk, 60, 5);
        Vonat test2 = test;
        EXPECT_EQ(strcmp(test.get_Vonatszam().c_str(), test2.get_Vonatszam().c_str()), 0);
        EXPECT_EQ(strcmp(test.get_indAll().c_str(), test2.get_indAll().c_str()), 0);
        EXPECT_EQ(strcmp(test.get_erkAll().c_str(), test2.get_erkAll().c_str()), 0);
        EXPECT_TRUE(test.get_indIdo().ora == test2.get_indIdo().ora && test.get_indIdo().perc == test2.get_indIdo().perc);
        EXPECT_TRUE(test.get_erkIdo().ora == test2.get_erkIdo().ora && test.get_erkIdo().perc == test2.get_erkIdo().perc);
        EXPECT_TRUE(test2.getKeses() == test.getKeses());
        EXPECT_TRUE(test2.getKocsiDB() == test.getKocsiDB());
    } END;

// JEGYEK - KONSTRUKTOROK

// default konstruktor
    TEST(Default_Construktor, JegyClass){
        Jegy test;
        EXPECT_EQ(strcmp(test.getVsz().c_str(), ""), 0);
        EXPECT_EQ(strcmp(test.getIndAll().c_str(), ""), 0);
        EXPECT_EQ(strcmp(test.getErkAll().c_str(), ""), 0);
        EXPECT_TRUE(test.getIndIdo().ora == 0 && test.getIndIdo().perc == 0);
        EXPECT_TRUE(test.getErkIdo().ora == 0 && test.getErkIdo().perc == 0);
        EXPECT_TRUE(test.getKocsiszam() == 0);
        EXPECT_TRUE(test.getHelyszam() == 0);
        EXPECT_TRUE(test.getKocsiszam() == 0);
    } END;
// parameteres konstruktor
    TEST(Param_Constructor, JegyClass){
        Ido ind(12, 12);
        Ido erk(13, 13);
        Jegy test("ind_all", "erk_all", ind, erk, "vonatszam", 1, 1, 1);
        EXPECT_EQ(strcmp(test.getVsz().c_str(), "vonatszam"), 0);
        EXPECT_EQ(strcmp(test.getIndAll().c_str(), "ind_all"), 0);
        EXPECT_EQ(strcmp(test.getErkAll().c_str(), "erk_all"), 0);
        EXPECT_TRUE(test.getIndIdo().ora == ind.ora && test.getIndIdo().perc == ind.perc);
        EXPECT_TRUE(test.getErkIdo().ora == erk.ora && test.getErkIdo().perc == erk.perc);
        EXPECT_TRUE(test.getKocsiszam() == 1);
        EXPECT_TRUE(test.getHelyszam() == 1);
        EXPECT_TRUE(test.getKocsiszam() == 1);
    } END;


}
