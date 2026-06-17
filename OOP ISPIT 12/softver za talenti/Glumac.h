#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Ucesnik.h"

class Glumac : public Ucesnik {
private:
    int brojRekvizita;
    int poeniZirijaZaIdeju;
    int poeniZirijaZaIzvodjenje;

public:
    Glumac();
    Glumac(int _redniBr, const char* _ime, const char* _prezime, int _poeniPublike,
        int _brojRekvizita, int _poeniZirijaZaIdeju, int _poeniZirijaZaIzvodjenje);
    Glumac(const Glumac& g);
    ~Glumac();

    double poeniZirija() const override;
    double ukupnoPoena() const override;
    int pomocnoOsoblje() const override;
    void prikazi(ostream& izlaz) override;
    int maksimalniPoeniZirija() const override;
};