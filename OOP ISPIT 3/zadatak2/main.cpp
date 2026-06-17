#include <iostream>
#include "Saonice.h"
#include "PaketicHrana.h"
#include "PaketicIgracke.h"

using namespace std;

int main() {

    Saonice s(10);

    Paketic* p1 = new PaketicHrana("Nemanjina 12", "crvena", 5, 2.5, 1200);
    Paketic* p2 = new PaketicHrana("Bulevar 8", "plava", 3, 1.2, 1000);

    Paketic* p3 = new PaketicIgracke("Nemanjina 12", "zelena", 4, 0.3, 800);
    Paketic* p4 = new PaketicIgracke("Cara Dusana 5", "zuta", 2, 0.5, 1500);

    s.Add(p1);
    s.Add(p2);
    s.Add(p3);
    s.Add(p4);

    cout << "Sadrzaj saonica:" << endl;
    cout << s << endl;

    cout << "Srednja cena: " << s.SrednjaCena() << endl;

    Paketic* naj = s.Najtezi();
    cout << "Najtezi paketic:" << endl;
    cout << *naj << endl;

    char adr[100];
    for (int i = 0; i < 3; i++) {
        cin >> adr;
        s.IzbaciPoAdresi(adr);
    }

    cout << "Posle izbacivanja:" << endl;
    cout << s << endl;

    s.Save("paketici.txt");

    return 0;
}
