#include <iostream>
using namespace std;

#define MAX 6 //array sbnyk 6
int queue[MAX]; //sm dgn int queue[6];
int front = -1, rear = -1; //awalnya kosong

// TODO : Enqueue
void enqueue( int value ) {
    if (rear == MAX - 1){//klau full
        cout << "Queue sudah penuh !\n";
    } else {
        if (front == -1) front = 0; //misal udh ada isinya, trs kt nambah data maka data yg udh ada td jd indeks 0
        rear++; //rear bertambah jd indeks selanjutnya
        queue[rear] = value; //mmisal masukin data dgn value 1, maka queue[0] = 1;
        cout << value << " Masuk ke dalam queue\n";
        //front tetap 0
    }
}

// TODO : Dequeue
void dequeue() {
    if (front == -1 || front > rear){//klau ksong atau 0 > -1
        cout << "Queue kosong\n";
    } else {
        cout << queue[front] << " keluar dari queue\n";
        front++; //pindah ke index selanjutnya
    }
}

// TODO : Nampilin isi queue
void display() {
    if (front == -1 || front > rear){
        cout << "Queue kosong !\n";
    } else {
        cout << "Isi dari queue : ";
        for (int i = front; i <= rear; i++){
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main () {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    display();

    enqueue(6);
    display();

    dequeue();
    display();

    return 0;
}