#include <iostream>
using namespace std;

// Deklarasi sebuah struktur node
struct Node { //mmebuat sebuah node
    //knp pake struct, biar mewakili smua data
    int value;
    Node *next;
};

//knp null, krn belum ada linkedlist, blm ada apaapa
Node *head = NULL; 
Node *tail = NULL; 

// TODO : Insert di Depan
void insertFirst(int n) {
    //MEMINTA program untuk membuat node baru
    // yg terdiri atas value dan *next
    Node *newNode = new Node;
    newNode -> value = n;
    newNode -> next = NULL; //ibaratnya msh 1 node aja mknya NULL blm ada alamat dr node lain

    
    if (head == NULL){//KLO HEAD = null itu brarti blum ada
        //brarti dia head skaligus tail krn msih 1 node
        head = newNode;
        tail = head;
    } else {
        newNode-> next = head;//jd klo head ga null maka head nya pindah ke node pertama
        head = newNode;
    }
}

// TODO : Insert di belakang
void insertLast(int n) {
    //buat node
    Node *newNode = new Node;
    newNode -> value = n;
    newNode -> next = NULL; //blm punya alamat

    if (head == NULL){//klo blm ada apa apa
        head = newNode; //dia jd head
        tail = head; //skligus tail
    } else {
        tail -> next = newNode; //tail yg tadi nunjuk ke newNode, otomatis dia gabole jd tail lg
                                //dia pindah ke paling blkg
        tail = newNode;
    }
}

// TODO : Insert setelah nilai tertentu
void insertAfter(int n, int check) {
    if (head == NULL){//KLO kosong, jd  setelah apa di tmbh
        cout << "List kosong, insert di depan dulu \n";
        return;
    }

    Node *newNode = new Node;
    newNode -> value = n;
    newNode -> next = NULL;

    Node *p = head; //si p punya tugas untuk mencari node smpe dpt si 20 (yg mau di insertafter)
    while(p != NULL && p -> value != check){ //check itu nilai yg mau di insertafter
        p = p -> next;
    }  
    
    if (p == NULL) {//P  UDH JUMPA / TDK SM SEKALI JUMPA
        cout << "Node dengan nilai " << check << " tidak ada\n";
        delete newNode; //maka hapus la node yg baru buat td, krn tempatnya gaada
    } else { //KALAU JUMPA
        newNode -> next = p -> next;
        p -> next = newNode; //NEWNODE BERISI P YG DITUNJUK
        if (p == tail){
            tail == newNode;
        }
    }
}
// Cetak linked list
void printList() {
    Node *temp = head;
    cout << "Isi dari linked list : ";
    while(temp != NULL) {
        cout << temp -> value << " -> ";
        temp = temp -> next;
    }
    cout << "NULL\n";
}

int main () {
    insertFirst(10);
    insertLast(20);
    insertLast(30);
    insertAfter(25, 20); //menambah 25 setelah 20
    insertFirst(5);

    printList();
    return 0;
}