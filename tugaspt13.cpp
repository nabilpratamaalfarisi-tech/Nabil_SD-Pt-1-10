#include <iostream>
#include <string>
#include <windows.h>   // untuk Sleep()
using namespace std;

// Struktur Node untuk data mahasiswa
struct Mahasiswa {
    string NIM;
    string NAMA;
    string GENDER;
    float NILAI;
    Mahasiswa *prev;
    Mahasiswa *next;
};

Mahasiswa *head = NULL;
Mahasiswa *tail = NULL;

// Fungsi animasi teks sederhana
void animasi(string teks, int delay = 50) {
    for (char c : teks) {
        cout << c << flush;
        Sleep(delay);
    }
    cout << endl;
}

// Fungsi untuk membuat node baru
Mahasiswa* buatNode(string nim, string nama, string gender, float nilai) {
    Mahasiswa* baru = new Mahasiswa;
    baru->NIM = nim;
    baru->NAMA = nama;
    baru->GENDER = gender;
    baru->NILAI = nilai;
    baru->prev = NULL;
    baru->next = NULL;
    return baru;
}

// ===== INSERT DATA (berdasarkan NIM urut naik) =====
void insertData() {
    string nim, nama, gender;
    float nilai;
    cout << "\nMasukkan NIM     : "; cin >> nim;
    cout << "Masukkan Nama    : "; cin.ignore(); getline(cin, nama);
    cout << "Masukkan Gender  : "; getline(cin, gender);
    cout << "Masukkan Nilai   : "; cin >> nilai;

    Mahasiswa* baru = buatNode(nim, nama, gender, nilai);

    // Jika list kosong
    if (!head) {
        head = tail = baru;
    } else {
        Mahasiswa* bantu = head;
        Mahasiswa* before = NULL;

        // Cari posisi sisip berdasarkan NIM (ascending)
        while (bantu && bantu->NIM < nim) {
            before = bantu;
            bantu = bantu->next;
        }

        if (!before) { // Sisip di awal
            baru->next = head;
            head->prev = baru;
            head = baru;
        } else if (!bantu) { // Sisip di akhir
            tail->next = baru;
            baru->prev = tail;
            tail = baru;
        } else { // Sisip di tengah
            before->next = baru;
            baru->prev = before;
            baru->next = bantu;
            bantu->prev = baru;
        }
    }

    animasi("Menambahkan data ke dalam Linked List...", 40);
    Sleep(500);
    cout << "? Data berhasil ditambahkan!\n";
}

// ===== HAPUS DATA =====
void hapusData() {
    if (!head) {
        cout << "List masih kosong!\n";
        return;
    }

    string nim;
    cout << "Masukkan NIM yang ingin dihapus: ";
    cin >> nim;

    Mahasiswa* bantu = head;

    while (bantu && bantu->NIM != nim)
        bantu = bantu->next;

    if (!bantu) {
        cout << "Data dengan NIM " << nim << " tidak ditemukan!\n";
        return;
    }

    animasi("Menghapus data...", 40);

    // Hapus node
    if (bantu == head && bantu == tail) { // hanya 1 data
        head = tail = NULL;
    } else if (bantu == head) {
        head = head->next;
        head->prev = NULL;
    } else if (bantu == tail) {
        tail = tail->prev;
        tail->next = NULL;
    } else {
        bantu->prev->next = bantu->next;
        bantu->next->prev = bantu->prev;
    }

    delete bantu;
    cout << "? Data berhasil dihapus!\n";
}

// ===== CETAK DATA =====
void cetakData() {
    if (!head) {
        cout << "List kosong!\n";
        return;
    }

    animasi("Menampilkan seluruh data mahasiswa...\n", 30);
    Mahasiswa* bantu = head;
    cout << "=========================================\n";
    cout << "NIM\tNAMA\t\tGENDER\tNILAI\n";
    cout << "-----------------------------------------\n";
    while (bantu) {
        cout << bantu->NIM << "\t" << bantu->NAMA << "\t"
             << bantu->GENDER << "\t" << bantu->NILAI << endl;
        bantu = bantu->next;
        Sleep(200); // efek animasi tampil satu per satu
    }
    cout << "=========================================\n";
}

// ===== MENU UTAMA =====
void menu() {
    int pilihan;
    do {
        cout << "\nLIN. DOUBLY LINKED LIST\n";
        cout << "==========================\n";
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
            case 4: animasi("Keluar dari program...", 50); break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);
}

// ===== MAIN =====
int main() {
    menu();
    return 0;
}

