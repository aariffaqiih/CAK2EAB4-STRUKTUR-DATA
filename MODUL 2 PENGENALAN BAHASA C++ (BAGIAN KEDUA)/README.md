<h1 align="center">Laporan Praktikum Modul 2 <br> PENGENALAN BAHASA C++ (BAGIAN KEDUA)</h1>
<p align="center">'Aarif R. J. Faqiih - 103112430182</p>

## Dasar Teori

### 1. array dan perulangan

array dipakai untuk menyimpan data berurutan, lalu diakses dengan loop (for). array menyediakan indeks untuk mengakses elemen.

### 2. pointer

- mengakses nilai dengan dereference *p,
- mengubah nilai asli variabel dari luar,
- pointer bertipe int* hanya bisa menyimpan alamat variabel int.

### 3. reference (call by reference)

soal kuadratkan dan tukar menggunakan parameter &. ini menjelaskan reference. reference adalah alias dari variabel lain. dengan reference, fungsi bisa mengubah nilai variabel aslinya tanpa harus return value.

### 4. fungsi (function)

beberapa contoh (hitungjumlah, tampilkanhasil, tukar) memperlihatkan fungsi sebagai blok kode yang bisa dipanggil ulang. fungsi dipakai untuk modularisasi, memecah program besar menjadi unit kecil yang reusable. parameter bisa dikirim by value, by pointer, atau by reference. return value dipakai untuk mengembalikan hasil.

### 5. string (array vs pointer)

string di c++ disimpan di memory read-only. kalau disimpan ke pointer, tidak bisa diubah isinya, hanya alamatnya yang bisa dipindahkan. sedangkan array char bisa dimodifikasi isinya. contoh: "nasi padang" akan tersimpan sebagai string biasa, sedangkan char pesan_array[] = "nasi padang"; menyalin ke array.

### 6. kesimpulan

- deklarasi dan manipulasi array.
- pointer (*) untuk call by pointer.
- reference (&) untuk call by reference.
- fungsi: deklarasi, parameter, return.

dengan function pointer, kita bisa memanggil fungsi secara tidak langsung, menggunakannya sebagai parameter, atau bahkan sebagai nilai balik dari fungsi lain. sintaksnya mirip dengan pointer ke variabel, hanya saja formatnya menyesuaikan dengan tipe return dan parameter fungsi yang dituju. selain itu, ada juga konsep reference ke fungsi yang bertindak sebagai alias permanen. manfaatnya, function pointer membuat kode lebih fleksibel, misalnya untuk callback.

---

## Guided

### Soal 1

program untuk mengiterasi dan menampilkan nilai-nilai dalam array beserta indeksnya.

```cpp
#include <iostream>
using namespace std;

int main() {
   int nilai[] = {1, 2, 3, 4, 5};

   for(int i = 0; i < 5; i++) {
      cout << "elemen ke-" << i << " = " << nilai[i] << endl;
   }

   return 0;
}
```

> Output
> 
> ![Screenshot Output Guided 1](output/ss_guided_1.jpg)

terdapat deklarasi array bernama nilai. array ini bertipe int dan langsung diisi dengan angka 1 sampai 5. program kemudian menggunakan perulangan for untuk menampilkan isi array.

variabel i digunakan sebagai penghitung dan berjalan dari 0 sampai kurang dari 5. setiap iterasi, program menampilkan teks "elemen ke-" diikuti dengan nilai i dan isi array pada indeks ke-i.

---

### Soal 2

program untuk menampilkan elemen-elemen dalam matriks 3x3.

```cpp
#include <iostream>
using namespace std;
int main() {
   int matrix[3][3] = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}};

      for (int i = 0; i < 3; i++) {
         for (int j = 0; j < 3; j++) {
            cout << matrix[i][j];
         }
         cout << endl;
      }

   return 0;
}
```

> Output
> 
> ![Screenshot Output Guided 2](output/ss_guided_2.jpg)

dalam fungsi main dibuat array dua dimensi dengan nama matrix. array ini bertipe int dan berukuran 3x3. isinya adalah angka 1 sampai 9 yang disusun dalam bentuk matriks. selanjutnya program menggunakan nested loop.

perulangan luar dengan variabel i berjalan dari 0 sampai 2. perulangan dalam dengan variabel j juga berjalan dari 0 sampai 2. setiap iterasi akan menampilkan elemen matrix[i][j]. setelah satu baris selesai, cout << endl dipakai untuk pindah ke baris baru.

---

### Soal 3

program yang digunakan untuk menampilkan nilai, alamat memori, dan isi pointer dari sebuah variabel.

```cpp
#include <iostream>
using namespace std;
int main() {
   int umur = 25;
   int *p_umur;

   p_umur = &umur;

   cout << "nilai 'umur' : " << umur << endl;
   cout << "alamat memori 'umur' : " << &umur << endl;
   cout << "nilai 'p_umur' (alamat) : " << p_umur << endl;
   cout << "nilai yang diakses 'p_umur' : " << *p_umur << endl;
   cout << "alamat memori dari pointer 'p_umur' itu sendiri : " << &p_umur << endl;

   return 0;
}
```

> Output
> 
> ![Screenshot Output Guided 3](output/ss_guided_3.jpg)

terdapat sebuah variabel int bernama umur yang bernilai 25. lalu ada pointer dengan nama p_umur yang bertipe int*. pointer ini kemudian diisi dengan alamat dari variabel umur menggunakan operator &. setelah itu program menampilkan beberapa hal.

pertama nilai variabel umur. kemudian alamat memori dari variabel umur. selanjutnya nilai pointer p_umur yang isinya adalah alamat dari umur. setelah itu ditampilkan nilai yang diakses pointer p_umur dengan operator *. terakhir ditampilkan alamat memori dari pointer p_umur itu sendiri.

---

### Soal 4

program yang digunakan untuk mengakses dan menampilkan elemen array dengan cara biasa dan menggunakan pointer.

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

terdapat array dengan nama data. array ini bertipe int dan berisi lima elemen yaitu 10, 20, 30, 40, dan 50. kemudian dibuat sebuah pointer bernama p_data yang langsung menunjuk ke array data.

program pertama menampilkan isi array dengan cara normal. digunakan perulangan for dengan variabel i dari 0 sampai 4. setiap iterasi akan menampilkan teks "nilai elemen ke-" ditambah nilai i dan isi array data[i].

selanjutnya program menampilkan isi array menggunakan pointer. tetap memakai perulangan for dengan variabel i dari 0 sampai 4. namun kali ini akses elemen dilakukan dengan *(p_data + i). tanda * dipakai untuk dereference pointer sehingga nilai yang ditunjuk bisa ditampilkan.

---

### Soal 5

program yang digunakan untuk menunjukkan perbedaan antara string sebagai array dan string sebagai pointer.

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

terdapat deklarasi string dengan dua cara. pertama adalah pesan_array yang bertipe char array dan diisi dengan teks "nasi padang". kedua adalah pesan_pointer yang bertipe char pointer dan menunjuk ke string literal "ayam bakar 23".

program lalu menampilkan isi dari pesan_array dan pesan_pointer. hasilnya adalah string array dan string pointer ditampilkan sesuai isinya. selanjutnya ada bagian untuk mengubah karakter dalam array.

pada baris ini karakter pertama dari pesan_array diganti menjadi 'h'. karena berupa array, perubahan ini diperbolehkan.

setelah itu string array ditampilkan kembali dan terlihat sudah berubah. berikutnya pointer pesan_pointer diubah untuk menunjuk ke string literal lain yaitu "sariman". setelah itu isi dari pesan_pointer ditampilkan lagi dan terlihat bahwa pointer sudah menunjuk ke string baru.

---

### Soal 6

program yang digunakan untuk menghitung dan menampilkan hasil penjumlahan dua angka.

```cpp
#include <iostream>
using namespace std;

int hitungJumllah(int a, int b) {
   return a + b;
}

void tampilkanHasil(int hasil){
   cout << "hasil penjumlahan adalah : " << hasil << endl;
}

int main() {
   int angka1 = 15;
   int angka2 = 10;
   int hasilJumlah;

   hasilJumlah = hitungJumllah(angka1, angka2);
   tampilkanHasil(hasilJumlah);

   return 0;
}
```

> Output
> 
> ![Screenshot Output Guided 6](output/ss_guided_6.jpg)

terdapat sebuah fungsi dengan nama hitungJumllah. fungsi ini menerima dua parameter bertipe int yaitu a dan b. fungsi ini mengembalikan hasil penjumlahan dari a + b. lalu ada fungsi tampilkanHasil. fungsi ini menerima parameter bertipe int dengan nama hasil. di dalamnya terdapat perintah cout untuk menampilkan teks "hasil penjumlahan adalah :" diikuti nilai hasil.

di fungsi main dibuat tiga variabel int yaitu angka1 dengan nilai 15, angka2 dengan nilai 10, dan hasilJumlah tanpa nilai awal. program kemudian memanggil fungsi hitungJumllah dengan argumen angka1 dan angka2. hasil dari pemanggilan fungsi tersebut disimpan di variabel hasilJumlah. setelah itu fungsi tampilkanHasil dipanggil dengan argumen hasilJumlah.

---

### Soal 7

program yang digunakan untuk menukar nilai dua variabel menggunakan pointer.

```cpp
#include <iostream>
using namespace std;

void tukar(int *px, int *py)
{
    int temp = *px;
    *px = *py;
    *py = temp;
}

int main()
{
    int a = 10, b = 20;
    cout << "Sebelum ditukar: a = " << a << ", b = " << b << endl;
    tukar(&a, &b);
    cout << "Setelah ditukar: a = " << a << ", b = " << b << endl;

    return 0;
}
```

> Output
> 
> ![Screenshot Output Guided 7](output/ss_guided_7.jpg)

terdapat sebuah fungsi dengan nama tukar. fungsi ini menerima dua parameter pointer yaitu px dan py. di dalam fungsi tukar, nilai yang ditunjuk px disimpan terlebih dahulu ke variabel temp. kemudian nilai yang ditunjuk px diganti dengan nilai yang ditunjuk py.

nilai yang ditunjuk py diganti dengan nilai temp. dengan cara ini maka nilai dari dua variabel yang dipassing akan saling bertukar. di dalam fungsi main dibuat dua variabel int yaitu a dengan nilai 10 dan b dengan nilai 20.

program lalu menampilkan nilai a dan b sebelum dipanggil fungsi tukar. selanjutnya fungsi tukar dipanggil dengan argumen alamat dari a dan b. karena parameter fungsi berupa pointer, maka nilai variabel a dan b benar-benar ditukar.

setelah itu program menampilkan kembali nilai a dan b. kali ini nilainya sudah tertukar.

---

### Soal 8

program yang digunakan untuk menukar nilai dua variabel menggunakan referensi.

```cpp
#include <iostream>
using namespace std;

void tukar(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 10, b = 20;
    cout << "Sebelum ditukar: a = " << a << ", b = " << b << endl;
    tukar(a, b);
    cout << "Setelah ditukar: a = " << a << ", b = " << b << endl;
    return 0;
}
```

> Output
> 
> ![Screenshot Output Guided 8](output/ss_guided_8.jpg)

terdapat sebuah fungsi dengan nama tukar. fungsi ini menggunakan parameter reference yaitu x dan y. di dalam fungsi tukar nilai x disimpan dulu ke variabel temp. kemudian x diganti dengan y, dan y diganti dengan temp.

dengan cara ini maka nilai dua variabel yang dikirim ke fungsi akan saling bertukar. di dalam fungsi main dibuat dua variabel int yaitu a dengan nilai 10 dan b dengan nilai 20. program kemudian menampilkan nilai a dan b sebelum dipanggil fungsi tukar.

selanjutnya fungsi tukar dipanggil dengan argumen a dan b. karena parameter berupa reference maka nilai a dan b benar-benar tertukar. setelah itu program menampilkan kembali nilai a dan b. hasilnya terlihat bahwa nilai a dan b sudah saling bertukar.

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

terdapat deklarasi array dua dimensi dengan ukuran 3x3. array tersebut bernama matrix dan sudah langsung diisi dengan angka 1 sampai 9. kemudian dibuat juga array baru bernama transpose dengan ukuran yang sama, yaitu 3x3.

program lalu menampilkan matrix awal. proses ini menggunakan nested loop, yaitu for di dalam for. loop pertama dengan variabel i berjalan dari 0 sampai 2. di dalamnya ada loop kedua dengan variabel j yang juga berjalan dari 0 sampai 2.

setelah satu baris selesai maka dilakukan cout << endl untuk pindah ke baris berikutnya. bagian selanjutnya adalah proses transpose. transpose dilakukan dengan cara menukar baris menjadi kolom. perintahnya adalah transpose[i][j] = matrix[j][i].

nested loop kembali dipakai agar semua elemen bisa diproses. setelah proses transpose selesai, program menampilkan matrix hasil transpose. caranya sama seperti saat menampilkan matrix awal, menggunakan nested loop dengan cout. hasilnya adalah tampilan matrix yang sudah ditukar antara baris dan kolom.

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

terdapat sebuah fungsi dengan nama kuadratkan. fungsi ini menerima parameter dengan tipe int menggunakan tanda &. tanda & berarti parameter tersebut dipassing dengan cara call by reference. di dalam fungsi kuadratkan terdapat perintah n = n * n yang artinya nilai n dikalikan dengan dirinya sendiri.

di fungsi main terdapat sebuah variabel n yang diinisialisasi dengan nilai 5. setelah itu fungsi kuadratkan dipanggil dengan argumen n. karena dipassing dengan reference, maka nilai variabel n di main akan berubah. setelah fungsi kuadratkan selesai dijalankan, program menampilkan nilai n lagi. kali ini nilainya sudah berubah menjadi 25 karena sebelumnya sudah dikuadratkan.

## Referensi

1. https://www.w3schools.com/cpp/cpp_arrays_loop.asp (diakses Selasa, 30 September 2025)
2. https://www.w3schools.com/cpp/cpp_references.asp (diakses Selasa, 30 September 2025)
3. https://www.w3schools.com/cpp/cpp_references_memory.asp (diakses Selasa, 30 September 2025)
4. https://www.w3schools.com/cpp/cpp_pointers.asp (diakses Selasa, 30 September 2025)
5. https://www.w3schools.com/cpp/cpp_pointers_dereference.asp (diakses Selasa, 30 September 2025)
6. https://www.w3schools.com/cpp/cpp_pointers_modify.asp (diakses Selasa, 30 September 2025)
7. https://www.w3schools.com/cpp/cpp_functions.asp (diakses Selasa, 30 September 2025)
8. https://www.w3schools.com/cpp/cpp_function_param.asp (diakses Selasa, 30 September 2025)
9. https://www.w3schools.com/cpp/cpp_function_multiple.asp (diakses Selasa, 30 September 2025)
10. https://www.w3schools.com/cpp/cpp_function_return.asp (diakses Selasa, 30 September 2025)
11. https://www.w3schools.com/cpp/cpp_function_reference.asp (diakses Selasa, 30 September 2025)
12. https://www.scaler.com/topics/cpp/function-pointer-cpp/ (diakses Selasa, 30 September 2025)
