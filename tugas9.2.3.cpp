#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* link;
};

Node* first = nullptr;
Node* last = nullptr;

// Fungsi untuk menambah node ke linked list
void insertNode(int nilai) {
    Node* baru = new Node;
    baru->info = nilai;
    baru->link = nullptr;

    if (first == nullptr) { // Jika linked list kosong
        first = baru;
        last = baru;
    } else { // Tambahkan di akhir
        last->link = baru;
        last = baru;
    }
}

// Menghitung jumlah simpul
int hitungSimpul() {
    int jumlah = 0;
    Node* bantu = first;
    while (bantu != nullptr) {
        jumlah++;
        bantu = bantu->link;
    }
    return jumlah;
}

// Menghitung total nilai INFO
int totalINFO() {
    int total = 0;
    Node* bantu = first;
    while (bantu != nullptr) {
        total += bantu->info;
        bantu = bantu->link;
    }
    return total;
}

// Mencetak semua nilai INFO
void cetakINFO() {
    Node* bantu = first;
    cout << "Nilai INFO dalam Linked List: ";
    while (bantu != nullptr) {
        cout << bantu->info << " ";
        bantu = bantu->link;
    }
    cout << endl;
}

// Menghitung jumlah simpul dengan nilai INFO = 50
int jumlahINFO50() {
    int jumlah = 0;
    Node* bantu = first;
    while (bantu != nullptr) {
        if (bantu->info == 50)
            jumlah++;
        bantu = bantu->link;
    }
    return jumlah;
}

int main() {
    // Membuat linked list
    insertNode(25);
    insertNode(12);
    insertNode(50);
    insertNode(27);
    insertNode(14);

    cout << "=== PROGRAM LINKED LIST ===" << endl;

    // 3a. Jumlah simpul
    cout << "Jumlah simpul: " << hitungSimpul() << endl;

    // 3b. Total INFO
    cout << "Total nilai INFO: " << totalINFO() << endl;

    // 3c. Cetak semua INFO
    cetakINFO();

    // 3d. Jumlah simpul dengan INFO = 50
    cout << "Jumlah simpul dengan INFO = 50: " << jumlahINFO50() << endl;

    return 0;
}

