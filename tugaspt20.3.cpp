#include <iostream>
using namespace std;

int main() {
    // 15 data terurut
    int data[15] = {
        3, 6, 9, 12, 15,
        18, 21, 24, 27, 30,
        33, 36, 39, 42, 45
    };

    int cari;
    int kiri = 0, kanan = 14;
    int langkah = 0;

    cout << "=== BINARY SEARCH (15 DATA) ===\n\n";

    cout << "Data yang tersedia:\n";
    for (int i = 0; i < 15; i++) {
        cout << data[i] << " ";
    }
    cout << "\n\n";

    cout << "Masukkan angka yang dicari: ";
    cin >> cari;

    // Proses Binary Search
    while (kiri <= kanan) {
        langkah++;
        int tengah = (kiri + kanan) / 2;

        cout << "Langkah ke-" << langkah
             << " | Bandingkan dengan data index "
             << tengah << " (" << data[tengah] << ")\n";

        if (data[tengah] == cari) {
            cout << "\nAngka " << cari << " ditemukan pada index "
                 << tengah << endl;
            cout << "Jumlah langkah pencarian: "
                 << langkah << endl;
            return 0;
        } else if (cari < data[tengah]) {
            kanan = tengah - 1;
        } else {
            kiri = tengah + 1;
        }
    }

    cout << "\nAngka " << cari << " tidak ditemukan\n";
    cout << "Jumlah langkah pencarian: "
         << langkah << endl;

    return 0;
}

