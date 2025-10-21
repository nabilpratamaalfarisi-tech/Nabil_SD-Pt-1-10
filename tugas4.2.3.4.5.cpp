#include <iostream>
using namespace std;

const int MAX = 10;
int S[MAX];   // array untuk stack
int top = -1; // penunjuk stack

// ===== FUNGSI =====
bool isEmpty() { return top == -1; }
bool isFull()  { return top == MAX - 1; }

void push(int data) {
    if (!isFull()) {
        S[++top] = data;
        cout << "PUSH: " << data << " masuk ke stack." << endl;
    } else {
        cout << "Stack Penuh!" << endl;
    }
}

void pop() {
    if (!isEmpty()) {
        cout << "POP: " << S[top--] << " dikeluarkan dari stack." << endl;
    } else {
        cout << "Stack Kosong!" << endl;
    }
}

void tampilkanStack() {
    if (isEmpty()) {
        cout << "Stack kosong.\n";
    } else {
        cout << "Isi stack: ";
        for (int i = 0; i <= top; i++) {
            cout << S[i] << " ";
        }
        cout << endl;
    }
}

void kondisiStack() {
    cout << "\n=== Kondisi Single Stack ===" << endl;
    cout << "a. Kosong    : top == -1" << endl;
    cout << "b. Penuh     : top == MAX-1" << endl;
    cout << "c. Bisa diisi: top < MAX-1" << endl;
    cout << "d. Ada isinya: top >= 0" << endl;
}

// ===== PROGRAM UTAMA =====
int main() {
    int pilihan, data;

    do {
        cout << "\n===== MENU STACK =====" << endl;
        cout << "1. PUSH data (sampai penuh / input manual)" << endl;
        cout << "2. POP data (satu per satu)" << endl;
        cout << "3. Isi stack penuh (otomatis dari input)" << endl;
        cout << "4. Keluarkan semua isi stack (POP sampai kosong)" << endl;
        cout << "5. Tampilkan kondisi stack (teori)" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data (999 untuk berhenti): ";
                cin >> data;
                while (data != 999 && !isFull()) {
                    push(data);
                    cout << "Masukkan data (999 untuk berhenti): ";
                    cin >> data;
                }
                if (isFull()) cout << "Stack sudah penuh.\n";
                break;

            case 2:
                pop();
                break;

            case 3:
                cout << "Masukkan data untuk mengisi stack penuh:\n";
                for (int i = top + 1; i < MAX; i++) {
                    cout << "Data ke-" << i + 1 << ": ";
                    cin >> data;
                    push(data);
                }
                cout << "Stack sudah penuh!\n";
                break;

            case 4:
                cout << "Mengeluarkan semua isi stack:\n";
                while (!isEmpty()) {
                    pop();
                }
                cout << "Stack kosong!\n";
                break;

            case 5:
                kondisiStack();
                break;

            case 0:
                cout << "Keluar program.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

        tampilkanStack();
    } while (pilihan != 0);

    return 0;
}

