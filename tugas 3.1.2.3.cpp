#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    int no;
    string nama;
    int umur;
    string alamat;
    float nilai;
};

int main() {
    Mahasiswa m1;          // untuk tugas 1
    Mahasiswa m5[5];       // untuk tugas 2
    Mahasiswa m15[15];     // untuk tugas 3
    int pilihan;

    do {
        cout << "\n=== MENU DATA MAHASISWA ===\n";
        cout << "1. Input & Cetak 1 Mahasiswa\n";
        cout << "2. Input 5 Mahasiswa, Cetak No Urut 2\n";
        cout << "3. Input 15 Mahasiswa & Cetak Semua\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            // Tugas 1
            cout << "\nMasukkan No urut: ";
            cin >> m1.no;
            cin.ignore();
            cout << "Masukkan Nama: ";
            getline(cin, m1.nama);
            cout << "Masukkan Umur: ";
            cin >> m1.umur;
            cout << "Masukkan Nilai: ";
            cin >> m1.nilai;

            cout << "\n=== Data Mahasiswa ===\n";
            cout << "No    : " << m1.no << endl;
            cout << "Nama  : " << m1.nama << endl;
            cout << "Umur  : " << m1.umur << endl;
            cout << "Nilai : " << m1.nilai << endl;
        }
        else if (pilihan == 2) {
            // Tugas 2
            for (int i = 0; i < 5; i++) {
                m5[i].no = i + 1;
                cout << "\nMahasiswa ke-" << m5[i].no << endl;
                cout << "Masukkan Nama: ";
                getline(cin, m5[i].nama);
                cout << "Masukkan Umur: ";
                cin >> m5[i].umur;
                cin.ignore();
            }

            cout << "\n=== Detail Mahasiswa No Urut 2 ===\n";
            cout << "No   : " << m5[1].no << endl;
            cout << "Nama : " << m5[1].nama << endl;
            cout << "Umur : " << m5[1].umur << endl;
        }
        else if (pilihan == 3) {
            // Tugas 3
            for (int i = 0; i < 15; i++) {
                m15[i].no = i + 1;
                cout << "\nMahasiswa ke-" << m15[i].no << endl;
                cout << "Masukkan Nama   : ";
                getline(cin, m15[i].nama);
                cout << "Masukkan Umur   : ";
                cin >> m15[i].umur;
                cin.ignore();
                cout << "Masukkan Alamat : ";
                getline(cin, m15[i].alamat);
                cout << "Masukkan Nilai  : ";
                cin >> m15[i].nilai;
                cin.ignore();
            }

            cout << "\n=== Data 15 Mahasiswa ===\n";
            for (int i = 0; i < 15; i++) {
                cout << m15[i].no << " | " << m15[i].nama 
                     << " | " << m15[i].umur 
                     << " | " << m15[i].alamat 
                     << " | " << m15[i].nilai << endl;
            }
        }
    } while (pilihan != 0);

    return 0;
}

