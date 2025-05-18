/**
 * @file fajlKezeles.hpp
 * @brief Fajl kezelo fuggvenyek
 */

#ifndef FAJLKEZELES_HPP
#define FAJLKEZELES_HPP


#include <fstream>
#include <sstream>
#include "string5.h"
#include "dinTomb.hpp"
#include "vonat.hpp"
#include "jegy.hpp"
#include "memtrace.h"

/**
 * @class Fajl
 * @brief Segéd osztály, ami feladata az fájlokba írni és onnan olvasni
 */
class Fajl{
public:

    /**
     * @brief Vonatok adatait olvassa be a fájlból
     * 
     * Beolvassa a vonatokat a fájlból és betölti a vonatok tömbbe
     * 
     * @param filename a fájl neve amelyből olvas be a függvény
     * @param vonatok dinamikus tömb, amiben a vonatokat tároljuk
     * @throws std::runtime_error kivételt dob, ha a fájl nem található, vagy rossz a fájl neve
     */
    static void beolvasVonatok(const std::string& filename, DinTomb<Vonat>& vonatok);

    /**
     * @brief Jegyek adatait olvassa be a fájlból
     * 
     * Beolvassa a jegyeket a fájlbóol és betölti a jegyek tömbbe
     * 
     * @param filename a fájl neve amelyből olvas be a függvény
     * @param jegyek dinamikus tömb, amiben a jegyeket tároljuk
     * @throws std::runtime_error kivételt dob, ha a fájl nem található, vagy rossz a fájl neve
     */
    static void beolvasJegyek(const std::string& filename, DinTomb<Jegy>& jegyek);

    /**
     * @brief Menti a vonatok adatait egy fájlba
     * 
     * Az összes vonat adatait menti egy adott formátumban
     * 
     * @param filename a fájl neve amelybe ment a függvény
     * @param vonatok dinamikus tömb, amely tartalmazza a vonatokat
     * @throws std::runtime_error kivételt dob, ha a fájl nem található, vagy rossz a fájl neve
     */
    static void mentesVonatok(const std::string& filename, const DinTomb<Vonat>& vonatok);

    /**
     * @brief Menti a jegyek adatait egy fájlba
     * 
     * Az összes jegy adatait menti egy adott formátumban
     * 
     * @param filename a fájl neve amelybe ment a függvény
     * @param jegyek dinamikus tömb, amely tartalmazza a jegyeket
     * @throws std::runtime_error kivételt dob, ha a fájl nem található, vagy rossz a fájl neve
     */
    static void mentesJegyek(const std::string& filename, const DinTomb<Jegy>& jegyek);
};


#endif // FAJLKEZELES_HPP

