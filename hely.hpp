
#ifndef HELY_HPP
#define HELY_HPP

#include <iostream>
#include "memtrace.h"

class Hely{
    int hely_ID;
    bool foglalt;
public:
    // parameteres konstruktor
    Hely(int id): hely_ID(id), foglalt(false) {};
    // default konstruktor
    Hely(): hely_ID(1), foglalt(false) {};
    // copy konstruktor
    Hely(const Hely& rhs): hely_ID(rhs.hely_ID), foglalt(rhs.foglalt) {};
    void foglal();
    void foglalas_torles();
    int getID() const {return hely_ID;};
    bool getFoglalt() const {return foglalt;};
    friend std::ostream& operator<<(std::ostream& os, const Hely& h);
    Hely& operator=(const Hely& rhs);
    bool operator==(const Hely& rhs) const;
    ~Hely() {};
};

#endif // HELY_HPP
