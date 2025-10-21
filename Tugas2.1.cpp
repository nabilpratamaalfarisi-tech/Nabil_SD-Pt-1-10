#include <iostream>
#include <iomanip>  // untuk hex

using namespace std;

int main() {
    char x[12];  // deklarasi array 1 dimensi

    // Asumsi alamat awal x[0] = 0x1000
    unsigned int alamat_awal = 0x1000;

    cout << "Simulasi alamat array x[12]" << endl;
    cout << "Ukuran char: " << sizeof(char) << " byte" << endl << endl;

    for (int i = 0; i < 12; i++) {
        unsigned int alamat = alamat_awal + i * sizeof(char);
        cout << "&x[" << i << "] = 0x" 
             << hex << uppercase << alamat << endl;
    }

    cout << endl << "Alamat &x[8] = 0x" 
         << hex << uppercase << (alamat_awal + 8) << endl;

    return 0;
}

