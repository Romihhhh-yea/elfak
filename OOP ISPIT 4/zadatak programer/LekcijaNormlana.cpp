#define _CRT_SECURE_NO_WARNINGS
#include "LekcijaNormlana.h"
#include <string.h>
LekcijaNormalna::LekcijaNormalna()
{
    naziv = nullptr;
    duzinaStranica = 0;
    tezina = 0;
}

LekcijaNormalna::LekcijaNormalna(const char* _naziv, int _duzinaStranica, int _tezina)
{
    naziv = new char[strlen(_naziv) + 1];
    strcpy(naziv, _naziv);
    duzinaStranica = _duzinaStranica;
    tezina = _tezina;
}

LekcijaNormalna::~LekcijaNormalna()
{
    delete[] naziv;
}

LekcijaNormalna::LekcijaNormalna(const LekcijaNormalna& gg)
{
    if (gg.naziv != nullptr) {
        naziv = new char[strlen(gg.naziv) + 1];
        strcpy(naziv, gg.naziv);
    }
    else {
        naziv = nullptr;
    }
    duzinaStranica = gg.duzinaStranica;
    tezina = gg.tezina;
}

ostream& operator<<(ostream& izlaz, const LekcijaNormalna& ln)
{
    izlaz << "Naziv: " << ln.naziv << "Duzina: " << ln.duzinaStranica << "Tezina: " << ln.tezina;
    return izlaz;
}
