#include <iostream>
using namespace std;

#define MAX 10
int arr[MAX];
int top1 = -1;     // Stack1 dari kiri
int top2 = MAX;    // Stack2 dari kanan

// PUSH Stack1
void PUSH1(int data) {
    if (top1 + 1 == top2) {
        cout << "Stack penuh! Tidak bisa tambah ke Stack1.\n";
    } else {
        top1++;
        arr[top1] = data;
        cout << "Data " << data << " dimasukkan ke Stack1.\n";
    }
}

// PUSH Stack2
void PUSH2(int data) {
    if (top1 + 1 == top2) {
        cout << "Stack penuh! Tidak bisa tambah ke Stack2.\n";
    } else {
        top2--;
        arr[top2] = data;
        cout << "Data " << data << " dimasukkan ke Stack2.\n";
    }
}

// POP Stack1
void POP1() {
    if (top1 == -1) {
        cout << "Stack1 kosong!\n";
    } else {
        cout << "Data " << arr[top1] << " dihapus dari Stack1.\n";
        top1--;
    }
}

// POP Stack2
void POP2() {
    if (top2 == MAX) {
        cout << "Stack2 kosong!\n";
    } else {
        cout << "Data " << arr[top2] << " dihapus dari Stack2.\n";
        top2++;
    }
}

// Mengecek kondisi
void cekKondisi() {
    if (top1 + 1 == top2) {
        cout << "\nKondisi (a): STACK PENUH - Baik Stack1 maupun Stack2 tak bisa diisi lagi.\n";
    } else if (top1 == -1 && top2 == MAX) {
        cout << "\nKondisi (c): STACK KOSONG - Baik Stack1 maupun Stack2 tak ada isinya.\n";
    } else {
        cout << "\nKondisi (b): STACK MASIH BISA DIISI - Masih ada ruang di antara Stack1 & Stack2.\n";
    }
}

int main() {
    cout << "=== PROGRAM DOUBLE STACK ===\n";

    // -------------------
    // (a) Kondisi PENUH
    // -------------------
    cout << "\n>>> (a) Kondisi PENUH <<<\n";
    top1 = -1;
    top2 = MAX;
    // Isi semua agar penuh
    PUSH1(1);
    PUSH1(2);
    PUSH1(3);
    PUSH1(4);
    PUSH1(5);
    PUSH2(10);
    PUSH2(20);
    PUSH2(30);
    PUSH2(40);
    PUSH2(50);
    cekKondisi();

    // -------------------
    // (b) Kondisi MASIH BISA DIISI
    // -------------------
    cout << "\n>>> (b) Kondisi MASIH BISA DIISI <<<\n";
    // Hapus sebagian isi agar masih bisa diisi
    POP1();
    POP2();
    cekKondisi();

    // -------------------
    // (c) Kondisi KOSONG
    // -------------------
    cout << "\n>>> (c) Kondisi KOSONG <<<\n";
    // Hapus semua data dari kedua stack
    while (top1 != -1) POP1();
    while (top2 != MAX) POP2();
    cekKondisi();

    cout << "\n=== PROGRAM SELESAI ===\n";
    return 0;
}

