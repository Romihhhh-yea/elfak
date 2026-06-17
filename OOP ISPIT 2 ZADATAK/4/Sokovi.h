#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class Sokovi
{
private:
	char* naziv;
	float zapremina;
	int procenat;
public:
	Sokovi();
	Sokovi(const char* _naziv, float _zapremina, int _procenat);
	~Sokovi();
	Sokovi(const Sokovi& gg);
	void prikazi(ostream& izlaz) const;
	operator float() const ;

	friend ostream& operator<<(ostream& izlaz, const Sokovi& s);
	Sokovi& operator=(const Sokovi&);
	bool operator==(const Sokovi& s) const ;
	bool operator<(const Sokovi& s) const ;
	friend istream& operator>>(istream& ulaz, Sokovi& s);
};

