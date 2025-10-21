#include <iostream>
using namespace std;

const int MAX = 10; // ukuran stack

int main() {
    int S[MAX];   // array untuk stack
    int top = -1; // penunjuk stack (kosong = -1)
    int data;

    cout << "=== Program Stack (PUSH & POP) ===" << endl;

    while (true) {
        cout << "\nMasukkan data (999 untuk selesai): ";
        cin >> data;

        if (data == 999) {
            cout << "Proses selesai." << endl;
            break; // keluar dari loop
        }

        if (data >= 60) { // PUSH
            if (top < MAX - 1) {
                top++;
                S[top] = data;
                cout << "PUSH: " << data << " masuk ke stack." << endl;
            } else {
                cout << "Stack Penuh!" << endl;
                break; // stack penuh -> selesai
            }
        } 
        else { // POP
            if (top >= 0) {
                cout << "POP: " << S[top] << " dikeluarkan dari stack." << endl;
                top--;
            } else {
                cout << "Stack Kosong!" << endl;
                break; // stack kosong -> selesai
            }
        }
    }

    // cetak isi stack setelah proses selesai
    if (top >= 0) {
        cout << "\nIsi stack akhir:" << endl;
        for (int i = 0; i <= top; i++) {
            cout << S[i] << " ";
        }
        cout << endl;
    } else {
        cout << "\nStack kosong." << endl;
    }

    return 0;
}


