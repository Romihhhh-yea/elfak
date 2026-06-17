#include <iostream>
#include "Skladiste.h"
#include "PaletaProsirena.h"

using namespace std;
void main() {
    int brElemenata = 10;

    float masa[] = { 20, 30, 20, 60, 35, 55, 30 };
    int broj[] = { 40, 40, 30, 30, 20, 20, 20 };
    float sirina[] = { 20, 50, 25, 60, 30, 50, 35 };

    Skladiste<PaletaProsirena> skladiste(brElemenata);

    for (int i = 0; i < 7; i++) {
        skladiste.Dodaj(PaletaProsirena(masa[i], broj[i], sirina[i]));
    }

    cout << skladiste << endl;

    skladiste.Preuzmi(4, 300);
    cout << skladiste << endl;

    skladiste.Preuzmi(4, 400);
    cout << skladiste << endl;

    float ukupno = skladiste.UkupnaMasa();
    cout << ukupno << endl;

    int zMasa = 2;
    int brojVK = skladiste.BrojSaVecomKolicinom(zMasa);
    cout << brojVK << endl;

    PaletaProsirena min, max;
    skladiste.NajViseManje(1, 4, min, max);
    cout << min << " " << max << endl;

    char fajl[] = "SkladPr.txt";
    skladiste.Sacuvaj(fajl);

    Skladiste<PaletaProsirena> skladisteUcitano(brElemenata);
    skladisteUcitano.Ucitaj(fajl);
    cout << skladisteUcitano << endl;
};

