#include <iostream>
using namespace std;

class Skup {
private:
    int n;      
    int* a;     

public:
    
   Skup() : n(0), a(nullptr) {}

    
    Skup(int broj) : n(broj) {
        if (n > 0)
        a = new int[n];
        else {
            n = 0;
            a = nullptr;
        }
    }

    
    ~Skup() {
        delete[] a;
    }

    
    inline int brojElemenata() const { 
        return n; 
    }

   
    void ucitaj() {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }

    
    void prikazi() const {
        for (int i = 0; i < n; i++) {
            cout << a[i];
            cout << " ";
        }
      
    }

    
    bool pripada(int x) const {
        for (int i = 0; i < n; i++) {
            if (a[i] == x) return true; 
        }
        return false;
    }

    
    void sortirajNerastuce() {
      
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

   
    void izbaciDuplikate() {
      

        
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
};

int main() {
    
    Skup* s1 = new Skup(10);

    cout << "Unesi 10 elemenata skupa s1:" << endl;
    s1->ucitaj();

    cout << "s1 = ";
    s1->prikazi();

    
    int q;
    cout << "\nKoliko brojeva zelis da proveris? ";
    cin >> q;

    for (int i = 0; i < q; i++) {
        int x;
        cout << "Unesi broj za proveru: ";
        cin >> x;

        if (s1->pripada(x)) cout << x << " pripada skupu.\n";
        else cout << x << " NE pripada skupu.\n";
    }

    
    cout << "\n--- TEST s2 ---" << endl;
    Skup* s2 = new Skup(10);

    cout << "Unesi 10 elemenata skupa s2:" << endl;
    s2->ucitaj();

    cout << "Pre izbacivanja duplikata, s2 = ";
    s2->prikazi();

    cout << "Broj elemenata (pre) = " << s2->brojElemenata() << endl;

    s2->izbaciDuplikate();
    cout << "Posle izbacivanja duplikata, s2 = ";
    s2->prikazi();

    cout << "Broj elemenata (posle) = " << s2->brojElemenata() << endl;

    s2->sortirajNerastuce();
    cout << "Posle sortiranja nerastuce, s2 = ";
    s2->prikazi();

    cout << "\nProvera pripadnosti u s2 (unesi jedan broj): ";
    int t;
    cin >> t;
    cout << (s2->pripada(t) ? "Pripada.\n" : "Ne pripada.\n");

    
    delete s1;
    delete s2;

    return 0;
}