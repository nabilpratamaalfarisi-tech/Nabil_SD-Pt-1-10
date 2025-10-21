#include <iostream>
#include <string>
using namespace std;


class Siswa {
protected:
    string nama;
    string kelas;
    int nilai;

public:
    
    Siswa(string nama, string kelas, int nilai) {
        this->nama = nama;
        this->kelas = kelas;
        this->nilai = nilai;
    }

    
    void tampilkanInfo() {
        cout << "Nama  : " << nama << endl;
        cout << "Kelas : " << kelas << endl;
        cout << "Nilai : " << nilai << endl;
    }
};


class SiswaIT : public Siswa {
private:
    string programStudi;

public:
    
    SiswaIT(string nama, string kelas, int nilai, string programStudi)
        : Siswa(nama, kelas, nilai)
    {
        this->programStudi = programStudi;
    }

    
    void tampilkanInfoLengkap() {
        
        tampilkanInfo();
    
        cout << "Program Studi : " << programStudi << endl;
    }
};


int main() {
    
    SiswaIT siswa_it_baru("nabi", "12B", 82, "Sistem Informasi");

    
    cout << "=== Data Siswa Baru ===" << endl;
    siswa_it_baru.tampilkanInfoLengkap();

}
