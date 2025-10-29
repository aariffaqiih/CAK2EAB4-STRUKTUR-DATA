#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

// NULL diganti namanya jadi Nil
// karena emang di modul kaya gitu
#define Nil NULL

// tipe data yang awalnya integer (int), kita ganti namanya jadi infotype
// biar apa? ya biar sama kaya di modul
typedef int infotype;
// jadi, typedef itu kaya buat ngasih alias atau nama baru atau kata ganti

// ElmList diganti namanya jadi address
// ElmList itu sebenerna kalo pas praktikum namanya node
// ElmList atau address ini adalah titik yang bakal ditunjuk sama node yang ada di depannya
typedef struct ElmList* address;

// struktur node, namanya ElmList
// info itu tipe datanya int, tapi sekarang jadi infotype karena typedef di line 13
// kalo address, liat line 19
struct ElmList {
   infotype info;
   address next;
};

// first itu sama aja kaya head
// node itu saling terhubung dan semuanya diawali dari head
struct List {
   address first;
};

// deklarasi semua fungsi yang bakal dipake di program ini
void createList(List &L);               // membuat list kosong
address alokasi(infotype x);            // membuat node baru
void dealokasi(address P);              // menghapus node
void printInfo(List L);                 // menampilkan semua data di list
void insertFirst(List &L, address P);   // menambah node di depan
address findElm(List L, infotype x);    // mencari node berdasarkan data (info)
int sumList(List L);                    // menghitung total seluruh nilai info

#endif
