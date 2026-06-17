#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Movie
{
private:
	char* naziv;
	char* punoImeReditelja;
	int trajanje;

public:
	Movie();
	Movie(const char* naziv, const char* punoImeReditelja, int trajanje);
	Movie(const Movie& og);
	~Movie();
	Movie& operator=(const Movie& og);
	bool operator==(const Movie& og) const;
	friend ostream& operator<<(ostream& izlaz, const Movie& m);
	friend istream& operator>>(istream& ulaz, Movie& m);
	Movie operator+(const Movie& d) const;
};
