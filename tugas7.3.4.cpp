#include <iostream>
#include <string>
#include <sstream>  // untuk konversi string ke double
using namespace std;

struct Karyawan {
    string id;
    string nama;
    string jabatan;
    double gaji;
};

int main() {
    const int MAKS = 10; // kapasitas maksimal antrian
    Karyawan antrian[MAKS];
    int front = 0, rear = -1, jumlah = 0;

    // ==========================
    // TUGAS 3: PENGISIAN ANTRIAN
    // ==========================
    cout << "=== TUGAS 3: PENGISIAN ANTRIAN RECORD ===" << endl;

    for (int i = 0; i < 10; i++) {
        if (jumlah == MAKS) {
            cout << "\nAntrian sudah penuh! Pengisian dihentikan walau belum 10 record." << endl;
            break;
        }

        rear = (rear + 1) % MAKS;
        cout << "\nMasukkan data record ke-" << (i + 1) << endl;
        cout << "ID Karyawan   : ";
        getline(cin, antrian[rear].id);
        cout << "Nama Karyawan : ";
        getline(cin, antrian[rear].nama);
        cout << "Jabatan       : ";
        getline(cin, antrian[rear].jabatan);

        string inputGaji;
        cout << "Gaji          : ";
        getline(cin, inputGaji);
        stringstream(inputGaji) >> antrian[rear].gaji; // ubah string ke double

        jumlah++;
        cout << "Record berhasil dimasukkan ke antrian!" << endl;
    }

    // Tampilkan isi antrian setelah pengisian
    cout << "\n=== ISI ANTRIAN SETELAH PENGISIAN ===" << endl;
    if (jumlah == 0) {
        cout << "Antrian kosong.\n";
    } else {
        for (int i = 0; i < jumlah; i++) {
            int idx = (front + i) % MAKS;
            cout << i + 1 << ". ID: " << antrian[idx].id
                 << " | Nama: " << antrian[idx].nama
                 << " | Jabatan: " << antrian[idx].jabatan
                 << " | Gaji: " << antrian[idx].gaji << endl;
        }
    }

    // ==========================
    // TUGAS 4: DELETE ANTRIAN
    // ==========================
    cout << "\n=== TUGAS 4: MENGHAPUS ISI ANTRIAN ===" << endl;

    for (int i = 0; i < 10; i++) {
        if (jumlah == 0) {
            cout << "\nAntrian sudah kosong! Penghapusan dihentikan walau belum 10 record." << endl;
            break;
        }

        cout << "\nMenghapus record ke-" << (i + 1) << " dengan ID: "
             << antrian[front].id << " (" << antrian[front].nama << ")" << endl;

        front = (front + 1) % MAKS;
        jumlah--;

        cout << "Record berhasil dihapus dari antrian." << endl;
    }

    // Tampilkan isi antrian setelah proses delete
    cout << "\n=== ISI ANTRIAN SETELAH DELETE ===" << endl;
    if (jumlah == 0) {
        cout << "Semua record sudah terhapus. Antrian kosong.\n";
    } else {
        for (int i = 0; i < jumlah; i++) {
            int idx = (front + i) % MAKS;
            cout << i + 1 << ". ID: " << antrian[idx].id
                 << " | Nama: " << antrian[idx].nama
                 << " | Jabatan: " << antrian[idx].jabatan
                 << " | Gaji: " << antrian[idx].gaji << endl;
        }
    }

    return 0;
}

