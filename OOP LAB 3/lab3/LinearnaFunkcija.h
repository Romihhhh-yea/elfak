#pragma once
#include "Funkcija.h"

class LinearnaFunkcija : public Funkcija
{
public:
    LinearnaFunkcija(double k, double n);
    double vrednost(double x) override;
    void prikaziFunkciju() override;
    double izvod(double x) override;
};

