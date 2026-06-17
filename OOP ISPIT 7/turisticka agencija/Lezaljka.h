#ifndef LEZALJKA_H
#define LEZALJKA_H

#include <iostream>

class Lezaljka {
protected:
    int redniBroj;
    int red;
    float cenaLezaljki;
    float cenaNapitaka;

public:
    // 1. Default konstruktor
    Lezaljka();

    // 2. Konstruktor sa parametrima
    Lezaljka(int _redniBroj, int _red, float _cenaLezaljki, float _cenaNapitaka);

    // 3. Copy konstruktor (nadimak gg)
    Lezaljka(const Lezaljka& gg);

    // 4. Destruktor
    virtual ~Lezaljka();

    int getRedniBroj() const { return redniBroj; }

    // Cisto virtuelna funkcija jer se formula razlikuje u izvedenim klasama
    virtual float svotaZaNaplatu() const = 0;

    // Treba nam za funkciju VratiNajskuplje u Boss klasi
    virtual float getCenaNapitaka() const { return cenaNapitaka; }

    virtual void Prikazi() const;
    friend std::ostream& operator<<(std::ostream& izlaz, const Lezaljka& l);
};

#endif

