<h1 align="center">Laporan Praktikum Modul 1 <br> Modul Pertama</h1>
<p align="center">'Aarif R. J. Faqiih - 103112430182</p>

## Dasar Teori

### Program Operasi Aritmatika
Konsep penting yang digunakan:
- **Fungsi (function):** kode yang dapat dipanggil untuk tugas tertentu.
- **Parameter & Return Value:** mengirim data ke fungsi dan pengembalian hasil.
- **Input/Output:** menggunakan `cin` untuk input dari pengguna dan `cout` untuk menampilkan hasil.

### Program Konversi Angka ke Teks (0–100)
Konsep yang dipakai:
- **Array:** digunakan untuk menyimpan tulisan satuan (`satuan[]`) dan puluhan (`puluhan[]`).
- **Percabangan (if-else):** menentukan tulisan yang sesuai untuk setiap rentang angka (satuan, belasan, puluhan, seratus, dan nol).
- **Operator Modulus (`%`) & Pembagian (`/`):** untuk memisahkan angka puluhan dan satuan.

### Program Pola Angka dengan For Loop
Konsep yang digunakan:
- **Perulangan Bersarang (nested for loop):** digunakan untuk membuat baris dan kolom secara bersamaan.

---

## Guided

### Soal 1

membaca dan menampilkan satu karakter yang dimasukkan.

```cpp
#include <iostream>
using namespace std;
int main()
{
    string ch;
    cout << "Masukkan sebuah karakter: ";
    // cin >> ch;
    ch = getchar();  //Menggunakan getchar() untuk membaca satu karakter
    cout << "Karakter yang Anda masukkan adalah: " << ch << endl;
    return 0;
}
```

> Output
> 
> ![Screenshot Output Guided 1](output/ss_guided_1.jpg)

program ini bertujuan untuk menerima input berupa satu karakter dan menampilkannya kembali.

di awal program, ada variabel bertipe string bernama ch yang digunakan untuk menyimpan karakter yang dimasukkan oleh pengguna. kemudian, getchar() digunakan untuk membaca satu karakter dari input pengguna. meskipun menggunakan cin >> ch; juga bisa, tapi disini getchar() digunakan agar kita bisa membaca satu karakter saja, bukan string penuh.

cara kerjanya adalah getchar() akan mengambil karakter pertama yang dimasukkan pengguna dan menyimpannya ke dalam variabel ch. setelah itu, program menampilkan karakter yang telah dimasukkan.

---

### Soal 2

membaca input panjang dan lebar, lalu menghitung serta menampilkan luas dan keliling dengan menggunakan fungsi dan prosedur.

```cpp
#include <iostream>
using namespace std;

// Prosedur: hanya menampilkan hasil, tidak mengembalikan nilai
void tampilkanHasil(double p, double l)
{
    cout << "\n=== Hasil Perhitungan ===" << endl;
    cout << "Panjang : " << p << endl;
    cout << "Lebar   : " << l << endl;
    cout << "Luas    : " << p * l << endl;
    cout << "Keliling: " << 2 * (p + l) << endl;
}

// Fungsi: mengembalikan nilai luas
double hitungLuas(double p, double l)
{
    return p * l;
}

// Fungsi: mengembalikan nilai keliling
double hitungKeliling(double p, double l)
{
    return 2 * (p + l);
}

int main()
{
    double panjang, lebar;

    cout << "Masukkan panjang: ";
    cin >> panjang;
    cout << "Masukkan lebar  : ";
    cin >> lebar;

    // Panggil fungsi
    double luas = hitungLuas(panjang, lebar);
    double keliling = hitungKeliling(panjang, lebar);

    cout << "\nDihitung dengan fungsi:" << endl;
    cout << "Luas      = " << luas << endl;
    cout << "Keliling  = " << keliling << endl;

    // Panggil prosedur
    tampilkanHasil(panjang, lebar);

    return 0;
}
```

> Output
> 
> ![Screenshot Output Guided 2](output/ss_guided_2.jpg)

program ini bertujuan untuk menghitung luas dan keliling dari sebuah persegi panjang, menggunakan baik fungsi maupun prosedur.

pertama, ada dua fungsi yang digunakan untuk menghitung, yaitu hitungLuas dan hitungKeliling. keduanya menerima dua parameter, yaitu panjang dan lebar, dan masing-masing mengembalikan nilai hasil perhitungan.

hitungLuas menghitung luas persegi panjang dengan rumus p * l dan mengembalikan nilai luas. hitungKeliling menghitung keliling persegi panjang dengan rumus 2 * (p + l) dan mengembalikan nilai keliling. setelah nilai luas dan keliling dihitung dengan fungsi, hasilnya ditampilkan di layar.

selanjutnya, prosedur tampilkanHasil digunakan untuk menampilkan hasil perhitungan yang sama, tetapi tanpa mengembalikan nilai. prosedur ini menerima dua parameter, yaitu panjang dan lebar, dan menampilkan panjang, lebar, luas, dan keliling.

di dalam main, program pertama-tama meminta input dari pengguna untuk panjang dan lebar. kemudian, program memanggil fungsi untuk menghitung luas dan keliling, dan menampilkan hasilnya. setelah itu, prosedur tampilkanHasil dipanggil untuk menampilkan hasil yang sama dengan cara yang berbeda.

---

### Soal 3

membaca jumlah perulangan dan menampilkan teks dengan format tertentu menggunakan perulangan do-while.

```cpp
#include <iostream>
using namespace std;
// int main()
// {
//     int jum;
//     cout << "jumlah perulangan: ";
//     cin >> jum;
//     for (int i = 0; i < jum; i++)
//     {
//         cout << "saya sahroni\n";
//     }
//     return 1;
// }


// while
int main()
{
    int i = 1;
    int jum;
    cin >> jum;
    do
    {
        cout << "bahlil ke-" << (i + 1) << endl;
        i++;
    } while (i < jum);
    return 0;
}
```

> Output
> 
> ![Screenshot Output Guided 3](output/ss_guided_3.jpg)

program ini bertujuan untuk mencetak tulisan "bahlil ke-" sebanyak n kali, menggunakan perulangan do while.

pertama, program meminta input angka dari user dan menyimpannya ke dalam variabel jum. kemudian, program menggunakan perulangan do while dengan variabel i yang dimulai dari 1.

di dalam perulangan, cout akan mencetak teks "bahlil ke-" ditambah dengan nilai (i + 1), artinya akan mulai dari 2, karena i dimulai dari 1. lalu, i++ akan menambah nilai i setiap kali perulangan dijalankan.

perulangan akan terus berjalan selama i < jum. artinya, jika jum yang dimasukkan adalah 5, maka output akan mulai dari "bahlil ke-2" hingga "bahlil ke-5".

---

### Soal 4

menentukan apakah sebuah hari termasuk hari kerja atau hari libur berdasarkan kode angka yang dimasukkan.

```cpp
##include <iostream>
using namespace std;
// int main()
// {
//     double tot_pembelian, diskon;
//     cout << "total pembelian: Rp";
//     cin >> tot_pembelian;
//     diskon = 0;
//     if (tot_pembelian >= 100000)
//         diskon = 0.05 * tot_pembelian;
//     cout << "besar diskon = Rp" << diskon;
// }



// int main()
// {
//     double tot_pembelian, diskon;
//     cout << "total pembelian: Rp";
//     cin >> tot_pembelian;
//     diskon = 0;
//     if (tot_pembelian >= 100000)
//         diskon = 0.05 * tot_pembelian;
//     else
//         diskon = 0;
//     cout << "besar diskon = Rp" << diskon;
// }



int main()
{
    int kode_hari;
    cout << "Menentukan hari kerja/libur\n"<<endl;
    cout << "1=Senin 3=Rabu 5=Jumat 7=Minggu "<<endl;
    cout << "2=Selasa 4=Kamis 6=Sabtu "<<endl;
    cin >> kode_hari;
    switch (kode_hari)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        cout<<"Hari Kerja";
        break;
    case 6:
    case 7:
        cout<<"Hari Libur";
        break;
    default:
        cout<<"Kode masukan salah!!!";
    }
    return 0;
}
```

> Output
> 
> ![Screenshot Output Guided 4](output/ss_guided_4.jpg)

program ini bertujuan untuk menentukan apakah sebuah hari termasuk hari kerja atau hari libur berdasarkan input kode hari dari user.

pertama, program akan menampilkan informasi kepada user tentang kode angka yang mewakili hari. misalnya, 1 untuk senin, 2 untuk selasa, dan seterusnya hingga 7 untuk minggu.

kemudian user diminta untuk memasukkan kode hari (angka dari 1 sampai 7), dan nilainya akan disimpan di variabel kode_hari. struktur switch digunakan untuk menentukan kategori hari berdasarkan nilai kode_hari.

jika kode_hari bernilai 1 sampai 5, maka program mencetak "hari kerja". jika kode_hari bernilai 6 atau 7, maka program mencetak "hari libur". jika nilainya di luar 1-7, maka masuk ke default dan program mencetak "kode masukan salah!!!" sebagai penanganan input yang tidak valid.

---

### Soal 5

menghitung dan menampilkan hasil pembagian dari jumlah dua bilangan dengan jumlah dua bilangan lainnya dalam bentuk desimal.

```cpp
#include <iostream>
using namespace std;
int main()
{
    int W, X, Y;
    float Z;
    X = 7;
    Y = 3;
    W = 1;
    Z = (X + Y) / (Y + W);
    cout << "Nilai z = " << Z << endl;
    return 0;
}
```

> Output
> 
> ![Screenshot Output Guided 5](output/ss_guided_5.jpg)

program ini bertujuan untuk menghitung nilai dari variabel z berdasarkan operasi aritmatika dari beberapa variabel bertipe int.

di awal, ada tiga variabel bertipe int yaitu w, x, dan y, lalu satu variabel z bertipe float. x diberi nilai 7, y diberi nilai 3, w diberi nilai 1, dan nilai z dihitung dengan rumus (x + y) / (y + w).

berarti, (7 + 3) / (3 + 1) → 10 / 4 hasilnya adalah 2 jika dalam integer, tapi karena z bertipe float, maka hasilnya akan tetap 2, bukan 2.5, karena operasi dilakukan antar int (x, y, dan w semua bertipe int), dan hasil dari pembagian int / int tetap dianggap integer sebelum dimasukkan ke dalam float.

---

### Soal 6

menginput dan menampilkan data mahasiswa berupa nama, nim, dan ipk menggunakan struct.

```cpp
#include <iostream>
#include <string>
using namespace std;

// Definisi struct
struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {

    Mahasiswa mhs1;

    cout << "Masukkan Nama Mahasiswa: ";
    getline(cin, mhs1.nama);
    // cin >> mhs1.nama;
    cout << "Masukkan NIM Mahasiswa : ";
    cin >> mhs1.nim;
    cout << "Masukkan IPK Mahasiswa : ";
    cin >> mhs1.ipk;

    cout << "\n=== Data Mahasiswa ===" << endl;
    cout << "Nama : " << mhs1.nama << endl;
    cout << "NIM  : " << mhs1.nim << endl;
    cout << "IPK  : " << mhs1.ipk << endl;

    return 0;
}
```

> Output
> 
> ![Screenshot Output Guided 6](output/ss_guided_6.jpg)

program ini bertujuan untuk menyimpan dan menampilkan data dari satu orang mahasiswa, menggunakan struct sebagai wadah penyimpanan data. pertama, didefinisikan sebuah struct dengan nama mahasiswa, yang berisi tiga anggota yaitu nama bertipe string, nim bertipe string, dan ipk bertipe float di dalam fungsi main.

dibuat satu variabel bernama mhs1 bertipe mahasiswa. kemudian program akan meminta input dari user untuk tiga data, yaitu nama mahasiswa dibaca menggunakan getline agar bisa membaca spasi, nim mahasiswa dibaca dengan cin, dan ipk mahasiswa dibaca juga dengan cin.

setelah data dimasukkan, program akan menampilkan ulang data tersebut ke layar, sesuai format.

---

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

---

### Soal 2

Buatlah sebuah program yang menerima menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100

<pre>79 : tujuh puluh sembilan</pre>

```cpp
#include <iostream>
using namespace std;

int main() {
   // array 1-10
   string satuan[]  = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh"};
   // array 20, 30, 40, ..., 90
   string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

   // declare n
   int n;
   // read n values from user
   cout << "enter number 0-100 : ";
   cin >> n;

   // 1 -10
   if (n >= 1 && n <= 10) {
      cout << satuan[n];
   }

   // 20 - 99
   else if (n >= 20 && n <= 99) {
      cout << puluhan[n/10] << " " << satuan[n%10];
   }

   // 11 - 19
   else if (n >= 11 && n <= 19) {
      if (n == 11) {
         cout << "sebelas";
      } else {
         cout << satuan[n % 10] << " belas";
      }
   }

   // 0
   else if (n == 0) {
      cout << "nol";
   }

   // 100
   else if (n == 100) {
      cout << "seratus";
   }

   // not 0-100
   else {
      cout << "angka di luar 0-100";
   }

   return 0;
}
```

> Output
> 
> ![Screenshot Output Unguided 2](output/ss_unguided_2.jpg)

program ini bertujuan untuk menampilkan tulisan dari sebuah input angka dalam range 1 sampai 100.

agar tidak 'hard-coded' dan agar efisien, kita butuh array yang menyimpan tulisan dari angka, tidak perlu semua, cukup satuan dan puluhan saja.

jika angka yang diinput antara 1-10, maka menggunakan array satuan sebagai outputnya, cara kerjanya adalah mengambil index ke-n pada array berdasarkan angka yang diinput.

jika angka antara 20-99, maka menggunakan array puluhan sebagai outputnya, tapi bedanya kita perlu membagi n dengan 10 agar kita mendapat satu angka puluhannya, misalkan 79 menjadi 7, kenapa? karena untuk mendapatkan index ke-7 yaitu tujuh puluh, kita hanya perlu input 7 saja.

kemudian untuk mengambil bagian satuannya, kita ambil modulus 10, atau sisa bagi jika dibagi 10, kita mendapatkan sisa 9, 9 ini akan mengakses array satuan pada index ke-9, yaitu sembilan.

jika angka antara 11-19, maka untuk angka 11 perlu ditulis manual, karena itu angka spesial, kemudian gunakan array satuan tapi dengan modulus 10, kenapa? sama seperti di kasus angka puluhan tadi, kita hanya perlu ambil bagian belakangnya saja untuk mengakses index pada array satuan, kemudian di bagian belakang ditambahkan tulisan belas.

untuk angka 0 dan 100, ini diberi tulisan manual saja, yaitu nol dan seratus. jika angka di luar range 1 sampai 100, maka program menampilkan angka di luar 0-100.

---

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
> ![Screenshot Output Unguided 3](output/ss_unguided_3.jpg)

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
4. https://www.w3schools.com/cpp/cpp_arrays.asp (diakses Kamis, 25 September 2025)
5. https://www.w3schools.com/cpp/cpp_arrays_loop.asp (diakses Kamis, 25 Septmber 2025)
