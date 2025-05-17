
#ifndef KOCSI_HPP
#define KOCSI_HPP

#include "hely.hpp"
#include "dinTomb.hpp"
#include "memtrace.h"

class Kocsi{
    int kocsi_szam;
    int hely_db;
    DinTomb<Hely> helyTomb;
    int foglalt_db;
public:
    // default konstruktor
    Kocsi() : kocsi_szam(0), hely_db(0), helyTomb(), foglalt_db(0) {};
    // parameters konstruktor
    Kocsi(int sz, int hdb, int fdb = 0): kocsi_szam(sz), hely_db(hdb), helyTomb(), foglalt_db(fdb) {
        for (int i = 0; i < hely_db; ++i){
            helyTomb.push_back(Hely(i));
        }
    };
    // copt konstruktor
    Kocsi(const Kocsi& masik): kocsi_szam(masik.kocsi_szam), hely_db(masik.hely_db), helyTomb(masik.helyTomb), foglalt_db(masik.foglalt_db) {};
    Hely get_hely(int id);
    Hely get_hely(size_t id);
    const Hely get_hely(size_t id) const;
    bool is_tele();
    int get_helyDB() const;
    void foglal_hely(int idx);
    Kocsi& operator=(const Kocsi& rhs);
    size_t getSzabadHely() const;
    // destruktor
    ~Kocsi() {helyTomb.clear();};
};

#endif // KOCSI_HPP
