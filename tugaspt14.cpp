#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Mahasiswa {
    string NAMA;
    string NIM;
    string GENDER;
    int NILAI;
    Mahasiswa *next;
};

Mahasiswa *FIRST = NULL;
Mahasiswa *LAST = NULL;

// ---------- BUAT SIMPUL ----------
Mahasiswa* buatSimpul(string nama, string nim, string gender, int nilai) {
    Mahasiswa *baru = new Mahasiswa;
    baru->NAMA = nama;
    baru->NIM = nim;
    baru->GENDER = gender;
    baru->NILAI = nilai;
    baru->next = NULL;
    return baru;
}

// ---------- INSERT DATA (TERURUT NAIK BERDASARKAN NIM) ----------
void insertData() {
    string nama, nim, gender;
    int nilai;

    cout << "\nMasukkan NAMA   : ";
    cin >> ws;
    getline(cin, nama);
    cout << "Masukkan NIM    : ";
    cin >> nim;
    cout << "Masukkan GENDER : ";
    cin >> gender;
    cout << "Masukkan NILAI  : ";
    cin >> nilai;

    Mahasiswa *baru = buatSimpul(nama, nim, gender, nilai);

    // Jika list kosong
    if (FIRST == NULL) {
        FIRST = LAST = baru;
        baru->next = FIRST;
        cout << "\nData berhasil ditambahkan!\n";
        return;
    }

    // Jika insert di depan (NIM paling kecil)
    if (nim < FIRST->NIM) {
        baru->next = FIRST;
        FIRST = baru;
        LAST->next = FIRST;
        cout << "\nData berhasil ditambahkan!\n";
        return;
    }

    // Insert di tengah/akhir
    Mahasiswa *bantu = FIRST;
    while (bantu->next != FIRST && bantu->next->NIM < nim) {
        bantu = bantu->next;
    }

    baru->next = bantu->next;
    bantu->next = baru;

    // Jika insert di belakang
    if (bantu == LAST) {
        LAST = baru;
    }

    cout << "\nData berhasil ditambahkan!\n";
}

// ---------- HAPUS DATA BERDASARKAN NIM ----------
void hapusData() {
    if (FIRST == NULL) {
        cout << "\nList kosong!\n";
        return;
    }

    string nim;
    cout << "\nMasukkan NIM yang ingin dihapus: ";
    cin >> nim;

    Mahasiswa *hapus, *bantu = FIRST;

    // Jika data yang dihapus adalah FIRST
    if (FIRST->NIM == nim) {
        hapus = FIRST;

        // Jika hanya ada satu node
        if (FIRST == LAST) {
            FIRST = LAST = NULL;
        } else {
            FIRST = FIRST->next;
            LAST->next = FIRST;
        }

        delete hapus;
        cout << "\nData berhasil dihapus!\n";
        return;
    }

    // Cari node sebelum yang akan dihapus
    while (bantu->next != FIRST && bantu->next->NIM != nim) {
        bantu = bantu->next;
    }

    // Jika tidak ditemukan
    if (bantu->next == FIRST) {
        cout << "\nData tidak ditemukan!\n";
        return;
    }

    // Hapus node
    hapus = bantu->next;
    bantu->next = hapus->next;

    // Jika yang dihapus adalah LAST
    if (hapus == LAST) {
        LAST = bantu;
    }

    delete hapus;
    cout << "\nData berhasil dihapus!\n";
}

// ---------- CETAK DATA ----------
void cetakData() {
    if (FIRST == NULL) {
        cout << "\nList kosong!\n";
        return;
    }

    cout << "\n=== DATA MAHASISWA (Circular Linked List) ===\n";
    Mahasiswa *bantu = FIRST;

    do {
        cout << "NAMA   : " << bantu->NAMA << endl;
        cout << "NIM    : " << bantu->NIM << endl;
        cout << "GENDER : " << bantu->GENDER << endl;
        cout << "NILAI  : " << bantu->NILAI << endl;
        cout << "-------------------------------------\n";
        bantu = bantu->next;
    } while (bantu != FIRST);
}

// ---------- MENU UTAMA ----------
int main() {
    int pilihan;

    do {
        cout << "\n\n  CIRCULAR LINKED LIST";
        cout << "\n  ==========================";
        cout << "\n  1. INSERT DATA";
        cout << "\n  2. HAPUS DATA";
        cout << "\n  3. CETAK DATA";
        cout << "\n  4. EXIT";
        cout << "\n  Pilihan (1-4) : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: insertData(); break;
            case 2: hapusData(); break;
            case 3: cetakData(); break;
            case 4: cout << "\nKeluar program...\n"; break;
            default: cout << "\nPilihan tidak valid!\n";
        }

    } while (pilihan != 4);

    return 0;
}

