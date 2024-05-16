#include <iostream>

using namespace std;

struct Mahasiswa {
    string nama;
    int umur;
    string jurusan;
};

int main() {
    Mahasiswa mhs1;
    mhs1.nama = "Azka";
    mhs1.umur = 18;
    mhs1.jurusan = "Sains Data";

    cout << "Nama    : " << mhs1.nama << endl;
    cout << "Umur    : " << mhs1.umur << endl;
    cout << "Jurusan : " << mhs1.jurusan << endl;

    return 0;
}