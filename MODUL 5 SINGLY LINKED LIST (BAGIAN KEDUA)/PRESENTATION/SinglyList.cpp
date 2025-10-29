#include "SinglyList.h"

// fungsi untuk membuat list kosong
void createList(List &L) {
   L.first = Nil;
   // L di sini itu parameter bertipe "List", dan ditulis pakai tanda "&"
   // tanda "&" di parameter berarti "pass by reference"
   // artinya data aslinya dikasih langsung ke fungsi ini, bukan salinannya
   // jadi kalo isi L diubah di sini, maka isi L yang di main() juga ikut berubah
   // kalo ga pakai "&", perubahan di sini ga bakal ngaruh ke luar fungsi
   // kenapa namanya L? L itu singkatan dari "List"
}

// fungsi untuk membuat node baru
address alokasi(infotype x) {
   address P = new ElmList;
   // kenapa namanya P? karena P itu singkatan dari "Pointer"

   // cek apakah node berhasil dibuat atau tidak
   // kalo "new" gagal, maka P nilainya bakal NULL
   // makanya dicek dulu, biar aman
   if (P != Nil) {
      // kalo berhasil, isi field "info" node itu dengan data x
      // x di sini adalah data yang dikirim dari user
      P->info = x;

      // terus pointer "next"-nya dikosongin dulu
      // karena node ini baru dibuat dan belum disambungin ke node lain
      P->next = Nil;
   }

   // terakhir, balikin alamat node yang baru dibuat
   // alamat ini nanti dikasih ke fungsi lain (kaya insertFirst)
   // supaya bisa disambungin ke list
   return P;
}

// fungsi untuk menghapus node
void dealokasi(address P) {
   delete P;
}

// fungsi untuk menampilkan seluruh isi list dari awal sampai akhir
void printInfo(List L) {
   // mulai dari node pertama, yaitu L.first
   address P = L.first;

   // kalo first = Nil, berarti list kosong
   if (P == Nil) {
      cout << "list kosong, ga ada data" << endl;
      return;
   }

   // kalo ga kosong, tampilkan semua datanya
   cout << "isi list: ";
   while (P != Nil)
   {
      cout << P->info;

      // biar lebih jelas, kasih tanda panah antar node
      if (P->next != Nil)
      {
         cout << " -> ";
      }

      // pindah ke node berikutnya
      P = P->next;
   }

   // kasih tanda akhir biar tahu kalo list udah selesai
   cout << " -> NULL" << endl;
}

// fungsi buat nambah node baru di bagian paling depan
void insertFirst(List &L, address P) {
   // node baru (P) diarahkan ke node pertama sebelumnya
   // jadi P->next diisi alamat node pertama lama
   // misalnya sebelumnya first = A, sekarang P->next = A
   P->next = L.first;

   // lalu first diarahkan ke node baru (P)
   // artinya node baru ini sekarang jadi node paling depan
   L.first = P;
}

// fungsi untuk mencari node
address findElm(List L, infotype x) {
   // mulai dari node pertama
   address P = L.first;

   // selama masih ada node (belum NULL)
   while (P != Nil)
   {
      // kalo data di node itu sama dengan yang dicari, berarti itu datanya
      if (P->info == x)
      {
         return P;
      }

      // kalo belum ketemu, pindah ke node berikutnya
      P = P->next;
   }

   // kalo udah nyampe ujung tapi belum ketemu, balikin Nil (NULL)
   return Nil;
}

// fungsi buat ngitung jumlah total semua data di list
int sumList(List L) {
   // mulai dari node pertama
   address P = L.first;

   // siapkan variabel buat nyimpen hasil totalnya
   int total = 0;

   // kalo list kosong, langsung balikin 0
   if (P == Nil) {
      return 0;
   }

   // selama masih ada node
   while (P != Nil)
   {
      // tambahkan data dari node itu ke total
      total = total + P->info;

      // pindah ke node berikutnya
      P = P->next;
   }

   // setelah selesai, balikin totalnya
   return total;
}
