<h1 align="center">Laporan Praktikum Modul 7<br>STACK</h1>
<p align="center">'Aarif Rahmaan Jalaluddin Faqiih - 103112430182</p>

## Dasar Teori

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

---

## Guided

### Soal 1

XXXXXXXXXXXXXXXXXXXXXXXX

```cpp
#include <iostream>
using namespace std;

// stack itu linked list yang cuma bisa diakses dari atas
// maksudnya gini, misal kita punya stack kayak gini
// | 30 | <- top
// | 20 |
// | 10 |
// nah kita cuma bisa nambahin data di atas (push) atau ngambil data di atas (pop)
// ngga bisa ngambil data di tengah atau di bawah
struct Node {
   int   data;
   Node* next;
};

// cek dulu stacknya kosong apa ngga
// kalo kosong, topnya nullptr karena ngga ada node sama sekali
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
   // temp itu maksudnya buat nyimpen node paling dulu biar bisa dihapus nanti
   Node* temp = top;
   // terus topnya digeser ke node berikutnya
   top = top->next;
   // nah baru deh node paling atas yang lama dihapus
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

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

---

### Soal 2

XXXXXXXXXXXXXXXXXXXXXXXX

```cpp
#include <iostream>
```

> Output
> 
> ![Screenshot Output Guided 2](output/ss_guided_2.jpg)

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

---

### Soal 3

XXXXXXXXXXXXXXXXXXXXXXXX

```cpp
#include <iostream>
```

> Output
> 
> ![Screenshot Output Guided 3](output/ss_guided_3.jpg)

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

---

### Soal 4

XXXXXXXXXXXXXXXXXXXXXXXX

```cpp
#include <iostream>
```

> Output
> 
> ![Screenshot Output Guided 4](output/ss_guided_4.jpg)

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

---

### Soal 5

XXXXXXXXXXXXXXXXXXXXXXXX

```cpp
#include <iostream>
```

> Output
> 
> ![Screenshot Output Guided 5](output/ss_guided_5.jpg)

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

---

### Soal 6

XXXXXXXXXXXXXXXXXXXXXXXX

```cpp
#include <iostream>
```

> Output
> 
> ![Screenshot Output Guided 6](output/ss_guided_6.jpg)

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

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
