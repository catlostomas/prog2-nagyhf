
#ifndef JEGY_HPP
#define JEGY_HPP

#include "ido.hpp"
#include "string5.h"

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
    // default konstructor
    Jegy(): ind_all(""), erk_all(""), ind_ido(0,0), erk_ido(0,0), vonatszam(""), kocsiszam(0), helyszam(), Jegy_ID() {};
    // parameteres konstruktor
    Jegy(String ia, String ea, Ido ind, Ido erk, String vsz, int ksz, int hsz, int id): ind_all(ia), erk_all(ea), ind_ido(ind), erk_ido(erk), vonatszam(vsz), kocsiszam(ksz), helyszam(hsz), Jegy_ID(id) {};
    void print();
    bool foglalt_e();
    void del_jegy();
    String getIndAll() const {return ind_all;};
    String getErkAll() const {return erk_all;};
    Ido getIndIdo() const {return ind_ido;};
    Ido getErkIdo() const {return erk_ido;};
    String getVsz() const {return vonatszam;};
    int getKocsiszam() const {return kocsiszam;};
    int getHelyszam() const {return helyszam;};
    int getJegyID() const {return Jegy_ID;};
};

#endif // JEGY_HPP
