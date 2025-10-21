#include <iostream>
using namespace std;

#define MAX 10   // kapasitas maksimum antrian

// Struktur record untuk data
struct Record {
    int id;
    string nama;
};

// Struktur queue
struct Queue {
    int front, rear;
    Record data[MAX];
};

// Inisialisasi queue
void initQueue(Queue &q) {
    q.front = q.rear = -1;
}

// Mengecek apakah queue penuh
bool isFull(Queue q) {
    return q.rear == MAX - 1;
}

// Mengecek apakah queue kosong
bool isEmpty(Queue q) {
    return q.front == -1;
}

// Menambahkan data ke dalam queue
void enqueue(Queue &q, Record r) {
    if (isFull(q)) {
        cout << "??  Antrian penuh! Tidak bisa menambah data lagi.\n";
        return;
    }
    if (isEmpty(q))
        q.front = 0;
    q.rear++;
    q.data[q.rear] = r;
    cout << "? Record ke-" << q.rear + 1 << " berhasil dimasukkan ke antrian.\n";
}

// Menampilkan isi queue
void tampilQueue(Queue q) {
    if (isEmpty(q)) {
        cout << "Antrian masih kosong.\n";
        return;
    }
    cout << "\n=== Daftar Isi Antrian ===\n";
    for (int i = q.front; i <= q.rear; i++) {
        cout << i + 1 << ". ID: " << q.data[i].id 
             << ", Nama: " << q.data[i].nama << endl;
    }
    cout << "==========================\n";
}

int main() {
    Queue q;
    initQueue(q);
    Record r;

    cout << "=== Program Mengisi Antrian Maksimum 10 Record ===\n";

    for (int i = 0; i < 10; i++) {
        if (isFull(q)) {
            cout << "\n??  Antrian penuh sebelum 10 record, pengisian dihentikan.\n";
            break;
        }

        cout << "\nMasukkan Record ke-" << i + 1 << ":\n";
        cout << "ID   : ";
        cin >> r.id;
        cout << "Nama : ";
        cin >> r.nama;

        enqueue(q, r);
    }

    cout << "\n=== Pengisian Antrian Selesai ===\n";
    tampilQueue(q);

    return 0;
}

