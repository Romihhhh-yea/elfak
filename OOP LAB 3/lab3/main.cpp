#include <fstream>
#include "Funkcija.h"
#include "KvadratnaFunkcija.h"
#include "EksponencijalnaFunkcija.h"
#include "LinearnaFunkcija.h"



int main()
{
    const int ukupno = 2019;
    const int po_grupi = 673;

    Funkcija** niz = new Funkcija * [ukupno];
    for (int i = 0; i < ukupno; i++) niz[i] = nullptr;

    ifstream ulaz("ulaz.txt");
    if (!ulaz)
    {
        cerr << "Greska pri otvaranju fajla!" << endl;
        delete[] niz;
    }

    int stvarniBroj = 0;
    double tempK, tempN;

    for (int i = 0; i < ukupno; i++)
    {
        if (!(ulaz >> tempK >> tempN)) break;

        if (i < po_grupi)
            niz[i] = new LinearnaFunkcija(tempK, tempN);
        else if (i < 2 * po_grupi)
            niz[i] = new KvadratnaFunkcija(tempK, tempN);
        else if (i < 3 * po_grupi)
            niz[i] = new EksponencijalnaFunkcija(tempN);
       

        stvarniBroj++;
    }
    ulaz.close();

    if (stvarniBroj == 0)
    {
        delete[] niz;
        return 0;
    }

    for (int i = 0; i < stvarniBroj; i++)
    {
        niz[i]->prikaziFunkciju();
    }

    double proveraX;
    cout << "Unesite x: ";
    cin >> proveraX;

    Funkcija* minF = niz[0];
    for (int i = 1; i < stvarniBroj; i++)
    {
        if (niz[i]->vrednost(proveraX) < minF->vrednost(proveraX))
        {
            minF = niz[i];
        }
    }

    cout << "\nMinimum za x=" << proveraX << ":" << endl;
    minF->prikaziFunkciju();
    cout << "Vrednost: " << minF->vrednost(proveraX) << endl;

    for (int i = 0; i < stvarniBroj; i++)
    {
        delete niz[i];
    }
    delete[] niz;

    return 0;
}
