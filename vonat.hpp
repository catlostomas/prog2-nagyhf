#ifndef VONAT_HPP
#define VONAT_HPP

#include "kocsi.hpp"
#include "string5.h"
#include "ido.hpp"

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
    // def konstruktor
    Vonat(): vonatszam(""), ind_allomas(""), erk_allomas(""), ind_ido(0, 0), erk_ido(0, 0), keses(0), kocsi_db(0), kocsik() {};
    // parameteres konstruktor
    Vonat(const String& vsz, const String& ind_all, const String& erk_all, const Ido& indIdo, const Ido& erkIdo, int k = 0, size_t kocsDB = 0): vonatszam(vsz), ind_allomas(ind_all), erk_allomas(erk_all), ind_ido(indIdo), erk_ido(erkIdo), keses(k), kocsi_db(kocsDB), kocsik() {
        for (size_t i = 0; i < kocsDB; i++){
            kocsik.push_back(Kocsi(i, 50)); // 50 hely legyen egy kocsiban
        }
    };
    // copy konstruktor
    Vonat(const Vonat& rhs): vonatszam(rhs.vonatszam), ind_allomas(rhs.ind_allomas), erk_allomas(rhs.erk_allomas), ind_ido(rhs.ind_ido), erk_ido(rhs.erk_ido), keses(rhs.keses), kocsi_db(0), kocsik(rhs.kocsik) {};
    void print(); // kiiras tesztelesre
    void setKeses(int k);
    int getKeses() const;
    String get_Vonatszam() const;
    String get_indAll() const;
    String get_erkAll() const;
    Ido get_indIdo() const;
    Ido get_erkIdo() const;
    size_t getKocsiDB() const;
    size_t getKocsiHelyDB(size_t keresett);
    Kocsi& getKocsi(size_t keresett);
    const Kocsi& getKocsi(size_t keresett) const;
    bool operator==(const Vonat& other) const;
    bool operator==(const String& vsz) const;

    // desturktor
    ~Vonat() {kocsik.clear();};

};

#endif // VONAT_HPP
