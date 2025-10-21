#include <iostream>
#include <string>
using namespace std;

struct Buku {
    int noAkses;
    string penulis;
    string judul;
    bool diterbitkan; // true = diterbitkan, false = tidak
};

int main() {
    const int MAX = 100;
    Buku perpustakaan[MAX];
    int jumlahBuku = 0;
    int pilihan;

    do {
        cout << "\n=== MENU PERPUSTAKAAN ===\n";
        cout << "1. Menampilkan informasi buku\n";
        cout << "2. Tambahkan buku baru\n";
        cout << "3. Tampilkan semua buku dari penulis tertentu\n";
        cout << "4. Tampilkan jumlah buku dengan judul tertentu\n";
        cout << "5. Tampilkan jumlah total buku\n";
        cout << "6. Terbitkan buku\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            for (int i = 0; i < jumlahBuku; i++) {
                cout << "\nNo Akses: " << perpustakaan[i].noAkses;
                cout << "\nPenulis: " << perpustakaan[i].penulis;
                cout << "\nJudul  : " << perpustakaan[i].judul;
                cout << "\nStatus : " << (perpustakaan[i].diterbitkan ? "Diterbitkan" : "Belum diterbitkan") << "\n";
            }
        }
        else if (pilihan == 2) {
            Buku b;
            cout << "Masukkan No Akses: ";
            cin >> b.noAkses;
            cin.ignore();
            cout << "Masukkan Nama Penulis: ";
            getline(cin, b.penulis);
            cout << "Masukkan Judul Buku: ";
            getline(cin, b.judul);
            b.diterbitkan = false;
            perpustakaan[jumlahBuku++] = b;
            cout << "Buku berhasil ditambahkan!\n";
        }
        else if (pilihan == 3) {
            string cari;
            cout << "Masukkan nama penulis: ";
            getline(cin, cari);
            cout << "\nDaftar buku oleh " << cari << ":\n";
            for (int i = 0; i < jumlahBuku; i++) {
                if (perpustakaan[i].penulis == cari) {
                    cout << "- " << perpustakaan[i].judul << endl;
                }
            }
        }
        else if (pilihan == 4) {
            string cari;
            int count = 0;
            cout << "Masukkan judul buku: ";
            getline(cin, cari);
            for (int i = 0; i < jumlahBuku; i++) {
                if (perpustakaan[i].judul == cari) count++;
            }
            cout << "Jumlah buku dengan judul \"" << cari << "\": " << count << endl;
        }
        else if (pilihan == 5) {
            cout << "Total buku di perpustakaan: " << jumlahBuku << endl;
        }
        else if (pilihan == 6) {
            int no;
            cout << "Masukkan No Akses buku yang akan diterbitkan: ";
            cin >> no;
            for (int i = 0; i < jumlahBuku; i++) {
                if (perpustakaan[i].noAkses == no) {
                    perpustakaan[i].diterbitkan = true;
                    cout << "Buku \"" << perpustakaan[i].judul << "\" sudah diterbitkan.\n";
                }
            }
        }
    } while (pilihan != 0);

    return 0;
}

