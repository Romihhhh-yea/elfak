#pragma once
#include <iostream>
using namespace std;
class PaletaProsirena
{
private:
	float masaDaske;
	int kolicina;
	float sirinaSvih;
public:
	PaletaProsirena();
	PaletaProsirena(float _masaDaske,int _kolicina,float _sirinaSvih);
	PaletaProsirena(const PaletaProsirena& gg);
	~PaletaProsirena();
	operator int() { return (int)(masaDaske * kolicina); }
    void operator-=(int skinutiMase) {
        if (this->masaDaske > 0) {
            int brojDasakaZaUklanjanje = skinutiMase / this->masaDaske;
            this->kolicina -= brojDasakaZaUklanjanje;

        }

       
    }
	friend ostream& operator<<(ostream& izlaz, const PaletaProsirena& p);
};

