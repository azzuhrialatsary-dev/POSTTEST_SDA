#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    int jumlah = 5;
    Mahasiswa mhs[jumlah];

    for (int i = 0; i < jumlah; i++) {
        cout << "Data Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama : ";
        cin >> mhs[i].nama;

        cout << "NIM  : ";
        cin >> mhs[i].nim;

        cout << "IPK  : ";
        cin >> mhs[i].ipk;
        cout << endl;
    }

    float ipkTertinggi = mhs[0].ipk;
    int indeksTertinggi = 0;

    for (int i = 1; i < jumlah; i++) {
        if (mhs[i].ipk > ipkTertinggi) {
            ipkTertinggi = mhs[i].ipk;
            indeksTertinggi = i;
        }
    }

    cout << "Mahasiswa dengan IPK tertinggi:" << endl;
    cout << "Nama : " << mhs[indeksTertinggi].nama << endl;
    cout << "NIM  : " << mhs[indeksTertinggi].nim << endl;
    cout << "IPK  : " << mhs[indeksTertinggi].ipk << endl;

    return 0;
}