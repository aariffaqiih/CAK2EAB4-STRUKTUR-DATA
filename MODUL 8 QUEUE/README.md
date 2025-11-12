<h1 align="center">Laporan Praktikum Modul 8 <br> QUEUE</h1>
<p align="center">'Aarif Rahmaan Jalaluddin Faqiih - 103112430182</p>

## Dasar Teori

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

---

## Guided

### Soal 1

```cpp
#include <iostream>
using namespace std;

// ukuran maksimal queue
#define MAX 5

// struktur queue
struct Queue {
   // datanya pake array yaa, bukan linked list
   int data[MAX];
   int head;
   int tail;
};

// membuat antrian kosong
void buat_queue (Queue &Q) {
   Q.head = -1;
   Q.tail = -1;
   // kenapa head dan tail-nya -1?
   // karena index array mulai dari 0
}

// cek queueu-nya kosong ngga?
bool cek_kosong (Queue Q) {
   return (Q.head == -1 && Q.tail == -1);
}

// cek queue-nya penuh ngga?
bool cek_penuh (Queue Q) {
   return (Q.tail == MAX - 1);
}

// menampilkan isi queue
void print_queue (Queue Q) {
   if (cek_kosong(Q)) {
      cout << "queue kosong" << endl;
   } else {
      cout << "queue : ";
      for (int i = Q.head; i <= Q.tail; i++) {
         cout << Q.data[i] << " -> ";
      }
      cout << endl;
   }
}

// menambahkan elemen (enqueue)
void enqueue (Queue &Q, int x) {
// x itu data yang mau dimasukin ke dalam queue
// kenapa namanya x? itu sih terserah, mau pake nama apa aja boleh
// mau dinamain ayam_bakar_haji_ismail juga gapapa
   if (cek_penuh(Q)) {
      cout << "queue sudah penuh, tidak bisa menambah data" << endl;
   } else {
      if (cek_kosong(Q)) {
         Q.head = Q.tail = 0;
      } else {
         Q.tail++;
      }

      Q.data[Q.tail] = x;
      cout << "menambahkan " << x << " ke dalam queue" << endl;
   }
}

// menghapus elemen (dequeue)
void dequeue (Queue &Q) {
   if (cek_kosong(Q)) {
      cout << "queue kosong, tidak ada yang bisa dihapus" << endl;
   } else {
      cout << "dequeue " << Q.data[Q.head] << " dari dalam queue" << endl;

      // jika hanya ada 1 elemen
      if (Q.head == Q.tail) {
         Q.head = Q.tail = -1;
      } else {
         // geser semua elemen ke depan/kiri
         // biar tempat kosong di depan dipenuhin
         // dan tempat di belakang bisa dikosongin
         for (int i = Q.head; i < Q.tail; i++) {
            Q.data[i] = Q.data[i + 1];
         }

         Q.tail--;
      }
   }
}

// eksekutor
int main() {
   Queue Q;
   buat_queue(Q);

   enqueue(Q, 5);
   enqueue(Q, 2);
   enqueue(Q, 7);
   print_queue(Q);

   dequeue(Q);
   print_queue(Q);

   enqueue(Q, 4);
   enqueue(Q, 9);
   print_queue(Q);

   dequeue(Q);
   dequeue(Q);
   print_queue(Q);

   return 0;
}
```

> Output
> 
> ![Screenshot Output Guided 1](output/ss_guided_1.jpg)

program ini bertujuan untuk mempelajari struktur data queue atau antrian menggunakan array.

di awal program, terdapat struktur bernama Queue yang terdiri dari array data berukuran maksimal 5 elemen, serta dua variabel yaitu head dan tail yang berfungsi sebagai penanda posisi depan dan belakang antrian.

prosedur buat_queue digunakan untuk menginisialisasi queue kosong, dengan cara mengatur nilai head dan tail menjadi -1. kenapa -1? karena index array dimulai dari 0.

fungsi cek_kosong digunakan untuk memeriksa apakah queue masih kosong atau tidak, caranya adalah dengan mengecek apakah nilai head dan tail sama-sama -1. jika iya, berarti queue masih kosong. sebaliknya, fungsi cek_penuh digunakan untuk memeriksa apakah queue sudah penuh atau belum, yaitu dengan mengecek apakah tail sudah mencapai index terakhir dari array (MAX - 1).

fungsi print_queue digunakan untuk menampilkan isi dari queue. kalau queue-nya kosong, maka akan muncul tulisan “queue kosong”. tapi kalau tidak kosong, maka program akan menampilkan isi queue dari index head sampai tail.

fungsi enqueue digunakan untuk menambahkan data ke dalam queue. parameter x adalah data yang mau dimasukkan. kalau queue sudah penuh, maka program akan menampilkan pesan bahwa data tidak bisa ditambahkan. tapi kalau masih ada ruang, maka data baru akan dimasukkan ke posisi tail. jika queue masih kosong, head dan tail di-set ke 0 dulu, tapi kalau sudah ada data sebelumnya, maka tail akan digeser sebelum data baru dimasukkan.

fungsi dequeue digunakan untuk menghapus data dari queue, yaitu data yang berada di posisi paling depan (head). kalau queue kosong, maka akan muncul pesan bahwa tidak ada data yang bisa dihapus. kalau hanya ada satu data, maka setelah dihapus queue akan dikosongkan dengan cara mengatur head dan tail menjadi -1. tapi kalau lebih dari satu data, maka semua elemen akan digeser satu posisi ke depan supaya tidak ada celah kosong di depan, dan nilai tail dikurangi satu agar posisi belakang ikut bergeser.

fungsi main bertugas untuk mengeksekusi semua proses di atas. pertama-tama program membuat queue kosong, lalu menambahkan beberapa data menggunakan enqueue, menampilkan isi queue, menghapus beberapa data dengan dequeue, dan menampilkan hasil akhirnya setelah setiap operasi.

---

## Unguided

### Soal 1 : Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file “queue.h”:

<pre>
type infotype : integer
type Queue : <
  info : array [5] of infotype
  head, tail : integer
>
procedure createQueue (input/output Q : Queue)
function isEmptyQueue (Q : Queue) -> boolean
function isFullQueue (Q : Queue) -> boolean
procedure enqueue (input/output Q : Queue, input x : infotype)
function dequeue (input/output Q : Queue) -> infotype
procedure printInfo (input Q : Queue)
</pre>

### Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue  Alternatif 1 (head diam, tail bergerak).

<pre>
int main() {
  cout << "Hello World" << endl;
  Queue Q;
  createQueue(Q);

  cout << "----------------------" << endl;
  cout << " H - T \t | Queue info" << endl;
  cout << "----------------------" << endl;

  printInfo(Q);

  enqueue(Q, 5);  printInfo(Q);
  enqueue(Q, 2);  printInfo(Q);
  enqueue(Q, 7);  printInfo(Q);
  dequeue(Q);     printInfo(Q);
  enqueue(Q, 4);  printInfo(Q);
  dequeue(Q);     printInfo(Q);
  dequeue(Q);     printInfo(Q);

  return 0;
}
</pre>

```cpp
#include <iostream>
```

> Output
> 
> ![Screenshot Output Unguided 1](output/ss_unguided_1.jpg)

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

---

### Soal 2 : Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue  Alternatif 2 (head bergerak, tail bergerak).

```cpp
#include <iostream>
```

> Output
> 
> ![Screenshot Output Guided 2](output/ss_unguided_2.jpg)

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

---

### Soal 3 : Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue  Alternatif 3 (head dan tail berputar).

```cpp
#include <iostream>
```

> Output
> 
> ![Screenshot Output Guided 2](output/ss_unguided_3.jpg)

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

---

## Kesimpulan

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

---

## Referensi

1. xxx
2. xxx
