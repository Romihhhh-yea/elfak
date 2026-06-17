#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class Predmet {
protected:
	char* naziv;
public:
	Predmet();
	Predmet(const char* _naziv);
	virtual ~Predmet();
	Predmet(const Predmet& gg);

	virtual void prikazi(ostream& izlaz) const;
	friend ostream& operator<<(ostream& izlaz, const Predmet& p);
	virtual double vrednost() const = 0;
	virtual double getMasa() const = 0;
 };