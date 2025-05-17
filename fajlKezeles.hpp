
#ifndef FAJLKEZELES_HPP
#define FAJLKEZELES_HPP


#include <fstream>
#include <sstream>
#include "string5.h"
#include "dinTomb.hpp"
#include "vonat.hpp"
#include "jegy.hpp"
#include "memtrace.h"


class Fajl{
public:
    static void beolvasVonatok(const std::string& filename, DinTomb<Vonat>& vonatok);
    static void beolvasJegyek(const std::string& filename, DinTomb<Jegy>& jegyek);
    static void mentesVonatok(const std::string& filename, const DinTomb<Vonat>& vonatok);
    static void mentesJegyek(const std::string& filename, const DinTomb<Jegy>& jegyek);
};


#endif // FAJLKEZELES_HPP

