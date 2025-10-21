#include <iostream>
using namespace std;

#define MAX 5

class Queue {
private:
    int front, rear;
    int ele[MAX];

public:
    // Inisialisasi queue
    Queue() {
        front = 0;
        rear = -1;
    }

    int isFull();
    int isEmpty();
    void insertQueue(int item);
    int deleteQueue(int *item);
};

// Untuk mengecek antrian sudah penuh atau belum
int Queue::isFull() {
    return (rear == MAX - 1);
}

// Untuk memeriksa antrian kosong atau tidak
int Queue::isEmpty() {
    return (front > rear);
}

// Masukkan Item ke queue
void Queue::insertQueue(int item) {
    if (isFull()) {
        cout << "\nQueue OverFlow" << endl;
        return;
    }
    ele[++rear] = item;
    cout << "\nNilai yang disisipkan: " << item;
}

// Hapus item dari queue
int Queue::deleteQueue(int *item) {
    if (isEmpty()) {
        cout << "\nQueue Underflow" << endl;
        return -1;
    }
    *item = ele[front++];
    return 0;
}

int main() {
    int item = 0;
    Queue q;

    // Insert
    q.insertQueue(10);
    q.insertQueue(20);
    q.insertQueue(30);
    q.insertQueue(40);
    q.insertQueue(50);
    q.insertQueue(60); // akan menampilkan Overflow

    // Delete
    if (q.deleteQueue(&item) == 0) cout << "\nItem dihapus: " << item;
    if (q.deleteQueue(&item) == 0) cout << "\nItem dihapus: " << item;
    if (q.deleteQueue(&item) == 0) cout << "\nItem dihapus: " << item;
    if (q.deleteQueue(&item) == 0) cout << "\nItem dihapus: " << item;
    if (q.deleteQueue(&item) == 0) cout << "\nItem dihapus: " << item;
    if (q.deleteQueue(&item) == 0) cout << "\nItem dihapus: " << item;

    cout << endl;
    return 0;
}

