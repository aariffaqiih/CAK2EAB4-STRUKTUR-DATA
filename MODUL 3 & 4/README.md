<h1 align="center">Laporan Praktikum Modul 3 & 4 <br> Modul XXXXXXXXXXXX</h1>
<p align="center">'Aarif R. J. Faqiih - 103112430182</p>

## Dasar Teori

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

---

## Guided

### Soal 1

XXXXXXXXXXXXXXXXXXXXXXXX

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
