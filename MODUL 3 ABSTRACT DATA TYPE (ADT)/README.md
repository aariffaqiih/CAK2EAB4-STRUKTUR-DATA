<h1 align="center">Laporan Praktikum Modul 3 <br> ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">'Aarif Rahmaan Jalaluddin Faqiih - 103112430182</p>

## Dasar Teori

- **Struct:** untuk membuat tipe data baru `mahasiswa` yang menyimpan nim dan dua nilai (nilai1 dan nilai2), `mahasiswa` dengan field nama, nim, uts, uas, tugas, dan nilai_akhir, dan `pelajaran` yang menyimpan `namaMapel` dan `kodeMapel`.
- **Fungsi (function):** `inputMhs` untuk input data mahasiswa, `rata2` untuk menghitung rata-rata nilai, `create_pelajaran` untuk membuat dan mengembalikan objek struct pelajaran yang terisi, dan `input_data_mahasiswa` untuk input data, `hitung_nilai_akhir` untuk menghitung nilai akhir berdasarkan bobot nilai uts (30%), uas (40%), dan tugas (30%), serta `tampilkan_nilai_akhir` untuk menampilkan hasil.
- **Parameter:** parameter `mahasiswa &m` digunakan agar input data langsung tersimpan di objek yang dipanggil.
- **Array:** untuk menyimpan data banyak mahasiswa (maksimal 10), dan array berukuran 3x3 untuk menyimpan data dan ditampilkan.
- **Perulangan:** untuk menginput data mahasiswa dan menampilkan hasil.
- **Pointer:** variabel yang menyimpan alamat memori, digunakan untuk menunjuk elemen array dan variabel lain.
- **Pertukaran Nilai:** menggunakan variabel sementara (`temp`) untuk menukar isi tanpa kehilangan data.

---

## Guided

### Soal 1

program untuk mencari rata-rata dari 2 nilai mahasiswa.

<code>mahasiswa.h</code>

```cpp
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED
struct mahasiswa
{
   char nim[10];
   int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);
#endif
```

<code>mahasiswa.cpp</code>

```cpp
#include "mahasiswa.h"
#include <iostream>
using namespace std;

void inputMhs(mahasiswa &m) {
   cout << "input nama = ";
   cin >> (m).nim;
   cout << "input nilai1 = ";
   cin >> (m).nilai1;
   cout << "input nilai2 = ";
   cin >> (m).nilai2;
}

float rata2(mahasiswa m) {
   return float(m.nilai1 + m.nilai2) / 2;
}
```
<code>main.cpp</code>

```cpp
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main()
{
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata-rata: " << rata2(mhs) << endl;
    return 0;
}
```

> Output
> 
> ![Screenshot Output Guided 1](output/ss_guided_1.jpg)

program ini bertujuan untuk mengelola data mahasiswa dengan menyimpan nim (nomor induk mahasiswa) dan dua nilai, serta menghitung rata-rata dari kedua nilai tersebut.

struct mahasiswa digunakan untuk membuat tipe data baru yang memiliki tiga anggota yaitu nim bertipe char array sepanjang 10 karakter, nilai1 dan nilai2 bertipe integer. nim digunakan untuk menyimpan kode atau nomor mahasiswa, sedangkan nilai1 dan nilai2 adalah dua nilai yang akan diproses.

fungsi inputMhs bertugas untuk menerima input dari pengguna berupa nim, nilai1, dan nilai2, kemudian menyimpan nilai tersebut ke dalam objek mahasiswa yang dilewatkan lewat parameter referensi agar perubahan bisa langsung tersimpan.

fungsi rata2 menerima objek mahasiswa sebagai parameter dan mengembalikan nilai rata-rata dari nilai1 dan nilai2 dalam bentuk float. perhitungan dilakukan dengan menjumlahkan nilai1 dan nilai2, lalu dibagi 2.

pada fungsi main, objek mhs dari tipe mahasiswa dideklarasikan terlebih dahulu, kemudian dipanggil fungsi inputMhs untuk mengisi data mhs. setelah itu dipanggil fungsi rata2 untuk menghitung rata-rata nilai dari mhs, dan hasilnya ditampilkan ke layar menggunakan cout.

---

## Unguided

### Soal 1

program untuk input data mahasiswa, menghitung nilai akhir berdasarkan uts, uas, dan tugas.

```cpp
#include <iostream>
using namespace std;

// struct buat nampung data mahasiswa
// field/kolomnya ada nama, nim, uts, uas, tugas, sama nilai akhir
struct mahasiswa {
   string nama;
   string nim;
   float uts, uas, tugas, nilai_akhir;
};

// prosedur buat input data mahasiswa ke masing-masing field/kolom
void input_data_mahasiswa(mahasiswa &m) {
   cout << "nama  : "; cin >> m.nama;
   cout << "nim   : "; cin >> m.nim;
   cout << "uts   : "; cin >> m.uts;
   cout << "uas   : "; cin >> m.uas;
   cout << "tugas : "; cin >> m.tugas;
}

// function buat perhitungan hasil nilai akhir
// rumusnya:
// nilai uts   * 0.3 atau 30% dari nilai akhir
// nilai uas   * 0.4 atau 40% dari nilai akhir
// nilai tugas * 0.3 atau 30% dari nilai akhir
// nilai akhir hasilnya bakal angka desimal, jadi pake tipe data float
float hitung_nilai_akhir(mahasiswa m) {
   return (m.uts * 0.3) + (m.uas * 0.4) + (m.tugas * 0.3);
}

// prosedur buat nampilin hasil nilai akhir setelah menghitung uts, uas, dan tugas
void tampilkan_nilai_akhir(mahasiswa m) {
   cout << "\n| nama        : " << m.nama;
   cout << "\n| nim         : " << m.nim;
   cout << "\n| nilai akhir : " << m.nilai_akhir;
   cout << "\n+---------------------";
}

int main() {
   int jumlah_mahasiswa;
   cout << "masukkan jumlah mahasiswa (max 10) : ";
   cin >> jumlah_mahasiswa;

   // buat nampung maksimal 10 mahasiswa
   mahasiswa array_mahasiswa[10];

   for (int i = 0; i < jumlah_mahasiswa; i++) {
      cout << "\nmahasiswa ke-" << i + 1 << endl;
      input_data_mahasiswa(array_mahasiswa[i]);
      // simpan hasil hitung nilai akhir ke field 'nilai_akhir' masing-masing mahasiswa
      array_mahasiswa[i].nilai_akhir = hitung_nilai_akhir(array_mahasiswa[i]);
   }

   cout << "\n+--------------------+";
   cout << "\n|   data mahasiswa   |";
   cout << "\n+--------------------+";
   for (int i = 0; i < jumlah_mahasiswa; i++) {
      tampilkan_nilai_akhir(array_mahasiswa[i]);
   }

   return 0;
}
```

> Output
> 
> ![Screenshot Output Unguided 1](output/ss_unguided_1.jpg)

program ini bertujuan untuk mengelola data mahasiswa dan menghitung nilai akhir berdasarkan nilai uts, uas, dan tugas yang diinput oleh user.

pertama, dibuat struct bernama mahasiswa yang berfungsi sebagai wadah atau tipe data khusus untuk menyimpan informasi mahasiswa, yaitu nama, nim, nilai uts, uas, tugas, dan nilai akhir. struct ini memudahkan kita mengelompokkan data yang berkaitan menjadi satu kesatuan.

lalu ada prosedur input_data_mahasiswa yang berfungsi untuk memasukkan data mahasiswa secara interaktif ke dalam masing-masing field pada struct mahasiswa. disini user akan diminta mengisi nama, nim, uts, uas, dan tugas.

setelah itu, ada fungsi hitung_nilai_akhir yang menerima parameter struct mahasiswa dan menghitung nilai akhir berdasarkan rumus: nilai uts dikalikan 0.3, nilai uas dikalikan 0.4, dan nilai tugas dikalikan 0.3, lalu hasilnya dijumlahkan. fungsi ini mengembalikan tipe data float karena nilai akhir bisa berupa angka desimal.

selanjutnya, prosedur tampilkan_nilai_akhir digunakan untuk menampilkan data mahasiswa termasuk nama, nim, dan nilai akhir yang sudah dihitung. format output dibuat agar lebih rapi dan mudah dibaca.

di fungsi main, pertama-tama user diminta memasukkan jumlah mahasiswa yang akan diinput (maksimal 10). kemudian dibuat array dengan tipe mahasiswa sebanyak 10 elemen sebagai tempat menyimpan data mahasiswa.

lalu dilakukan perulangan sebanyak jumlah mahasiswa yang diinput user untuk melakukan input data tiap mahasiswa dengan memanggil input_data_mahasiswa. setelah data diinput, program langsung menghitung nilai akhir mahasiswa tersebut dan menyimpannya ke field nilai_akhir.

setelah semua data mahasiswa selesai diinput dan dihitung, program menampilkan daftar nilai akhir semua mahasiswa menggunakan perulangan yang memanggil tampilkan_nilai_akhir untuk setiap mahasiswa.

---

### Soal 2

program untuk membuat dan menampilkan data mata pelajaran menggunakan struct.

<code>pelajaran.h</code>

```cpp
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>
using namespace std;

// struct pelajaran
// berisi dua field: namaMapel dan kodeMapel
// ini adalah tipe data baru (ADT) yang mewakili 1 pelajaran
struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

// function untuk membuat data pelajaran baru
// menerima dua parameter string, lalu mengembalikan struct pelajaran
pelajaran create_pelajaran(string namapel, string kodepel);

// procedure untuk menampilkan isi data pelajaran
void tampil_pelajaran(pelajaran pel);

#endif
```

<code>pelajaran.cpp</code>

```cpp
#include "pelajaran.h"
#include <iostream>
using namespace std;

// function create_pelajaran()
// fungsinya untuk mengisi field namaMapel dan kodeMapel
// lalu mengembalikan struct pelajaran yang sudah terisi
pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

// procedure tampil_pelajaran()
// fungsinya untuk menampilkan data pelajaran ke layar
void tampil_pelajaran(pelajaran pel) {
    cout << "Nama Mata Pelajaran : " << pel.namaMapel << endl;
    cout << "Kode Mata Pelajaran : " << pel.kodeMapel << endl;
}
```

<code>main.cpp</code>

```cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    // buat objek pelajaran dengan memanggil function create_pelajaran()
    pelajaran pel = create_pelajaran(namapel, kodepel);

    // tampilkan data pelajaran
    tampil_pelajaran(pel);

    return 0;
}
```

> Output
> 
> ![Screenshot Output Guided 2](output/ss_unguided_2.jpg)

program ini bertujuan untuk membuat sebuah tipe data baru bernama struct pelajaran yang memiliki dua atribut, yaitu namaMapel dan kodeMapel, yang keduanya bertipe string. struct pelajaran ini berguna untuk menyimpan informasi mengenai sebuah mata pelajaran, seperti nama mata pelajaran dan kode pelajarannya.

ada fungsi create_pelajaran yang menerima dua parameter string, yaitu namapel dan kodepel, kemudian fungsi ini akan membuat objek struct pelajaran, mengisi field namaMapel dengan nilai namapel dan field kodeMapel dengan nilai kodepel, lalu mengembalikan objek struct pelajaran yang sudah terisi tersebut. fungsi ini memudahkan kita membuat data pelajaran baru tanpa harus mengisi field satu per satu secara manual.

selain itu, ada juga prosedur tampil_pelajaran yang menerima parameter berupa objek struct pelajaran. prosedur ini bertugas untuk menampilkan isi dari data pelajaran tersebut ke layar, dengan mencetak nama mata pelajaran dan kode mata pelajaran dalam format yang jelas dan mudah dibaca.

di dalam fungsi main, pertama kita membuat dua variabel string, yaitu namapel dengan nilai "Struktur Data" dan kodepel dengan nilai "STD". kemudian kita memanggil fungsi create_pelajaran dengan memasukkan kedua variabel tersebut sebagai argumen, hasilnya disimpan dalam variabel pel yang bertipe struct pelajaran. setelah itu, kita memanggil prosedur tampil_pelajaran untuk menampilkan isi dari pel ke layar.

---

### Soal 3

program untuk menukar elemen pada dua array 2D dan menukar nilai variabel menggunakan pointer.

```cpp
#include <iostream>
using namespace std;

// prosedur untuk bikin array 3x3
void membuat_array(int arr[3][3]) {
   // selama i kurang dari 3, maka bakal nge-loop baris
   for (int i = 0; i < 3; i++) {
      // selama j kurang dari 3, maka bakal nge-loop kolom
      for (int j = 0; j < 3; j++) {
         // \t itu gunanya buat ngasih jarak antar angka biar rapi
         cout << arr[i][j] << "\t";
      }
      // endl buat ganti baris tiap baris array selesai ditampilkan
      cout << endl;
   }
}

// prosedur untuk menukar isi dari dua array 2d di posisi tertentu
void menukar_elemen(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
   // nyimpen sementara nilai dari array pertama di variabel temp
   int temp = arr1[baris][kolom];
   // isi array pertama diganti dengan nilai dari array kedua
   arr1[baris][kolom] = arr2[baris][kolom];
   // isi array kedua diganti dengan nilai yang disimpen di temp tadi
   arr2[baris][kolom] = temp;
}

// prosedur untuk menukar isi dari dua variabel yang ditunjuk pointer
void menukar_pointer(int *x, int *y) {
   // nyimpen nilai yang ditunjuk pointer x ke variabel temp
   int temp = *x;
   // isi yang ditunjuk pointer x diganti sama nilai yang ditunjuk pointer y
   *x = *y;
   // isi yang ditunjuk pointer y diganti sama nilai yang disimpen di temp
   *y = temp;
}

int main() {
   // bikin dua array 2d berukuran 3x3
   int A[3][3] = {{1, 2, 3},
                  {4, 5, 6},
                  {7, 8, 9}};
   int B[3][3] = {{10, 11, 12},
                  {13, 14, 15},
                  {16, 17, 18}};

   // dua pointer yang masing-masing nunjuk ke elemen tertentu di array
   int *p1 = &A[0][0]; // p1 nunjuk ke elemen pertama array A (yaitu 1)
   int *p2 = &B[2][2]; // p2 nunjuk ke elemen terakhir array B (yaitu 18)

   // nampilin array A sebelum ada pertukaran
   cout << "array A sebelum pertukaran:\n";
   membuat_array(A);

   // nampilin array B sebelum ada pertukaran
   cout << "\narray B sebelum pertukaran:\n";
   membuat_array(B);

   // tukar elemen array A dan B di posisi [1][1] (baris ke-2 kolom ke-2)
   menukar_elemen(A, B, 1, 1);

   // nampilin hasil setelah pertukaran elemen array
   cout << "\nsetelah menukar elemen [1][1] antara A dan B:\n";
   cout << "array A:\n";
   membuat_array(A);

   cout << "\narray B:\n";
   membuat_array(B);

   // nampilin nilai yang ditunjuk pointer sebelum pertukaran pointer
   cout << "\nnilai yang ditunjuk p1: " << *p1 << endl;
   cout << "nilai yang ditunjuk p2: " << *p2 << endl;

   // tukar isi variabel yang ditunjuk pointer p1 dan p2
   menukar_pointer(p1, p2);

   // nampilin nilai yang ditunjuk pointer setelah pertukaran
   cout << "\nsetelah menukar isi variabel yang ditunjuk pointer:\n";
   cout << "nilai yang ditunjuk p1 sekarang: " << *p1 << endl;
   cout << "nilai yang ditunjuk p2 sekarang: " << *p2 << endl;

   // nampilin kondisi akhir dari array setelah semua pertukaran
   cout << "\narray A akhir:\n";
   membuat_array(A);
   cout << "\narray B akhir:\n";
   membuat_array(B);

   return 0;
}
```

> Output
> 
> ![Screenshot Output Guided 3](output/ss_unguided_3.jpg)

program ini bertujuan untuk menunjukkan cara menukar elemen dalam dua array 2 dimensi berukuran 3x3 dan juga menukar isi variabel yang ditunjuk oleh pointer.

prosedur membuat_array berfungsi untuk menampilkan isi array 3x3 ke layar, dengan menggunakan dua perulangan nested yaitu for i untuk baris dan for j untuk kolom. setiap elemen array ditampilkan dengan tab (\t) supaya rapi berjajar, dan setelah selesai satu baris, pindah ke baris baru dengan endl.

prosedur menukar_elemen bertujuan untuk menukar nilai elemen pada posisi tertentu antara dua array 2d yang diberikan. caranya dengan menyimpan nilai elemen pertama ke variabel sementara temp, lalu mengisi elemen pertama dengan elemen kedua, dan mengisi elemen kedua dengan nilai temp tadi. parameter baris dan kolom menentukan posisi elemen yang ingin ditukar.

prosedur menukar_pointer menunjukkan cara menukar nilai dari dua variabel yang ditunjuk oleh pointer. pointer x dan y menunjuk ke alamat variabel, lalu isi variabel yang ditunjuk pointer x dan y ditukar menggunakan variabel sementara temp sama seperti di prosedur sebelumnya.

di fungsi main, pertama dibuat dua array A dan B masing-masing 3x3 dengan nilai yang berbeda. lalu dibuat dua pointer p1 dan p2 yang menunjuk ke elemen tertentu dari array A dan B, yaitu elemen pertama A dan elemen terakhir B.

setelah itu, array A dan B ditampilkan sebelum pertukaran menggunakan prosedur membuat_array. kemudian elemen di posisi [1][1] (baris ke-2 kolom ke-2) dari kedua array ditukar menggunakan prosedur menukar_elemen. hasil pertukaran ini ditampilkan lagi.

selanjutnya, nilai yang ditunjuk oleh pointer p1 dan p2 ditampilkan, kemudian isi variabel yang ditunjuk pointer tersebut ditukar menggunakan prosedur menukar_pointer. hasil setelah pertukaran pointer juga ditampilkan.

di akhir, kondisi terakhir dari array A dan B setelah semua pertukaran ditampilkan sekali lagi menggunakan prosedur membuat_array.

---

## Referensi

1. https://www.w3schools.com/cpp/cpp_for_loop.asp (diakses 13 Oktober 2025)
2. https://www.w3schools.com/cpp/cpp_for_loop_nested.asp (diakses 13 Oktober 2025)
3. https://www.w3schools.com/cpp/cpp_arrays_loop.asp (diakses 13 Oktober 2025)
4. https://www.w3schools.com/cpp/cpp_arrays.asp (diakses 13 Oktober 2025)
5. https://www.w3schools.com/cpp/cpp_references.asp (diakses 14 Oktober 2025)
