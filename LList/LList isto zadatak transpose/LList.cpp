#include <iostream>

struct Cvor {
    int key;
    Cvor* next;
};

Cvor* head = nullptr;

void Transpose2(int key) {
    Cvor* curr = head;
    Cvor* prev = nullptr;
    Cvor* prev2 = nullptr;


   
    while (curr != nullptr && curr->key != key) {
            prev2 = prev;
            prev = curr;
            curr = curr->next;
    }
    if (curr == nullptr) {
        return;
    }
    if (prev == nullptr) {
        return;
    }
    if (prev2 == nullptr) {
        prev->next = curr->next;
        curr->next = head;
        head = curr;
        return;
    }
    prev->next = curr->next;
    curr->next = prev2->next;
    prev2->next = curr;

}