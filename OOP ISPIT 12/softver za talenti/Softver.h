#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Ucesnik.h"

class Softver {
private:
    Ucesnik** niz;        // Dinamièki niz pokazivaèa na uèesnike
    int trBr;             // Trenutni broj elemenata u evidenciji
    int maxEl;            // Maksimalni kapacitet evidencije

public:
    // 1. Default konstruktor
    Softver();

    // 2. Konstruktor sa parametrima
    Softver(int _maxEl);

    // 3. Copy konstruktor (nadimak s)
    Softver(const Softver& s);

    // 4. Destruktor
    ~Softver();

    // Funkcije koje Softver radi kao "Boss"
    void dodajUcesnika(Ucesnik* _noviUcesnik);   // Dodavanje novog uèesnika
    void obrisiUcesnika(int _redniBr);           // Brisanje na osnovu rednog broja

    double srednjaVrednostPoenaFinalista() const; // Prosek onih koji ispunjavaju uslove
    Ucesnik* najveciPoeniZirija() const;          // Nalazi takmièara sa najviše bodova žirija

    void sortirajIUpisi(const char* _imeFajla);  // Sortiranje po osoblju i upis u fajl
};