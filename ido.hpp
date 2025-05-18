/**
 * @file ido.hpp
 * @brief Ido segédosztály
 */
#ifndef IDO_HPP
#define IDO_HPP

#include <iostream>
#include "memtrace.h"

/**
 * @struct Ido
 * @brief Időpontokat tárolására szükséges
 * 
 * Struct, amiben időpontokat lehet tárolni, változtatni
 * Óra és perc formátumban tárol
 */
struct Ido{
    int ora;    /**< (0-23) */
    int perc;   /**< (0-59) */

    /**
     * @brief Default konstruktor
     * 
     * Létrehoz egy objektumot és 00:00-ra állítja az időt
     */
    Ido(): ora(0), perc(0) {};

    /**
     * @brief Paraméteres konstruktor
     * 
     * Létrehoz egy objektumot és beállítja a paraméterek szerint az időt
     * 
     * @param o Órák
     * @param p Percek
     */
    Ido(int o, int p): ora(o), perc(p) {};

    /**
     * @brief Inzerter operáator
     * 
     * Kiírja az időpontot ÓÓ:PP alakban
     * 
     * @param os Output stream
     * @param rhs Objektum amit szeretnénk kiírni
     * @return std::ostream& referencia az output streamre
     */
    friend std::ostream& operator<<(std::ostream&os, const Ido& rhs);
};

#endif // IDO_HPP

