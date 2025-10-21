#include <iostream>
using namespace std;

#define MAX 5

int stack1[MAX];
int stack2[MAX];
int top1 = -1;
int top2 = -1;

// a. Mengisi Stack1 (PUSH1)
void PUSH1(int data) {
    if (top1 == MAX - 1) {
        cout << "Stack1 penuh!" << endl;
    } else {
        top1++;
        stack1[top1] = data;
        cout << "Data " << data << " dimasukkan ke Stack1." << endl;
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
        cout << "Data " << data << " dimasukkan ke Stack2." << endl;
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

int main() {
    cout << "=== PROGRAM STACK1 & STACK2 ===" << endl;

    cout << "\n[a] PUSH Stack1:" << endl;
    PUSH1(10);
    PUSH1(20);
    PUSH1(30);

    cout << "\n[b] POP Stack1:" << endl;
    POP1();
    POP1();

    cout << "\n[c] PUSH Stack2:" << endl;
    PUSH2(100);
    PUSH2(200);
    PUSH2(300);

    cout << "\n[d] POP Stack2:" << endl;
    POP2();
    POP2();

    cout << "\n=== Program selesai ===" << endl;
    return 0;
}

