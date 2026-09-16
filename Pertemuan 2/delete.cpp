#include <iostream>
using namespace std;

// Deklarasi Struktur Node
struct Node { //biar bs dipake di semua void
    int value;
    Node *next;
};
//Linkedlist nya blm ada
Node *head = NULL;
Node *tail = NULL;

// Fungsi Cetak List
void printList() {
    Node *temp = head;
    cout << "Isi Linked List: ";
    while (temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Fungsi tambah node di akhir (biar ada data untuk dihapus)
void insertLast(int n) {
    Node *newNode = new Node{n, NULL};
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// TODO : Hapus node pertama
void deleteFirst() {
    if (head == NULL){//linkedlist kosong, klo gaada jd apa yg diapus
        cout << " Listnya kosong\n";
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head == NULL) tail == NULL; //klo cuma ada 1 node
    delete temp;
}

// TODO : Hapus node terakhir
void deleteLast() {
    if (head == NULL){//linkedlist kosong, klo gaada jd apa yg diapus
        cout << " Listnya kosong\n";
        return;
    }

    if (head == tail){// dlm list cuma ada 1 node
        delete head; //hapus 1 node tsb
        head = tail = NULL;
        return;
    }

    Node *p = head; //*p untuk menjelajahi yg mau di hapus smpe tail
    while(p->next != tail){//untuk p agar berhenti di tail
        p = p -> next;
    }
    delete tail;
    tail = p;
    tail->next = NULL; //membuat *next dr node yg sblm di hapus itu NULL krn setelahnya udh gaada lgi
    //dan dia jdnya tail
}

// TODO : Hapus node dengan nilai tertentu
void deleteMiddle(int value) {
    if (head == NULL){//linkedlist kosong, klo gaada jd apa yg diapus
        cout << " Listnya kosong\n";
        return;
    }

    if (head -> value == value){//klo trnyata dlm linkedlist cuma ada 1 node, maka
        deleteFirst(); //panggil fungsi ini
        return;
    }

    //mau hapus node tertentu gabsa lgsg indeks
    //jd hrs buat : 
    Node *p = head; //untuk mncari node yg mau dihapus dan mengasih tanda agar yg sebelumnya tdk ikut terhapus
    while (p->next != NULL && p->next->value != value){//tempatkan si p sebelum yg mau di hapus
        p = p -> next;
    }

    if (p->next == NULL){//klo gak jumpa dan gaada
        cout << "Node dengan nilai " << value << " tidak ada\n";
    } else {//klau jumpa
        Node *temp = p->next; //nyimpan yg mau di hapus itu di temp
        p->next = temp->next; //jd *next ny udh gaboleh lg nunjuk ke yg udh di hapus, jd nunjuk ke node yg setelahnya
        if (temp == tail) tail = p;
        delete temp;
    }
    
}

int main() {
    // Contoh list awal
    insertLast(10);
    insertLast(20);
    insertLast(30);

    cout << "List awal:\n";
    printList();

    cout << "\nHapus node pertama:\n"; //si 10 di apus
    deleteFirst();
    printList();

    cout << "\nHapus node terakhir:\n"; //30 diapus
    deleteLast();
    printList();

    cout << "\nHapus node dengan nilai 20:\n";
    deleteMiddle(20); //mnghapus nilai tertentu
    printList();

    //jdnya null krn smua diapus
    return 0;
}