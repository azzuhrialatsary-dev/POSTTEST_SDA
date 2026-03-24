#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

struct Kereta {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
};

void swap(Kereta *a, Kereta *b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(Kereta *arr, int n) {
    system("cls");
    cout << left << setw(8) << "No"
        << setw(15) << "Nama"
        << setw(15) << "Asal"
        << setw(15) << "Tujuan"
        << setw(10) << "Harga" << endl;
    cout << "-------------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << left << setw(8) << (arr + i)->nomor
            << setw(15) << (arr + i)->nama
            << setw(15) << (arr + i)->asal
            << setw(15) << (arr + i)->tujuan
            << setw(10) << (arr + i)->harga << endl;
    }

    system("pause");
}

void tambah(Kereta *&arr, int &n) {
    system("cls");
    Kereta *baru = new Kereta[n + 1];

    for (int i = 0; i < n; i++) {
        *(baru + i) = *(arr + i);
    }
    cout << "\nInput Data Baru\n";
    cout << "Nomor: "; cin >> (baru + n)->nomor;
    cin.ignore();
    cout << "Nama Kereta: "; getline(cin, (baru + n)->nama);
    cout << "Asal: "; getline(cin, (baru + n)->asal);
    cout << "Tujuan: "; getline(cin, (baru + n)->tujuan);
    cout << "Harga: "; cin >> (baru + n)->harga;

    delete[] arr;
    arr = baru;
    n++;
}

void linearSearch(Kereta *arr, int n, string asal, string tujuan) {
    cout << "\nProses Linear Search:\n";

    for (int i = 0; i < n; i++) {
        cout << "Iterasi ke-" << i << " -> cek "
            << (arr + i)->asal << "-" << (arr + i)->tujuan << endl;

        if ((arr + i)->asal == asal && (arr + i)->tujuan == tujuan) {
            cout << "Ditemukan: " << (arr + i)->nama << endl;
            system("pause");
            return;
        }
    }

    cout << "Tidak ditemukan\n";
    system("pause");
}

void jumpSearch(Kereta *arr, int n, int key) {
    int step = sqrt(n); // lebih masuk akal
    int prev = 0;

    // cari blok
    while (prev < n && (arr + (step < n ? step : n) - 1)->nomor < key) {
        prev = step;
        step += sqrt(n);

        if (prev >= n) {
            cout << "Tidak ditemukan\n";
            system("pause");
            return;
        }
    }

    // linear search dalam blok
    for (int i = prev; i < step && i < n; i++) {
        if ((arr + i)->nomor == key) {
            cout << "Ditemukan: " << (arr + i)->nama << endl;
            system("pause");
            return;
        }
    }

    cout << "Tidak ditemukan\n";
    system("pause");
}

void merge(Kereta *arr, int l, int m, int r) {
    Kereta L[50], R[50];

    int n1 = m - l + 1;
    int n2 = r - m;

    for (int i = 0; i < n1; i++)
        L[i] = *(arr + l + i);

    for (int j = 0; j < n2; j++)
        R[j] = *(arr + m + 1 + j);

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i].nama < R[j].nama) {
            *(arr + k) = L[i++];
        } else {
            *(arr + k) = R[j++];
        }
        k++;
    }

    while (i < n1) *(arr + k++) = L[i++];
    while (j < n2) *(arr + k++) = R[j++];
}

void mergeSort(Kereta *arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void selectionSort(Kereta *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga < (arr + min)->harga) {
                min = j;
            }
        }
        swap(arr + i, arr + min);
    }
}

void sortNomor(Kereta *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((arr + i)->nomor > (arr + j)->nomor) {
                swap(arr + i, arr + j);
            }
        }
    }
}

int main() {
    int n = 3;

    Kereta *arr = new Kereta[n]{
        {101, "Argo", "Jakarta", "Surabaya", 300000},
        {102, "Taksaka", "Jogja", "Jakarta", 250000},
        {103, "Matarmaja", "Malang", "Jakarta", 200000}
    };

    int pilih;

    do {
        system("cls");

        cout << "=============================== MENU ==================================\n";
        cout << "1. Tampil jadwal\n2. Tambah data kereta baru\n3. Cari berdasarkan asal dan tujuan (Linear Search)\n";
        cout << "4. Cari berdasarkan nomor kereta (Jump Search)\n5. Urutkan berdasarkan nama (Merge Sort)\n6. Urutkan berdasarkan harga (Selection Sort)\n7. Keluar\n";
        cout << "=======================================================================\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) tampil(arr, n);

        else if (pilih == 2) tambah(arr, n);

        else if (pilih == 3) {
            string asal, tujuan;
            cin.ignore();
            cout << "Asal: "; getline(cin, asal);
            cout << "Tujuan: "; getline(cin, tujuan);
            linearSearch(arr, n, asal, tujuan);
        }

        else if (pilih == 4) {
            int no;
            cout << "Nomor: "; cin >> no;

            sortNomor(arr, n);
            jumpSearch(arr, n, no);
        }

        else if (pilih == 5) {
            mergeSort(arr, 0, n - 1);
            tampil(arr, n);
            system("pause");
        }

        else if (pilih == 6) {
            selectionSort(arr, n);
            tampil(arr, n);
            system("pause");
        }

    } while (pilih != 0);

    delete[] arr;
}