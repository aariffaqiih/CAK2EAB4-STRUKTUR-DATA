<h1 align="center">Laporan Praktikum Modul 2 <br> PENGENALAN BAHASA C++ (BAGIAN KEDUA)</h1>
<p align="center">'Aarif R. J. Faqiih - 103112430182</p>

## Dasar Teori

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

---

## Guided

### Soal 1

XXXXXXXXXXXXXXXXXXXXXXXX

```cpp
#include <iostream>
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
using namespace std;

int main() {
   int data[5] = {10, 20, 30, 40, 50};
   int *p_data = data;

   cout << "mengakses elemen array cara normal : " << endl;

   for (int i = 0; i < 5; ++i) {
      cout << "nilai elemen ke-" << i << " : " << data[i] << endl;
   }

   cout << "mengakses elemen array menggunakan pointer : " << endl;

   for (int i = 0; i < 5; ++i) {
      cout << "nilai elemen ke-" << i << " : " << *(p_data + i) << endl;
   }

   return 0;
}
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
using namespace std;

int main() {
   char pesan_array[] = "nasi padang";
   char *pesan_pointer = "ayam bakar 23";

   cout << "string array : " << pesan_array << endl;
   cout << "string pointer : " << pesan_pointer << endl;

   // mengubah karakter dalam array diperbolehkan
   pesan_array[0] = 'h';
   cout << "string array setelah diubah : " << pesan_array << endl;

   // pointer dapat diubah untuk menunjuk ke string lain
   pesan_pointer = "sariman";
   cout << "string pointer setelah menunjuk ke string lain : " << pesan_pointer << endl;

   return 0;
}
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

### Soal 7

XXXXXXXXXXXXXXXXXXXXXXXX

```cpp
#include <iostream>
```

> Output
> 
> ![Screenshot Output Guided 7](output/ss_guided_7.jpg)

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

---

### Soal 8

XXXXXXXXXXXXXXXXXXXXXXXX

```cpp
#include <iostream>
```

> Output
> 
> ![Screenshot Output Guided 8](output/ss_guided_8.jpg)

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

---

## Unguided

### Soal 1

Buatlah sebuah program untuk melakukan transpose pada sebuah matriks persegi berukuran 3x3. Operasi transpose adalah mengubah baris menjadi kolom dan sebaliknya. Inisialisasi matriks awal di dalam kode, kemudian buat logika untuk melakukan transpose dan simpan hasilnya ke dalam matriks baru. Terakhir, tampilkan matriks awal dan matriks hasil transpose.

<pre>
Contoh Output:

Matriks Awal:
1 2 3
4 5 6
7 8 9

Matriks Hasil Transpose:
1 4 7
2 5 8
3 6 9
</pre>

```cpp
#include <iostream>
using namespace std;
int main() {
   int matrix[3][3] = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}};
   int transpose[3][3];

   cout << "matrix awal :" << endl;
      for (int i = 0; i < 3; i++) {
         for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
         }
         cout << endl;
      }

   // do transpose
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         transpose[i][j] = matrix[j][i];
      }
   }

   // print transpose
   cout << "matrix hasil transpose :" << endl;
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         cout << transpose[i][j] << " ";
      }
      cout << endl;
   }

   return 0;
}
```

> Output
> 
> ![Screenshot Output Unguided 1](output/ss_unguided_1.jpg)

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

---

### Soal 2

Buatlah program yang menunjukkan penggunaan call by reference. Buat sebuah prosedur bernama kuadratkan yang menerima satu parameter integer secara referensi (&). Prosedur ini akan mengubah nilai asli variabel yang dilewatkan dengan nilai kuadratnya. Tampilkan nilai variabel di main() sebelum dan sesudah memanggil prosedur untuk membuktikan perubahannya.

<pre>
Contoh Output:

Nilai awal: 5
Nilai setelah dikuadratkan: 25
</pre>

```cpp
#include <iostream>
using namespace std;

// call by reference using &
void kuadratkan(int &n) {
   n = n * n;
}

int main() {
   int n = 5;
   cout << "nilai awal : " << n << endl;

   kuadratkan(n);
   cout << "nilai setelah dikuadratkan : " << n;

   return 0;
}
```

> Output
> 
> ![Screenshot Output Guided 2](output/ss_guided_2.jpg)

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

## Referensi

1. https://www.w3schools.com/cpp/cpp_functions.asp (diakses XXXXXXXXXXXX)
