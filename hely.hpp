/**
 * @file hely.hpp
 * @brief Hely osztály implementációja
 */

#ifndef HELY_HPP
#define HELY_HPP

#include <iostream>
#include "memtrace.h"

/**
 * @class Hely
 * @brief Egy helyet képvisel egy kocsiban
 * 
 * Tárolja a hely azonosítóját és hogy foglalt-e
 */

class Hely{
    int hely_ID;
    bool foglalt;
public:
    /**
     * @brief Paraméteres konstruktor
     * 
     * Létrehoz egy helyet a hely azonosítójával és nem foglalt-ra állítja
     * 
     * @param id hely azonosító (sorszáma a helynek)
     */
    Hely(int id): hely_ID(id), foglalt(false) {};

    /**
     * @brief Default konstruktor
     * 
     * Létrehoz egy helyet 1 azonosítóval és nem foglalt-ra állítja
     */
    Hely(): hely_ID(1), foglalt(false) {};

    /**
     * @brief Másoló konstruktor
     * 
     * Létrehoz egy új helyet egy másik hely adataival
     * 
     * @param rhs a másik hely amiből másol
     */
    Hely(const Hely& rhs): hely_ID(rhs.hely_ID), foglalt(rhs.foglalt) {};
    
    /**
     * @brief Lefoglalja a helyet
     * 
     * Igaz-ra állítja a foglalt változót
     */
    void foglal();

    /**
     * @brief Foglalást törli
     * 
     * Hamis-ra állítja a foglalt változót
     */
    void foglalas_torles();

    /**
     * @brief hely_ID getter
     * 
     * @return int Visszaadja a hely azonosítóját
     */
    int getID() const {return hely_ID;};

    /**
     * @brief foglalt getter
     * 
     * @return True, ha foglalt a hely és false, ha nem foglalt
     */
    bool getFoglalt() const {return foglalt;};

    /**
     * @brief Inzerter operátor
     * 
     * Kiirja a hely adatait
     * 
     * @param os Az output stream
     * @param h A hely, amelyet kiírni szeretnénk
     * @return std::ostream& Az output streamet visszaadjuk
     */
    friend std::ostream& operator<<(std::ostream& os, const Hely& h);

    /**
     * @brief Értékadó operátor
     * 
     * Átmásolja ebbe az objektumba egy mások objektum állapotát
     * 
     * @param rhs A hely amiből másolni szeretnénk
     * @return Hely& referencia erre a helyre
     */
    Hely& operator=(const Hely& rhs);

    /**
     * @brief Egyenlőség operátor
     * 
     * Összehasonlít két hely objektumot
     * 
     * @param rhs A másik objektum
     * @return bool True, ha megegyeznek, false, ha nem
     */
    bool operator==(const Hely& rhs) const;

    /**
     * @brief Destruktor
     */
    ~Hely() {};
};

#endif // HELY_HPP

