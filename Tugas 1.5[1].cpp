#include <iostream>
using namespace std;

int main() {
    int A, B;
    cout << "Masukkan A: ";
    cin >> A;
    cout << "Masukkan B: ";
    cin >> B;

    int temp = A;
    A = B;
    B = temp;

    cout << "Setelah ditukar: A = " << A << ", B = " << B << endl;
    return 0;
}

