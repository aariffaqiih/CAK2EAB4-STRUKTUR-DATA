<h1 align="center">Laporan Praktikum Modul 3 <br> ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">'Aarif R. J. Faqiih - 103112430182</p>

## Dasar Teori

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

---

## Guided

### Soal 1

program untuk mencari rata-rata dari 2 nilai mahasiswa

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

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

---

## Unguided

### Soal 1

XXXXXXXXXXXXXXXXXXXXXXXX

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

## Referensi

1. https://www.w3schools.com/cpp/cpp_functions.asp (diakses XXXXXXXXXXXX)
