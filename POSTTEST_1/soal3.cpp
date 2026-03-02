#include <iostream>
using namespace std;

void reverseArray(int* arr, int n) {
    int* awal = arr;
    int* akhir = arr + n - 1;
    int sementara;

    while (awal < akhir) {
        sementara = *awal;
        *awal = *akhir;
        *akhir = sementara;

        awal++;
        akhir--;
    }
}

int main() {
    int data[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;

    cout << "Array sebelum dibalik:\n";
    for (int i = 0; i < n; i++) {
        cout << "Nilai: " << *(data + i)
            << " | Alamat: " << (data + i) << endl;
    }

    reverseArray(data, n);

    cout << "\nArray sesudah dibalik:\n";
    for (int i = 0; i < n; i++) {
        cout << "Nilai: " << *(data + i)
            << " | Alamat: " << (data + i) << endl;
    }

    return 0;
}