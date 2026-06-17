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

	inline int brojElemenata() const{ 
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
			for (int j = 0; j < n - i - 1; j++) {
				if (a[j] < a[j + 1]) {
					int temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
	}
	void izbaciduplikate() {
		int* temp = new int[n];
		int k = 0;
		for (int i = 0; i < n; i++) {
			bool vecpostoji = false;
			for (int j = 0; j < k; j++) {
				if (temp[j] == a[i]) {
					vecpostoji = true;
					break;
				}
			}
			if (!vecpostoji) {
				temp[k++] = a[i];
			}
		}
		delete[] a;
		a = new int[n];
		for (int i = 0; i < n; i++) 
			a[i] = temp[i];
			n = k;
			delete[] temp;
	}

};

	