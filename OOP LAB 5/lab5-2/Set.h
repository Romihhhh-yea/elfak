#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Set
{
private:
	T* niz;
	int n;

public:
	Set()
	{
		niz = nullptr;
		n = 0;
	}

	Set(int n)
	{
		this->n = n;
		niz = new T[n];
	}

	Set(const Set<T>& og)
	{
		n = og.n;
		niz = new T[n];
		for (int i = 0; i < n; i++)
		{
			niz[i] = og.niz[i];
		}
	}

	~Set()
	{
		delete[] niz;
	}

	inline int getBrElemenata() const { return n; }

	Set<T>& operator=(const Set<T>& og) {
		if (this != &og) {
			delete[] niz;
			n = og.n;
			niz = new T[n];
			for (int i = 0; i < n; i++) {
				niz[i] = og.niz[i];
			}
		}
		return *this;
	}

	bool pripada(const T& el) const
	{
		for (int i = 0; i < n; i++)
		{
			if (niz[i] == el)
			{
				return true;
			}
		}
		return false;
	}

	Set<T> operator*(const Set<T>& t) const
	{
		int br = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < t.n; j++)
			{
				if (niz[i] == t.niz[j])
				{
					br++;
					break;
				}

			}
		}

		Set<T> presek(br);
		int k = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < t.n; j++)
			{
				if (niz[i] == t.niz[j])
				{
					presek.niz[k++] = niz[i];
					break;
				}
			}
		}

		return presek;
	}

	friend ostream& operator<<(ostream& izlaz, const Set<T>& s)
	{
		izlaz << "Broj elemenata: " << s.n << endl;
		for (int i = 0; i < s.n; i++)
		{
			izlaz << s.niz[i] << endl;
		}

		return izlaz;
	}

	friend istream& operator>>(istream& ulaz, Set<T>& s)
	{
		int n;
		if (ulaz >> n)
		{
			delete[] s.niz;
			s.n = n;
			s.niz = new T[s.n];
			for (int i = 0; i < s.n; i++)
			{
				ulaz >> s.niz[i];
			}
		}

		return ulaz;
	}
	/*Set<T> operator+(const Set<T>& s) const
	{
		Set<T> rez(n + s.n);

		int k = 0;

		for (int i = 0; i < n; i++)
			rez.niz[k++] = niz[i];

		for (int i = 0; i < s.n; i++)
			rez.niz[k++] = s.niz[i];

		return rez;
	}*/
	Set<T> operator+(const Set<T>& s) const
	{
		int m = (n < s.n) ? n : s.n;  
		Set<T> rez(m);

		for (int i = 0; i < m; i++)
			rez.niz[i] = niz[i] + s.niz[i];

		return rez;
	}




};
	

