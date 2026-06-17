#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class Figura{
protected:
	char* boja;
public:
	Figura();
	Figura(const char* _boja);
	Figura(const Figura& gg);
	virtual ~Figura();

	friend ostream& operator<<(ostream& izlaz, const Figura& f);
	virtual void prikazi(ostream& izlaz) const ;
	virtual double obim() const = 0;
	virtual double povrsina() const = 0; 
	virtual double koeficijent() const ;
	inline char* getBoja() const { return boja; }
};

