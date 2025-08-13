#include <iostream>
#define nil NULL
using namespace std;

struct piring {
    int nomor;
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
    if(L.top == nil){
        L.top = P;
        cout << "\033[32mPiring pertama berhasil ditambahkan\033[0m" << endl;
        return;
    }
    P->next = L.top;
    L.top = P;
    cout << "\033[32mPiring berhasil ditambahkan\033[0m" << endl;
}

void pop(list &L) {
    if (!isEmpty(L)) {
        address P = L.top;
        L.top = L.top->next;
        delete P;
        cout << "\033[32mPiring berhasil diambil\033[0m" << endl;
    }else{
        cout << "\033[31mTidak ada piring yang bisa digunakan\033[0m" << endl;
    }
}

bool isEmpty(const list &L) {
    return L.top == nil;
}

void printList(list &L){
    if(isEmpty(L)){
        cout << "\033[31mTidak ada piring yang bisa digunakan\033[0m" << endl;
        return;
    }
    cout << "\033[33mPiring diurutkan dari tumpukan paling atas\033[0m" << endl;
    int i = 1;
    address p = L.top;
    while(p != nil){
        cout << i << ". " << p->info.nomor << endl;
        p = p->next;
        i++;
    }
    cout << "\033[32mTotal piring yang tersedia berjumlah: \033[0m" << i-1 << endl;
}

    void printMenu() {
    cout << "===============================" << endl;
    cout << "          Piring Restorant        " << endl;
    cout << "===============================" << endl;
    cout << "1. Tambah piring bersih" << endl;
    cout << "2. Ambil piring" << endl;
    cout << "3. Lihat semua piring" << endl;
    cout << "0. Keluar" << endl;
    cout << "===============================" << endl;
    cout << "\033[33mPilih menu: \033[0m"; 
}


int main() {
    list L;
    int input, nomor;
    createList(L);
    do{
        printMenu();
        cin >> input;
        switch(input){
            case 1:{
                cout << "Masukan nomor piring: ";
                cin >> nomor;
                infotype piring = {nomor};
                address P = createElmtList(piring);
                push(L, P);
                break;
            }
            case 2:{
                pop(L);
                break;
            }
            case 3:{
                printList(L);
                break;
            }
            case 0:{
                cout << "\033[32mTerima kasih sudah menggunakan layanan kami\033[0m" << endl;
                break;
            }
            default:
                cout << "\033[31mInput tidak valid\033[0m" << endl;
        }
    }while (input != 0);
    return 0;
}