#include <iostream>
using namespace std;

struct Pribadi {
    char nama[50];
    int usia;
    float gaji;
};

// Fungsi deklarasi
Pribadi getData(Pribadi p);
void displayData(Pribadi p);

int main() {
    Pribadi p;
    p = getData(p);
    displayData(p);
    return 0;
}

// Fungsi untuk input data
Pribadi getData(Pribadi p) {
    cout << "Masukkan Nama Lengkap: ";
    cin.get(p.nama, 50);
    cin.ignore(); // untuk menangani newline setelah input nama
    cout << "Masukkan Usia: ";
    cin >> p.usia;
    cout << "Masukkan Gaji: ";
    cin >> p.gaji;
    return p;
}

// Fungsi untuk menampilkan data
void displayData(Pribadi p) {
    cout << "\nMenampilkan Informasi:" << endl;
    cout << "Nama: " << p.nama << endl;
    cout << "Usia: " << p.usia << endl;
    cout << "Gaji: " << p.gaji << endl;
}

