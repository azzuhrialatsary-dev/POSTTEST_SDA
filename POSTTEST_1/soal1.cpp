#include <iostream>
using namespace std;

void FindMin(int A[], int n, int &minValue, int &minIndex) {
    minValue = A[0];
    minIndex = 0;

    for(int i = 1; i < n; i++) {
        if(A[i] < minValue) {
            minValue = A[i];
            minIndex = i;
        }
    }
}

int main() {
    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int minValue, minIndex;

    FindMin(A, 8, minValue, minIndex);

    cout << "Nilai minimum : " << minValue << endl;
    cout << "Indeks minimum: " << minIndex << endl;

    return 0;
}

// TABEL COST (FindMin)

// Baris                     Cost    Tmin      Tmax
// -------------------------------------------------
// min ← A[0]                C1      1         1
// for i ← 1 to n-1          C2      n         n
// if A[i] < min             C3      n-1       n-1
// min ← A[i]                C4      0         n-1
// return min                C5      1         1

// BEST CASE:
// Tmin(n) = C1 + C2n + C3(n-1) + 0 + C5
//         ≈ 4n + konstanta
// Big-O = O(n)

// WORST CASE:
// Tmax(n) = C1 + C2n + C3(n-1) + C4(n-1) + C5
//         ≈ 5n + konstanta
// Big-O = O(n)

// Kesimpulan:
// Kompleksitas waktu linear karena seluruh elemen tetap diperiksa.
