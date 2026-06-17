#include <iostream>
#include "Paketic.h"
class PaketicHrana : public Paketic {
private:
    int brojCokolada;
    double ukupnaTezinaCokolade;
    double cenaPoKg;

public:
    PaketicHrana();                                   // default
    PaketicHrana(const char* adresa,const char* boja,int brojCokolada,double ukupnaTezinaCokolade,double cenaPoKg); // param
    PaketicHrana(const PaketicHrana&);                // copy
    ~PaketicHrana();                                  // destruktor

    double cena() const override;
    double tezina() const override;
    void prikazi(std::ostream&) const override;
};