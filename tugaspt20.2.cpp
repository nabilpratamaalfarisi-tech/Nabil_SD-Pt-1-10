#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

/* ==========================
   INSERT DATA
========================== */
void insertData(int nilai) {
    Node* baru = new Node;
    baru->data = nilai;

    // Jika list kosong
    if (head == NULL) {
        head = baru;
        baru->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = baru;
        baru->next = head;
    }

    cout << "Insert data: " << nilai << endl;
}

/* ==========================
   DELETE DATA
========================== */
void deleteData(int nilai) {
    if (head == NULL) {
        cout << "List kosong\n";
        return;
    }

    Node *temp = head, *prev = NULL;

    // Jika data ada di head
    if (head->data == nilai) {
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        // Jika hanya satu node
        if (head->next == head) {
            delete head;
            head = NULL;
        } else {
            last->next = head->next;
            Node* hapus = head;
            head = head->next;
            delete hapus;
        }

        cout << "Delete data: " << nilai << endl;
        return;
    }

    // Jika data ada di tengah / akhir
    do {
        prev = temp;
        temp = temp->next;

        if (temp->data == nilai) {
            prev->next = temp->next;
            delete temp;
            cout << "Delete data: " << nilai << endl;
            return;
        }
    } while (temp != head);

    cout << "Data " << nilai << " tidak ditemukan\n";
}

/* ==========================
   TRAVERSE DATA
========================== */
void traverseData() {
    if (head == NULL) {
        cout << "List kosong\n";
        return;
    }

    Node* temp = head;
    cout << "Isi list: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

/* ==========================
   MAIN PROGRAM
========================== */
int main() {
    cout << "=== CIRCULAR SINGLE LINKED LIST ===\n\n";

    insertData(10);
    insertData(20);
    insertData(30);
    traverseData();

    deleteData(20);
    traverseData();

    deleteData(10);
    traverseData();

    return 0;
}

