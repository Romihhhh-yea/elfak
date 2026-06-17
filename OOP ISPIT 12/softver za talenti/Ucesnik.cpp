#include "Ucesnik.h"
#include <cstring>

// 1. Default konstruktor
Ucesnik::Ucesnik() {
    redniBr = 0;
    ime = nullptr;
    prezime = nullptr;
    poeniPublike = 0;
}

// 2. Konstruktor sa parametrima
Ucesnik::Ucesnik(int _redniBr, const char* _ime, const char* _prezime, int _poeniPublike) {
    redniBr = _redniBr;
    poeniPublike = _poeniPublike;

    // Dinamièka alokacija za ime
    if (_ime != nullptr) {
        ime = new char[strlen(_ime) + 1];
        strcpy(ime, _ime);
    }
    else {
        ime = nullptr;
    }

    // Dinamièka alokacija za prezime
    if (_prezime != nullptr) {
        prezime = new char[strlen(_prezime) + 1];
        strcpy(prezime, _prezime);
    }
    else {
        prezime = nullptr;
    }
}

// 3. Copy konstruktor (nadimak u)
Ucesnik::Ucesnik(const Ucesnik& u) {
    redniBr = u.redniBr;
    poeniPublike = u.poeniPublike;

    // Duboko kopiranje imena
    if (u.ime != nullptr) {
        ime = new char[strlen(u.ime) + 1];
        strcpy(ime, u.ime);
    }
    else {
        ime = nullptr;
    }

    // Duboko kopiranje prezimena
    if (u.prezime != nullptr) {
        prezime = new char[strlen(u.prezime) + 1];
        strcpy(prezime, u.prezime);
    }
    else {
        prezime = nullptr;
    }
}

// 4. Destruktor
Ucesnik::~Ucesnik() {
    // Oslobaðanje dinamièke memorije
    delete[] ime;
    delete[] prezime;
}

// Virtuelna funkcija za prikaz osnovnih podataka
void Ucesnik::prikazi(ostream& izlaz) {
    izlaz << "RB: " << redniBr
        << " | Ime i prezime: " << ime << " " << prezime
        << " | Poeni publike: " << poeniPublike;
}

// Operator za ispis koji omoguæava polimorfizam
ostream& operator<<(ostream& izlaz, const Ucesnik& u) {
    // Cast-ovanjem na (Ucesnik&) skidamo const da bismo pozvali prikazi
    // ali pošto je prikazi u bazi, on æe pozvati verziju od Glumca ili Pevaèa
    ((Ucesnik&)u).prikazi(izlaz);
    return izlaz;
}