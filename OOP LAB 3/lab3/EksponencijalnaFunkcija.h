#pragma once
#include "Funkcija.h"

class EksponencijalnaFunkcija : public Funkcija
{
public:
    EksponencijalnaFunkcija();
    EksponencijalnaFunkcija(double n);
    double vrednost(double x) override;
    void prikaziFunkciju() override;
    double izvod(double x) override;

};