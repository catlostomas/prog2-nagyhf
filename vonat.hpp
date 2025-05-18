/**
 * @file vonat.hpp
 * @brief A vonat osztály implementációja
 */

#ifndef VONAT_HPP
#define VONAT_HPP

#include "kocsi.hpp"
#include "string5.h"
#include "ido.hpp"
#include "memtrace.h"

/**
 * @class Vonat
 * @brief Egy vonatot képvisel
 *
 * Minden adatot tárol, ami egy vonathoz tartozik
 */

class Vonat{
    String vonatszam;
    String ind_allomas;
    String erk_allomas;
    Ido ind_ido;
    Ido erk_ido;
    int keses;
    size_t kocsi_db;
    DinTomb<Kocsi> kocsik;
public:

    /**
     * @brief Default konstruktor
     * 
     * Létrehoz egy üres vonatot
     */
    Vonat(): vonatszam(""), ind_allomas(""), erk_allomas(""), ind_ido(0, 0), erk_ido(0, 0), keses(0), kocsi_db(0), kocsik() {};

    /**
     * @brief Paraméteres konstruktor
     * 
     * Létrehoz egy vonatot az adott paraméterek szerint
     * 
     * @param vsz Vonatszám
     * @param ind_all Indulási állomás
     * @param erk_all Érkezési állomás
     * @param indIdo Indulási időpont
     * @param erkIdo Érkezési időpont
     * @param k Késés (default: 0)
     * @param kocsDB Kocsik száma (default: 0)
     * @param KocsibanHely Hány hely van 1 kocsiban (default: 50)
     */
    Vonat(const String& vsz, const String& ind_all, const String& erk_all, const Ido& indIdo, const Ido& erkIdo, int k = 0, size_t kocsDB = 0, size_t KocsibanHely = 50): vonatszam(vsz), ind_allomas(ind_all), erk_allomas(erk_all), ind_ido(indIdo), erk_ido(erkIdo), keses(k), kocsi_db(kocsDB), kocsik() {
        for (size_t i = 0; i < kocsDB; i++){
            kocsik.push_back(Kocsi(i, KocsibanHely)); 
        }
    };
    
    /**
     * @brief Másoló konstruktor
     * 
     * Létrehoz egy vonatot egy másik vonat adataival
     * 
     * @param rhs Másik vonat, amiből másolni fog
     */
    Vonat(const Vonat& rhs): vonatszam(rhs.vonatszam), ind_allomas(rhs.ind_allomas), erk_allomas(rhs.erk_allomas), ind_ido(rhs.ind_ido), erk_ido(rhs.erk_ido), keses(rhs.keses), kocsi_db(rhs.kocsi_db) {
        for (size_t i = 0; i < rhs.kocsik.getSiz(); ++i){
            kocsik.push_back(rhs.kocsik[i]);
        }
    };

    /**
     * @brief Kiírja a vonat adatait a konzolba
     * 
     * Kiír minden információt sorban
     */
    void print(); 

    /**
     * @brief Késés beállitása
     * 
     * @param k Késés percben
     */
    void setKeses(int k);

    /**
     * @brief Késés getter
     * 
     * @return int Késés percben
     */
    int getKeses() const;

    /**
     * @brief Vonatszám getter
     * 
     * @return String Vonatszám
     */
    String get_Vonatszam() const;

    /**
     * @brief Indulási állomás getter
     * 
     * @return String Az indulási állomás neve
     */
    String get_indAll() const;

    /**
     * @brief Érkezési állomás getter
     * 
     * @return String Az érkezési állomás neve
     */
    String get_erkAll() const;

    /**
     * @brief Indulási idő getter
     * 
     * @return Ido Az indulás időpontja
     */
    Ido get_indIdo() const;

    /**
     * @brief Érkezési idő getter
     * 
     * @return Ido Az érkezés időpontja
     */
    Ido get_erkIdo() const;

    /**
     * @brief KocsiDB getter
     * 
     * @return size_t Hány kocsi található a vonaton
     */
    size_t getKocsiDB() const;

    /**
     * @brief Hány hely van egy adott kocsiban
     * 
     * @param keresett A kocsi sorszáma
     * @return size_t A helyek száma
     * @throws std::out_of_range kivélt dob, ha az index helytelen
     */
    size_t getKocsiHelyDB(size_t keresett);

    /**
     * @brief Egy adott kocsi getter (nem const)
     * 
     * @param keresett Kocsi index
     * @return Kocsi& referencia a keresett kocsira
     * @throws std::out_of_range kivélt dob, ha az index helytelen
     */
    Kocsi& getKocsi(size_t keresett);

    /**
     * @brief Egy adott kocsi getter (const)
     * 
     * @param keresett Kocsi index
     * @return const Kocsi& referencia a keresett kocsira
     * @throws std::out_of_range kivélt dob, ha az index helytelen
     */
    const Kocsi& getKocsi(size_t keresett) const;

    /**
     * @brief Egyenlőség operátor két vonat összehasonlítására
     * 
     * Két vonatot hasonlít össze
     * 
     * @param other A másik vonat
     * @return bool True, ha megegyeznek és False ha nem
     */
    bool operator==(const Vonat& masik) const;

    /**
     * @brief Egyenlőség operátor két vonatszám összehasonlítására
     * 
     * Két vonat vonatszámat hasonlítja össze
     * 
     * @param vsz A másik vonatszám
     * @return bool True, ha megegyeznek és False ha nem
     */
    bool operator==(const String& vsz) const;

    /**
     * @brief Destruktor
     * 
     * Törli az adatokat
     */
    ~Vonat() {kocsik.clear();};

};

#endif // VONAT_HPP

