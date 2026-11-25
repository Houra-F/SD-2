#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTableChaining {
private:
    int size; //nyimpan jlh slot/hash table
    vector<list<int>> table;//buat array dinamisnya

    // TODO 1: Buat hash function
    int hashFunction(int key) {
        // return rumus hashing
        return key % size;
    }

public:
    HashTableChaining(int s) {//constructor yg akan bantu buat hash table
        size = s;
        table.resize(size);
    }

    // TODO 2: Buat fungsi insert untuk menyimpan key ke hash table
    void insert(int key) {
        // 1. Hitung index pakai hashFunction
        int index = hashFunction(key);
        // 2. Tambahkan angka ke list pada index tersebut
        table[index].push_back(key);
    }

    // TODO 3: Tampilkan isi hash table
    void display() {//mencetak hash table
        for (int i = 0; i < size; i++) {//ulg dr slot 0 smpai size - 1
            cout << i << ": ";
            // tampilkan semua elemen di slot ini
            for (int val : table[i]) {//ngebaca setiap elemen yg tersimpan dlm list
                cout << val << " -> ";
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    int size, n, value;

    cout << "Masukkan ukuran hash table: ";
    cin >> size;

    HashTableChaining ht(size);

    cout << "Berapa banyak angka yang ingin dimasukkan? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Input angka ke-" << i + 1 << ": ";
        cin >> value;
        ht.insert(value);
    }

    cout << "\n=== HASH TABLE (CHAINING) ===\n";
    ht.display();

    return 0;
}