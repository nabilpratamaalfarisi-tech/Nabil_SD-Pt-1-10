#include <iostream>
using namespace std;

/* ==========================
   STRUKTUR NODE QUEUE
========================== */
struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

/* ==========================
   ENQUEUE
========================== */
void enqueue(int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (rear == NULL) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }

    cout << "Enqueue: " << nilai << endl;
}

/* ==========================
   DEQUEUE
========================== */
void dequeue() {
    if (front == NULL) {
        cout << "Queue kosong\n";
        return;
    }

    Node* temp = front;
    cout << "Dequeue: " << front->data << endl;

    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }

    delete temp;
}

/* ==========================
   TAMPILKAN QUEUE
========================== */
void tampilQueue() {
    if (front == NULL) {
        cout << "Queue kosong\n";
        return;
    }

    Node* temp = front;
    cout << "Isi Queue: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/* ==========================
   MAIN PROGRAM
========================== */
int main() {
    cout << "=== PROGRAM QUEUE LINKED LIST ===\n\n";

    enqueue(10);
    enqueue(20);
    enqueue(30);
    tampilQueue();

    dequeue();
    tampilQueue();

    dequeue();
    tampilQueue();

    return 0;
}

