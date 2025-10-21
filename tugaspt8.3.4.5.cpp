// Program Double Ended Queue (Deque) - Soal No. 3, 4, dan 5
#include <iostream>
using namespace std;

#define MAX 10  // kapasitas maksimal antrian

class Deque {
private:
    int data[MAX];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFullRight() {
        return (rear == MAX - 1);
    }

    bool isFullLeft() {
        return (front == 0);
    }

    // === Soal 3 & 5: Insert dari kanan ===
    void insertRight(int value) {
        if (isFullRight()) {
            cout << "Antrian penuh di kanan, tidak bisa diisi lagi!\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        data[rear] = value;
        cout << "Data " << value << " dimasukkan dari kanan.\n";
    }

    // === Soal 4: Delete dari kanan ===
    void deleteRight() {
        if (isEmpty()) {
            cout << "Antrian kosong, tidak bisa dihapus!\n";
            return;
        }
        cout << "Data " << data[rear] << " dihapus dari kanan.\n";
        if (front == rear) {
            front = rear = -1; // antrian jadi kosong
        } else {
            rear--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "(Kosong)\n";
            return;
        }
        cout << "Isi antrian: ";
        for (int i = front; i <= rear; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Deque dq;
    int pilih, value;

    do {
        cout << "\n=== MENU DOUBLE ENDED QUEUE ===\n";
        cout << "1. (No.3) Isi antrian dari kanan sampai penuh\n";
        cout << "2. (No.4) Hapus isi antrian dari kanan sampai kosong\n";
        cout << "3. (No.5) Isi antrian dari kanan sebanyak 10 record\n";
        cout << "4. Tampilkan isi antrian\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1: // Soal 3
                while (!dq.isFullRight()) {
                    cout << "Masukkan nilai: ";
                    cin >> value;
                    dq.insertRight(value);
                }
                cout << "Antrian sudah penuh kanan.\n";
                break;

            case 2: // Soal 4
                while (!dq.isEmpty()) {
                    dq.deleteRight();
                }
                cout << "Antrian sudah kosong.\n";
                break;

            case 3: // Soal 5
                for (int i = 0; i < 10; i++) {
                    if (dq.isFullRight()) {
                        cout << "Antrian penuh kanan, proses berhenti.\n";
                        break;
                    }
                    cout << "Masukkan nilai ke-" << (i + 1) << ": ";
                    cin >> value;
                    dq.insertRight(value);
                }
                break;

            case 4:
                dq.display();
                break;

            case 0:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 0);

    return 0;
}

