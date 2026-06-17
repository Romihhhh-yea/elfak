#include "Pevac.h"
#include <cstring>

// 1. Default konstruktor
Pevac::Pevac() : Ucesnik() {
    nazivPesme = nullptr;
    brojPratecihInstrumenata = 0;
    brojPratecihVokala = 0;
    poeniMuzickogZirija = 0;
}

// 2. Konstruktor sa parametrima
Pevac::Pevac(int _redniBr, const char* _ime, const char* _prezime, int _poeniPublike,
    const char* _nazivPesme, int _brojPratecihInstrumenata,
    int _brojPratecihVokala, int _poeniMuzickogZirija)
    : Ucesnik(_redniBr, _ime, _prezime, _poeniPublike) {

    // Provera opsega poena (0-50)
    if (_poeniMuzickogZirija < 0 || _poeniMuzickogZirija > 50) {
        throw "Nevalidan broj poena za muzicki ziri!";
    }

    if (_nazivPesme != nullptr) {
        nazivPesme = new char[strlen(_nazivPesme) + 1];
        strcpy(nazivPesme, _nazivPesme);
    }
    else {
        nazivPesme = nullptr;
    }

    brojPratecihInstrumenata = _brojPratecihInstrumenata;
    brojPratecihVokala = _brojPratecihVokala;
    poeniMuzickogZirija = _poeniMuzickogZirija;
}

// 3. Copy konstruktor (nadimak p)
Pevac::Pevac(const Pevac& p) : Ucesnik(p) {
    if (p.nazivPesme != nullptr) {
        nazivPesme = new char[strlen(p.nazivPesme) + 1];
        strcpy(nazivPesme, p.nazivPesme);
    }
    else {
        nazivPesme = nullptr;
    }
    brojPratecihInstrumenata = p.brojPratecihInstrumenata;
    brojPratecihVokala = p.brojPratecihVokala;
    poeniMuzickogZirija = p.poeniMuzickogZirija;
}

// 4. Destruktor
Pevac::~Pevac() {
    delete[] nazivPesme;
}

double Pevac::poeniZirija() const {
    // Pevaè ima samo muzièki žiri
    return (double)poeniMuzickogZirija;
}

double Pevac::ukupnoPoena() const {
    // Ukupno = publika + muzièki žiri
    return (double)(poeniPublike + poeniMuzickogZirija);
}

int Pevac::pomocnoOsoblje() const {
    // Za pevaèa je to zbir prateæih instrumenata i vokala
    return brojPratecihInstrumenata + brojPratecihVokala;
}

int Pevac::maksimalniPoeniZirija() const {
    // Muzièki žiri daje max 50 poena
    return 50;
}

void Pevac::prikazi(ostream& izlaz) {
    Ucesnik::prikazi(izlaz); // Pozivamo osnovni ispis iz baze
    izlaz << " | TIP: Pevac | Pesma: " << (nazivPesme ? nazivPesme : "Nema")
        << " | Pomocno osoblje: " << pomocnoOsoblje();
}