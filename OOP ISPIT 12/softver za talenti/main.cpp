#include <iostream>
#include "Softver.h"
#include "Glumac.h"
#include "Pevac.h"

using namespace std;

int main() {
    try {
        // 1. Pravimo Boss klasu
        // Koristimo tvoja imena: unutra su 'niz', 'trBr', 'maxEl'
        Softver takmicenje(10);

        // 2. Dodajemo Ucesnike
        // PAZI: Dodajemo ih preko 'new' jer 'niz' u Softveru cuva pokazivace (Ucesnik**)

        // Glumac: rb, ime, prezime, poeni publike, rekviziti, ideja(0-100), izvodjenje(0-50)
        takmicenje.dodajUcesnika(new Glumac(1, "Marko", "Markovic", 80, 10, 90, 40));
        takmicenje.dodajUcesnika(new Glumac(2, "Jovana", "Jovic", 70, 4, 40, 20));

        // Pevac: rb, ime, prezime, poeni publike, pesma, instrumenti, vokali, ziri(0-50)
        takmicenje.dodajUcesnika(new Pevac(3, "Nikola", "Nikolic", 95, "Lutka", 2, 3, 45));
        takmicenje.dodajUcesnika(new Pevac(4, "Ana", "Anic", 60, "Zora", 1, 1, 10));

        // 3. Testiramo funkcije Bossa
        cout << "Srednja vrednost poena finalista: "
            << takmicenje.srednjaVrednostPoenaFinalista() << endl;

        // 4. Sortiranje i upis u fajl
        // Ovo koristi tvoju funkciju koja gleda 'pomocnoOsoblje'
        takmicenje.sortirajIUpisi("takmicenje.txt");
        cout << "Podaci su sortirani i upisani u fajl takmicenje.txt" << endl;

        // 5. Brisanje jednog ucesnika (po rednom broju)
        takmicenje.obrisiUcesnika(2);
        cout << "Ucesnik sa RB 2 je obrisan." << endl;

    }
    catch (const char* greska) {
        // Ovde hvatamo onaj 'throw' iz konstruktora ako su poeni losi
        cout << "GRESKA: " << greska << endl;
    }

    return 0;
}