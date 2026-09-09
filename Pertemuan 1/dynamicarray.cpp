/* Dynamic array = bisa dibesarkan atau kecilkan ga kaya array biasa */
#include <iostream>
using namespace std;

int main(){
    int n;

    cout << "Masukkan jumlah elemen array : ";
    cin >> n;
    //mengalokasikan memori agar bisa memasukkan data secara dinamis
    int* arr = new int[n]; //dynamic array

    cout << "Masukkan " << n << " angka : \n";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Isi array : ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    delete[] arr; //fungsi new hrus ada delete[] agar memori hrs di bersihkan biar program ga trs berjalan
    return 0;

}