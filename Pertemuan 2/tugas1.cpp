#include <iostream>
using namespace std;

struct Node {
    int value;      
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void insertFirst(int n) {
    Node *newNode = new Node;
    newNode -> value = n;
    newNode -> next = NULL;

    if (head == NULL){          
        head = newNode;
        tail = head;            
    } else {
        newNode -> next = head; 
        head = newNode;         
    }
}

void insertLast(int n) {
    Node *newNode = new Node;
    newNode -> value = n;
    newNode -> next = NULL;

    if (head == NULL){
        head = newNode;
        tail = head;
    } else {
        tail -> next = newNode; 
        tail = newNode;         
    }
}

void insertAfter(int n, int check) {
    if (head == NULL){
        cout << "List kosong, insert di depan dulu\n";
        return;
    }

    Node *newNode = new Node;
    newNode -> value = n;
    newNode -> next = NULL;

    Node *p = head;             
    while(p != NULL && p -> value != check){
        p = p -> next;
    }

    if (p == NULL) {            
        cout << "Node dengan nilai " << check << " tidak ada\n";
        delete newNode;         
    } else {
        newNode -> next = p -> next;
        p -> next = newNode;
        if (p == tail){         
            tail = newNode;
        }
    }
}

void deleteMiddle(int value) {
    if (head == NULL){
        cout << " Listnya kosong\n";
        return;
    }

    if (head -> value == value){
        Node *temp = head;      
        head = head -> next;    
        if (head == NULL) tail = NULL; 
        delete temp;
        return;
    }
 
    Node *p = head; 
    while (p->next != NULL && p->next->value != value){
        p = p -> next;
    }

    if (p->next == NULL){
        cout << "Node dengan nilai " << value << " tidak ada\n";
    } else {
        Node *temp = p->next; 
        p->next = temp->next; 
        if (temp == tail) tail = p; 
        delete temp;
    }
}

void printList() {
    Node *temp = head;
    cout << "Isi Linked List: ";
    while(temp != NULL) {
        cout << temp -> value << " -> ";
        temp = temp -> next;
    }
    cout << "NULL\n";
}

int main () {
    int pilihan, nilai, check;

    do {
        cout << "\n===== MENU SINGLE LINKED LIST =====\n";
        cout << "1. Tambah di awal\n";
        cout << "2. Tambah di akhir\n";
        cout << "3. Tambah setelah nilai tertentu\n";
        cout << "4. Hapus berdasarkan nilai\n";
        cout << "5. Tampilkan Linked List\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1){
            cout << "Masukkan nilai: ";
            cin >> nilai;
            insertFirst(nilai);
            printList();
        } else if (pilihan == 2){
            cout << "Masukkan nilai: ";
            cin >> nilai;
            insertLast(nilai);
            printList();
        } else if (pilihan == 3){
            cout << "Masukkan nilai baru: ";
            cin >> nilai;
            cout << "Masukkan nilai yang ingin dicari: ";
            cin >> check;
            insertAfter(nilai, check);
            printList();
        } else if (pilihan == 4){
            cout << "Masukkan nilai yang ingin dihapus: ";
            cin >> nilai;
            deleteMiddle(nilai);
            printList();
        } else if (pilihan == 5){
            printList();
        } else if (pilihan == 0){
            cout << "Program selesai\n";
        } else {
            cout << "Pilihan tidak ada\n";
        }

    } while (pilihan != 0);

    return 0;
}