#include <iostream>
#include <string>
using namespace std;

// Struktur node untuk data mahasiswa
struct Mahasiswa {
    string NIM;
    string NAMA;
    float NILAI;
    Mahasiswa* next;
};

Mahasiswa* head = NULL;

// Fungsi untuk menambah data baru sesuai urutan NILAI (ascending)
void tambahData() {
    Mahasiswa* baru = new Mahasiswa;
    cout << "\nMasukkan NIM   : ";
    cin >> baru->NIM;
    cout << "Masukkan NAMA  : ";
    cin.ignore();
    getline(cin, baru->NAMA);
    cout << "Masukkan NILAI : ";
    cin >> baru->NILAI;
    baru->next = NULL;

    // Jika list kosong atau data baru lebih kecil dari head
    if (head == NULL || baru->NILAI < head->NILAI) {
        baru->next = head;
        head = baru;
    } else {
        Mahasiswa* bantu = head;
        while (bantu->next != NULL && bantu->next->NILAI <= baru->NILAI) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }

    cout << "\nData berhasil ditambahkan!\n";
}

// Fungsi untuk menampilkan data dengan nilai = 90
void tampilNilai90() {
    if (head == NULL) {
        cout << "\nData kosong!\n";
        return;
    }

    bool ditemukan = false;
    Mahasiswa* bantu = head;
    cout << "\nData dengan NILAI = 90:\n";
    while (bantu != NULL) {
        if (bantu->NILAI == 90) {
            cout << "NIM   : " << bantu->NIM << endl;
            cout << "NAMA  : " << bantu->NAMA << endl;
            cout << "NILAI : " << bantu->NILAI << endl << endl;
            ditemukan = true;
        }
        bantu = bantu->next;
    }

    if (!ditemukan)
        cout << "Tidak ada mahasiswa dengan nilai 90.\n";
}

// Fungsi untuk menampilkan seluruh data
void tampilSemua() {
    if (head == NULL) {
        cout << "\nData kosong!\n";
        return;
    }

    cout << "\n=== DAFTAR SELURUH DATA MAHASISWA (URUT NILAI NAIK) ===\n";
    Mahasiswa* bantu = head;
    while (bantu != NULL) {
        cout << "NIM   : " << bantu->NIM << endl;
        cout << "NAMA  : " << bantu->NAMA << endl;
        cout << "NILAI : " << bantu->NILAI << endl;
        cout << "---------------------------------\n";
        bantu = bantu->next;
    }
}

// Fungsi untuk menghapus data berdasarkan NIM
void hapusData(string nimHapus) {
    if (head == NULL) {
        cout << "\nData kosong!\n";
        return;
    }

    Mahasiswa* hapus;
    if (head->NIM == nimHapus) {
        hapus = head;
        head = head->next;
        delete hapus;
        cout << "\nData dengan NIM " << nimHapus << " berhasil dihapus!\n";
        return;
    }

    Mahasiswa* bantu = head;
    while (bantu->next != NULL && bantu->next->NIM != nimHapus) {
        bantu = bantu->next;
    }

    if (bantu->next == NULL) {
        cout << "\nData dengan NIM " << nimHapus << " tidak ditemukan.\n";
    } else {
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
        cout << "\nData dengan NIM " << nimHapus << " berhasil dihapus!\n";
    }
}

// Fungsi untuk menghitung rata-rata nilai kelas
void rataRata() {
    if (head == NULL) {
        cout << "\nData kosong!\n";
        return;
    }

    int jumlah = 0;
    float total = 0;
    Mahasiswa* bantu = head;

    while (bantu != NULL) {
        total += bantu->NILAI;
        jumlah++;
        bantu = bantu->next;
    }

    cout << "\nRata-rata nilai kelas: " << total / jumlah << endl;
}

// Menu utama
int main() {
    int pilihan;
    string nim;

    do {
        cout << "\n===== MENU LINKED LIST MAHASISWA =====";
        cout << "\n1. Tambah Data Mahasiswa";
        cout << "\n2. Tampilkan Data dengan NILAI = 90";
        cout << "\n3. Tampilkan Seluruh Data";
        cout << "\n4. Hapus Data (NIM = 2007140022)";
        cout << "\n5. Hitung Rata-rata Nilai Kelas";
        cout << "\n6. Keluar";
        cout << "\nPilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahData();
                break;
            case 2:
                tampilNilai90();
                break;
            case 3:
                tampilSemua();
                break;
            case 4:
                hapusData("2007140022");
                break;
            case 5:
                rataRata();
                break;
            case 6:
                cout << "\nTerima kasih!\n";
                break;
            default:
                cout << "\nPilihan tidak valid!\n";
        }
    } while (pilihan != 6);

    return 0;
}

