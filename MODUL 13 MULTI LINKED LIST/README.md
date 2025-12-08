<h1 align="center">Laporan Praktikum Modul 13 <br> MULTI LINKED LIST</h1>
<p align="center">'Aarif Rahmaan Jalaluddin Faqiih - 103112430182</p>

## Dasar Teori

---

## Guided

### Soal 1

```cpp
#include <iostream>
#include <string>
using namespace std;

struct child_node
{
   string info;
   child_node* next;
};

struct parent_node
{
   string info;
   child_node* child_head;
   parent_node* next;
};

parent_node *create_parent(string info)
{
   parent_node* new_node = new parent_node;
   new_node->info = info;
   new_node->child_head = NULL;
   new_node->next = NULL;
   return new_node;
};

child_node *create_child(string info)
{
   child_node* new_node = new child_node;
   new_node->info = info;
   new_node->next = NULL;
   return new_node;
};

void insert_parent(parent_node *&head, string info)
{
   parent_node* new_node = create_parent(info);
   if (head == NULL)
   {
      head = new_node;
   }
   else
   {
      parent_node* temporary = head;
      while (temporary->next != NULL)
      {
         temporary = temporary->next;
      }
      temporary->next = new_node;
   }
}

void insert_child(parent_node *head, string parent_info, string child_info)
{
   parent_node *parent_temp = head;
   while (parent_temp != NULL && parent_temp->info != parent_info)
   {
      parent_temp = parent_temp->next;
   }
   if (parent_temp != NULL)
   {
      child_node *new_child = create_child(child_info);
      if (parent_temp->child_head == NULL)
      {
         parent_temp->child_head = new_child;
      }
      else
      {
         child_node *child_temp = parent_temp->child_head;
         while (child_temp->next != NULL)
         {
            child_temp = child_temp->next;
         }
         child_temp->next = new_child;
      }
   }
}

void print_all(parent_node *head)
{
   parent_node *parent_temp = head;
   while (parent_temp != NULL)
   {
      cout << parent_temp->info;
      child_node *child_temp = parent_temp->child_head;
      if (child_temp != NULL)
      {
         while (child_temp != NULL)
         {
            cout << " -> " << child_temp->info;
            child_temp = child_temp->next;
         }
      }
      cout << endl;
      parent_temp = parent_temp->next;
   }
}

int main()
{
   parent_node *list = NULL;

   insert_parent(list, "parent node 1");
   insert_parent(list, "parent node 2");

   print_all(list);
   cout << "\n";

   insert_child(list, "parent node 1", "child node a");
   insert_child(list, "parent node 1", "child node b");
   insert_child(list, "parent node 2", "child node c");

   print_all(list);

   return 0;
}
```

> Output
> 
> ![](output/ss_guided_1.jpeg)

program ini bertujuan untuk menampilkan hubungan antara parent node dan child node menggunakan struktur linked list bersarang. setiap parent bisa punya beberapa child, dan setiap child terhubung dengan child berikutnya melalui pointer next.

di awal program ada dua struct utama yaitu parent_node dan child_node. struct parent_node menyimpan info dari parent, lalu pointer child_head yang menunjuk ke child pertama yang dimiliki parent tersebut, dan pointer next untuk menghubungkan parent satu dengan parent lainnya. struct child_node menyimpan info child dan pointer next untuk menghubungkan child berikutnya dalam satu parent.

setelah itu ada dua fungsi pembuat node yaitu create_parent dan create_child. dua fungsi ini bekerja dengan cara membuat node baru di memori dengan operator new, kemudian mengisi field info sesuai input dan mengatur pointer next menjadi NULL karena node baru belum terhubung ke node lain.

fungsi insert_parent bekerja dengan cara menambahkan parent baru ke akhir daftar parent. jika head masih kosong maka parent pertama langsung menjadi head. tetapi jika sudah ada parent lain, maka program melakukan traversal dengan temporary sampai menemukan parent terakhir, lalu menghubungkan parent baru ke bagian akhir melalui temporary->next.

fungsi insert_child bekerja dengan cara mencari parent tertentu berdasarkan info. pertama-tama dilakukan traversal pada list parent sampai menemukan parent yang info-nya sama dengan parent_info. jika parent ditemukan maka dibuat child baru dengan fungsi create_child. jika parent tersebut belum punya child sama sekali maka child baru langsung menjadi child_head. tetapi jika sudah ada child sebelumnya maka traversal dilakukan dengan child_temp sampai child terakhir, lalu child baru ditempatkan di bagian belakang child list.

fungsi print_all bekerja dengan cara melakukan traversal pada seluruh parent. setiap parent dicetak info-nya terlebih dahulu. setelah itu dicek apakah parent tersebut punya child. jika punya maka dilakukan traversal untuk mencetak semua child dengan format parent -> child1 -> child2 dan seterusnya. setelah selesai mencetak child, berpindah ke parent berikutnya sampai semua parent selesai dicetak.

---

## Unguided

### Soal 1 : buat  multilist.cpp  untuk  implementasi  semua  fungsi  pada multilist.h. Buat main.cpp untuk pemanggilan fungsi-fungsi tersebut.

<code>multilist.h</code>

```cpp
#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED
#define Nil NULL

typedef bool boolean;
typedef int infotypeanak;
typedef int infotypeinduk;
typedef struct elemen_list_induk *address;
typedef struct elemen_list_anak *address_anak;

struct elemen_list_anak{
   infotypeanak info;
   address_anak next;
   address_anak prev;
};

struct listanak {
   address_anak first;
   address_anak last;
};

struct elemen_list_induk{
   infotypeanak info;
   listanak lanak;
   address next;
   address prev;
};

struct listinduk {
   address first;
   address last;
};

boolean ListEmpty(listinduk L);
boolean ListEmptyAnak(listanak L);

void CreateList(listinduk &L);
void CreateListAnak(listanak &L);

address alokasi(infotypeinduk P);
address_anak alokasiAnak(infotypeanak P);

void dealokasi(address P);
void dealokasiAnak(address_anak P);

address findElm(listinduk L, infotypeinduk X);
address_anak findElm(listanak Lanak, infotypeanak X);

boolean fFindElm(listinduk L, address P);
boolean fFindElmanak(listanak Lanak, address_anak P);

address findBefore(listinduk L, address P);
address_anak findBeforeAnak(listanak Lanak, infotypeinduk X, address_anak P);

void insertFirst(listinduk &L, address P);
void insertAfter(listinduk &L, address P, address Prec);
void insertLast(listinduk &L, address P);

void insertFirstAnak(listanak &L, address_anak P);
void insertAfterAnak(listanak &L, address_anak P, address_anak Prec);
void insertLastAnak(listanak &L, address_anak P);

void delFirst(listinduk &L, address &P);
void delLast(listinduk &L, address &P);
void delAfter(listinduk &L, address &P, address Prec);
void delP(listinduk &L, infotypeinduk X);

void delFirstAnak(listanak &L, address_anak &P);
void delLastAnak(listanak &L, address_anak &P);
void delAfterAnak(listanak &L, address_anak &P, address_anak Prec);
void delPAnak(listanak &L, infotypeanak X);

void printInfo(listinduk L);
int nbList(listinduk L);

void printInfoAnak(listanak Lanak);
int nbListAnak(listanak Lanak);

void delAll(listinduk &L);

#endif
```

<code>multilist.cpp</code>

```cpp
#include <iostream>
using namespace std;
#include "multilist.h"

boolean ListEmpty(listinduk L) {
   return (L.first == Nil && L.last == Nil);
}

boolean ListEmptyAnak(listanak L) {
   return (L.first == Nil && L.last == Nil);
}

void CreateList(listinduk &L) {
   L.first = Nil;
   L.last = Nil;
}

void CreateListAnak(listanak &L) {
   L.first = Nil;
   L.last = Nil;
}

address alokasi(infotypeinduk P) {
   address Q = new elemen_list_induk;
   if (Q != Nil) {
      Q->info = P;
      Q->lanak.first = Nil;
      Q->lanak.last = Nil;
      Q->next = Nil;
      Q->prev = Nil;
   }
   return Q;
}

address_anak alokasiAnak(infotypeanak P) {
   address_anak Q = new elemen_list_anak;
   if (Q != Nil) {
      Q->info = P;
      Q->next = Nil;
      Q->prev = Nil;
   }
   return Q;
}

void dealokasi(address P) {
   delete P;
}

void dealokasiAnak(address_anak P) {
   delete P;
}

address findElm(listinduk L, infotypeinduk X) {
   address P = L.first;
   while (P != Nil && P->info != X) {
      P = P->next;
   }
   return P;
}

address_anak findElm(listanak L, infotypeanak X) {
   address_anak P = L.first;
   while (P != Nil && P->info != X) {
      P = P->next;
   }
   return P;
}

boolean fFindElm(listinduk L, address P) {
   address Q = L.first;
   while (Q != Nil) {
      if (Q == P) return true;
      Q = Q->next;
   }
   return false;
}

boolean fFindElmanak(listanak L, address_anak P) {
   address_anak Q = L.first;
   while (Q != Nil) {
      if (Q == P) return true;
      Q = Q->next;
   }
   return false;
}

address findBefore(listinduk L, address P) {
   if (P == L.first) return Nil;
   return P->prev;
}

address_anak findBeforeAnak(listanak L, infotypeinduk X, address_anak P) {
   if (P == L.first) return Nil;
   return P->prev;
}

void insertFirst(listinduk &L, address P) {
   if (ListEmpty(L)) {
      L.first = P;
      L.last = P;
   } else {
      P->next = L.first;
      L.first->prev = P;
      L.first = P;
   }
}

void insertAfter(listinduk &L, address P, address Prec) {
   P->next = Prec->next;
   P->prev = Prec;
   if (Prec->next != Nil)
      Prec->next->prev = P;
   else
      L.last = P;
   Prec->next = P;
}

void insertLast(listinduk &L, address P) {
   if (ListEmpty(L)) {
      L.first = P;
      L.last = P;
   } else {
      L.last->next = P;
      P->prev = L.last;
      L.last = P;
   }
}

void insertFirstAnak(listanak &L, address_anak P) {
   if (ListEmptyAnak(L)) {
      L.first = P;
      L.last = P;
   } else {
      P->next = L.first;
      L.first->prev = P;
      L.first = P;
   }
}

void insertAfterAnak(listanak &L, address_anak P, address_anak Prec) {
   P->next = Prec->next;
   P->prev = Prec;
   if (Prec->next != Nil)
      Prec->next->prev = P;
   else
      L.last = P;
   Prec->next = P;
}

void insertLastAnak(listanak &L, address_anak P) {
   if (ListEmptyAnak(L)) {
      L.first = P;
      L.last = P;
   } else {
      L.last->next = P;
      P->prev = L.last;
      L.last = P;
   }
}

void delFirst(listinduk &L, address &P) {
   P = L.first;
   if (L.first == L.last) {
      L.first = Nil;
      L.last = Nil;
   } else {
      L.first = P->next;
      L.first->prev = Nil;
      P->next = Nil;
   }
}

void delLast(listinduk &L, address &P) {
   P = L.last;
   if (L.first == L.last) {
      L.first = Nil;
      L.last = Nil;
   } else {
      L.last = P->prev;
      L.last->next = Nil;
      P->prev = Nil;
   }
}

void delAfter(listinduk &L, address &P, address Prec) {
   P = Prec->next;
   if (P != Nil) {
      Prec->next = P->next;
      if (P->next != Nil)
         P->next->prev = Prec;
      else
         L.last = Prec;
      P->next = Nil;
      P->prev = Nil;
   }
}

void delP(listinduk &L, infotypeinduk X) {
   address P = findElm(L, X);
   if (P != Nil) {
      if (P == L.first)
         delFirst(L, P);
      else if (P == L.last)
         delLast(L, P);
      else {
         P->prev->next = P->next;
         P->next->prev = P->prev;
         P->next = Nil;
         P->prev = Nil;
      }
      dealokasi(P);
   }
}

void delFirstAnak(listanak &L, address_anak &P) {
   P = L.first;
   if (L.first == L.last) {
      L.first = Nil;
      L.last = Nil;
   } else {
      L.first = P->next;
      L.first->prev = Nil;
      P->next = Nil;
   }
}

void delLastAnak(listanak &L, address_anak &P) {
   P = L.last;
   if (L.first == L.last) {
      L.first = Nil;
      L.last = Nil;
   } else {
      L.last = P->prev;
      L.last->next = Nil;
      P->prev = Nil;
   }
}

void delAfterAnak(listanak &L, address_anak &P, address_anak Prec) {
   P = Prec->next;
   if (P != Nil) {
      Prec->next = P->next;
      if (P->next != Nil)
         P->next->prev = Prec;
      else
         L.last = Prec;
      P->next = Nil;
      P->prev = Nil;
   }
}

void delPAnak(listanak &L, infotypeanak X) {
   address_anak P = findElm(L, X);
   if (P != Nil) {
      if (P == L.first)
         delFirstAnak(L, P);
      else if (P == L.last)
         delLastAnak(L, P);
      else {
         P->prev->next = P->next;
         P->next->prev = P->prev;
         P->next = Nil;
         P->prev = Nil;
      }
      dealokasiAnak(P);
   }
}

void printInfo(listinduk L) {
   address P = L.first;
   while (P != Nil) {
       cout << P->info << " ";
       P = P->next;
   }
   cout << endl;
}

int nbList(listinduk L) {
   int n = 0;
   address P = L.first;
   while (P != Nil) {
       n++;
       P = P->next;
   }
   return n;
}

void printInfoAnak(listanak L) {
   address_anak P = L.first;
   while (P != Nil) {
      cout << P->info << " ";
      P = P->next;
   }
   cout << endl;
}

int nbListAnak(listanak L) {
   int n = 0;
   address_anak P = L.first;
   while (P != Nil) {
      n++;
      P = P->next;
   }
   return n;
}

void delAll(listinduk &L) {
   address P;
   while (!ListEmpty(L)) {
      delFirst(L, P);
      address_anak C;
      while (!ListEmptyAnak(P->lanak)) {
         delFirstAnak(P->lanak, C);
         dealokasiAnak(C);
      }
      dealokasi(P);
   }
}
```

<code>main.cpp</code>

```cpp
#include <iostream>
using namespace std;
#include "multilist.h"

int main() {
   listinduk L;
   CreateList(L);

   cout << "=== test insert induk ===" << endl;
   insertLast(L, alokasi(10));
   insertLast(L, alokasi(20));
   insertLast(L, alokasi(30));

   cout << "isi list induk: ";
   printInfo(L);

   cout << "jumlah induk: " << nbList(L) << endl << endl;

   cout << "=== test insert anak ===" << endl;
   address P = findElm(L, 20);
   if (P != Nil) {
      insertLastAnak(P->lanak, alokasiAnak(201));
      insertLastAnak(P->lanak, alokasiAnak(202));
      insertLastAnak(P->lanak, alokasiAnak(203));
   }

   cout << "anak dari induk 20: ";
   printInfoAnak(P->lanak);

   cout << "jumlah anak induk 20: " << nbListAnak(P->lanak) << endl << endl;

   cout << "=== test delete anak ===" << endl;
   delPAnak(P->lanak, 202);

   cout << "anak dari induk 20 setelah hapus 202: ";
   printInfoAnak(P->lanak);

   cout << endl;

   cout << "=== TEST DELETE INDUK ===" << endl;
   delP(L, 20);

   cout << "isi list induk setelah hapus induk 20: ";
   printInfo(L);

   cout << endl;

   cout << "=== test insert first dan after ===" << endl;
   insertFirst(L, alokasi(5));
   address Q = findElm(L, 10);
   if (Q != Nil) {
      insertAfter(L, alokasi(15), Q);
   }

   cout << "isi induk sekarang: ";
   printInfo(L);

   cout << endl;

   cout << "=== test delete all ===" << endl;
   delAll(L);

   cout << "isi list induk setelah delete all: ";
   printInfo(L);

   return 0;
}
```

> Output
> 
> ![](output/ss_unguided_1.jpeg)

program ini bertujuan untuk mengelola struktur data multilist, yaitu sebuah list induk yang setiap elemennya punya list anak sendiri. jadi ada dua level list, list utama atau induknya, dan list di dalam elemen induk yaitu list anak. struktur data seperti ini biasanya dipakai kalau kita butuh hubungan satu ke banyak, misalnya kategori dan item, atau kelas dan mahasiswa.

di awal program ada beberapa tipe data yang dideklarasikan, yaitu elemen_list_induk dan elemen_list_anak. elemen_list_induk berisi info induk, pointer next dan prev untuk membentuk double linked list, dan juga sebuah listanak yang menyimpan pointer ke anak-anaknya. sedangkan elemen_list_anak hanya berisi info anak dan pointer next dan prev untuk membentuk double linked list juga. kemudian ada struct listinduk dan listanak yang masing-masing menyimpan pointer first dan last.

setelah itu ada fungsi-fungsi dasar untuk membuat list, yaitu CreateList dan CreateListAnak. dua fungsi ini bertujuan untuk mengosongkan list dengan cara mengisi first dan last menjadi Nil. kemudian ada fungsi ListEmpty dan ListEmptyAnak untuk mengecek apakah suatu list kosong atau tidak, caranya adalah memastikan first dan last bernilai Nil.

kemudian fungsi alokasi dan alokasiAnak berguna untuk membuat node baru baik untuk induk maupun anak. saat elemen induk dibuat, info diisi dengan parameter yang diberikan, lanak atau list anak diset kosong, dan semua pointer next prev diset Nil. hal yang sama juga terjadi pada alokasiAnak, hanya saja tidak ada list anak di dalamnya. kalau node berhasil dibuat maka pointer dikembalikan.

ada juga fungsi dealokasi dan dealokasiAnak yang bertugas menghapus node dari memori. setelah itu terdapat fungsi findElm untuk mencari elemen induk ataupun anak. cara kerjanya adalah melakukan traversal dari first hingga menemukan node dengan info sesuai parameter. kalau ketemu dikembalikan, kalau tidak sampai habis akan mengembalikan Nil.

fungsi insertFirst, insertLast, dan insertAfter berguna untuk memasukkan node induk ke posisi pertama, terakhir, atau setelah elemen tertentu. cara kerjanya adalah mengubah pointer next dan prev agar elemen baru tersambung dengan benar. begitu juga dengan insertFirstAnak, insertLastAnak, dan insertAfterAnak yang bekerja untuk list anak. prinsipnya sama, hanya list yang berbeda.

fungsi delFirst, delLast, dan delAfter bekerja untuk menghapus node induk dari posisi pertama, terakhir, atau setelah node tertentu. cara kerjanya adalah memutus pointer dari node yang dihapus, menyambungkan pointer sekitar, dan mengembalikan node yang dihapus melalui parameter. hal yang sama juga dilakukan pada delFirstAnak, delLastAnak, dan delAfterAnak untuk list anak.

fungsi delP dan delPAnak bekerja untuk menghapus elemen induk atau anak berdasarkan nilai info. caranya adalah mencari dulu elemennya memakai findElm, lalu kalau ketemu fungsi delete yang sesuai dipanggil, terakhir node tersebut didealokasi supaya memori tidak bocor.

kemudian ada fungsi printInfo dan printInfoAnak untuk mencetak isi list induk dan isi list anak. keduanya bekerja dengan traversal dari first hingga pointer Nil sambil mencetak nilai info setiap node. fungsi nbList dan nbListAnak melakukan penghitungan jumlah elemen dalam list induk maupun list anak dengan prinsip yang sama.

terakhir ada fungsi delAll yang bertugas menghapus seluruh isi list induk beserta semua anaknya. cara kerjanya adalah menghapus elemen induk satu per satu memakai delFirst, kemudian sebelum induk itu didealokasi, seluruh anak di dalam list anaknya juga dihapus memakai delFirstAnak. dengan cara itu semua memori baik induk maupun anak benar-benar dibersihkan.

---

### Soal 2 : Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue  Alternatif 2 (head bergerak, tail bergerak).

<code>queue.h</code>

```cpp
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;
#define MAX 5

struct Queue {
   infotype info[MAX];
   int head;
   int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

<code>queue.cpp</code>

```cpp
#include "queue.h"

void createQueue(Queue &Q) {
   Q.head = -1;
   Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
   return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
   return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, infotype x) {
   if (isFullQueue(Q) && Q.head > 0) {
      // geser semua elemen ke depan
      int j = 0;
      for (int i = Q.head; i <= Q.tail; i++) {
         Q.info[j] = Q.info[i];
         j++;
      }

      Q.tail = j - 1;
      Q.head = 0;
   }

   if (isFullQueue(Q)) {
      cout << "queue penuh (beneran penuh), ga bisa nambah data" << endl;
      return;
   }

   if (isEmptyQueue(Q)) {
      Q.head = 0;
      Q.tail = 0;
      Q.info[Q.tail] = x;
   } else {
      Q.tail++;
      Q.info[Q.tail] = x;
   }
}

infotype dequeue(Queue &Q) {
   if (isEmptyQueue(Q)) {
      cout << "queue kosong, ga ada yang bisa dihapus" << endl;
      return -1;
   }

   infotype hasil = Q.info[Q.head];

   if (Q.head == Q.tail) {
      Q.head = -1;
      Q.tail = -1;
   } else {
      Q.head++;
   }

   return hasil;
}

void printInfo(Queue Q) {
   if (isEmptyQueue(Q)) {
      cout << Q.head << "  - " << Q.tail << "  | empty queue" << endl;
   } else {
      cout << " " << Q.head << "  -  " << Q.tail << "  | ";
      for (int i = Q.head; i <= Q.tail; i++) {
         cout << Q.info[i] << " ";
      }
      cout << endl;
   }
}
```

<code>main.cpp</code>

```cpp
#include "queue.h"

int main() {
   cout << "Hello world!" << endl;

   cout<<"-----------------------"<<endl;
   cout<<" H  -  T  | Queue Info"<<endl;
   cout<<"-----------------------"<<endl;

   Queue Q;
   createQueue(Q);

   printInfo(Q);
   enqueue(Q,5); printInfo(Q);
   enqueue(Q,2); printInfo(Q);
   enqueue(Q,7); printInfo(Q);
   dequeue(Q); printInfo(Q);
   enqueue(Q,4); printInfo(Q);
   dequeue(Q); printInfo(Q);
   dequeue(Q); printInfo(Q);

   cout<<"-1  - -1  | empty queue"<<endl;

   return 0;
}
```

> Output
> 
> ![](output/ss_unguided_2.jpeg)

program ini bertujuan untuk menampilkan proses penambahan dan penghapusan data pada sebuah queue dengan menggunakan alternatif 2, yaitu queue dengan head dan tail yang bergerak tanpa berputar, dan hanya melakukan pergeseran elemen jika tail sudah mencapai index paling akhir pada array.

fungsi enqueue bekerja dengan cara menambahkan elemen baru x ke dalam queue. pertama fungsi ini mengecek apakah tail sudah berada di ujung array tetapi head tidak berada di 0. kalau kondisi itu terjadi berarti masih ada ruang kosong di bagian depan array, jadi perlu dilakukan pergeseran elemen. pergeseran dilakukan dengan cara menyalin semua elemen mulai dari index head sampai tail ke posisi paling depan array mulai dari index 0. setelah itu tail disesuaikan menjadi posisi baru, yaitu j-1, dan head kembali menjadi 0.

fungsi dequeue bekerja dengan cara mengambil dan menghapus data paling depan pada queue. pertama dicek apakah queue kosong. kalau kosong maka program menampilkan pesan bahwa tidak ada data yang bisa dihapus. kalau tidak kosong, maka data yang berada di index head disimpan sementara sebagai hasil. jika setelah penghapusan queue menjadi kosong, yaitu ketika head dan tail berada di posisi yang sama, maka keduanya diset kembali menjadi -1. jika tidak kosong, maka head cukup maju satu langkah ke depan.

---

### Soal 3 : Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue  Alternatif 3 (head dan tail berputar).

<code>queue.h</code>

```cpp
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;
#define MAX 5

struct Queue {
   infotype info[MAX];
   int head;
   int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

<code>queue.cpp</code>

```cpp
#include "queue.h"

void createQueue(Queue &Q) {
   Q.head = -1;
   Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
   return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
   if (isEmptyQueue(Q)) return false;
   return ((Q.tail + 1) % MAX) == Q.head;
}

void enqueue(Queue &Q, infotype x) {
   if (isFullQueue(Q)) {
      cout << "queue penuh, tidak bisa menambah data" << endl;
      return;
   }

   if (isEmptyQueue(Q)) {
      Q.head = 0;
      Q.tail = 0;
   } else {
      Q.tail = (Q.tail + 1) % MAX;
   }

   Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
   if (isEmptyQueue(Q)) {
      cout << "queue kosong, tidak ada yang bisa dihapus" << endl;
      return -1;
   }

   infotype hasil = Q.info[Q.head];

   if (Q.head == Q.tail) {
      Q.head = -1;
      Q.tail = -1;
   } else {
      Q.head = (Q.head + 1) % MAX;
   }

   return hasil;
}

void printInfo(Queue Q) {
   if (isEmptyQueue(Q)) {
      cout << Q.head << "  - " << Q.tail << "  | empty queue" << endl;
   } else {
      cout << " " << Q.head << "  -  " << Q.tail << "  | ";

      int i = Q.head;
      while (true) {
         cout << Q.info[i] << " ";
         if (i == Q.tail) break;
         i = (i + 1) % MAX;
      }

      cout << endl;
   }
}
```

<code>main.cpp</code>

```cpp
#include "queue.h"

int main() {
   cout << "Hello world!" << endl;

   cout<<"-----------------------"<<endl;
   cout<<" H  -  T  | Queue Info"<<endl;
   cout<<"-----------------------"<<endl;

   Queue Q;
   createQueue(Q);

   printInfo(Q);
   enqueue(Q,5); printInfo(Q);
   enqueue(Q,2); printInfo(Q);
   enqueue(Q,7); printInfo(Q);
   dequeue(Q); printInfo(Q);
   enqueue(Q,4); printInfo(Q);
   dequeue(Q); printInfo(Q);
   dequeue(Q); printInfo(Q);

   cout<<"-1  - -1  | empty queue"<<endl;

   return 0;
}
```

> Output
> 
> ![](output/ss_unguided_3.jpeg)

program ini bertujuan untuk mengimplementasikan struktur data queue menggunakan metode circular buffer sesuai dengan alternatif 3, yaitu representasi HEAD dan TAIL yang bergerak melingkar dari index awal sampai index akhir kemudian kembali ke awal tanpa perlu melakukan pergeseran elemen seperti pada alternatif sebelumnya.

fungsi enqueue bekerja dengan cara menambahkan elemen baru ke dalam queue. jika queue sudah berisi, maka tail dimajukan 1 langkah dengan rumus (tail + 1) % MAX agar ketika tail mencapai index MAX-1, langkah berikutnya kembali ke index 0. setelah posisi tail diperbarui, nilai x dimasukkan ke array info pada indeks tail.

fungsi dequeue bekerja dengan cara mengambil dan menghapus elemen pada posisi head. jika jumlah elemen lebih dari satu, maka head dimajukan 1 langkah menggunakan rumus (head + 1) % MAX sehingga ia berputar jika mencapai index MAX-1.

fungsi printInfo bekerja dengan cara menampilkan kondisi queue, yaitu print posisi head dan tail serta seluruh elemen yang sedang ada di dalam queue. jika queue kosong maka program menampilkan tulisan empty queue. jika tidak kosong, program menampilkan semua elemen mulai dari head hingga tail dengan menggunakan pergerakan melingkar, yaitu dengan menaikkan index menggunakan (i + 1) % MAX sampai index mencapai posisi tail.

---

## Kesimpulan

dari praktikum ini, kita bisa belajar bagaimana struktur data queue dapat diimplementasikan dalam tiga pendekatan berbeda dengan karakteristik dan efisiensinya masing-masing. pada alternatif pertama, operasi dequeue membutuhkan pergeseran elemen sehingga kurang efisien karena kompleksitasnya meningkat seiring jumlah data.

alternatif kedua memperbaiki masalah tersebut dengan menggerakkan head dan tail secara linear, serta hanya melakukan pergeseran ketika benar-benar diperlukan saat tail mencapai batas array tetapi masih ada ruang kosong di depan.

alternatif ketiga menjadi solusi dari dua alternatif sebelumnya melalui penggunaan circular queue, di mana head dan tail dapat berputar menggunakan operasi modulo sehingga tidak ada pergeseran sama sekali. dari ketiga implementasi tersebut dapat disimpulkan bahwa pemilihan mekanisme queue dapat mempengaruhi kinerja program, dan circular queue adalah metode terbaik.

---

## Referensi

1. GeeksforGeeks. (2025, October 30). *Implementation of Circular Queue Using Array*. Retrieved November 12, 2025, from [https://www.geeksforgeeks.org/dsa/introduction-to-circular-queue/](https://www.geeksforgeeks.org/dsa/introduction-to-circular-queue/)
2. Mishra, H. (2024, June 3). *Queues, Data Structures*. DEV Community. Retrieved November 14, 2025, from [https://dev.to/harshm03/queues-data-structures-1dd1](https://dev.to/harshm03/queues-data-structures-1dd1)
3. Mufada, N. *Struktur Data Queue: Pengertian, Jenis, dan Kegunaannya*. Medium. Retrieved November 15, 2025, from [https://medium.com/%40nadhifmufada09/struktur-data-queue-pengertian-jenis-dan-kegunaannya-0494fa6ccc1d](https://medium.com/%40nadhifmufada09/struktur-data-queue-pengertian-jenis-dan-kegunaannya-0494fa6ccc1d)
4. SoftwareSeni. *Queue Adalah: Pengertian, Tipe, dan Contoh Implementasi*. Retrieved November 16, 2025, from [https://www.softwareseni.co.id/blog/queue-adalah-pengertian-tipe-dan-contoh-implementasi](https://www.softwareseni.co.id/blog/queue-adalah-pengertian-tipe-dan-contoh-implementasi)
