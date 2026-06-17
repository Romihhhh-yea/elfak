#include "KvadratnaFunkcija.h"

KvadratnaFunkcija::KvadratnaFunkcija()
    : Funkcija(1.0, 0.0, "Kvadratna funkcija")
{
}

KvadratnaFunkcija::KvadratnaFunkcija(double k, double n)
    : Funkcija(k, n, "Kvadratna funkcija")
{
}

double KvadratnaFunkcija::vrednost(double x)
{
    return pow(x + n, k);
}

void KvadratnaFunkcija::prikaziFunkciju()
{
    cout << "Kvadratna";
    Funkcija::prikaziFunkciju();
}

double KvadratnaFunkcija::izvod(double x)
{
    return k * pow(x + n, k - 1);
}
