#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "IspitniMaterijal.h"

class Zadatak : public IspitniMaterijal {
private:
    int brLinijaKoda;

public:
    Zadatak();
    Zadatak(int _oznaka, float _tezina, int _brLinija, const char* _savladan = "NE");
    Zadatak(const Zadatak& z);
    ~Zadatak();

    float vremeSavladavanja(float _vJedinicno) const;
    void prikazi(std::ostream& izlaz) const override;
};