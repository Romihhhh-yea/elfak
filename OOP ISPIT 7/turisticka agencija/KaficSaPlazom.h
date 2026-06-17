#ifndef KAFICSAPLAZOM_H
#define KAFICSAPLAZOM_H

#include "Lezaljka.h"

class KaficSaPlazom {
private:
    Lezaljka** niz; // double pointer niz
    int trBr;      // trenutni broj
    int maxEl;     // maksimalan broj

public:
    // 1. Default konstruktor
    KaficSaPlazom();

    // 2. Konstruktor sa parametrima
    KaficSaPlazom(int _maxEl);

    // 3. Copy konstruktor (nadimak gg)
    KaficSaPlazom(const KaficSaPlazom& gg);

    // 4. Destruktor
    ~KaficSaPlazom();

    // Metode iz teksta zadatka
    void Dodaj(Lezaljka* _nova);
    void Oslobodi(int _redniBroj);
    int UkupnoLezaljki() const;
    float UkupnaSvotaNovca() const;
    bool PostojiGdeTrebaPlatiti(float _svota) const;

    // Funkcija sa dva pokazivaca za najvecu cenu i najvise pica
    void VratiNajskuplje(Lezaljka** _maxUkupno, Lezaljka** _maxNapitak);

    // Operator za ispis Boss klase
    friend std::ostream& operator<<(std::ostream& izlaz, const KaficSaPlazom& ksp);
};

#endif

