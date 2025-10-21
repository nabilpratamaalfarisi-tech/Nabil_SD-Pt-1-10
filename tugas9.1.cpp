#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* link;
};

int main() {
    // Membuat node secara manual
    Node A, B, C;

    // Mengisi data
    A.info = 25;
    B.info = 12;
    C.info = 50;

    // Menghubungkan node
    A.link = &B;
    B.link = &C;
    C.link = nullptr;

    // Deklarasi pointer
    Node* P = &A;
    Node* Q = &A;
    Node* R = &B;
    Node* S = &C;

    // Mengecek kondisi seperti di soal 1.c
    cout << "Hasil kondisi pointer:\n";
    cout << "1. P == Q : " << (P == Q ? "TRUE" : "FALSE") << endl;
    cout << "2. Q->link == R : " << (Q->link == R ? "TRUE" : "FALSE") << endl;
    cout << "3. R->link == S : " << (R->link == S ? "TRUE" : "FALSE") << endl;
    cout << "4. S->link == nullptr : " << (S->link == nullptr ? "TRUE" : "FALSE") << endl;
    cout << "5. P->info == 25 : " << (P->info == 25 ? "TRUE" : "FALSE") << endl;
    cout << "6. R->info == 50 : " << (R->info == 50 ? "TRUE" : "FALSE") << endl;
    cout << "7. P->link->info == 12 : " << (P->link->info == 12 ? "TRUE" : "FALSE") << endl;

    return 0;
}

