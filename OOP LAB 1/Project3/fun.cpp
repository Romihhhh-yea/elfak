#include "Skup.h"
using namespace std;

Skup::Skup() : n(0), a(nullptr) {}


Skup::Skup(int broj) : n(broj){
    if (n > 0)
        a = new int[n];
    else {
        n = 0; 
        a = nullptr;
    }
}


Skup::~Skup() {
    delete[] a;
}
Skup::Skup(const Skup& s) : n(s.n) {
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = s.a[i];
        }
}




void Skup::ucitaj() {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}


void Skup::prikazi()  {
    for (int i = 0; i < n; i++) {
        cout << a[i];
        cout << " ";
    }

}


bool Skup::pripada(int x)  {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) return true;
    }
    return false;
}


void Skup::sortirajNerastuce() {

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] < a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}


void Skup::izbaciDuplikate() {



    int* temp = new int[n];
    int k = 0;

    for (int i = 0; i < n; i++) {
        bool vecPostoji = false;
        for (int j = 0; j < k; j++) {
            if (temp[j] == a[i]) {
                vecPostoji = true;
                break;
            }
        }
        if (!vecPostoji) {
            temp[k++] = a[i];
        }
    }


    delete[] a;
    a = new int[k];
    for (int i = 0; i < k; i++)
        a[i] = temp[i];
    n = k;

    delete[] temp;
}
