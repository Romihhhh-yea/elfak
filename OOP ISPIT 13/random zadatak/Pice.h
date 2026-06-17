#ifndef PICE_H
#define PICE_H

#include <iostream>

class Pice {
protected:
    double zapremina;
    int broj;

public:
    Pice();
    Pice(double, int b = 1);
    Pice(const Pice&);
    virtual ~Pice();
    int getBroj() { return broj; }
    double getZapremina() { return zapremina; }
    void setBroj(int n) { broj = n; }
    virtual void prikazi(std::ostream&) const = 0;

    friend std::ostream& operator<<(std::ostream&, const Pice&);
};

#endif


