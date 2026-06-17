#include "Stovariste.h"
#include "PaletaDzak.h"
#include "PaletaPloce.h"
Stovariste::Stovariste() {
	kapacitet = 0;
	trBr = 0;
	niz = nullptr;
}
Stovariste::Stovariste(int _kapacitet) {
	kapacitet = _kapacitet;
	trBr = 0;
	niz = new Paleta * [kapacitet];
}
Stovariste::~Stovariste() {
	for (int i = 0; i < trBr; i++) {
		delete niz[i];
	}
	delete[] niz;

}
Stovariste::Stovariste(const Stovariste& gg) {
    kapacitet = gg.kapacitet;
    trBr = gg.trBr;
    niz = new Paleta * [kapacitet];

    for (int i = 0; i < trBr; i++) {
        if (auto* d = dynamic_cast<PaletaDzak*>(gg.niz[i])) {
            niz[i] = new PaletaDzak(*d);
        }
        else if (auto* p = dynamic_cast<PaletaPloce*>(gg.niz[i])) {
            niz[i] = new PaletaPloce(*p);
        }
        else {
            niz[i] = nullptr;
        }
    }
}
void Stovariste::Ispisi(std::ostream& out) const {
    for (int i = 0; i < trBr; i++) {
        out << *(niz[i]) << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Stovariste& s) {
    s.Ispisi(out);
    return out;
}
void Stovariste::Dodaj(Paleta* p) {
    if (trBr < kapacitet)
        niz[trBr++] = p;
}
void Stovariste::Preuzmi(int oznaka) {
    for (int i = 0; i < trBr; i++) {
        if (niz[i]->GetOznaka() == oznaka) {
            delete niz[i];

            for (int j = i; j < trBr - 1;j++) {
                niz[j] = niz[j + 1];
            }
            trBr--;
            niz[trBr] == nullptr;
            return;
        }
    }
}
float Stovariste::UkupnaMasa() {
    float suma = 0;
    for (int i = 0; i < trBr;i++) {
        suma += niz[i]->UkupnaMasa();
    }
    return suma;
}
float Stovariste::UkupnaVrednost() {
    float suma = 0;
    for (int i = 0; i < trBr; i++) {
        suma += niz[i]->Vrednost();
    }
    return suma;
}
