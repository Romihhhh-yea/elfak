#include "EksponencijalnaFunkcija.h"

EksponencijalnaFunkcija::EksponencijalnaFunkcija()
    : Funkcija(exp(1.0), 0.0, "Eksponencijalna funkcija")
{
}

EksponencijalnaFunkcija::EksponencijalnaFunkcija(double n)
    : Funkcija(exp(1.0), n, "Eksponencijalna funkcija")
{
}

double EksponencijalnaFunkcija::vrednost(double x)
{
    return pow(k, x + n);
}

void EksponencijalnaFunkcija::prikaziFunkciju()
{
    cout << "Eksponencijalna";
    Funkcija::prikaziFunkciju();
}

double EksponencijalnaFunkcija::izvod(double x)
{
    return log(k) * pow(k, x + n);
}
