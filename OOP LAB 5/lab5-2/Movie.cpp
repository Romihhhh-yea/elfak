#include "Movie.h"
#include <cstring>

Movie::Movie()
{
	naziv = nullptr;
	punoImeReditelja = nullptr;
	trajanje = 0;
}

Movie::Movie(const char* naziv, const char* punoImeReditelja, int trajanje)
{
	this->naziv = new char[strlen(naziv) + 1];
	strcpy(this->naziv, naziv);
	this->punoImeReditelja = new char[strlen(punoImeReditelja) + 1];
	strcpy(this->punoImeReditelja, punoImeReditelja);
	this->trajanje = trajanje;
}

Movie::Movie(const Movie& og)
{
	naziv = new char[strlen(og.naziv) + 1];
	strcpy(naziv, og.naziv);
	punoImeReditelja = new char[strlen(og.punoImeReditelja) + 1];
	strcpy(punoImeReditelja, og.punoImeReditelja);
	trajanje = og.trajanje;
}

Movie::~Movie()
{
	if (naziv != nullptr)
	{
		delete[] naziv;
	}
	if (punoImeReditelja != nullptr)
	{
		delete[] punoImeReditelja;
	}
}

Movie& Movie::operator=(const Movie& og)
{
	if (this != &og)
	{
		delete[] naziv;
		delete[] punoImeReditelja;
		naziv = new char[strlen(og.naziv) + 1];
		strcpy(naziv, og.naziv);
		punoImeReditelja = new char[strlen(og.punoImeReditelja) + 1];
		strcpy(punoImeReditelja, og.punoImeReditelja);
		trajanje = og.trajanje;
	}

	return *this;
}
Movie Movie::operator+(const Movie& d) const
{
	return Movie(naziv, punoImeReditelja, trajanje + d.trajanje);
}


bool Movie::operator==(const Movie& og) const
{
	if (trajanje != og.trajanje || naziv == nullptr || punoImeReditelja == nullptr || og.naziv == nullptr ||
		og.punoImeReditelja == nullptr)
	{
		return false;
	}
	if (strcmp(naziv, og.naziv) == 0 && strcmp(punoImeReditelja, og.punoImeReditelja) == 0)
	{
		return true;
	}

	return false;
}

ostream& operator<<(ostream& izlaz, const Movie& m)
{
	izlaz << "Naziv filma: " << m.naziv << endl;
	izlaz << "Puno ime reditelja: " << m.punoImeReditelja << endl;
	izlaz << "Trajanje filma: " << m.trajanje << endl;
	return izlaz;
}

istream& operator>>(istream& ulaz, Movie& m)
{
	char pom[100];
	ulaz >> ws;
	ulaz.getline(pom, 100);
	delete[] m.naziv;
	m.naziv = new char[strlen(pom) + 1];
	strcpy(m.naziv, pom);

	ulaz.getline(pom, 100);
	delete[] m.punoImeReditelja;
	m.punoImeReditelja = new char[strlen(pom) + 1];
	strcpy(m.punoImeReditelja, pom);

	ulaz >> m.trajanje;

	return ulaz;
}