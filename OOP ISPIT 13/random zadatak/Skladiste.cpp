#include "Skladiste.h"
#include <typeinfo>

void Skladiste::zauzmimem(int _maxEl) {
    trBr = 0;
    maxEl = _maxEl;
    niz = new Pice * [maxEl];
    for (int i = 0; i < maxEl; i++)
        niz[i] = nullptr;
}
void Skladiste::oslobodimem() {
    if (niz != nullptr)
        for (int i = 0; i < maxEl; i++)
            if (niz[i] != nullptr)
                delete niz[i];
    delete[] niz;
    
}
Skladiste::Skladiste() {
	niz = nullptr;
	maxEl = 0;
	trBr = 0;
}
Skladiste::Skladiste(int _maxEl) {
    zauzmimem(_maxEl);
	
}
Skladiste::~Skladiste() {
    oslobodimem();
}
Skladiste::Skladiste(const Skladiste& gg) {
    zauzmimem(gg.maxEl);

    for (int i = 0; i < gg.trBr; i++) {
       
        if (typeid(*gg.niz[i]) == typeid(Sok)) {
            
            niz[i] = new Sok(*dynamic_cast<Sok*>(gg.niz[i]));
        }
        else {
            
            niz[i] = new Voda(*dynamic_cast<Voda*>(gg.niz[i]));
        }
    }
}
void Skladiste::Dodaj(Pice* p) {
    for (int i = 0; i < trBr; i++) {
        
        if (typeid(*niz[i]) == typeid(*p)) {

            
            if (niz[i]->getZapremina() == p->getZapremina()) {

               
                niz[i]->setBroj(niz[i]->getBroj() + p->getBroj());

                delete p; 
                return;  
            }
        }
    }
    if (trBr < maxEl)
        niz[trBr++] = p;
}
void Skladiste::prikazi(ostream& izlaz) {
    izlaz << "Sadrzaj skladista:" << endl;
    for (int i = 0; i < trBr; i++) {
        
        izlaz << *niz[i] << endl;
    }
}
ostream& operator<<(ostream& izlaz, const Skladiste& s) {
    izlaz << "--- SKLADISTE (kapacitet: " << s.maxEl << ", popunjeno: " << s.trBr << ") ---" << endl;
    for (int i = 0; i < s.trBr; i++) {
        izlaz << "[" << i + 1 << "] " << *s.niz[i] << endl;
    }
    return izlaz;
}
void Skladiste::Izdvoji(Pice* p, int kolicina) {
    for (int i = 0; i < trBr; i++) {
       
        if (typeid(*niz[i]) == typeid(*p) && niz[i]->getZapremina() == p->getZapremina()) {

            int trenutno = niz[i]->getBroj();


            if (trenutno >= kolicina) {
                int novoStanje = trenutno - kolicina;
                niz[i]->setBroj(novoStanje);

                
                if (novoStanje == 0) {
                    delete niz[i]; 

                   
                    for (int j = i; j < trBr - 1; j++) {
                        niz[j] = niz[j + 1];
                    }
                    trBr--; 
                }
            }
            else {
                
                cout << "Nema dovoljno ambalaza za iznosenje!" << endl;
            }
            return; 
        }
    }
    
    cout << "Trazeno pice ne postoji u skladistu!" << endl;
}