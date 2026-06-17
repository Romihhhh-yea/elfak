#include "Kupac.h"
#include "Predmet.h"
#include "ZlatnaPoluga.h"
#include "DragoKamenje.h"
#include "Jabuka.h"
void Kupac::zauzmimem(int _maxBr) {
    trBr = 0;
    maxBr= _maxBr;
    niz = new Predmet * [maxBr];
    for (int i = 0; i < maxBr; i++) {
        niz[i] = nullptr;
    }
}
void Kupac::oslobodimem() {
    if (niz != nullptr)
        for (int i = 0; i < trBr; i++) {
            if (niz[i] != nullptr)
                delete niz[i];
        }
    delete[] niz;
}
Kupac::Kupac() {
    maxBr = 0;
    trBr = 0;
    niz = nullptr;
}

Kupac::Kupac(int _maxBr) {
    niz = new Predmet * [_maxBr];
}

Kupac::Kupac(const Kupac& gg) {
    zauzmimem(gg.maxBr);
    for (int i = 0; i < gg.trBr; i++) {
        if (typeid(*gg.niz[i]) == typeid(ZlatnaPoluga)) {
            Add(new ZlatnaPoluga(*dynamic_cast<ZlatnaPoluga*>(gg.niz[i])));
        }
        else if (typeid(*gg.niz[i]) == typeid(DragoKamenje)) {
            Add(new DragoKamenje(*dynamic_cast<DragoKamenje*>(gg.niz[i])));
        }
        else
            Add(new Jabuka(*dynamic_cast<Jabuka*>(gg.niz[i])));
        
          }
    
}

Kupac::~Kupac() {
    oslobodimem();
}
void Kupac::prikazi(ostream& izlaz) const {
    for (int i = 0; i < trBr; i++) {
        niz[i]->prikazi(izlaz);
      
    }
}

ostream& operator<<(ostream& izlaz, const Kupac& k) {
    for (int i = 0; i < k.maxBr; i++) {
        k.niz[i]->prikazi(izlaz);
        return izlaz;
    }
}
double Kupac::prosecnaVrednost() const {
    double suma = 0;
    for (int i = 0; i <trBr; i++) {
        suma += niz[i]->vrednost();
    }
    return suma / trBr;
}
Predmet* Kupac::najvrednijiPoJediniciMase() const {
    if (trBr == 0) return nullptr;
    Predmet* max = niz[0];
    double maxV = niz[0]->vrednost() / niz[0]->getMasa();
    for (int i = 1; i < trBr; i++) {
        double v = niz[i]->vrednost() / niz[0]->getMasa();
        if (v > maxV) {
            maxV = v;
            max = niz[i];
        }
    }
    return max;

}
void Kupac::Add(Predmet* p) {
    if (trBr < maxBr)
        niz[trBr++] = p;
}

