#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Ucesnik.h"

class Pevac : public Ucesnik {
private:
    char* nazivPesme;
    int brojPratecihInstrumenata;
    int brojPratecihVokala;
    int poeniMuzickogZirija;

public:
    // 1. Default konstruktor
    Pevac();

    // 2. Konstruktor sa parametrima
    Pevac(int _redniBr, const char* _ime, const char* _prezime, int _poeniPublike,
        const char* _nazivPesme, int _brojPratecihInstrumenata,
        int _brojPratecihVokala, int _poeniMuzickogZirija);

    // 3. Copy konstruktor (nadimak p)
    Pevac(const Pevac& p);

    // 4. Destruktor
    ~Pevac();

    // Implementacija apstraktnih funkcija iz baze
    double poeniZirija() const override;
    double ukupnoPoena() const override;
    int pomocnoOsoblje() const override;
    int maksimalniPoeniZirija() const override;
    void prikazi(ostream& izlaz) override;
};