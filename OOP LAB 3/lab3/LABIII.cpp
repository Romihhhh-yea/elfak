#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>

class Funkcija {
protected:
    double k;
    double n;
    char* naziv;
public:
    Funkcija() : k(1), n(0) {
        naziv = new char[strlen("Linearna funkcija") + 1];
        strcpy(naziv, "Linearna funkcija");
    };

    Funkcija(double kk, double nn) : k(kk), n(nn) {
        naziv = new char[strlen("Linearna funkcija") + 1];
        strcpy(naziv, "Linearna funkcija");
    };

    virtual ~Funkcija() {
        delete[] naziv;
    };

    virtual double vrednost(double x) const {
        return k * x + n;
    };

    virtual void prikaziFunkciju() const {
        std::cout << naziv << "\n";
        std::cout << "f(x) = kx + n\n";
    };
};

class KvadratnaFunkcija : public Funkcija {
public:
    KvadratnaFunkcija() : Funkcija(2, 0) {
        delete[] naziv;
        naziv = new char[strlen("Kvadratna funkcija") + 1];
        strcpy(naziv, "Kvadratna funkcija");
    }

    KvadratnaFunkcija(double kk, double nn, const char* naz) : Funkcija(kk, nn) {
        delete[] naziv;
        naziv = new char[strlen(naz) + 1];
        strcpy(naziv, naz);
    };

    double vrednost(double x) const override {
        return pow((x + n), k);
    };

    void prikaziFunkciju() const override {
        std::cout << naziv << "\n";
        std::cout << "f(x) = (x + n)^k\n";
    };
};

class EksponencijalnaFunkcija : public Funkcija {
public:
    EksponencijalnaFunkcija() : Funkcija(exp(1.0), 0) {
        delete[] naziv;
        naziv = new char[strlen("Eksponencijalna funkcija") + 1];
        strcpy(naziv, "Eksponencijalna funkcija");
    }
    EksponencijalnaFunkcija(double nn, const char* naz) : Funkcija(std::exp(1.0), nn) {
        delete[] naziv;
        naziv = new char[std::strlen(naz) + 1];
        std::strcpy(naziv, naz);
    };
    double vrednost(double x) const override {
        return pow(k,(x+n));
    };

    void prikaziFunkciju() const override {
        std::cout << naziv << "\n";
        std::cout << "f(x) = k^(x + n)\n";
    };

};
int main() {
    Funkcija* niz[2019];

    for (int i = 0; i < 673; i++) {
        niz[i] = new Funkcija();
    }
    for (int i = 673; i < 673 + 673; i++) {
        niz[i] = new KvadratnaFunkcija();
    }
    for (int i = 673 + 673; i < 673 + 673 + 673; i++) {
        niz[i] = new EksponencijalnaFunkcija();
    }

    for (int i = 0; i < 2019; i++) {
        niz[i]->prikaziFunkciju();
    }
    double x;
    std::cout << "Unesi x: ";
    std::cin >> x;
    int minIdx = 0;
    double minVal = niz[0]->vrednost(x);
    for (int i = 1; i < 2019; i++) {
        double v = niz[i]->vrednost(x);
        if (v < minVal) {
            minVal = v;
            minIdx = i;
        }
    }
    std::cout << "MIN = " << minVal << "\n";
    niz[minIdx]->prikaziFunkciju();
    for (int i = 0; i < 2019; i++) {
        delete niz[i];
    }
    return 0;

};
