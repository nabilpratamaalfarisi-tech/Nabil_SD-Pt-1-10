#include <iostream>
#include <iomanip>  // untuk manipulasi hex

using namespace std;

int main() {
    int x[15];  // array int

    // Diketahui &x[3] = 0x1000
    unsigned int alamat_x3 = 0x1000;
    int ukuran_int = sizeof(int);

    cout << "Ukuran int: " << ukuran_int << " byte" << endl << endl;

    // Simulasi perhitungan alamat
    for (int i = 0; i < 15; i++) {
        // cari offset dari x[3]
        int selisih = i - 3;
        unsigned int alamat = alamat_x3 + selisih * ukuran_int;

        cout << "&x[" << i << "] = 0x" 
             << hex << uppercase << alamat << endl;
    }

    cout << endl << "Alamat &x[9] = 0x" 
         << hex << uppercase << (alamat_x3 + (9 - 3) * ukuran_int) << endl;

    return 0;
}

