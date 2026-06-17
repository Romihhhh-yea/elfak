#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>

using namespace std;

class Ucesnik
{
protected:
    int redniBr;
    char* ime;
    char* prezime;
    int poeniPublike;

public:
    Ucesnik();
    Ucesnik(int _redniBr, const char* _ime, const char* _prezime, int _poeniPublike);
    virtual ~Ucesnik();
    Ucesnik(const Ucesnik& u);

    
    virtual double poeniZirija() const = 0;      
    virtual double ukupnoPoena() const = 0;     
    virtual int pomocnoOsoblje() const = 0;     
    virtual int maksimalniPoeniZirija() const = 0;

    friend ostream& operator<<(ostream& izlaz, const Ucesnik& u);
    virtual void prikazi(ostream& izlaz);

    int getRedniBr() const { return redniBr; }
};