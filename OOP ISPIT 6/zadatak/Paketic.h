#pragma once
#include <iostream>
#include "Poklon.h"

class Paketic {
private:
    Poklon** niz;
    int top;
    int maxEl;

public:
    Paketic(int _maxEl);
    Paketic(const Paketic& og);
    ~Paketic();

    void Add(Poklon* p);
    int BrojPoklona() const;

    Poklon* Max() const;
    void RemoveMinimum(Poklon** p);
    void Save(const char* fajl) const;

    Paketic operator+(const Paketic& other) const;

    friend std::ostream& operator<<(std::ostream& izlaz, const Paketic& p);
};

