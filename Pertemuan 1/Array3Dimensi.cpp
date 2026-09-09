/* 3 dimensi = tumpukan tabel, jadi baris dan kolomnya lebih banyak
(kaya rubik)
cth = int angka[2][3][4]
yg [2] itu adalah seberapa banyak lapis tabelnya.
*/
#include <iostream>
using namespace std;

int main(){
    //deklarasi
    int array [2][3][4];

    int angka = 1;//penanda agar dimulai dr satu, krn isi array nya mau ganjil smua angkanya

    //mengisi array dgn angka ganjil
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 4; k++){
                array[i][j][k] = angka;
                angka += 2; //agar yg muncul setelah angka 1 adalah 3, jd seterusnya jg ganjil
            }
        }
    }

    //menampilkan array
    for (int i = 0; i < 2; i++){
        cout << "Lapis " << i+1 << endl; //agar tiap lapis keluar tulisan lapis 1/2

        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 4; k++){
                cout << array[i][j][k] << "\t"; //agar bentuknya tabel
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;

}