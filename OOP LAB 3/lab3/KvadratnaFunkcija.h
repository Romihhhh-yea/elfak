#pragma once
#include "Funkcija.h"

class KvadratnaFunkcija : public Funkcija
{
public:
    KvadratnaFunkcija();
    KvadratnaFunkcija(double k, double n);
    double vrednost(double x) override;
    void prikaziFunkciju() override;
    double izvod(double x) override;

};