#include <iostream>
using namespace std;

#define MAX 10   // kapasitas maksimum antrian

// Struktur record
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
    q.front = 0;
    q.rear = -1;
}

// Mengecek apakah queue kosong
bool isEmpty(Queue q) {
    return q.front > q.rear;
}

// Menghapus data (dequeue)
void dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "??  Antrian sudah kosong!\n";
        return;
    }
    cout << "???  Menghapus Record -> ID: " << q.data[q.front].id 
         << ", Nama: " << q.data[q.front].nama << endl;
    q.front++;
}

// Menampilkan isi antrian
void tampilQueue(Queue q) {
    if (isEmpty(q)) {
        cout << "Antrian kosong.\n";
        return;
    }
    cout << "\n=== Isi Antrian Sekarang ===\n";
    for (int i = q.front; i <= q.rear; i++) {
        cout << i + 1 << ". ID: " << q.data[i].id 
             << ", Nama: " << q.data[i].nama << endl;
    }
    cout << "===========================\n";
}

int main() {
    Queue q;
    initQueue(q);

    // Isi antrian awal (contoh supaya bisa dihapus)
    int n;
    cout << "Masukkan jumlah data awal dalam antrian (max 10): ";
    cin >> n;

    if (n > MAX) n = MAX;

    for (int i = 0; i < n; i++) {
        cout << "Masukkan ID record ke-" << i + 1 << " : ";
        cin >> q.data[i].id;
        cout << "Masukkan Nama record ke-" << i + 1 << " : ";
        cin >> q.data[i].nama;
        q.rear++;
    }

    cout << "\n=== Mulai Proses Delete Antrian (maksimum 10 kali) ===\n";

    for (int i = 0; i < 10; i++) {
        if (isEmpty(q)) {
            cout << "\n??  Antrian sudah kosong sebelum 10 kali delete, proses dihentikan.\n";
            break;
        }
        dequeue(q);
    }

    cout << "\n=== Proses Delete Selesai ===\n";
    tampilQueue(q);

    return 0;
}

