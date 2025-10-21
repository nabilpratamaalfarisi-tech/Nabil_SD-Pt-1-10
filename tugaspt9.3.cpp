#include <iostream>
using namespace std;

// Struktur simpul (node)
struct Node {
    int INFO;
    Node* LINK;
};

int main() {
    // Buat beberapa simpul manual (contoh data)
    Node *first, *second, *third, *fourth, *fifth;

    // Alokasi memori
    first = new Node;
    second = new Node;
    third = new Node;
    fourth = new Node;
    fifth = new Node;

    // Isi data INFO dan LINK
    first->INFO = 25;
    first->LINK = second;

    second->INFO = 12;
    second->LINK = third;

    third->INFO = 50;
    third->LINK = fourth;

    fourth->INFO = 27;
    fourth->LINK = fifth;

    fifth->INFO = 14;
    fifth->LINK = NULL; // simpul terakhir

    // Pointer bantu untuk traversal
    Node* P = first;

    // Variabel hitung
    int total = 0;
    int sum = 0;
    int count = 0;

    // === Proses menghitung ===
    while (P != NULL) {
        total++;              // menghitung jumlah simpul
        sum += P->INFO;       // menambah total INFO
        if (P->INFO == 50)    // menghitung simpul yang bernilai 50
            count++;
        P = P->LINK;          // pindah ke simpul berikutnya
    }

    // Tampilkan hasil
    cout << "Jumlah simpul: " << total << endl;
    cout << "Total INFO: " << sum << endl;
    cout << "Jumlah simpul dengan INFO = 50: " << count << endl;

    return 0;
}

