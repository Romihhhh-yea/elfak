#include <iostream>
#include "Paketic.h"

class PaketicIgracke : public Paketic {
private:
    int brojIgracaka;
    double tezinaJedne;
    double cenaJedne;

public:
    PaketicIgracke();
    PaketicIgracke(const char* adresa, const char* boja,
    int brojIgracaka, double tezinaJedne, double cenaJedne);
    PaketicIgracke(const PaketicIgracke& gg);
    ~PaketicIgracke();

    double tezina() const override;
    double cena() const override;
    void prikazi(std::ostream&) const override;
};
