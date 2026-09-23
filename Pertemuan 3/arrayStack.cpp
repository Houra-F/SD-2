#include <iostream>
using namespace std;

#define MAX 5 //array dgn kapasitas max 5
int stack[MAX]; //sama aja dgn int stack[5];
int top = -1; //array masih kosong

// TODO : Operasi Push
void push (int value) {
    if(top == MAX-1){//pengkondisian klau trnyata stack sudah penuh (max = 5, dikurang 1 = 4)
        cout << "Stack penuh ! \n";
    } else {
        top++; //menambah top nya jadi 0
        stack[top] = value;//value = 50
        cout << value << " ditambahkan dalam stack\n";
    }
}

// TODO : Operasi Pop
void pop (){
    if (top == -1){//klau stack kosong
         cout << "Stack kosong ! \n";
    } else {
        cout << "\n" << stack[top] << " dihapus dari Stack\n"; //hapus data dr atas
        top--;
    }
}

// TODO : Nampilin Stack
void display() {
    if(top == -1){
        cout << "Stack kosong!\n";
    } else {
        cout << "\nIsi Stack : \n";
        for (int i = top; i >= 0; i--){//menampilkan dari index terbesar
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main (){
    push(50);
    push(40);
    push(30);
    push(20);
    push(10);

    display();
    pop();
    display;

    return 0;
}