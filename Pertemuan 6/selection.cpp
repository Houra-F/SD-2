#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    int data[n];
    cout << "Masukkan elemen-elemen data: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // TODO : Selection Sort dari terbesar hingga terkecil
    for (int i = 0; i < n; i++){//ngatur kursinya
        int maxIndex = 1; //untuk menyimpan nilai max sementara
        for (int j = i + 1; j < n; j++){// cek smua sampe juma mana yg mau di tukar
            if (data[j] < data[maxIndex]){//jika data j < maxIndex
                maxIndex = j; // maka maxIndex nya adalah j
            }
        }

        //tempat sementara untuk data yg lg di tukar
        int temp = data[i];
        data[i] = data[maxIndex];
        data[maxIndex] = temp;
    }

    cout << "Data setelah diurutkan dari terbesar hingga terkecil:\n";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}