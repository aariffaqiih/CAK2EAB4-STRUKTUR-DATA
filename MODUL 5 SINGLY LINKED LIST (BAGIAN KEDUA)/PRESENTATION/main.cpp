#include "SinglyList.h"

int main() {
   // bikin variabel list utama
   // ini yang bakal nyimpen semua node yang kita tambahin
   List L;

   // bikin variabel pointer (alamat node)
   address P1, P2, P3, P4, P5 = Nil;

   // bikin list kosong dulu buat diisi
   createList(L);

   // nambahin data satu per satu
   P1 = alokasi(2);
   insertFirst(L, P1);

   P2 = alokasi(0);
   insertFirst(L, P2);

   P3 = alokasi(8);
   insertFirst(L, P3);

   P4 = alokasi(12);
   insertFirst(L, P4);

   P5 = alokasi(9);
   insertFirst(L, P5);

   // tampilkan semua isi list
   printInfo(L);

   // cari node dengan nilai 8
   cout << "\nmencari elemen dengan info 8..." << endl;
   address hasil = findElm(L, 8);

   // kalo hasilnya bukan Nil, berarti ketemu
   if (hasil != Nil)
   {
      cout << "data 8 ketemu di alamat memori: " << hasil << endl;
      cout << "isi node itu adalah: " << hasil->info << endl;
   }
   else
   {
      // kalo hasilnya Nil, berarti datanya ga ada
      cout << "data 8 tidak ketemu di list" << endl;
   }

   // hitung total dari semua node yang ada di list
   int total = sumList(L);

   // tampilkan hasil totalnya
   cout << "total seluruh elemen (9 + 12 + 8 + 0 + 2) = " << total << endl;

   return 0;
}

// g++ *.cpp -o program.exe
// .\program.exe
