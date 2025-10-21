#include <iostream>
#include <iomanip>  // untuk hex

using namespace std;

int main() {
    float x[5][8];  // array 2D
    
    // diketahui &x[0][0] = 0x1000
    unsigned int base_address = 0x1000;
    int kolom = 8;
    int ukuran_float = sizeof(float);

    cout << "Ukuran float: " << ukuran_float << " byte" << endl << endl;

    // tampilkan alamat simulasi tiap elemen
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            unsigned int alamat = base_address + (i * kolom + j) * ukuran_float;
            cout << "&x[" << i << "][" << j << "] = 0x"
                 << hex << uppercase << alamat << "\t";
        }
        cout << endl;
    }

    cout << endl << "Alamat &x[2][4] = 0x"
         << hex << uppercase 
         << (base_address + ((2 * kolom + 4) * ukuran_float)) << endl;

    return 0;
}

