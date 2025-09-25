<h1 align="center">Laporan Praktikum Modul 1 <br> Nama Modul</h1>
<p align="center">'Aarif R. J. Faqiih - 103112430182</p>

## Dasar Teori

zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz

## Unguided

### Soal 1

Buatlah program yang menerima input-an dua buah bilangan bertipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```cpp
#include <iostream>
using namespace std;

// function to read two float numbers from user input
void readNumbers (float &a, float &b) {
   cout << "enter first float number : ";
   cin >> a;
   cout << "enter second float number : ";
   cin >> b;
   cout << "ok, we have " << a << " and " << b << endl;
   cout << "so..." << endl;
}

// function to add two numbers
float addition (float a, float b) {
   return a + b;
}

// function to subtract two numbers
float subtraction (float a, float b) {
   return a - b;
}

// function to multiply two numbers
float multiplication (float a, float b) {
   return a * b;
}

// function to divide two numbers
float division (float a, float b) {
   return a / b;
}

int main() {
   // declare two floats
   float a, b;
   // read input values from user
   readNumbers(a, b);

   // perform calculations
   float add = addition(a, b);
   float sub = subtraction(a, b);
   float mul = multiplication(a, b);
   float div = division(a, b);

   // print results
   cout << a << " + " << b << " = " << add  << endl;
   cout << a << " - " << b << " = " << sub << endl;
   cout << a << " * " << b << " = " << mul << endl;
   cout << a << " / " << b << " = " << div << endl;

   return 0;
}
```

> Output
> 
> ![Screenshot Output Unguided 1](output/ss_unguided_1.jpg)

program ini bertujuan untuk menampilkan hasil penjumlahan, pengurangan, perkalian, dan pembagian dari 2 angka bertipe float.

prosedur readNumbers di awal program bertujuan untuk menerima 2 input angka dari variabel a dan b yang nantinya akan masuk ke proses perhitungan.

setelah itu ada 4 fungsi utama yang menjadi core di program ini, yaitu addition, subtraction, multiplication, dan division. 4 fungsi ini memiliki 2 parameter yang sama yaitu angka bertipe float dari variabel a dan b.

fungsi addition bekerja dengan cara menjumlahkan nilai dari variabel a dan b, kemudian fungsi subtraction bekerja dengan cara mengurangi nilai dari variabel a dengan variabel b, setelah itu fungsi multiplication bekerja dengan cara mengalikan nilai dari variabel a dengan variabel b, dan fungsi division bekerja dengan cara membagi nilai dari variabel a dengan variabel b.

terakhir, fungsi main bertugas untuk mendeklarasikan variabel, memanggil fungsi, dan menampilkan hasil.

### Soal 3

Buatlah program yang dapat memberikan input dan output sebagai berikut.

<pre>
input  : 3
output :
321*123
 21*12
  1*1
   *
</pre>

```cpp
#include <iostream>
using namespace std;

int main() {
   // declare n
   int n;
   // read n values from user
   cout << "enter n : ";
   cin >> n;

   // outer for to create rows
   for (int i = n; i >= 1; i--) {
      // inner for to print space before numbers
      for (int k = 0; k < n - i; k++) {
         cout << " ";
      }

      // inner for to print descending numbers
      for (int j = i; j >= 1; j--) {
         cout << j;
      }

      // print * as a mirror
      cout << "*";

      // inner for to print ascending numbers
      for (int j = 1; j <= i; j++) {
         cout << j;
      }
      cout << endl;
   }

   // 2nd outer for to print space before last *
   for (int k = 0; k < n; k++) {
      cout << " ";
   }

   // * tail
   cout << "*";

   return 0;
}
```

> Output
> 
> ![Screenshot Output Unguided 1](output/ss_unguided_3.jpg)

program ini bertujuan untuk menampilkan urutan angka secara descending dan ada bintang di tengahnya seperti cermin, kemudian di sisi kanan bintang ada kebalikan dari urutan angka di sisi kiri, angka di sisi kanan diurutkan secara ascending.

pertama, masukan jumlah n. masuk di perulangan pertama, yaitu for (int i = n; i >= 1; i--), ini berfungsi untuk melakukan pengulangan jumlah baris.

perulangan kedua, yaitu for (int k = 0; k < n - i; k++), berfungsi untuk memberikan spasi sebelum mencetak angka, kenapa perlu spasi? agar bisa rata di tengah, jumlah spasinya mengikuti urutan perulangan.

perulangan ketiga, yaitu for (int j = i; j >= 1; j--), berfungsi untuk menampilkan urutan angka di sisi kiri, yaitu angka yang diurutkan secara descending karena j--.

sebagai cermin antara sisi kiri dan kanan, kita perlu menambahkan cout << "*";.

perulangan keempat, yaitu for (int j = 1; j <= i; j++), berfungsi untuk menampilkan urutan angka di sisi kanan, yaitu angka yang diurutkan secara ascending karena j++.

karena di bagian paling bawah terdapat 1 bintang tambahan dan bintang itu juga akan dibuat rata tengah, maka kita perlu spasi terlebih dahulu menggunakan for (int k = 0; k < n; k++).

terakhir, cetak bintang di paling bawah dengan cout << "*";.

## Referensi

1. https://www.w3schools.com/cpp/cpp_functions.asp (diakses Selasa, 23 September 2025)
2. https://www.w3schools.com/cpp/cpp_for_loop.asp (diakses Rabu, 24 September 2025)
3. https://www.w3schools.com/cpp/cpp_for_loop_nested.asp (diakses Rabu, 24 September 2025)
