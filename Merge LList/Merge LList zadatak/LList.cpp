#include <iostream>

struct Node {
    int key;
    Node* next;
};

Node* Merge(Node* h1, Node* h2) {
    Node* glava = nullptr;
    Node* tail = nullptr;
    while (h1 != nullptr && h2 != nullptr) {
        if (h1->key < h2->key) {
            if (glava == nullptr) {
                glava = h1;
                tail = h1;
            }
            else {
                tail->next = h1;
                tail = h1;
            }
            h1 = h1->next;
        }
        else {
            if (glava == nullptr) {
                glava = h2;
                tail = h2;
            }
            else {
                tail->next = h2;
                tail = h2;
            }
            h2 = h2->next;
        }
        if (h1 != nullptr)
            tail->next = h1;  
        if (h2 != nullptr)
            tail->next = h2;  
    }
    return glava;
}