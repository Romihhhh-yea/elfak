#include "Birac.h"

class HashTabela {
private:
    Birac** primarni;
    Birac** sinonimi;
    int* sledeci;
    int velicina;
    int lrmp;
public:
    HashTabela(int velicina);
    ~HashTabela();
    int hashFunkcija(char* jmbg);
    void dodajBiraca(char* jmbg, char* ime, char* prezime);
};