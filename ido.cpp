#include "ido.hpp"
#include <iomanip>

// kiiras helyes (00:00) formatumban
std::ostream& operator<<(std::ostream&os, const Ido& rhs){
    os << std::setfill('0') << std::setw(2) << rhs.ora << ":" << std::setw(2) << rhs.perc;
    return os;
}
