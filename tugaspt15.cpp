#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Mahasiswa {
    string nama, gender;
    int nim;
    float nilai;
    Mahasiswa *next, *prev;
};

Mahasiswa *head = NULL;

// Animasi loading sederhana
void loading() {
    for (int i = 0; i < 3; i++) {
        cout << ".";
        for (volatile int j = 0; j < 80000000; j++); 
    }
    cout << endl;
}

// ===================== INSERT DATA =====================
void insertData() {
    Mahasiswa *baru = new Mahasiswa;
    cout << "\n=== INSERT DATA ===\n";
    cout << "Nama   : ";
    cin.ignore();
    getline(cin, baru->nama);
    cout << "NIM    : ";
    cin >> baru->nim;
    cout << "Gender : ";
    cin >> baru->gender;
    cout << "Nilai  : ";
    cin >> baru->nilai;

    baru->next = baru->prev = NULL;

    // Jika list kosong
    if (head == NULL) {
        head = baru;
        head->next = head->prev = head;
        cout << "Data berhasil ditambahkan";
        loading();
        return;
    }

    Mahasiswa *curr = head;
    Mahasiswa *before = NULL;

    // Cari posisi sesuai urutan NIM
    do {
        if (baru->nim < curr->nim) break;
        before = curr;
        curr = curr->next;
    } while (curr != head);

    // Insert sebelum head (data paling kecil)
    if (baru->nim < head->nim) {
        Mahasiswa *tail = head->prev;
        baru->next = head;
        baru->prev = tail;
        tail->next = baru;
        head->prev = baru;
        head = baru;
    }
    else {
        baru->next = curr;
        baru->prev = before;
        before->next = baru;
        curr->prev = baru;
    }

    cout << "Data berhasil ditambahkan";
    loading();
}

// ===================== HAPUS DATA =====================
void hapusData() {
    if (head == NULL) {
        cout << "\nList masih kosong!\n";
        return;
    }

    int key;
    cout << "\n=== HAPUS DATA ===\n";
    cout << "Masukkan NIM yang akan dihapus: ";
    cin >> key;

    Mahasiswa *curr = head;

    // Cari data
    do {
        if (curr->nim == key) break;
        curr = curr->next;
    } while (curr != head);

    if (curr->nim != key) {
        cout << "Data tidak ditemukan!\n";
        return;
    }

    // Jika hanya 1 data
    if (curr == head && curr->next == head) {
        delete curr;
        head = NULL;
        cout << "Data berhasil dihapus";
        loading();
        return;
    }

    // Jika hapus head
    if (curr == head) {
        Mahasiswa *tail = head->prev;
        head = head->next;
        tail->next = head;
        head->prev = tail;
    }
    else {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    delete curr;
    cout << "Data berhasil dihapus";
    loading();
}

// ===================== CETAK DATA =====================
void cetakData() {
    if (head == NULL) {
        cout << "\nList kosong!\n";
        return;
    }

    cout << "\n=== DATA MAHASISWA ===\n";
    cout << left << setw(15) << "Nama"
         << setw(12) << "NIM"
         << setw(10) << "Gender"
         << setw(10) << "Nilai" << endl;

    cout << "--------------------------------------------\n";

    Mahasiswa *curr = head;
    do {
        cout << left << setw(15) << curr->nama
             << setw(12) << curr->nim
             << setw(10) << curr->gender
             << setw(10) << curr->nilai << endl;
        curr = curr->next;
    } while (curr != head);

    cout << "--------------------------------------------\n";
}

// ===================== MAIN MENU =====================
int main() {
    int pilihan;

    do {
        cout << "\n CIRCULAR DOUBLY LINKED LIST\n";
        cout << "===============================\n";
        cout << "1. INSERT DATA\n";
        cout << "2. HAPUS DATA\n";
        cout << "3. CETAK DATA\n";
        cout << "4. EXIT\n";
        cout << "Pilihan (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: insertData(); break;
            case 2: hapusData(); break;
            case 3: cetakData(); break;
            case 4: cout << "Keluar program...\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 4);

    return 0;
}

