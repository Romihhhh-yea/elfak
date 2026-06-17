#ifndef VODA_H
#define VODA_H

#include "Pice.h"

class Voda : public Pice {
public:
    Voda();
    Voda(double z, int b = 1);
    Voda(const Voda&);
    ~Voda();
    int getBroj() { return broj; }
    double getZapremina() { return zapremina; }
    void prikazi(std::ostream&) const override;
};

#endif


