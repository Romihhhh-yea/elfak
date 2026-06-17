#include <stdio.h>
    typedef struct {
        int id;               
        char naziv[100];
        char autor[100];
        int godina;
        float cena;
        int kolicina;
    } Knjiga;

    void ucitajIzFajla(Knjiga** niz, int* n)
    {
        FILE* f = fopen("knjige.dat", "rb");
        if (f == NULL)
        {
            *n = 0;
            *niz = NULL;
            return;
        }

        fread(n, sizeof(int), 1, f);
        *niz = (Knjiga*)malloc((*n) * sizeof(Knjiga));
        fread(*niz, sizeof(Knjiga), *n, f);

        fclose(f);
    }
    void SacuvajUFajl(Knjiga* niz, int n) {
        FILE* f = fopen("knjige.dat", "wb");
        if (f == NULL) {
            printf("Greska");
            return;
        }
        fwrite(&n, sizeof(int), 1, f);
        if (n > 0) {
            fwrite(niz, sizeof(Knjiga), n, f);
        }
        fclose(f);
    }

    int main() {
        Knjiga* niz = NULL;
        int n = 0;

        ucitajIzFajla(&niz, &n);

        

        sacuvajUFajl(niz, n);
        free(niz);
        return 0;
    }
