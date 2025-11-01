<h1 align="center">Laporan Praktikum Modul 7<br>STACK</h1>
<p align="center">'Aarif Rahmaan Jalaluddin Faqiih - 103112430182</p>

## Dasar Teori

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

---

## Guided

### Soal 1

program untuk push, pop, dan menampilkan isi stack.

```cpp
#include <iostream>
using namespace std;

// stack itu kaya box yang ditumpuk ke atas
// stack itu linked list tapi cuma bisa diakses dari belakang
// maksudnya gini, misal ada stack kaya gini
// | 30 | <- top
// | 20 |
// | 10 |
// nah, kita cuma bisa nambahin di atas (push) atau ngambil dari atas (pop)
// ngga bisa ngambil di tengah atau di bawah
// bayangin aja tumpukan box, kalo diambil bagian tengah atau bawah pasti yang diatas bakal jatuh, makannya cuma diakses dari atas
struct Node {
   int   data;
   Node* next;
};

// cek dulu stacknya kosong ngga?
// kalo kosong, topnya nullptr
bool apakah_kosong(Node *top) {
   return top == nullptr;
};

// nambahin data ke atas stack
void push(Node*& top, int data) {
   Node* node_baru = new Node();
   node_baru->data = data;
   node_baru->next = top;
   top = node_baru;
};

// ngambil data dari atas stack
int pop(Node*& top) {
    // kalo stacknya kosong, ngga bisa di-pop
   if (apakah_kosong(top)) {
      cout << "stack kosong, apa yang mau di-pop?" << endl;
      return -1;
   }

   int data_dikeluarkan = top->data;
   // temp itu tempat penyimpanan node sementara untuk dihapus nanti
   // anggap aja kaya buat nandain yang mau dihapus
   Node* temp = top;
   // terus topnya digeser ke node berikutnya
   top = top->next;
   // nah baru deh node yang paling atas (yang tadi di temp) dihapus
   delete temp;
   return data_dikeluarkan;
};

// nampilin isi stack dari atas ke bawah
void tampilkan_stack(Node* top) {
   // kalo stacknya kosong, ngga ada yang ditampilin
   if (apakah_kosong(top)) {
    cout << "stack kosong, apa yang mau di-pop?" << endl;
      return;
   };

   cout << "TOP -> ";
   Node* temp = top;

   while (temp != nullptr) {
      cout << temp->data;
      if (temp->next != nullptr) cout << " -> ";
      temp = temp->next;
   }
   cout << endl;
};

int main() {
   Node* stack = nullptr;

   push(stack, 10);
   push(stack, 20);
   push(stack, 30);

   cout << "isi stacknya: " << endl;
   tampilkan_stack(stack);

   cout << "mengeluarkan data (pop): " << pop(stack) << endl;

   cout << "sisa stack sekarang: " << endl;
   tampilkan_stack(stack);

   return 0;
}
```

> Output
> 
> ![Screenshot Output Guided 1](output/ss_guided_1.jpg)

program ini tujuannya untuk menampilkan cara kerja struktur data stack menggunakan konsep linked list, di mana stack ini hanya bisa diakses dari bagian atas saja. maksudnya, kita hanya bisa menambah data di atas (push) dan mengambil data dari atas (pop), tidak bisa langsung mengambil data di tengah atau di bawah.

di awal program, ada struct Node yang berfungsi sebagai komponen dasar dari stack. setiap Node menyimpan dua hal, yaitu data bertipe integer dan pointer next yang menunjuk ke node berikutnya. pointer ini yang membuat node-node saling terhubung membentuk linked list.

setelah itu ada fungsi apakah_kosong yang gunanya untuk mengecek apakah stack masih kosong atau tidak. kalau top bernilai nullptr, artinya belum ada node sama sekali, jadi stack masih kosong.

fungsi push digunakan untuk menambahkan data ke atas stack. caranya adalah membuat node baru, lalu isi data di dalam node tersebut dengan nilai yang dimasukkan, kemudian hubungkan node baru ini ke node paling atas sebelumnya dengan cara node_baru->next = top, dan terakhir ubah top agar menunjuk ke node baru ini. jadi, node baru otomatis menjadi data paling atas di stack.

fungsi pop digunakan untuk mengeluarkan data dari atas stack. pertama, dicek dulu apakah stack kosong menggunakan fungsi apakah_kosong, kalau kosong maka tidak bisa dilakukan pop dan program akan menampilkan pesan. kalau tidak kosong, data paling atas disimpan sementara ke variabel data_dikeluarkan. kemudian pointer top digeser ke node berikutnya agar node paling atas bisa dilepas, lalu node lama dihapus dengan delete. fungsi ini akan mengembalikan nilai data yang sudah dikeluarkan tadi.

fungsi tampilkan_stack digunakan untuk menampilkan isi stack dari atas ke bawah. kalau stack kosong, program akan menampilkan pesan bahwa stack kosong. kalau tidak, program akan menelusuri node dari top sampai ke node terakhir dengan menggunakan pointer sementara temp, dan menampilkan setiap data yang ada di dalamnya secara berurutan dari atas ke bawah.

di dalam fungsi main, pertama-tama dibuat pointer stack yang diinisialisasi dengan nullptr karena belum ada data sama sekali. kemudian dilakukan beberapa operasi push untuk menambahkan data 10, 20, dan 30 secara berurutan. setelah itu, program menampilkan isi stack menggunakan fungsi tampilkan_stack. lalu dilakukan operasi pop untuk mengeluarkan satu data dari atas stack, dan hasilnya ditampilkan. terakhir, program menampilkan lagi isi stack setelah satu data teratas dikeluarkan.

---

## Unguided

### Soal 1

XXXXXXXXXXXXXXXXXXXXXXXX

```cpp
#include <iostream>
```

> Output
> 
> ![Screenshot Output Unguided 1](output/ss_unguided_1.jpg)

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

---

### Soal 2

XXXXXXXXXXXXXXXXXXXXXXXX

```cpp
#include <iostream>
```

> Output
> 
> ![Screenshot Output Guided 2](output/ss_unguided_2.jpg)

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

---

### Soal 3

XXXXXXXXXXXXXXXXXXXXXXXX

```cpp
#include <iostream>
```

> Output
> 
> ![Screenshot Output Guided 3](output/ss_unguided_3.jpg)

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

---

### Soal 4

XXXXXXXXXXXXXXXXXXXXXXXX

```cpp
#include <iostream>
```

> Output
> 
> ![Screenshot Output Guided 4](output/ss_unguided_4.jpg)

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

---

### Soal 5

XXXXXXXXXXXXXXXXXXXXXXXX

```cpp
#include <iostream>
```

> Output
> 
> ![Screenshot Output Guided 5](output/ss_unguided_5.jpg)

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

---

### Soal 6

XXXXXXXXXXXXXXXXXXXXXXXX

```cpp
#include <iostream>
```

> Output
> 
> ![Screenshot Output Guided 6](output/ss_unguided_6.jpg)

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

---

## Referensi

1. XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
