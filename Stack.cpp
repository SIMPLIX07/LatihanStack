#include <iostream>
#define nil NULL
using namespace std;

struct piring {
    string punyaOrang;
};

typedef piring infotype;
typedef struct elmtList *address;

struct elmtList {
    infotype info;
    address next;
};

struct list {
    address top;
};


void createList(list &L);
address createElmtList(infotype data);
void push(list &L, address P);
void pop(list &L);
bool isEmpty(const list &L);
bool isFull(const list &L); 

void createList(list &L) {
    L.top = nil;
}

address createElmtList(infotype data) {
    address P = new elmtList;
    P->info = data;
    P->next = nil;
    return P;
}

void push(list &L, address P) {
    P->next = L.top;
    L.top = P;
}

void pop(list &L) {
    if (!isEmpty(L)) {
        address P = L.top;
        L.top = L.top->next;
        delete P;
    }
}

bool isEmpty(const list &L) {
    return L.top == nil;
}

int main() {
    cout << "Haloo";
    return 0;
}