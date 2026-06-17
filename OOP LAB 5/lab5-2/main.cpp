#include <iostream>
#include <fstream>
#include "Set.h"
#include "Movie.h"

using namespace std; // dodaj operator+ koji ce da shodno zadatku radi konkatenaciju(da sabira levu i desnu stranu(treba da radi za int i za bilo koju klasu))

int main() {
    ifstream ulaz("podaci.txt");
    if (!ulaz) return 1;

    Set<double>* d1 = new Set<double>();
    Set<double>* d2 = new Set<double>();

    ulaz >> *d1 >> *d2;
    Set<double> zbirD = (*d1) + (*d2);
    cout << "Zbir double:\n" << zbirD;

    cout << "Double skup 1:\n" << *d1;
    cout << "Double skup 2:\n" << *d2;

    Set<double> presekD = (*d1) * (*d2);
    cout << "Presek double:\n" << presekD;

    Set<Movie>* m1 = new Set<Movie>();
    Set<Movie>* m2 = new Set<Movie>();

    ulaz >> *m1 >> *m2;
    Set<Movie> zbirM = (*m1) + (*m2);
    cout << "Zbir Movie:\n" << zbirM;


    cout << "\nMovie skup 1:\n" << *m1;
    cout << "\nMovie skup 2:\n" << *m2;

    Set<Movie> presekM = (*m1) * (*m2);
    cout << "\nPresek Movie:\n" << presekM;


    delete d1;
    delete d2;
    delete m1;
    delete m2;

    ulaz.close();
    return 0;
}