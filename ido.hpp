#ifndef IDO_HPP
#define IDO_HPP

#include <iostream>

struct Ido{
    int ora;
    int perc;
    Ido(): ora(0), perc(0) {};
    Ido(int o, int p): ora(o), perc(p) {};
    friend std::ostream& operator<<(std::ostream&os, const Ido& rhs);
};

#endif // IDO_HPP
