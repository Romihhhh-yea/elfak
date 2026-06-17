#include "KaficSaPlazom.h"

KaficSaPlazom::KaficSaPlazom() {
    maxEl = 10;
    trBr = 0;
    niz = new Lezaljka*[maxEl];
}

KaficSaPlazom::KaficSaPlazom(int _maxEl) {
    maxEl = _maxEl;
    trBr = 0;
    niz = new Lezaljka*[maxEl];
}

KaficSaPlazom::KaficSaPlazom(const KaficSaPlazom& gg) {
    maxEl = gg.maxEl;
    trBr = gg.trBr;
    niz = new Lezaljka*[maxEl];
    for (int i = 0; i < trBr; i++) {
        niz[i] = gg.niz[i]; // Plitka kopija pokazivaca
    }
}

KaficSaPlazom::~KaficSaPlazom() {
    for (int i = 0; i < trBr; i++) {
        delete niz[i]; // Brisanje svakog objekta
    }
    delete[] niz; // Brisanje samog niza pokazivaca
}

void KaficSaPlazom::Dodaj(Lezaljka* _nova) {
    if (trBr < maxEl) {
        niz[trBr++] = _nova;
    }
}

void KaficSaPlazom::Oslobodi(int _redniBroj) {
    for (int i = 0; i < trBr; i++) {
        if (niz[i]->getRedniBroj() == _redniBroj) {
            delete niz[i];
            for (int j = i; j < trBr - 1; j++) {
                niz[j] = niz[j + 1]; // Pomeranje niza ulevo
            }
            trBr--;
            return;
        }
    }
}

int KaficSaPlazom::UkupnoLezaljki() const {
    return trBr;
}

float KaficSaPlazom::UkupnaSvotaNovca() const {
    float ukupno = 0;
    for (int i = 0; i < trBr; i++) {
        ukupno += niz[i]->svotaZaNaplatu();
    }
    return ukupno;
}

bool KaficSaPlazom::PostojiGdeTrebaPlatiti(float _svota) const {
    for (int i = 0; i < trBr; i++) {
        if (niz[i]->svotaZaNaplatu() > _svota) return true;
    }
    return false;
}

void KaficSaPlazom::VratiNajskuplje(Lezaljka** _maxUkupno, Lezaljka** _maxNapitak) {
    if (trBr == 0) return;
    *_maxUkupno = niz[0];
    *_maxNapitak = niz[0];
    for (int i = 1; i < trBr; i++) {
        if (niz[i]->svotaZaNaplatu() > (*_maxUkupno)->svotaZaNaplatu())
            *_maxUkupno = niz[i];
        if (niz[i]->getCenaNapitaka() > (*_maxNapitak)->getCenaNapitaka())
            *_maxNapitak = niz[i];
    }
}

std::ostream& operator<<(std::ostream& izlaz, const KaficSaPlazom& ksp) {
    for (int i = 0; i < ksp.trBr; i++) {
        izlaz << *(ksp.niz[i]) << std::endl;
    }
    return izlaz;
}
