#pragma once
#include <iostream>

class Paleta {
private:
    int oznaka;
    int masa;

public:
    Paleta();
    Paleta(int _oznaka, int _masa);
    Paleta(const Paleta& gg);
    virtual ~Paleta();

    int GetOznaka() const;
    int GetMasaPalete() const;

    virtual float UkupnaMasa() const = 0;
    virtual float Vrednost() const = 0;
    virtual void Ispisi(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Paleta& p);
};
