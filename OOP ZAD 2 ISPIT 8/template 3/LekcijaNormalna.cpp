#include "LekcijaNormalna.h"
#include <cstring> 


LekcijaNormalna::LekcijaNormalna() {
    naziv = nullptr;
    duzina = 0;
    tezina = 0.0f;
}


LekcijaNormalna::LekcijaNormalna(const char* _naziv, int _duzina, float _tezina) {
    duzina = _duzina;
    tezina = _tezina;

    if (_naziv != nullptr) {
        naziv = new char[strlen(_naziv) + 1];
        strcpy(naziv, _naziv);
    }
    else {
        naziv = nullptr;
    }
}

LekcijaNormalna::~LekcijaNormalna() {
    if (naziv != nullptr) {
        delete[] naziv;
    }
}


LekcijaNormalna::LekcijaNormalna(const LekcijaNormalna& gg) {
    duzina = gg.duzina;
    tezina = gg.tezina;

    if (gg.naziv != nullptr) {
        naziv = new char[strlen(gg.naziv) + 1];
        strcpy(naziv, gg.naziv);
    }
    else {
        naziv = nullptr;
    }
}

std::ostream& operator<<(std::ostream& izlaz, const LekcijaNormalna& l) {
    if (l.naziv != nullptr) {
        izlaz << l.naziv;
    }
    else {
        izlaz << "Nema naziva";
    }

    izlaz << " " << l.duzina << " " << l.tezina << " ";

    return izlaz;
}
istream& operator>>(istream& ulaz, LekcijaNormalna& l) {
    char buffer[100];
    if (ulaz >> buffer >> l.duzina >> l.tezina)
    {
        delete[] l.naziv;
        l.naziv = new char[strlen(buffer) + 1];
        strcpy(l.naziv, buffer);
    }
    return ulaz;
}
LekcijaNormalna::operator float() {
    return duzina * tezina;
}
LekcijaNormalna& LekcijaNormalna::operator=(const LekcijaNormalna& ln) {
    if (this != &ln) {
        duzina = ln.duzina;
        tezina = ln.tezina;

        if (ln.naziv != nullptr) {
            naziv = new char[strlen(ln.naziv) + 1];
            strcpy(naziv, ln.naziv);
        }
        else {
            naziv = nullptr;
        }
    }
    return *this;
}
