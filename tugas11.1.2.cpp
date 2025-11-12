#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// Struktur data mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    string gender;
    float nilai;
    Mahasiswa* next;
};

// Pointer head (digunakan untuk mode dengan head)
Mahasiswa* head = NULL;

// Pointer top (untuk mode tanpa head)
Mahasiswa* top = NULL;

// ======== MODE 1: Stack dengan HEAD ========
void pushWithHead() {
    Mahasiswa* newNode = new Mahasiswa;
    cout << "\n=== INPUT DATA MAHASISWA (Linked List dengan Head) ===" << endl;
    cout << "Nama                : "; cin.ignore(); getline(cin, newNode->nama);
    cout << "NIM                 : "; getline(cin, newNode->nim);
    cout << "Gender (L/P)        : "; getline(cin, newNode->gender);
    cout << "Nilai Struktur Data : "; cin >> newNode->nilai;

    newNode->next = head;
    head = newNode;

    cout << "Data berhasil dimasukkan ke Stack!\n";
}

void popWithHead() {
    if (head == NULL) {
        cout << "Stack kosong, tidak ada data untuk dihapus.\n";
        return;
    }
    Mahasiswa* temp = head;
    head = head->next;
    cout << "Data dengan nama '" << temp->nama << "' telah dihapus dari Stack.\n";
    delete temp;
}

void printWithHead() {
    if (head == NULL) {
        cout << "Stack kosong.\n";
        return;
    }
    cout << "\n=== ISI STACK (Dengan Head) ===\n";
    Mahasiswa* temp = head;
    while (temp != NULL) {
        cout << "Nama   : " << temp->nama << endl;
        cout << "NIM    : " << temp->nim << endl;
        cout << "Gender : " << temp->gender << endl;
        cout << "Nilai  : " << temp->nilai << endl;
        cout << "-------------------------------\n";
        temp = temp->next;
    }
}

// ======== MODE 2: Stack tanpa HEAD ========
void pushNoHead() {
    Mahasiswa* newNode = new Mahasiswa;
    cout << "\n=== INPUT DATA MAHASISWA (Linked List tanpa Head) ===" << endl;
    cout << "Nama                : "; cin.ignore(); getline(cin, newNode->nama);
    cout << "NIM                 : "; getline(cin, newNode->nim);
    cout << "Gender (L/P)        : "; getline(cin, newNode->gender);
    cout << "Nilai Struktur Data : "; cin >> newNode->nilai;

    newNode->next = top;
    top = newNode;

    cout << "Data berhasil dimasukkan ke Stack!\n";
}

void popNoHead() {
    if (top == NULL) {
        cout << "Stack kosong, tidak ada data untuk dihapus.\n";
        return;
    }
    Mahasiswa* temp = top;
    top = top->next;
    cout << "Data dengan nama '" << temp->nama << "' telah dihapus dari Stack.\n";
    delete temp;
}

void printNoHead() {
    if (top == NULL) {
        cout << "Stack kosong.\n";
        return;
    }
    cout << "\n=== ISI STACK (Tanpa Head) ===\n";
    Mahasiswa* temp = top;
    while (temp != NULL) {
        cout << "Nama   : " << temp->nama << endl;
        cout << "NIM    : " << temp->nim << endl;
        cout << "Gender : " << temp->gender << endl;
        cout << "Nilai  : " << temp->nilai << endl;
        cout << "-------------------------------\n";
        temp = temp->next;
    }
}

// ======== MENU UTAMA ========
int main() {
    int mode;
    do {
        cout << "\n=== PROGRAM ANIMASI STACK LINKED LIST ===" << endl;
        cout << "1. Stack dengan Head" << endl;
        cout << "2. Stack tanpa Head" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih mode: ";
        cin >> mode;

        if (mode == 1) {
            int pilihan;
            do {
                cout << "\n--- MENU STACK DENGAN HEAD ---" << endl;
                cout << "1. INSERT DATA" << endl;
                cout << "2. HAPUS DATA" << endl;
                cout << "3. CETAK DATA" << endl;
                cout << "4. KEMBALI KE MENU UTAMA" << endl;
                cout << "Pilih: ";
                cin >> pilihan;

                switch (pilihan) {
                    case 1: pushWithHead(); break;
                    case 2: popWithHead(); break;
                    case 3: printWithHead(); break;
                }
            } while (pilihan != 4);
        }

        else if (mode == 2) {
            int pilihan;
            do {
                cout << "\n--- MENU STACK TANPA HEAD ---" << endl;
                cout << "1. INSERT DATA" << endl;
                cout << "2. HAPUS DATA" << endl;
                cout << "3. CETAK DATA" << endl;
                cout << "4. KEMBALI KE MENU UTAMA" << endl;
                cout << "Pilih: ";
                cin >> pilihan;

                switch (pilihan) {
                    case 1: pushNoHead(); break;
                    case 2: popNoHead(); break;
                    case 3: printNoHead(); break;
                }
            } while (pilihan != 4);
        }

    } while (mode != 3);

    cout << "\nProgram selesai.\n";
    return 0;
}

