#pragma once
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Funkcija
{
protected:
    double k, n;
    char* naziv;
public:
    Funkcija();
    Funkcija(double k, double n, const char* ime_funkcije);
    virtual ~Funkcija();
    virtual double vrednost(double x);
    virtual void prikaziFunkciju();
    const char* ime() { return naziv; }
    virtual double izvod(double x) = 0;
};
