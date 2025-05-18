/**
 * @file jegy.hpp
 * @brief Jegy osztály megvalósítása
 */

#ifndef JEGY_HPP
#define JEGY_HPP

#include "ido.hpp"
#include "string5.h"
#include "memtrace.h"

/**
 * @class Jegy
 * @brief Egy jegyet képvisel
 * Minden adatot tárol, ami egy jegyhez kell
 */
class Jegy{
    String ind_all;
    String erk_all;
    Ido ind_ido;
    Ido erk_ido;
    String vonatszam;
    int kocsiszam;
    int helyszam;
    int Jegy_ID;
public:

    /**
     * @brief Default konstruktor
     * 
     * Létrehoz egy üres jegyet
     */
    Jegy(): ind_all(""), erk_all(""), ind_ido(0,0), erk_ido(0,0), vonatszam(""), kocsiszam(0), helyszam(0), Jegy_ID(0) {};

    /**
     * @brief Paraméteres konstruktor
     * 
     * Létrehoz egy jegyet az adott paraméterek szerint
     * 
     * @param ia Honnan
     * @param ea Hova
     * @param ind Indulás ideje
     * @param erk Erkezés ideje
     * @param vsz Vonatszám
     * @param ksz Kocsiszám
     * @param hsz Jegyszám
     * @param id Jegyazonosító
     */
    Jegy(String ia, String ea, Ido ind, Ido erk, String vsz, int ksz, int hsz, int id): ind_all(ia), erk_all(ea), ind_ido(ind), erk_ido(erk), vonatszam(vsz), kocsiszam(ksz), helyszam(hsz), Jegy_ID(id) {};

    /**
     * @brief Kiírja a jegy adatait a standard output-ra
     */
    void print();

    /**
     * @brief Egyenlőség operátor
     * 
     * Két jegyet hasonlít össze
     * 
     * @param masik A másik jegy, amivel hasonlítunk össze
     * @return bool True, ha megegyeznek és false, ha nem
     */
    bool operator==(const Jegy& masik) const;

    /**
     * @brief Indulási állomás getter
     * 
     * @return String Indulási állomás
     */
    String getIndAll() const {return ind_all;};

    /**
     * @brief Érkezési állomás getter
     * 
     * @return String Érkezési állomás
     */
    String getErkAll() const {return erk_all;};

    /**
     * @brief Indulási idő getter
     * 
     * @return Ido Indulási idő
     */
    Ido getIndIdo() const {return ind_ido;};

    /**
     * @brief Érkezési idő getter
     * 
     * @return Ido Érkezési idő
     */
    Ido getErkIdo() const {return erk_ido;};

    /**
     * @brief Vonatszám getter
     * 
     * @return String A vonatszám
     */
    String getVsz() const {return vonatszam;};

    /**
     * @brief Kocsiszám getter
     * 
     * @return int A kocsi sorszáma
     */
    int getKocsiszam() const {return kocsiszam;};

    /**
     * @brief Helyszam getter
     * 
     * @return int A hely sorszáma
     */
    int getHelyszam() const {return helyszam;};

    /**
     * @brief JegyID getter
     * 
     * @return int A jegy azonosítója
     */
    int getJegyID() const {return Jegy_ID;};
};

#endif // JEGY_HPP

