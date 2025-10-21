#include <iostream>
#include <iomanip> // untuk format heksadesimal
using namespace std;

int main() {
    // Deklarasi array 3 dimensi
    int x[2][3][5];

    // Diketahui: &x[1][1][4] = 0x12EF
    unsigned int alamat_diketahui = 0x12EF;

    // Ukuran tipe data int = 2 byte (bisa dicek dengan sizeof(int))
    int ukuran = 2;

    // Jumlah elemen per dimensi
    int dim1 = 2; // [0..1]
    int dim2 = 3; // [0..2]
    int dim3 = 5; // [0..4]

    // Posisi yang diketahui dan yang ditanya
    int i1 = 1, j1 = 1, k1 = 4; // diketahui
    int i2 = 0, j2 = 0, k2 = 3; // ditanya

    // Hitung posisi elemen secara linear (jumlah elemen dari awal)
    int posisi_diketahui = (i1 * dim2 * dim3) + (j1 * dim3) + k1;
    int posisi_ditanya   = (i2 * dim2 * dim3) + (j2 * dim3) + k2;

    // Hitung selisih posisi
    int selisih = posisi_diketahui - posisi_ditanya;

    // Karena alamat yang ditanya berada sebelum elemen diketahui
    unsigned int alamat_ditanya = alamat_diketahui - (selisih * ukuran);

    // Tampilkan hasil
    cout << "Simulasi alamat array 3 dimensi int x[2][3][5]" << endl;
    cout << "Ukuran int: " << ukuran << " byte" << endl;
    cout << "&x[1][1][4] = 0x" << hex << uppercase << alamat_diketahui << endl;
    cout << "&x[0][0][3] = 0x" << hex << uppercase << alamat_ditanya << endl;

    return 0;
}

