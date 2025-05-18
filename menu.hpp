/**
 * @file menu.hpp
 * @brief Header file a menu osztályhoz
 */

#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <cstdlib>
#include "dinTomb.hpp"
#include "vonat.hpp"
#include "jegy.hpp"
#include "fajlKezeles.hpp"
#include "test_esetek.hpp"
#include "memtrace.h"

/**
 * @class Menu
 * @brief A programot irányító osztály
 * 
 * A programot irányítja, vonatokat és jegyeket kezel
 */
class Menu{
private:
    DinTomb<Vonat> vonatok; /**< Vonatok tömbje, amelyek a rendszerben vannak */
    DinTomb<Jegy> jegyek;   /**< Jegyek tömbje, amelyek a rendszerben vannak */
public:
    /**
     * @brief Menu, amit indításkor kiír a program
     * 
     * Az adatokat a két fájlból beolvassa, a funkciókat kiírja a konzolra,
     * meghívja a felhasználó által választott függvényt és menti az adatokat kilépéskor
     */
    void mainloop();

    /**
     * @brief Az admin menü opcióit írja ki
     * 
     * Azokat a funkciókat írja ki a konzolra, amelyeket az admin felhasználók használhatnak
     */
    void showAdmin() const;

    /**
     * @brief Az admin függvényeket kezeli
     * 
     * Kiírja az admin függvényeket és meghívja a választott funkció függvényét
     * @throws std::out_of_range kivételt dob, ha helytelen funckiót akarunk meghívni
     */
    void AdminMainloop();

    /**
    * @brief A menü opcióit kiírja
    * 
    * Azokat a funciókat írja ki a konzolra, amelyeket az átlagos felhasználó használhat
    */
    void show() const;

    /**
    * @brief Logo
    * 
    * A konzolra kiír egy vonat ASCII ábrázolását
    */
    void showLogo() const;

    /**
    * @brief Hitelesíiti, hogy helyes funkciót választottunk
    * 
    * @return Egy intet ad vissza, ha helyes funkciót választottunk
    * @throws std::out_of_range kivételt dob, ha helytelen funkciót választottunk
    */
    int get_func();

    /**
     * @brief Új vonatot hoz létre
     * 
     * Bekéri az adatokat a felhasználótól (vonatszám, állomások, időpontok, kapacitások),
     * és hozzáadja a rendszerhez az új vonatot, ha még nem találhato meg a rendszerben
     * 
     * @throws std::runtime_error kivételt dob, ha már a rendszerben van a vonat
     * @throws std::out_of_range kivételt dob, ha hibás időpontokat akarunk megadni
     */
    void uj_vonat();

    /**
     * @brief Töröl egy vonatot a rendszerből
     * 
     * Bekéri a vonatszámot es az alapján megkeresi a vonatot.
     * Miután megtalálta a vonatot, megkérdezi a felhasználót, hogy tényleg szeretné-e a
     * vonatot törölni. Ha a felhasználó 1-et ír be, akkor a vonatot törli a rendszer, ha
     * 0-t akkor viszont nem.
     */
    void vonat_torlese();

    /**
     * @brief Vonatszám alapján keres ki egy vonatot
     * 
     * Sorban veszi az összes vonatot es összehasonlítja a vonatszámokat
     * 
     * @param vsz A keresett vonat száma
     * @return size_t a keresett vonat indexe
     * @throws std::out_of_range kivételt dob, ha a keresett vonat nem létezik
     */
    size_t vonat_idx_keres(const String& vsz);
    
    void vonat_torol();

    /**
     * @brief Keses beállít egy adott vonatnak
     * 
     * Bekéri a vonatszámot es az alapján megkeresi a vonatot
     * Miután megtalálta a vonatot kiírja az aktuális késést és megkérdezi a felhasználót
     * mennyire szeretné a késést beállítani 
     */
    void keses_beallit();

    /**
     * @brief Lefoglal egy helyet a keresett vonaton
     * 
     * @param idx A vonat indexe, amelyiket helyet szeretnénk foglalni
     * @throws std::out_of_range kivételet dob ha a kocsi vagy hely nem létezik
     * @throws std::runtime_error kivételt dob ha a hely már foglalt
     */
    void foglal(size_t idx);

    /**
     * @brief Random létrehoz egy JegyID-t
     * 
     * @return Egy 5 számjegyű random int
     */
    int randomJegyID();

    /**
     * @brief Kiírja a keresett vonat adatait a konzolra
     * 
     * Vonatszám alapján kiírja az összes adatát a keresett vonatnak
     */
    void vonatAdatok();

    /**
     * @brief Ket végállomás között foglal helyet
     * 
     * Bekéri a két végállomást és kikeresi a vonatokat, amelyek a két végállomás között 
     * közlekednek. A megfelelő vonatokat kiírja és megkérdezi a felhasználót melyik vonatra
     * szeretne helyet foglalni. Ha a felhasználó megadja a vonat vonatszámát, akkor 
     * meghívja a foglal() függvény.
     */
    void foglalVegallomasok();

    /**
     * @brief Konzol törli
     * 
     * A konzolt törli az operációs rendszerekhez specifikus parancsokkal
     * Nem csinál semmit, ha a teszteseteket futtatjuk (CPORTA makró)
     */
    void clear();

    /**
     * @brief Visszaad egy vonatot az index alapján
     * 
     * @param idx A keresett vonat indexe a tömbben
     * @return Vonat Visszaadja a keresett vonatot
     * @throws std::out_of_range kivétetlt dob ha az index helytelen
     */
    Vonat getVonat(size_t idx) const;

    /**
     * @brief Jegy getter
     * 
     * @param idx A keresett jegy indexe
     * @return Jegy A keresett jegy
     */
    Jegy getJegy(size_t idx) const;

    /**
     * @brief Az jegyek dinamikus tömbböt adja vissza (tesztesetekhez)
     * 
     * @return const DinTomb<Jegy>& referencia a jegy tömbre
     */
    const DinTomb<Jegy>& getJegyek() const;

    /**
     * @brief Az vonatok dinamikus tömbböt adja vissza (tesztesetekhez)
     * 
     * @return const DinTomb<Vonat>& referencia a vonatok tömbre
     */
    const DinTomb<Vonat>& getVonatok() const;
};

#endif // DINTOMB_HPP

