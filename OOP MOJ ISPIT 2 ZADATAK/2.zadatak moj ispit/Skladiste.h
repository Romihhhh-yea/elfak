#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Skladiste {
private:
    T* niz;
    int maxEl;
    int trBr;
public:
    Skladiste() {
        niz = nullptr;
        maxEl = 0;
        trBr = 0;
    }

    Skladiste(int _maxEl) {
        maxEl = _maxEl;
        trBr = 0; // Na pocetku je prazno, iako imamo mesta
        niz = new T[maxEl];
    }

    ~Skladiste() {
        if (niz != nullptr) delete[] niz;
    }

    void Dodaj(T novi) {
        // Ako hoces na prvo slobodno mesto (tvoj trBr):
        if (trBr < maxEl) {
            niz[trBr++] = novi;
        }
        else {
            throw "Popunjeno!";
        }
    }

    void Preuzmi(int indeks, int kolicina) {
        if (indeks >= trBr || indeks < 0) throw "Greska u indeksu!";
        if ((int)niz[indeks] < kolicina) throw "Greska u kolicini!";

        // Smanjujemo kolicinu
        niz[indeks] -= kolicina;

        // Ako je postala prazna, shiftujemo
        if ((int)niz[indeks] == 0) {
            T prazna = niz[indeks];
            for (int j = indeks; j < trBr - 1; j++) {
                niz[j] = niz[j + 1];
            }
            niz[trBr - 1] = prazna;
            trBr--; // Smanjujemo broj popunjenih
        }
    }

    int UkupnaMasa() {
        int suma = 0;
        for (int i = 0; i < trBr; i++) {
            suma += (int)niz[i];
        }
        return suma;
    }

    int BrojSaVecomKolicinom(int broj) {
        int koliko = 0;
        for (int i = 0; i < trBr; i++) {
            if ((int)niz[i] > broj) {
                koliko++;
            }
        }
        return koliko;
    }

    void NajViseManje(int od, int doo, T& min, T& max) {
        if (od < 0 || doo >= trBr || od > doo) throw "Greska";
        min = niz[od];
        max = niz[od];
        for (int i = od + 1; i <= doo; i++) {
            if ((int)niz[i] < (int)min) min = niz[i];
            if ((int)niz[i] > (int)max) max = niz[i];
        }
    }
    friend ostream& operator<<(ostream& izlaz, const Skladiste<T>& s) {
        for (int i = 0; i < s.trBr; i++) {
            izlaz << s.niz[i] << endl;
        }
        return izlaz;
    }
    };
