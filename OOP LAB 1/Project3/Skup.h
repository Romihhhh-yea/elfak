#ifndef SKUP_H
#define SKUP_H

#include <iostream>
#include "Complex.h"

class Skup {
private:
    int n;
    Complex* a;

    void dodajAkoNePostoji(const Complex& x);

public:
    Skup();
    Skup(int brojElemenata);
    Skup(const Skup& s);
    ~Skup();

    Skup& operator=(const Skup& s);

    bool pripada(const Complex& x) const;
    void izbaciDuplikate();

    Skup unija(const Skup& s) const;
    Skup presek(const Skup& s) const;
    Skup razlika(const Skup& s) const;

    friend std::istream& operator>>(std::istream& in, Skup& s);
    friend std::ostream& operator<<(std::ostream& out, const Skup& s);
};

// OBAVEZNO – deklaracije izvan klase
std::istream& operator>>(std::istream& in, Skup& s);
std::ostream& operator<<(std::ostream& out, const Skup& s);

#endif

