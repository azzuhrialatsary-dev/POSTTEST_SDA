#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk Circular Linked List Perpustakaan
struct BukuNode {
    string judulBuku;
    BukuNode* next;

    // Constructor
    BukuNode(string judul) {
        judulBuku = judul;
        next = nullptr;
    }
};

// Fungsi insert di akhir Circular Linked List
BukuNode* tambahBuku(BukuNode* head, string judul) {
    BukuNode* newNode = new BukuNode(judul);

    // Jika list kosong
    if (head == nullptr) {
        newNode->next = newNode;
        return newNode;
    }

    // Cari node terakhir
    BukuNode* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    // Tambahkan node baru
    temp->next = newNode;
    newNode->next = head;

    return head;
}

bool cariBuku(BukuNode* head, string judulDicari) {
    if (head == nullptr) {
        return false;
    }

    BukuNode* temp = head;

    do {
        if (temp->judulBuku == judulDicari) {
            return true;
        }
        temp = temp->next;
    } while (temp != head);

    return false;
}

int main() {
    BukuNode* head = nullptr;

    // Tambah data
    head = tambahBuku(head, "Struktur Data dengan C++");
    head = tambahBuku(head, "Pengantar Algoritma");
    head = tambahBuku(head, "Pemrograman Berorientasi Objek");
    head = tambahBuku(head, "Sistem Basis Data");

    string buku1 = "Pengantar Algoritma";
    string buku2 = "Kalkulus Lanjut";

    // Output pencarian
    cout << "Mencari buku '" << buku1 << "': "
        << (cariBuku(head, buku1) ? "Ditemukan" : "Tidak Ditemukan") << endl;

    cout << "Mencari buku '" << buku2 << "': "
        << (cariBuku(head, buku2) ? "Ditemukan" : "Tidak Ditemukan") << endl;

    return 0;
}