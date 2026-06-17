#ifndef PALETA_H
#define PALETA_H
#include <iostream>

class Paleta {
protected:
    int masaDrvnogMaterijala;
public:
    Paleta();
    Paleta(int _masaDrvnogMaterijala);
    Paleta(const Paleta& gg);
    virtual ~Paleta();

    virtual int getMasa() const { return masaDrvnogMaterijala; }
    void smanjiMasu(int _iznos);

    virtual void Prikazi(std::ostream& izlaz) const;
    friend std::ostream& operator<<(std::ostream& izlaz, const Paleta& p);

   
    friend std::istream& operator>>(std::istream& ulaz, Paleta& p);
};
#endif