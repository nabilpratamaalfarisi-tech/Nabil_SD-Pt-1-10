#include <iostream>
using namespace std;

int main() {
    int F, R, N, jumlahIsi;

    cout << "Masukkan ukuran maksimum queue (N): ";
    cin >> N;
    cout << "Masukkan posisi Front (F): ";
    cin >> F;
    cout << "Masukkan posisi Rear (R): ";
    cin >> R;

    if (R >= F)
        jumlahIsi = R - F + 1;
    else
        jumlahIsi = N - F + 1 + R;

    cout << "Jumlah elemen yang ada isinya: " << jumlahIsi << endl;

    return 0;
}

