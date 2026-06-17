#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "IspitniMaterijal.h"

class Lekcija : public IspitniMaterijal {
private:
    float duzina;

public:
    Lekcija();
    Lekcija(int _oznaka, int _tezina, float _duzina, const char* _savladan = "NE");
    Lekcija(const Lekcija& l);
    ~Lekcija();


    float vremeSavladavanja(float _vJedinicno) const;
    void prikazi(std::ostream& izlaz) const override;
};