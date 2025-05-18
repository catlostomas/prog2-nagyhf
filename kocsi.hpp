/**
 * @file kocsi.hpp
 * @brief Vonat kocsi osztály implementációja
 */
#ifndef KOCSI_HPP
#define KOCSI_HPP

#include "hely.hpp"
#include "dinTomb.hpp"
#include "memtrace.h"


/**
 * @class Kocsi
 * @brief Egy kocsit képvisel a vonatban
 *
 * Egy kocsi információit tárolja
 */
class Kocsi{
    int kocsi_szam;
    int hely_db;
    DinTomb<Hely> helyTomb;
    int foglalt_db;
public:

    /**
     * @brief Default konstruktor
     * 
     * Létrehoz egy üres kocsit
     */
    Kocsi() : kocsi_szam(0), hely_db(0), helyTomb(), foglalt_db(0) {};
    
    /**
     * @brief Paraméteres konstruktor
     * 
     * Létrehoz egy kocsi objektumot a megadott paraméterekkel
     * 
     * @param sz Kocsi száma
     * @param hdb Hány helyet tartalmaz a kocsi
     * @param fdb Hány hely már foglalt (default = 0)
     */
    Kocsi(int sz, int hdb, int fdb = 0): kocsi_szam(sz), hely_db(hdb), helyTomb(), foglalt_db(fdb) {
        for (int i = 0; i < hely_db; ++i){
            helyTomb.push_back(Hely(i));
        }
    };

    /**
     * @brief Másoló konstruktor
     * 
     * Egy másik kocsi alapján létrehoz egy kocsit
     * 
     * @param masik A másik kocsi, amiből másolni fog
     */

    Kocsi(const Kocsi& masik): kocsi_szam(masik.kocsi_szam), hely_db(masik.hely_db), helyTomb(masik.helyTomb), foglalt_db(masik.foglalt_db) {};

    /**
     * @brief Hely getter id alapján
     * 
     * @param id A hely sorszáma
     * @return Hely A keresett hely
     * @throws std::out_of_range kivételt dob ha a id helytelen
     */
    Hely get_hely(int id);

    /**
     * @brief Hely getter size_t id alapján
     * 
     * @param id A hely sorszáma
     * @return Hely A keresett hely
     * @throws std::out_of_range kivételt dob ha a id helytelen
     */
    Hely get_hely(size_t id);

    /**
     * @brief Hely getter size_t id alapján (const verzió)
     * 
     * @param id A hely sorszáma
     * @return const Hely A keresett hely
     * @throws std::out_of_range kivételt dob ha a id helytelen
     */
    const Hely get_hely(size_t id) const;

    /**
     * @brief Megnézi, hogy a kocsi tele van-e
     * 
     * @return bool True, ha a kocsi tele van és False, ha nincs tele
     */
    bool is_tele();

    /**
     * @brief getter a helyek számára
     * 
     * @return int Összesen hány hely van a kocsiban
     */
    int get_helyDB() const;

    /**
     * @brief Egy adott helyet lefoglal
     * 
     * @param idx A keresett hely indexe
     * @throws std::runtime_error kivételt dob ha már foglalt a hely
     */
    void foglal_hely(int idx);

    /**
     * @brief Értékadó operátor
     * 
     * Átmásolja egy másik kocsi adatait ebbe a kocsiba
     * 
     * @param rhs A másik kocsi
     * @return Kocsi& referencia erre a kocsira
     */
    Kocsi& operator=(const Kocsi& rhs);

    /**
     * @brief getter az üres helyek számára
     * 
     * @return size_t Hány üres hely van még a kocsiban
     */
    size_t getSzabadHely() const;

    /**
     * @brief Destruktor
     * 
     * Törli az adatokat
     */
    ~Kocsi() {helyTomb.clear();};
};

#endif // KOCSI_HPP

