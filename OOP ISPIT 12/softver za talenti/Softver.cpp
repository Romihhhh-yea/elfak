#include "Softver.h"
#include <fstream>

// 1. Default konstruktor
Softver::Softver() {
    maxEl = 10;
    trBr = 0;
    niz = new Ucesnik * [maxEl];
}

// 2. Konstruktor sa parametrima
Softver::Softver(int _maxEl) {
    maxEl = _maxEl;
    trBr = 0;
    niz = new Ucesnik * [maxEl];
}

// 3. Copy konstruktor (nadimak s)
Softver::Softver(const Softver& s) {
    maxEl = s.maxEl;
    trBr = s.trBr;
    niz = new Ucesnik * [maxEl];

    for (int i = 0; i < trBr; i++) {
        // Ovde se radi plitko kopiranje (prepisivanje adresa) 
        // jer u bazi nemamo virtuelnu funkciju za kopiranje objekta
        niz[i] = s.niz[i];
    }
}

// 4. Destruktor
Softver::~Softver() {
    for (int i = 0; i < trBr; i++) {
        delete niz[i]; // Brišemo svakog uèesnika pojedinaèno
    }
    delete[] niz; // Brišemo sam niz pokazivaèa
}

void Softver::dodajUcesnika(Ucesnik* _noviUcesnik) {
    if (trBr < maxEl) {
        niz[trBr++] = _noviUcesnik;
    }
    else {
        throw "Greska: Nema vise mesta u evidenciji!";
    }
}

void Softver::obrisiUcesnika(int _redniBr) {
    for (int i = 0; i < trBr; i++) {
        if (niz[i]->getRedniBr() == _redniBr) { // Geter iz baze
            delete niz[i];
            // Pomeranje elemenata ulevo da ne ostane rupa u nizu
            for (int j = i; j < trBr - 1; j++) {
                niz[j] = niz[j + 1];
            }
            trBr--;
            return;
        }
    }
}

double Softver::srednjaVrednostPoenaFinalista() const {
    double suma = 0;
    int brojFinalista = 0;
    for (int i = 0; i < trBr; i++) {
        // Uslov: ukupno > 100 i poeni zirija >= 50% od max
        double procenatZirija = niz[i]->poeniZirija() / (double)niz[i]->maksimalniPoeniZirija();

        if (niz[i]->ukupnoPoena() > 100 && procenatZirija >= 0.5) {
            suma += niz[i]->ukupnoPoena();
            brojFinalista++;
        }
    }
    return (brojFinalista > 0) ? (suma / brojFinalista) : 0.0;
}

Ucesnik* Softver::najveciPoeniZirija() const {
    if (trBr == 0) return nullptr;

    Ucesnik* rekorder = niz[0];
    for (int i = 1; i < trBr; i++) {
        if (niz[i]->poeniZirija() > rekorder->poeniZirija()) {
            rekorder = niz[i];
        }
    }
    return rekorder;
}

void Softver::sortirajIUpisi(const char* _imeFajla) {
    // Sortiranje u opadajuci redosled po pomocnom osoblju
    for (int i = 0; i < trBr - 1; i++) {
        for (int j = i + 1; j < trBr; j++) {
            if (niz[i]->pomocnoOsoblje() < niz[j]->pomocnoOsoblje()) {
                Ucesnik* temp = niz[i];
                niz[i] = niz[j];
                niz[j] = temp;
            }
        }
    }

    // Upis u fajl takmicenje.txt
    ofstream fajl(_imeFajla);
    if (fajl.is_open()) {
        for (int i = 0; i < trBr; i++) {
            niz[i]->prikazi(fajl); // Pozivamo virtuelnu funkciju
            fajl << endl;
        }
        fajl.close();
    }
}