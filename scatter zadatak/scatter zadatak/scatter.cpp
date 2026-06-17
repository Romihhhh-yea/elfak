#include <iostream>

struct ScatterObject {
	int key;
};
class scatter {
	int m;
	ScatterObject* tabela[m];

	unsigned int h(ScatterObject o) {
		int kljuc = o.key;

		return kljuc % m;
	}
	unsigned int g(int i) {
		return i * i;
	}
	void insert(ScatterObject o) {
		unsigned int indeks = h(o);
		int i = 0;
		while (tabela[indeks] != nullptr) {
			i++;
			indeks = (h(o) + g(i)) % m;
		}
		tabela[indeks] = o;
	}
};