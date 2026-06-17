#ifndef SKLADISTE_H
#define SKLADISTE_H

#include <iostream>
#include <fstream>

template <typename T>
class Skladiste {
private:
    T* niz;
    int trBr;
    int maxEl;

public:
    Skladiste() {
        maxEl = 10;
        trBr = 0;
        niz = new T[maxEl];
    }

    Skladiste(int _maxEl) {
        maxEl = _maxEl;
        trBr = 0;
        niz = new T[maxEl];
    }

    Skladiste(const Skladiste<T>& gg) {
        maxEl = gg.maxEl;
        trBr = gg.trBr;
        niz = new T[maxEl];
        for (int i = 0; i < trBr; i++) {
            niz[i] = gg.niz[i];
        }
    }

    ~Skladiste() {
        delete[] niz;
    }

    void Dodaj(T _podatak) {
        if (trBr < maxEl) {
            niz[trBr++] = _podatak;
        }
    }

    void Preuzmi(int _indeks, int _kolicina) {
        if (_indeks >= 0 && _indeks < trBr) {
            niz[_indeks].smanjiMasu(_kolicina);
            if (niz[_indeks].getMasa() <= 0) {
                for (int i = _indeks; i < trBr - 1; i++) {
                    niz[i] = niz[i + 1];
                }
                trBr--;
            }
        }
    }

    int UkupnaMasa() const {
        int suma = 0;
        for (int i = 0; i < trBr; i++) {
            suma += niz[i].getMasa();
        }
        return suma;
    }

    int BrojSaVecomKolicinom(int _granica) const {
        int brojac = 0;
        for (int i = 0; i < trBr; i++) {
            if (niz[i].getMasa() > _granica) {
                brojac++;
            }
        }
        return brojac;
    }

    void NajViseManje(int _indeks1, int _indeks2, T& _min, T& _max) {
        if (_indeks1 < 0 || _indeks1 >= trBr) return;
        _min = niz[_indeks1];
        _max = niz[_indeks1];
        for (int i = _indeks1 + 1; i <= _indeks2 && i < trBr; i++) {
            if (niz[i].getMasa() < _min.getMasa()) _min = niz[i];
            if (niz[i].getMasa() > _max.getMasa()) _max = niz[i];
        }
    }

    void Sacuvaj(const char* _imeFajla) {
        std::ofstream fajl(_imeFajla);
        if (fajl.is_open()) {
            fajl << trBr << std::endl;
            for (int i = 0; i < trBr; i++) {
                fajl << niz[i] << std::endl;
            }
            fajl.close();
        }
    }

    void Ucitaj(const char* _imeFajla) {
        std::ifstream fajl(_imeFajla);
        if (fajl.is_open()) {
            fajl >> trBr;
            for (int i = 0; i < trBr; i++) {
                fajl >> niz[i];
            }
            fajl.close();
        }
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& izlaz, const Skladiste<U>& s);
};

template <typename U>
std::ostream& operator<<(std::ostream& izlaz, const Skladiste<U>& s) {
    for (int i = 0; i < s.trBr; i++) {
        izlaz << s.niz[i] << " ";
    }
    return izlaz;
}

template <>
class Skladiste<int> {
private:
    int* niz;
    int trBr;
    int maxEl;

public:
    Skladiste(int _maxEl) {
        maxEl = _maxEl;
        trBr = 0;
        niz = new int[maxEl];
    }

    ~Skladiste() {
        delete[] niz;
    }

    void Dodaj(int _m) {
        if (trBr < maxEl) niz[trBr++] = _m;
    }

    void Preuzmi(int _i, int _k) {
        if (_i >= 0 && _i < trBr) {
            niz[_i] -= _k;
            if (niz[_i] <= 0) {
                for (int j = _i; j < trBr - 1; j++) {
                    niz[j] = niz[j + 1];
                }
                trBr--;
            }
        }
    }

    int UkupnaMasa() {
        int s = 0;
        for (int i = 0; i < trBr; i++) s += niz[i];
        return s;
    }

    int BrojSaVecomKolicinom(int _g) {
        int b = 0;
        for (int i = 0; i < trBr; i++) if (niz[i] > _g) b++;
        return b;
    }

    void NajViseManje(int _i1, int _i2, int& _min, int& _max) {
        if (_i1 < 0 || _i1 >= trBr) return;
        _min = niz[_i1];
        _max = niz[_i1];
        for (int i = _i1 + 1; i <= _i2 && i < trBr; i++) {
            if (niz[i] < _min) _min = niz[i];
            if (niz[i] > _max) _max = niz[i];
        }
    }

    void Sacuvaj(const char* _f) {
        std::ofstream o(_f);
        if (o.is_open()) {
            o << trBr << std::endl;
            for (int i = 0; i < trBr; i++) o << niz[i] << " ";
            o.close();
        }
    }

    void Ucitaj(const char* _f) {
        std::ifstream i(_f);
        if (i.is_open()) {
            i >> trBr;
            for (int j = 0; j < trBr; j++) i >> niz[j];
            i.close();
        }
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& o, const Skladiste<U>& s);
};

#endif