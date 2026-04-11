#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

#define MAX 100

struct Kereta {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
};

struct Tiket {
    string namaPenumpang;
    string asal;
    string tujuan;
    string namaKereta;
};

Tiket stackTiket[MAX];
int top = -1;

void push(Tiket t) {
    if (top >= MAX - 1) {
        cout << "Stack overflow\n";
        return;
    }
    *(stackTiket + (++top)) = t;
}

void pop() {
    if (top < 0) {
        cout << "Stack underflow\n";
        return;
    }
    cout << "Hapus riwayat: " << (stackTiket + top)->namaPenumpang << endl;
    top--;
}

void peekStack() {
    if (top < 0) {
        cout << "Stack kosong\n";
        return;
    }
    cout << "Terakhir: " << (stackTiket + top)->namaPenumpang
        << " (" << (stackTiket + top)->namaKereta << ")\n";
}

void tampilStack() {
    if (top < 0) {
        cout << "Riwayat kosong\n";
        return;
    }

    cout << "\nRiwayat Transaksi:\n";
    for (Tiket *ptr = stackTiket; ptr <= stackTiket + top; ptr++) {
        cout << ptr->namaPenumpang << " | "
            << ptr->namaKereta << " | "
            << ptr->asal << "-" << ptr->tujuan << endl;
    }
}

Tiket queueTiket[MAX];
int front = -1, rear = -1;

bool isFull() {
    return rear == MAX - 1;
}

bool isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(Tiket t) {
    if (isFull()) {
        cout << "Queue overflow\n";
        return;
    }
    if (front == -1) front = 0;

    *(queueTiket + (++rear)) = t;
    cout << "Masuk antrian: " << t.namaPenumpang << endl;
}

Tiket dequeue() {
    Tiket kosong;

    if (isEmpty()) {
        cout << "Queue underflow\n";
        return kosong;
    }

    Tiket t = *(queueTiket + front);
    front++;

    if (isEmpty()) front = rear = -1;

    return t;
}

void peekQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong\n";
        return;
    }
    cout << "Depan: " << (queueTiket + front)->namaPenumpang << endl;
}

void tampilQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong\n";
        return;
    }

    cout << "\nAntrian:\n";
    for (Tiket *ptr = queueTiket + front; ptr <= queueTiket + rear; ptr++) {
        cout << ptr->namaPenumpang << " | "
            << ptr->asal << "-" << ptr->tujuan << endl;
    }
}

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

    for (Kereta *ptr = arr; ptr < arr + n; ptr++) {
        cout << left << setw(8) << ptr->nomor
            << setw(15) << ptr->nama
            << setw(15) << ptr->asal
            << setw(15) << ptr->tujuan
            << setw(10) << ptr->harga << endl;
    }
    system("pause");
}

void tambah(Kereta *&arr, int &n) {
    Kereta *baru = new Kereta[n + 1];

    for (int i = 0; i < n; i++)
        *(baru + i) = *(arr + i);

    cout << "Nomor: "; cin >> (baru + n)->nomor;
    cin.ignore();
    cout << "Nama: "; getline(cin, (baru + n)->nama);
    cout << "Asal: "; getline(cin, (baru + n)->asal);
    cout << "Tujuan: "; getline(cin, (baru + n)->tujuan);
    cout << "Harga: "; cin >> (baru + n)->harga;

    delete[] arr;
    arr = baru;
    n++;
}

void linearSearch(Kereta *arr, int n, string asal, string tujuan) {
    for (Kereta *ptr = arr; ptr < arr + n; ptr++) {
        if (ptr->asal == asal && ptr->tujuan == tujuan) {
            cout << "Ditemukan: " << ptr->nama << endl;
            system("pause");
            return;
        }
    }
    cout << "Tidak ditemukan\n";
    system("pause");
}

void sortNomor(Kereta *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((arr + i)->nomor > (arr + j)->nomor)
                swap(arr + i, arr + j);
        }
    }
}

void jumpSearch(Kereta *arr, int n, int key) {
    int step = sqrt(n), prev = 0;

    while ((arr + (step < n ? step : n) - 1)->nomor < key) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            cout << "Tidak ditemukan\n";
            return;
        }
    }

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
    int n1 = m - l + 1, n2 = r - m;

    Kereta *L = new Kereta[n1];
    Kereta *R = new Kereta[n2];

    for (int i = 0; i < n1; i++) *(L + i) = *(arr + l + i);
    for (int j = 0; j < n2; j++) *(R + j) = *(arr + m + 1 + j);

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if ((L + i)->nama < (R + j)->nama)
            *(arr + k++) = *(L + i++);
        else
            *(arr + k++) = *(R + j++);
    }

    while (i < n1) *(arr + k++) = *(L + i++);
    while (j < n2) *(arr + k++) = *(R + j++);

    delete[] L;
    delete[] R;
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
            if ((arr + j)->harga < (arr + min)->harga)
                min = j;
        }
        swap(arr + i, arr + min);
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

        cout << "=========== MENU ===========\n";
        cout << "1. Tampil Jadwal\n";
        cout << "2. Tambah Data\n";
        cout << "3. Linear Search\n";
        cout << "4. Jump Search\n";
        cout << "5. Merge Sort (Nama)\n";
        cout << "6. Selection Sort (Harga)\n";
        cout << "7. Enqueue Tiket\n";
        cout << "8. Dequeue Tiket\n";
        cout << "9. Tampil Antrian\n";
        cout << "10. Tampil Riwayat\n";
        cout << "11. Pop Riwayat\n";
        cout << "12. Peek\n";
        cout << "13. Keluar\n";
        cout << "============================\n";
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
        }

        else if (pilih == 6) {
            selectionSort(arr, n);
            tampil(arr, n);
        }

        else if (pilih == 7) {
            Tiket t;
            cin.ignore();
            cout << "Nama: "; getline(cin, t.namaPenumpang);
            cout << "Asal: "; getline(cin, t.asal);
            cout << "Tujuan: "; getline(cin, t.tujuan);
            cout << "Kereta: "; getline(cin, t.namaKereta);
            enqueue(t);
            system("pause");
        }

        else if (pilih == 8) {
            Tiket t = dequeue();
            if (t.namaPenumpang != "") {
                cout << "Diproses: " << t.namaPenumpang << endl;
                push(t);
            }
            system("pause");
        }

        else if (pilih == 9) {
            tampilQueue();
            system("pause");
        }

        else if (pilih == 10) {
            tampilStack();
            system("pause");
        }

        else if (pilih == 11) {
            pop();
            system("pause");
        }

        else if (pilih == 12) {
            peekQueue();
            peekStack();
            system("pause");
        }

    } while (pilih != 13);

    delete[] arr;
}