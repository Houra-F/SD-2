#include <iostream>
using namespace std;

int main() {
    int nilai[3][4] = {
        {80, 75, 90, 85},
        {70, 60, 88, 77},
        {95, 85, 92, 89}
    };

    for (int i = 0; i < 3; i++){
        cout << "Mahasiwa " << i + 1 << " : ";

        for (int j = 0; j < 4; j++){
            cout << nilai[i][j] << " ";
        }

        cout << endl;
    }
    return 0;
}

/* Visualisasi array 2D VS 3D
Contoh multidimensi = matriks
2 dimensi = baris dan kolom (tabel)
cth: int angka[4][6]; 

cth:  ada 3 mahasiswa yg baru dpt nilai ujian
        dapat 4 nilai
    = int mhsw[3][4]; */