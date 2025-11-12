#include <iostream>
using namespace std;

// ==========================
// 1. Struktur Stack (LIFO)
// ==========================
#define MAX 5
int stack[MAX];
int top = -1;

void push(int data) {
    if (top == MAX - 1)
        cout << "Stack penuh!\n";
    else
        stack[++top] = data;
}

void pop() {
    if (top == -1)
        cout << "Stack kosong!\n";
    else
        cout << "Data " << stack[top--] << " dihapus dari Stack (LIFO)\n";
}

void tampilStack() {
    cout << "Isi Stack (LIFO): ";
    for (int i = 0; i <= top; i++)
        cout << stack[i] << " ";
    cout << endl;
}

// ==========================
// 2. Struktur Queue (FIFO)
// ==========================
int queue[MAX];
int front = 0, rear = -1, count = 0;

void enqueue(int data) {
    if (count == MAX)
        cout << "Queue penuh!\n";
    else {
        rear = (rear + 1) % MAX;
        queue[rear] = data;
        count++;
    }
}

void dequeue() {
    if (count == 0)
        cout << "Queue kosong!\n";
    else {
        cout << "Data " << queue[front] << " dihapus dari Queue (FIFO)\n";
        front = (front + 1) % MAX;
        count--;
    }
}

void tampilQueue() {
    cout << "Isi Queue (FIFO): ";
    for (int i = 0; i < count; i++)
        cout << queue[(front + i) % MAX] << " ";
    cout << endl;
}

// ==========================
// 3. Program Utama
// ==========================
int main() {
    cout << "=== DEMO LIFO (STACK) dan FIFO (QUEUE) ===\n";

    // Contoh LIFO (STACK)
    cout << "\n>>> Operasi STACK (LIFO):\n";
    push(10);
    push(20);
    push(30);
    tampilStack();
    pop();
    tampilStack();

    // Contoh FIFO (QUEUE)
    cout << "\n>>> Operasi QUEUE (FIFO):\n";
    enqueue(100);
    enqueue(200);
    enqueue(300);
    tampilQueue();
    dequeue();
    tampilQueue();

    cout << "\n=== Program selesai ===";
    return 0;
}

