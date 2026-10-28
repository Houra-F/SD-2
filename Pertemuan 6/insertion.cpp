#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    int data[n];
    cout << "Masukkan elemen-elemen data: \n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // TODO : Insertion Sort dari terkecil hingga terbesar
    for (int i = 1; i < n; i++){//mulai dr index 1, krn index 0 sdh pst kita buyat jd data rapi sementara
        //seperti data 23 di contoh
        int key = data[i]; //simpan di key data yg mau dibandingkan
        int j = i - 1; //ceknya hanya dgn yg sdh rapi (yg di sblh kiri)

        while (j >= 0 && data[j] > key){//proses inssert ke tmpt yg sdh rapi agar tdk nabrak dgn yg ada di dpn (yg udh rapi) dan angka yg > key
            data[j + 1] = data[j]; //suruh mundur data yg rapi yg lbh besar
            j--; //decrement krna mau cek lg data di depan apakah msh ada yg lbh besar dr si key
        }
        data[j + 1] = key; //masukkan key ke tempatnya ketika sdh dibandingkan
    }
    
    
    cout << "Data setelah diurutkan dari terkecil hingga terbesar:\n";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    
    cout << endl;
    return 0;
}