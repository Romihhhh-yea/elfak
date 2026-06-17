#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include "Paketic.h"

class Saonice {
private:
    Paketic** niz;
    int top;
    int maxEl;

public:
    Saonice();
    Saonice(int _maxEl);
    Saonice(const Saonice& s);
    ~Saonice();

    void Add(Paketic* p);
    void IzbaciPoAdresi(const char* adr);
    double SrednjaCena() const;
    Paketic* Najtezi() const;
    void Save(const char* filename) const;

    friend std::ostream& operator<<(std::ostream& izlaz, const Saonice& s);
};
