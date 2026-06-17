void Update(int value, int add) {
    Cvor* trenutni = head;
    Cvor* prethodni = nullptr;

    // trazimo cvor sa vrednošcu value
    while (trenutni != nullptr && trenutni->vrednost != value) {
        prethodni = trenutni;
        trenutni = trenutni->next;
    }

    // ako nije nadjen
    if (trenutni == nullptr)
        return;

    // iskljucujemo ga iz liste
    Cvor* temp = trenutni;
    if (prethodni == nullptr)
        head = trenutni->next;
    else
        prethodni->next = trenutni->next;

    // povecavamo vrednost
    temp->vrednost += add;

    // trazimo pravo mesto za ubacivanje
    trenutni = head;
    prethodni = nullptr;
    while (trenutni != nullptr && temp->vrednost > trenutni->vrednost) {
        prethodni = trenutni;
        trenutni = trenutni->next;
    }

    // ubacujemo na pravo mesto
    temp->next = trenutni;
    if (prethodni == nullptr)
        head = temp;
    else
        prethodni->next = temp;
} 