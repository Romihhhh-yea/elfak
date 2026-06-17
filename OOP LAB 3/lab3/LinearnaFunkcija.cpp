#include "LinearnaFunkcija.h"

LinearnaFunkcija::LinearnaFunkcija(double k, double n)
    : Funkcija(k, n, "Linearna funkcija")
{
}

double LinearnaFunkcija::vrednost(double x)
{
    return k * x + n;
}

void LinearnaFunkcija::prikaziFunkciju()
{
    cout << "Linearna ";
    Funkcija::prikaziFunkciju();
}

double LinearnaFunkcija::izvod(double)
{
    return k;
}
