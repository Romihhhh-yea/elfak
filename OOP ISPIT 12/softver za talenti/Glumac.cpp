#include "Glumac.h"

Glumac::Glumac() : Ucesnik() {
    brojRekvizita = 0;
    poeniZirijaZaIdeju = 0;
    poeniZirijaZaIzvodjenje = 0;
}

Glumac::Glumac(int _redniBr, const char* _ime, const char* _prezime, int _poeniPublike,
    int _brojRekvizita, int _poeniZirijaZaIdeju, int _poeniZirijaZaIzvodjenje)
    : Ucesnik(_redniBr, _ime, _prezime, _poeniPublike) {

    // Validacija poena prema tekstu
    if (_poeniZirijaZaIdeju < 0 || _poeniZirijaZaIdeju > 100 ||
        _poeniZirijaZaIzvodjenje < 0 || _poeniZirijaZaIzvodjenje > 50) {
        throw "Nevalidan broj poena za glumca!";
    }

    brojRekvizita = _brojRekvizita;
    poeniZirijaZaIdeju = _poeniZirijaZaIdeju;
    poeniZirijaZaIzvodjenje = _poeniZirijaZaIzvodjenje;
}

Glumac::Glumac(const Glumac& g) : Ucesnik(g) {
    brojRekvizita = g.brojRekvizita;
    poeniZirijaZaIdeju = g.poeniZirijaZaIdeju;
    poeniZirijaZaIzvodjenje = g.poeniZirijaZaIzvodjenje;
}

Glumac::~Glumac() {} // Nema dinamicke memorije u samom Glumcu

double Glumac::poeniZirija() const {
    return (double)(poeniZirijaZaIdeju + poeniZirijaZaIzvodjenje);
}

double Glumac::ukupnoPoena() const {
    // Ukupan broj poena je suma publike i oba zirija
    return (double)(poeniPublike + poeniZirijaZaIdeju + poeniZirijaZaIzvodjenje);
}

int Glumac::pomocnoOsoblje() const {
    return brojRekvizita / 2;
}

int Glumac::maksimalniPoeniZirija() const {
    return 150; // 100 za ideju + 50 za izvodjenje
}

void Glumac::prikazi(ostream& izlaz) {
    Ucesnik::prikazi(izlaz); // Pozivamo osnovni prikaz iz baze
    izlaz << " | TIP: Glumac | Rekviziti: " << brojRekvizita
        << " | Pomocno osoblje: " << pomocnoOsoblje();
}
