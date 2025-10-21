#include <iostream>
#include <conio.h>
using namespace std;

#define MAX 5  // kapasitas stack

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

// a. Mengisi Stack1 (PUSH1)
void PUSH1(int data) {
    if (top1 == MAX - 1) {
        cout << "Stack1 penuh!" << endl;
    } else {
        top1++;
        stack1[top1] = data;
        cout << "Data " << data << " berhasil dimasukkan ke Stack1." << endl;
    }
}

// b. Menghapus isi Stack1 (POP1)
void POP1() {
    if (top1 == -1) {
        cout << "Stack1 kosong!" << endl;
    } else {
        cout << "Data " << stack1[top1] << " dihapus dari Stack1." << endl;
        top1--;
    }
}

// c. Mengisi Stack2 (PUSH2)
void PUSH2(int data) {
    if (top2 == MAX - 1) {
        cout << "Stack2 penuh!" << endl;
    } else {
        top2++;
        stack2[top2] = data;
        cout << "Data " << data << " berhasil dimasukkan ke Stack2." << endl;
    }
}

// d. Menghapus isi Stack2 (POP2)
void POP2() {
    if (top2 == -1) {
        cout << "Stack2 kosong!" << endl;
    } else {
        cout << "Data " << stack2[top2] << " dihapus dari Stack2." << endl;
        top2--;
    }
}

// Tampilkan isi kedua stack
void tampilStack() {
    cout << "\nIsi Stack1: ";
    if (top1 == -1)
        cout << "Kosong";
    else
        for (int i = 0; i <= top1; i++)
            cout << stack1[i] << " ";

    cout << "\nIsi Stack2: ";
    if (top2 == -1)
        cout << "Kosong";
    else
        for (int i = 0; i <= top2; i++)
            cout << stack2[i] << " ";

    cout << endl;
}

// Program utama
int main() {
    int pilihan, data;
    do {
        cout << "\n=== PROGRAM STACK 1 & STACK 2 ===" << endl;
        cout << "1. PUSH Stack1" << endl;
        cout << "2. POP Stack1" << endl;
        cout << "3. PUSH Stack2" << endl;
        cout << "4. POP Stack2" << endl;
        cout << "5. Tampilkan isi Stack" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data untuk Stack1: ";
                cin >> data;
                PUSH1(data);
                break;
            case 2:
                POP1();
                break;
            case 3:
                cout << "Masukkan data untuk Stack2: ";
                cin >> data;
                PUSH2(data);
                break;
            case 4:
                POP2();
                break;
            case 5:
                tampilStack();
                break;
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }

        cout << endl;
        system("pause");
        system("cls");
    } while (pilihan != 0);

    return 0;
}
n
