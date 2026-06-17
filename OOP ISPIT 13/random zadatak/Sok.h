#ifndef SOK_H
#define SOK_H

#include "Pice.h"

class Sok : public Pice {
private:
    char* naziv;
    double procenat;
    double odnosCene;

public:
    Sok();
    Sok(double z, const char* n, int p, double o, int b = 1);
    Sok(const Sok&);
    ~Sok();
    int getBroj() { return broj; }
    double getZapremina() { return zapremina; }
    void prikazi(std::ostream&) const override;
};

#endif


