#include <iostream>
using namespace std;

#define MAX 5
int stack1[MAX];
int stack2[MAX];
int top1 = -1;
int top2 = -1;

// PUSH Stack1
void PUSH1(int data) {
    if (top1 == MAX - 1)
        cout << "Stack1 penuh!\n";
    else {
        top1++;
        stack1[top1] = data;
    }
}

// POP Stack1
int POP1() {
    if (top1 == -1) {
        cout << "Stack1 kosong!\n";
        return -1;
    } else {
        int data = stack1[top1];
        top1--;
        return data;
    }
}

// PUSH Stack2
void PUSH2(int data) {
    if (top2 == MAX - 1)
        cout << "Stack2 penuh!\n";
    else {
        top2++;
        stack2[top2] = data;
    }
}

// POP Stack2
int POP2() {
    if (top2 == -1) {
        cout << "Stack2 kosong!\n";
        return -1;
    } else {
        int data = stack2[top2];
        top2--;
        return data;
    }
}

// Menampilkan isi Stack1 sambil mengosongkannya
void cetakDanKosongkanStack1() {
    cout << "\nIsi Stack1 diambil satu per satu:\n";
    while (top1 != -1) {
        int data = POP1();
        cout << "Ambil data dari Stack1: " << data << endl;
    }
    cout << "Stack1 sekarang kosong.\n";
}

// Menampilkan isi Stack2 sambil mengosongkannya
void cetakDanKosongkanStack2() {
    cout << "\nIsi Stack2 diambil satu per satu:\n";
    while (top2 != -1) {
        int data = POP2();
        cout << "Ambil data dari Stack2: " << data << endl;
    }
    cout << "Stack2 sekarang kosong.\n";
}

int main() {
    cout << "=== PROGRAM PENGAMBILAN ISI STACK ===\n";

    // Isi Stack1
    PUSH1(10);
    PUSH1(20);
    PUSH1(30);
    PUSH1(40);
    PUSH1(50);

    // Isi Stack2
    PUSH2(100);
    PUSH2(200);
    PUSH2(300);
    PUSH2(400);
    PUSH2(500);

    // Ambil dan cetak isi Stack1
    cetakDanKosongkanStack1();

    // Ambil dan cetak isi Stack2
    cetakDanKosongkanStack2();

    cout << "\n=== Program selesai ===\n";
    return 0;
}

