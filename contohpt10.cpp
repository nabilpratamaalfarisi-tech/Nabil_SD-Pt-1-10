#include <iostream>
using namespace std;

// Struktur node untuk stack (tumpukan)
struct Node {
    int data;
    Node* link;
};

// Pointer global ke elemen teratas
Node* top = NULL;

// Fungsi untuk menambah elemen ke stack (push)
void push(int data) {
    Node* temp = new Node();

    // Cek alokasi memori
    if (!temp) {
        cout << "\nHeap Overflow";
        return;
    }

    // Isi data dan atur link
    temp->data = data;
    temp->link = top;
    top = temp;
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty() {
    return top == NULL;
}

// Fungsi untuk melihat elemen teratas (tanpa menghapus)
int peek() {
    if (!isEmpty())
        return top->data;
    else {
        cout << "\nStack kosong!" << endl;
        return -1;
    }
}

// Fungsi untuk menghapus elemen teratas (pop)
void pop() {
    if (isEmpty()) {
        cout << "\nStack Underflow (kosong, tidak bisa pop)" << endl;
        return;
    }

    Node* temp = top;
    top = top->link;
    delete temp; // gunakan delete, bukan free
}

// Fungsi untuk menampilkan seluruh isi stack
void display() {
    if (isEmpty()) {
        cout << "\nStack kosong!" << endl;
        return;
    }

    Node* temp = top;
    cout << "\nIsi Stack: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->link;
    }
    cout << "NULL\n";
}

// Program utama
int main() {
    // Tambah elemen ke stack
    push(11);
    push(22);
    push(33);
    push(44);

    // Tampilkan isi stack
    display();

    // Tampilkan elemen teratas
    cout << "\nElemen Top adalah: " << peek() << endl;

    // Hapus dua elemen teratas
    pop();
    pop();

    // Tampilkan isi stack lagi
    display();

    // Tampilkan elemen teratas sekarang
    cout << "\nElemen Top sekarang adalah: " << peek() << endl;

    return 0;
}

