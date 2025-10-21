#include <iostream>   // pakai header modern
#include <cstdlib>    // untuk malloc()

using namespace std;

struct SIMPUL {
    int INFO;
    SIMPUL *LINK;
};

SIMPUL *P, *FIRST, *LAST;

void BUAT_SIMPUL(int x);

int main() {
    int x;
    cout << "Masukkan Data : ";
    cin >> x;
    
    BUAT_SIMPUL(x);

    if (P != NULL)
        cout << "Data : " << P->INFO << endl;
    else
        cout << "Pembuatan simpul gagal." << endl;

    return 0;
}

void BUAT_SIMPUL(int x) {
    P = (SIMPUL *)malloc(sizeof(SIMPUL)); // alokasi memori
    if (P != NULL) {
        P->INFO = x;
        P->LINK = NULL; // pointer link diatur ke NULL
    } else {
        cout << "Pembuatan simpul gagal." << endl;
    }
}

