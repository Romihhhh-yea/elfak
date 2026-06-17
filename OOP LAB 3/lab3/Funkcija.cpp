#define _CRT_SECURE_NO_WARNINGS
#include "Funkcija.h"

Funkcija::Funkcija()
{
    k = 1.0;
    n = 0.0;
    naziv = new char[strlen("Linearna funkcija") + 1];
    strcpy(naziv, "Linearna funkcija");
}

Funkcija::Funkcija(double k, double n, const char* ime_funkcije)
{
    this->k = k;
    this->n = n;
    this->naziv = new char[strlen(ime_funkcije) + 1];
    strcpy(this->naziv, ime_funkcije);
}

Funkcija::~Funkcija()
{
    if (naziv != nullptr)
    {
        delete[] naziv;
        naziv = nullptr;
    }
}

double Funkcija::vrednost(double x)
{
    return k * x + n;
}

void Funkcija::prikaziFunkciju()
{
    cout << "Naziv: " << naziv << endl;
    cout << "k = " << k << endl;
    cout << "n = " << n << endl;
}
