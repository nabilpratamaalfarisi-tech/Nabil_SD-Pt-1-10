#include <iostream>
#include <iomanip>  // untuk hex

using namespace std;

int main() {
    long x[12][14];  // array 2D
    
    // diketahui &x[0][0] = 0x1000
    unsigned int base_address = 0x1000;
    int kolom = 14;
    int ukuran_long = sizeof(long);

    cout << "Ukuran long: " << ukuran_long << " byte" << endl << endl;

    // tampilkan alamat simulasi sebagian saja (biar tidak kepanjangan)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) { // batasi 6 kolom biar ringkas
            unsigned int alamat = base_address + (i * kolom + j) * ukuran_long;
            cout << "&x[" << i << "][" << j << "] = 0x"
                 << hex << uppercase << alamat << "\t";
        }
        cout << endl;
    }

    cout << endl << "Alamat &x[2][4] = 0x"
         << hex << uppercase 
         << (base_address + ((2 * kolom + 4) * ukuran_long)) << endl;

    return 0;
}

