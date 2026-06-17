#include "Skup.h"


Skup::Skup() : n(0) {
    a = new Complex[n];
}


Skup::Skup(int brojElemenata) : n(brojElemenata) {
    a = new Complex[n];
}


Skup::Skup(const Skup& s) : n(s.n) {
    a = new Complex[n];
    for (int i = 0; i < n; i++)
        a[i] = s.a[i];
}


Skup::~Skup() {
    delete[] a;
}


Skup& Skup::operator=(const Skup& s) {
    if (this == &s) return *this;

    delete[] a;
    n = s.n;
    a = new Complex[n];

    for (int i = 0; i < n; i++)
        a[i] = s.a[i];

    return *this;
}


bool Skup::pripada(const Complex& x) const {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) return true;
    }
    return false;
}


void Skup::izbaciDuplikate() {
    Complex* temp = new Complex[n];
    int k = 0;

    for (int i = 0; i < n; i++) {
        bool postoji = false;
        for (int j = 0; j < k; j++) {
            if (temp[j] == a[i]) {
                postoji = true;
                break;
            }
        }
        if (!postoji) temp[k++] = a[i];
    }

    delete[] a;
    a = new Complex[k];
    n = k;

    for (int i = 0; i < n; i++)
        a[i] = temp[i];

    delete[] temp;
}


void Skup::dodajAkoNePostoji(const Complex& x) {
    if (pripada(x)) return;

    Complex* novi = new Complex[n + 1];
    for (int i = 0; i < n; i++)
        novi[i] = a[i];

    novi[n] = x;

    delete[] a;
    a = novi;
    n++;
}


Skup Skup::unija(const Skup& s) const {
    Skup r;
    for (int i = 0; i < n; i++)
        r.dodajAkoNePostoji(a[i]);
    for (int i = 0; i < s.n; i++)
        r.dodajAkoNePostoji(s.a[i]);
    return r;
}


Skup Skup::presek(const Skup& s) const {
    Skup r;
    for (int i = 0; i < n; i++) {
        if (s.pripada(a[i])) r.dodajAkoNePostoji(a[i]);
    }
    return r;
}


Skup Skup::razlika(const Skup& s) const {
    Skup r;
    for (int i = 0; i < n; i++) {
        if (!s.pripada(a[i])) r.dodajAkoNePostoji(a[i]);
    }
    return r;
}


std::istream& operator>>(std::istream& in, Skup& s) {
    for (int i = 0; i < s.n; i++)
        in >> s.a[i];

    s.izbaciDuplikate();
    return in;
}


std::ostream& operator<<(std::ostream& out, const Skup& s) {
    out << "{ ";
    for (int i = 0; i < s.n; i++) {
        out << s.a[i];
        if (i != s.n - 1) out << ", ";
    }
    out << " }";
    return out;
}
