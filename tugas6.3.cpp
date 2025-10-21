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

// a. INISIALISASI
void initQueue(Queue &q) {
    q.front = -1;
    q.rear = -1;
    cout << "? Antrian berhasil diinisialisasi.\n";
}

// Mengecek apakah antrian penuh
bool isFull(Queue q) {
    return q.rear == MAX - 1;
}

// Mengecek apakah antrian kosong
bool isEmpty(Queue q) {
    return q.front == -1;
}

// b. INSERT SEBUAH RECORD
void insertQueue(Queue &q, Record r) {
    if (isFull(q)) {
        cout << "??  Antrian penuh! Tidak dapat menambahkan data.\n";
        return;
    }
    if (isEmpty(q))
        q.front = 0;
    q.rear++;
    q.data[q.rear] = r;
    cout << "? Data berhasil dimasukkan ke antrian.\n";
}

// c. DELETE SEBUAH RECORD
void deleteQueue(Queue &q) {
    if (isEmpty(q)) {
        cout << "??  Antrian kosong! Tidak ada data yang bisa dihapus.\n";
        return;
    }

    cout << "???  Menghapus Record -> ID: " << q.data[q.front].id
         << ", Nama: " << q.data[q.front].nama << endl;

    if (q.front == q.rear) {
        q.front = q.rear = -1;  // Antrian jadi kosong
    } else {
        q.front++;
    }
}

// d. RESET ANTRIAN
void resetQueue(Queue &q) {
    q.front = -1;
    q.rear = -1;
    cout << "??  Antrian telah direset (kosong kembali).\n";
}

// Menampilkan isi antrian
void tampilQueue(Queue q) {
    if (isEmpty(q)) {
        cout << "Antrian kosong.\n";
        return;
    }
    cout << "\n=== Isi Antrian ===\n";
    for (int i = q.front; i <= q.rear; i++) {
        cout << i + 1 << ". ID: " << q.data[i].id 
             << ", Nama: " << q.data[i].nama << endl;
    }
    cout << "===================\n";
}

int main() {
    Queue q;
    initQueue(q);
    Record r;
    int pilihan;

    do {
        cout << "\n=== MENU ANTRIAN ===\n";
        cout << "1. Insert (Tambah Record)\n";
        cout << "2. Delete (Hapus Record)\n";
        cout << "3. Tampilkan Antrian\n";
        cout << "4. Reset Antrian\n";
        cout << "5. Keluar\n";
        cout << "Pilih (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan ID: ";
                cin >> r.id;
                cout << "Masukkan Nama: ";
                cin >> r.nama;
                insertQueue(q, r);
                break;
            case 2:
                deleteQueue(q);
                break;
            case 3:
                tampilQueue(q);
                break;
            case 4:
                resetQueue(q);
                break;
            case 5:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}

