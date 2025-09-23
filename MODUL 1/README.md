# <h1 align="center">Laporan Praktikum Modul 1 <br> Nama Modul</h1>
<p align="center">'Aarif R. J. Faqiih - 103112430182</p>

## Dasar Teori

yang panjang dikit

## Unguided

### Soal 1

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
