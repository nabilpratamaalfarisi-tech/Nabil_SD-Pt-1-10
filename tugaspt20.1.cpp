#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int data[10];
    srand(time(0));

    // Generate data random
    cout << "=== ANIMASI BUBBLE SORT ===\n\n";
    cout << "Data awal: ";
    for (int i = 0; i < 10; i++) {
        data[i] = rand() % 100;
        cout << data[i] << " ";
    }
    cout << "\n\n";

    // Proses Bubble Sort
    for (int i = 0; i < 9; i++) {
        cout << "PASS KE-" << i + 1 << endl;
        for (int j = 0; j < 9 - i; j++) {
            cout << "Bandingkan " << data[j]
                 << " dan " << data[j + 1];

            if (data[j] > data[j + 1]) {
                // Tukar data
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
                cout << " -> Ditukar\n";
            } else {
                cout << " -> Tidak ditukar\n";
            }

            // Tampilkan kondisi array
            cout << "Data sekarang: ";
            for (int k = 0; k < 10; k++) {
                cout << data[k] << " ";
            }
            cout << endl;
        }
        cout << "-----------------------------\n";
    }

    // Hasil akhir
    cout << "\nData setelah diurutkan: ";
    for (int i = 0; i < 10; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}


