#include <iostream>
#include <cstring>


class Paketic {
protected:
	char* adresa;
	char* boja;
public:
	Paketic();
	Paketic(const char* _adresa, const char* _boja);
	virtual ~Paketic();
	Paketic(const Paketic& gg);

	virtual double cena() const = 0;
	virtual double tezina() const = 0;
	virtual void prikazi(std::ostream& izlaz) const;
	friend std::ostream& operator<<(std::ostream& izlaz, const Paketic& p);
	const char* getAdresa() const;
};
  