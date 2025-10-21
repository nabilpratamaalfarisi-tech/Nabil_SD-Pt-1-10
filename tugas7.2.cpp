#include <iostream>
#include <string>
using namespace std;

// Struktur data record
struct Karyawan {
    string id;
    string nama;
    string jabatan;
    double gaji;
};

int main() {
    const int MAKS = 100;
    Karyawan data[MAKS];
    int jumlahData = 0;

    // ====== Tahap 1: INSERT RECORD ======
    cout << "=== INSERT RECORD ===" << endl;
    cout << "Masukkan ID Karyawan   : ";
    getline(cin, data[jumlahData].id);
    cout << "Masukkan Nama Karyawan : ";
    getline(cin, data[jumlahData].nama);
    cout << "Masukkan Jabatan       : ";
    getline(cin, data[jumlahData].jabatan);
    cout << "Masukkan Gaji          : ";
    cin >> data[jumlahData].gaji;
    cin.ignore();

    jumlahData++;
    cout << "Record berhasil ditambahkan!\n" << endl;

    // Tampilkan data setelah insert
    cout << "=== DATA SETELAH INSERT ===" << endl;
    for (int i = 0; i < jumlahData; i++) {
        cout << i + 1 << ". ID: " << data[i].id
             << " | Nama: " << data[i].nama
             << " | Jabatan: " << data[i].jabatan
             << " | Gaji: " << data[i].gaji << endl;
    }

    // ====== Tahap 2: DELETE RECORD ======
    cout << "\n=== DELETE RECORD ===" << endl;
    string idHapus;
    cout << "Masukkan ID Karyawan yang ingin dihapus: ";
    getline(cin, idHapus);

    int posisi = -1;
    for (int i = 0; i < jumlahData; i++) {
        if (data[i].id == idHapus) {
            posisi = i;
            break;
        }
    }

    if (posisi == -1) {
        cout << "Record dengan ID " << idHapus << " tidak ditemukan.\n";
    } else {
        for (int i = posisi; i < jumlahData - 1; i++) {
            data[i] = data[i + 1];
        }
        jumlahData--;
        cout << "Record berhasil dihapus!\n";
    }

    // Tampilkan data setelah delete
    cout << "\n=== DATA SETELAH DELETE ===" << endl;
    if (jumlahData == 0) {
        cout << "Tidak ada data tersisa." << endl;
    } else {
        for (int i = 0; i < jumlahData; i++) {
            cout << i + 1 << ". ID: " << data[i].id
                 << " | Nama: " << data[i].nama
                 << " | Jabatan: " << data[i].jabatan
                 << " | Gaji: " << data[i].gaji << endl;
        }
    }

    return 0;
}

