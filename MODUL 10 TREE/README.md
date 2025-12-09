<h1 align="center">Laporan Praktikum Modul 10 <br> TREE</h1>
<p align="center">'Aarif Rahmaan Jalaluddin Faqiih - 103112430182</p>

## **Dasar Teori**

### **1. pengertian tree**

* tree adalah struktur data yang tersusun dari node-node yang saling terhubung melalui relasi parent–child.
* setiap node memiliki nilai dan pointer yang menunjuk ke node lain.

### **2. binary search tree (bst)**

* jika `x` adalah nilai pada node tertentu:

  * semua nilai di **subtree kiri** < `x`
  * semua nilai di **subtree kanan** > `x`

### **3. operasi dasar pada bst**

#### **a. insert**

* proses memasukkan nilai baru dilakukan dengan membandingkan nilai yang dimasukkan dengan node saat ini.
* proses berlanjut rekursif hingga menemukan posisi `null` yang sesuai.
* insert mematuhi aturan bst, yang lebih kecil ke kiri, sementara yang lebih besar ke kanan.

#### **b. search**

* pencarian menggunakan sifat bst:
  * lebih kecil -> kiri
  * lebih besar -> kanan

#### **c. delete**

operasi delete pada bst memiliki tiga kemungkinan kasus:

1. **node tanpa anak (leaf)** -> dihapus langsung.
2. **node dengan satu anak** -> node diganti dengan child-nya.
3. **node dengan dua anak** -> nilai node diganti dengan nilai terkecil di subtree kanan, lalu dihapus.

#### **d. update**

* secara konsep, bst tidak menyediakan operasi update.
* implementasinya seperti ini: **delete nilai lama -> insert nilai baru**, agar aturan bst tetap konsisten.

### **4. traversal pada binary tree**

traversal adalah proses mengunjungi seluruh node dalam urutan tertentu.

#### **a. in-order (left -> node -> right)**

* pada bst, traversal ini **selalu menghasilkan urutan ascending**.
* karena itu digunakan untuk menampilkan isi tree secara terurut.

#### **b. pre-order (node -> left -> right)**

* digunakan untuk mengekspor struktur tree atau merekonstruksi tree.

#### **c. post-order (left -> right -> node)**

### **5. perhitungan dalam bst**

#### **a. jumlah node**

* dihitung dengan menjumlahkan:
  `1 + jumlah(subtree kiri) + jumlah(subtree kanan)`

#### **b. total nilai (sum)**

* mengambil `info` setiap node lalu menjumlahkannya secara rekursif.

#### **c. kedalaman (depth / height)**

* depth menunjukkan panjang jalur dari root ke node terdalam.
* diukur dengan mencari nilai maksimum antara kedalaman subtree kiri dan kanan.

---

## Guided

### Soal 1

```cpp
#include <iostream>
using namespace std;

struct Node {
   int data;
   Node *kiri, *kanan;
};

// bikin node baru
Node *membuat_node(int data) {
   Node *node_baru = new Node();
   node_baru->data = data;  
   // karena masih baru, jadi belum punya anak
   node_baru->kiri = node_baru->kanan = NULL;
   return node_baru;
}

// masukin data ke pohon
Node *insert(Node *root, int nilai) {
   // kalo masih kosong, langsung bikin node, belum mikirin kiri kanan
   if (root == NULL) {
      return membuat_node(nilai);
   }
   // kalo udah ada isinya, bandingin nilainya kiri kanan
   // kalo nilainya lebih kecil dari nilai yang di atasnya, berarti masuk ke kiri
   if (nilai < root->data) {
      // rekursif ke kiri
      root->kiri = insert(root->kiri, nilai);
   }
   // kalo lebih besar, berarti masuk ke kanan
   else if (nilai > root->data) {
      // rekursif ke kanan
      root->kanan = insert(root->kanan, nilai);
   }

   return root;
}

// nyari nilai
Node *search(Node *root, int nilai) {
   if (root == NULL || root->data == nilai) {
      return root;
   }
   // lanjut ke subtree kiri
   if (nilai < root->data) {
      return search(root->kiri, nilai);
   }
   // lanjut ke subtree kanan
   return search(root->kanan, nilai);
}

Node *nilai_terkecil(Node *root) {
   Node *sekarang = root;
   while (sekarang && sekarang->kiri != NULL) {
      // geser terus ke kiri buat nyari nilai paling kecil
      sekarang = sekarang->kiri;
   }
   return sekarang;
}

Node *hapus(Node *root, int nilai) {
   if (root == NULL) {
      return root;
   }
   if (nilai < root->data) {
      // hapus dari subtree kiri
      root->kiri = hapus(root->kiri, nilai);
   } else if (nilai > root->data) {
      // hapus dari subtree kanan
      root->kanan = hapus(root->kanan, nilai);
   } else {
      // kasus node dengan hanya 1 anak atau tidak punya anak
      if (root->kiri == NULL) {
         Node *sementara = root->kanan;
         delete root;
         return sementara;
      }
      else if (root->kanan == NULL) {
         Node *sementara = root->kiri;
         delete root;
         return sementara;
      }
      // kasus dua anak: cari nilai terkecil di subtree kanan
      Node *sementara = nilai_terkecil(root->kanan);
      root->data = sementara->data;
      root->kanan = hapus(root->kanan, sementara->data);
   }
   return root;
}

// ubah data
Node *update(Node *root, int lama, int baru) {
   if (search(root, lama) != NULL) {
      // hapus data lama
      root = hapus(root, lama);
      // masukin data baru
      root = insert(root, baru);
      cout << "data " << lama << " diganti jadi " << baru << endl;
   }
   else {
      cout << "data " << lama << " ngga ketemu" << endl;
   }
   return root;
}

// menampilkan data dengan cara traversal
// traversal tuh maksudnya ngecek semua node di pohon satu per satu
void pre_order(Node *root) {
   if (root != NULL) {
      cout << root->data << " ";   // tampilkan node saat masuk
      pre_order(root->kiri);       // lanjut kiri dulu
      pre_order(root->kanan);      // terakhir kanan
   }
}

void in_order(Node *root) {
   if (root != NULL) {
      in_order(root->kiri);        // cek kiri dulu
      cout << root->data << " ";   // tampilkan data setelah kiri selesai
      in_order(root->kanan);       // lanjut kanan
   }
}

void post_order(Node *root) {
   if (root != NULL) {
      post_order(root->kiri);      // proses kiri dulu
      post_order(root->kanan);     // lalu kanan
      cout << root->data << " ";   // tampilkan data paling terakhir
   }
}

int main() {
   Node *root = NULL;

   cout << "=== 1. insert data ===" << endl;
   root = insert(root, 10);
   insert(root, 5);
   insert(root, 20);
   insert(root, 3);
   insert(root, 7);
   insert(root, 15);
   insert(root, 25);
   cout << "data berhasil dimasukkan!" << endl;

   cout << "\n=== 2. traversal tree ===" << endl;
   cout << "pre-order : ";
   pre_order(root);
   cout << endl;
   cout << "in-order  : ";
   in_order(root);
   cout << endl;
   cout << "post-order: ";
   post_order(root);
   cout << endl;

   cout << "\n=== 3. search data ===" << endl;
   int cari1 = 7, cari2 = 99;
   cout << "mencari " << cari1 << ": " << (search(root, cari1) ? "ketemu" : "ngga ketemu") << endl;
   cout << "mencari " << cari2 << ": " << (search(root, cari2) ? "ketemu" : "ngga ketemu") << endl;
   cout << endl;

   cout << "=== 4. update data ===" << endl;
   root = update(root, 5, 8);
   cout << "in-order setelah update: ";
   in_order(root);
   cout << endl;

   cout << "pre-order : ";
   pre_order(root);
   cout << endl;
   cout << "in-order  : ";
   in_order(root);
   cout << endl;
   cout << "post-order: ";
   post_order(root);
   cout << endl;

   cout << "\n=== 5. delete data ===" << endl;
   cout << "menghapus 20" << endl;
   root = hapus(root, 20);

   cout << "pre-order : ";
   pre_order(root);
   cout << endl;
   cout << "in-order  : ";
   in_order(root);
   cout << endl;
   cout << "post-order: ";
   post_order(root);
   cout << endl;
   return 0;
}
```

> Output
> 
> ![](output/ss_guided_1.jpeg)

program ini bertujuan untuk membuat, menampilkan, mencari, mengubah, dan menghapus data di dalam struktur data binary search tree. binary search tree sendiri adalah struktur data berbentuk pohon yang punya aturan bahwa nilai yang lebih kecil selalu berada di kiri dan nilai yang lebih besar selalu berada di kanan.

pertama ada struct Node yang isinya variabel data dan dua pointer kiri dan kanan. pointer ini tujuannya untuk ngasih tau node sebelah kiri dan node sebelah kanan. kalau node baru dibuat, otomatis pointer kiri dan kanan masih kosong atau NULL.

setelah itu ada prosedur membuat_node yang fungsinya untuk bikin node baru. saat node dibuat, nilai data diisi sesuai input, dan pointer kiri serta kanan diset NULL karena node belum punya anak.

lalu ada fungsi insert untuk memasukkan data ke tree. kalau root masih kosong, berarti langsung bikin node baru dan jadikan itu root. kalau root udah ada nilainya, maka dibandingkan apakah nilai yang mau dimasukin lebih kecil atau lebih besar. kalau lebih kecil masuk ke subtree kiri, kalau lebih besar masuk ke subtree kanan. proses ini dilakukan secara rekursif sampai ketemu posisi yang kosong untuk ditaruh.

fungsi search digunakan untuk mencari suatu nilai di dalam tree. cara kerjanya mirip dengan insert, yaitu membandingkan nilai yang dicari dengan nilai di root. kalau lebih kecil, masuk ke kiri, kalau lebih besar masuk ke kanan. proses ini dilakukan terus sampai ketemu nilai yang sesuai atau sampai ketemu NULL yang berarti datanya tidak ada.

fungsi nilai_terkecil dipakai untuk mencari nilai paling kecil dari suatu subtree. caranya tinggal geser pointer terus ke kiri karena di binary search tree nilai terkecil pasti selalu di posisi paling kiri.

fungsi hapus digunakan untuk menghapus data di tree. kalau nilai yang dicari lebih kecil dari nilai root, maka proses penghapusan dilakukan di subtree kiri. kalau lebih besar dilakukan di subtree kanan. kalau nilainya sama dengan root, maka ada beberapa kemungkinan. pertama, node tidak punya anak atau hanya punya satu anak, maka node tinggal dihapus dan diganti dengan anaknya. kedua, node punya dua anak. dalam kasus ini dicari nilai terkecil dari subtree kanan untuk menggantikan nilai node yang mau dihapus. setelah itu nilai terkecil tersebut dihapus dari subtree kanan.

fungsi update dipakai untuk mengganti nilai lama menjadi nilai baru. pertama dicek apakah nilai lama ada di tree dengan fungsi search. kalau ada, nilai lama dihapus dengan fungsi hapus lalu nilai baru dimasukkan lagi dengan fungsi insert. kalau nilai lama tidak ditemukan, maka muncul pesan kalau datanya tidak ada.

fungsi pre_order, in_order, dan post_order adalah fungsi traversal yang tujuannya untuk menampilkan semua data di tree. pre-order menampilkan data saat node pertama kali dikunjungi, in-order menampilkan data setelah subtree kiri selesai, sedangkan post-order menampilkan data setelah kiri dan kanan selesai dicek.

di fungsi main, pertama tree masih kosong. lalu masukan beberapa data menggunakan fungsi insert. setelah itu data ditampilkan menggunakan traversal pre-order, in-order, dan post-order. kemudian dilakukan pencarian untuk dua angka, apakah ketemu atau tidak. setelah itu dilakukan update yaitu mengganti angka 5 menjadi 8. tree ditampilkan lagi setelah update. terakhir dilakukan proses delete untuk menghapus angka 20, dan hasil tree ditampilkan lagi menggunakan traversal.

---

## Unguided

### Soal 1 : Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file “bstree.h”. Buatlah implementasi ADT Binary Search Tree pada file “bstree.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”

<code>bstree.h</code>

```cpp
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct node {
	infotype info;
	node *left, *right;
};

typedef node* address;

#define nil NULL

address alokasi(infotype x);
void insertnode(address &root, infotype x);
address findnode(infotype x, address root);
void inorder(address root);

#endif
```

<code>bstree.cpp</code>

```cpp
#include "bstree.h"

address alokasi(infotype x) {
	address p = new node;
	p->info = x;
	p->left = nil;
	p->right = nil;
	return p;
}

void insertnode(address &root, infotype x) {
	if (root == nil) {
		root = alokasi(x);
	}
	else if (x < root->info) {
		insertnode(root->left, x);
	}
	else if (x > root->info) {
		insertnode(root->right, x);
	}
}

address findnode(infotype x, address root) {
	if (root == nil || root->info == x) {
		return root;
	}
	if (x < root->info) {
		return findnode(x, root->left);
	}
	return findnode(x, root->right);
}

void inorder(address root) {
	if (root != nil) {
		inorder(root->left);
		cout << root->info << " -> ";
		inorder(root->right);
	}
}
```

<code>main.cpp</code>

```cpp
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
	cout << "hello world" << endl;
	address root = nil;
	insertnode(root,1);
	insertnode(root,2);
	insertnode(root,6);
	insertnode(root,4);
	insertnode(root,5);
	insertnode(root,3);
	insertnode(root,6);
	insertnode(root,7);
	inorder(root);
	return 0;
}
```

> Output
> 
> ![](output/ss_unguided_1.jpeg)

program ini bertujuan untuk membuat sebuah binary search tree (BST), memasukkan beberapa angka ke dalam tree tersebut, kemudian menampilkannya menggunakan traversal inorder agar menghasilkan urutan angka dari yang paling kecil sampai yang paling besar.

pada file header, terdapat struktur data node yang menyimpan info bertipe int serta pointer left dan right sebagai anak kiri dan anak kanan pada tree. kemudian terdapat juga deklarasi fungsi-fungsi yang akan digunakan seperti alokasi, insertnode, findnode, dan inorder. alokasi sendiri bertujuan untuk membuat node baru yang nantinya akan diisi oleh angka yang dimasukkan ke dalam tree.

fungsi alokasi bekerja dengan cara membuat node baru menggunakan operator new, kemudian mengisi bagian info dengan angka yang dikirim sebagai parameter. setelah itu, bagian left dan right diset menjadi NULL karena node baru belum memiliki anak. node yang sudah lengkap ini kemudian dikembalikan agar bisa digunakan pada proses selanjutnya.

fungsi insertnode bekerja dengan cara membandingkan angka yang akan dimasukkan dengan info dari node saat ini. jika root masih kosong atau NULL, maka node pertama akan dibuat menggunakan fungsi alokasi. jika angka yang dimasukkan lebih kecil dari info node saat ini, maka proses dilanjutkan ke subtree kiri. jika lebih besar, maka proses dilanjutkan ke subtree kanan. fungsi ini memastikan bahwa aturan BST tetap terjaga, yaitu semua angka di kiri lebih kecil dan semua angka di kanan lebih besar.

fungsi findnode bekerja dengan cara mencari sebuah angka tertentu pada BST. jika node saat ini kosong atau info dari node sama dengan angka yang dicari, maka node tersebut langsung dikembalikan. jika angka yang dicari lebih kecil, pencarian dilanjutkan ke anak kiri, dan jika lebih besar pencarian dilanjutkan ke anak kanan. proses ini memanfaatkan sifat BST yang membuat pencarian menjadi lebih efisien.

fungsi inorder bekerja dengan cara mengunjungi subtree kiri terlebih dahulu, kemudian menampilkan info dari node saat ini, lalu mengunjungi subtree kanan. karena urutan traversalnya seperti itu, hasil akhirnya adalah angka-angka pada tree akan ditampilkan dalam urutan naik.

fungsi main bertugas untuk mencetak tulisan hello world, membuat root awal tree yang bernilai NULL, kemudian memasukkan beberapa angka menggunakan insertnode.

---

### Soal 2 : Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut.
- fungsi hitungJumlahNode( root:address ) : integer
  - fungsi mengembalikan integer banyak node yang ada di dalam BST
- fungsi hitungTotalInfo( root:address, start:integer ) : integer
  - fungsi mengembalikan jumlah (total) info dari node-node yang ada di dalam BST
- fungsi hitungKedalaman( root:address, start:integer ) : integer
  - fungsi rekursif mengembalikan integer kedalaman maksimal dari binary tree

<code>bstree.h</code>

```cpp
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct node {
	infotype info;
	node *left, *right;
};

typedef node* address;

#define nil NULL

address alokasi(infotype x);
void insertnode(address &root, infotype x);
address findnode(infotype x, address root);
void inorder(address root);
int hitungjumlahnode(address root);
int hitungtotalinfo(address root);
int hitungkedalaman(address root, int start);

#endif
```

<code>bstree.cpp</code>

```cpp
#include "bstree.h"

address alokasi(infotype x) {
	address p = new node;
	p->info = x;
	p->left = nil;
	p->right = nil;
	return p;
}

void insertnode(address &root, infotype x) {
	if (root == nil) {
		root = alokasi(x);
	}
	else if (x < root->info) {
		insertnode(root->left, x);
	}
	else if (x > root->info) {
		insertnode(root->right, x);
	}
}

address findnode(infotype x, address root) {
	if (root == nil || root->info == x) {
		return root;
	}
	if (x < root->info) {
		return findnode(x, root->left);
	}
	return findnode(x, root->right);
}

void inorder(address root) {
	if (root != nil) {
		inorder(root->left);
		cout << root->info << " -> ";
		inorder(root->right);
	}
}

int hitungjumlahnode(address root) {
	if (root == nil) {
		return 0;
	}
	return 1 + hitungjumlahnode(root->left) + hitungjumlahnode(root->right);
}

int hitungtotalinfo(address root) {
	if (root == nil) {
		return 0;
	}
	return root->info + hitungtotalinfo(root->left) + hitungtotalinfo(root->right);
}

int hitungkedalaman(address root, int start) {
	if (root == nil) {
		return start;
	}
	int kiri = hitungkedalaman(root->left, start + 1);
	int kanan = hitungkedalaman(root->right, start + 1);
	return (kiri > kanan ? kiri : kanan);
}
```

<code>main.cpp</code>

```cpp
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
	cout << "hello world" << endl;
	address root = nil;
	insertnode(root,1);
	insertnode(root,2);
	insertnode(root,6);
	insertnode(root,4);
	insertnode(root,5);
	insertnode(root,3);
	insertnode(root,6);
	insertnode(root,7);
	inorder(root);
	cout << endl;
	cout << "kedalaman : " << hitungkedalaman(root,0) << endl;
	cout << "jumlah node : " << hitungjumlahnode(root) << endl;
	cout << "total : " << hitungtotalinfo(root) << endl;
	return 0;
}
```

> Output
> 
> ![](output/ss_unguided_2.jpeg)

kelanjutan program ini bertujuan untuk menampilkan tiga informasi penting dari sebuah binary search tree, yaitu kedalaman tree, jumlah node yang ada di dalam tree, dan total nilai dari seluruh info pada setiap node.

fungsi hitungjumlahnode bekerja dengan cara menghitung berapa banyak node yang ada di dalam tree. jika root bernilai nil, artinya tidak ada node, maka hasilnya 0. jika tidak, fungsi ini akan menjumlahkan 1 untuk node yang sedang diakses, lalu memanggil dirinya sendiri ke bagian kiri dan bagian kanan sampai seluruh node sudah dihitung. dengan begitu, hasil akhirnya adalah total seluruh node pada tree.

fungsi hitungtotalinfo bekerja dengan cara menjumlahkan seluruh nilai info dari setiap node pada tree. mekanismenya sama seperti hitungjumlahnode, yaitu menggunakan rekursi. jika root bernilai nil, maka hasilnya 0 karena tidak ada nilai yang bisa dijumlahkan. jika tidak, fungsi ini akan mengambil nilai info dari node saat ini, kemudian menambahkan hasil penjumlahan dari subtree kiri dan subtree kanan, sampai semua node selesai diproses.

fungsi hitungkedalaman bekerja dengan cara mencari seberapa dalam tree tersebut. jika root bernilai nil, maka hasilnya adalah nilai start yang dikirim dari parameter, karena itu menandakan bahwa kita sudah mencapai ujung tree. jika tidak, fungsi ini memanggil dirinya sendiri ke subtree kiri dan subtree kanan dengan menambah 1 pada start untuk setiap turun satu level. setelah itu fungsi membandingkan kedalaman kiri dan kanan, dan mengembalikan kedalaman yang paling besar, karena itu adalah kedalaman maksimum dari tree tersebut.

---

### Soal 3 : Print tree secara pre-order dan post-order.

<code>bstree.h</code>

```cpp
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct node {
	infotype info;
	node *left, *right;
};

typedef node* address;

#define nil NULL

address alokasi(infotype x);
void insertnode(address &root, infotype x);
address findnode(infotype x, address root);
void inorder(address root);
int hitungjumlahnode(address root);
int hitungtotalinfo(address root);
int hitungkedalaman(address root, int start);
void preorder(address root);
void postorder(address root);

#endif
```

<code>bstree.cpp</code>

```cpp
#include "bstree.h"

address alokasi(infotype x) {
	address p = new node;
	p->info = x;
	p->left = nil;
	p->right = nil;
	return p;
}

void insertnode(address &root, infotype x) {
	if (root == nil) {
		root = alokasi(x);
	}
	else if (x < root->info) {
		insertnode(root->left, x);
	}
	else if (x > root->info) {
		insertnode(root->right, x);
	}
}

address findnode(infotype x, address root) {
	if (root == nil || root->info == x) {
		return root;
	}
	if (x < root->info) {
		return findnode(x, root->left);
	}
	return findnode(x, root->right);
}

void inorder(address root) {
	if (root != nil) {
		inorder(root->left);
		cout << root->info << " -> ";
		inorder(root->right);
	}
}

int hitungjumlahnode(address root) {
	if (root == nil) {
		return 0;
	}
	return 1 + hitungjumlahnode(root->left) + hitungjumlahnode(root->right);
}

int hitungtotalinfo(address root) {
	if (root == nil) {
		return 0;
	}
	return root->info + hitungtotalinfo(root->left) + hitungtotalinfo(root->right);
}

int hitungkedalaman(address root, int start) {
	if (root == nil) {
		return start;
	}
	int kiri = hitungkedalaman(root->left, start + 1);
	int kanan = hitungkedalaman(root->right, start + 1);
	return (kiri > kanan ? kiri : kanan);
}

void preorder(address root) {
	if (root != nil) {
		cout << root->info << " -> ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(address root) {
	if (root != nil) {
		postorder(root->left);
		postorder(root->right);
		cout << root->info << " -> ";
	}
}
```

<code>main.cpp</code>

```cpp
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
	cout << "hello world" << endl;
	address root = nil;
	insertnode(root,1);
	insertnode(root,2);
	insertnode(root,6);
	insertnode(root,4);
	insertnode(root,5);
	insertnode(root,3);
	insertnode(root,6);
	insertnode(root,7);
	cout << "inorder: ";
	inorder(root);
	cout << endl;
	cout << "preorder: ";
	preorder(root);
	cout << endl;
	cout << "postorder: ";
	postorder(root);
	cout << endl;
	cout << "kedalaman : " << hitungkedalaman(root,0) << endl;
	cout << "jumlah node : " << hitungjumlahnode(root) << endl;
	cout << "total : " << hitungtotalinfo(root) << endl;
	return 0;
}
```

> Output
> 
> ![](output/ss_unguided_3.jpeg)

kelanjutan program ini bertujuan untuk menampilkan urutan penelusuran node pada sebuah binary search tree menggunakan dua jenis traversal, yaitu preorder dan postorder. kedua traversal ini dipakai untuk menampilkan isi tree dalam urutan yang berbeda sesuai dengan aturan masing-masing.

fungsi preorder bekerja dengan cara menampilkan isi node terlebih dahulu, yaitu root->info, kemudian masuk ke subtree kiri dengan memanggil preorder(root->left), dan setelah itu masuk ke subtree kanan dengan memanggil preorder(root->right). jadi urutan kerjanya selalu node dulu, lalu kiri, lalu kanan. fungsi ini hanya berjalan jika node yang dicek tidak kosong.

fungsi postorder bekerja dengan cara yang kebalikan dari preorder pada bagian outputnya. pertama program masuk dulu ke subtree kiri dengan memanggil postorder(root->left), setelah itu masuk ke subtree kanan dengan memanggil postorder(root->right), dan baru setelah selesai dua-duanya, barulah node yang sedang dicek ditampilkan dengan cout << root->info. jadi urutannya kiri dulu, kanan, baru node. sama seperti fungsi sebelumnya, fungsi ini juga hanya berjalan jika node tersebut tidak kosong.

terakhir, di fungsi main tugasnya memanggil kedua fungsi traversal tersebut dan menampilkan hasilnya. program menuliskan “preorder:” lalu memanggil fungsi preorder untuk mencetak urutan preorder, setelah itu menuliskan “postorder:” dan memanggil fungsi postorder untuk menampilkan urutan postorder.

---

## Kesimpulan

dari praktikum ini, program yang dibuat bertujuan untuk memahami cara kerja binary search tree mulai dari proses pembuatan node, memasukkan/insert data, mencari nilai, menghapus node, mengubah data, hingga menampilkan isi tree menggunakan berbagai jenis traversal.

---

## Referensi

1. tpointtech. Inorder traversal. Diakses 26 November 2025, dari https://www.tpointtech.com/inorder-traversal
2. Guru99. Binary tree. Diakses 2 Desember 2025, dari https://www.guru99.com/id/binary-tree.html
3. CompileNRun. BST operations. Diakses 9 Desember 2025, dari https://www.compilenrun.com/docs/fundamental/algorithm/tree-algorithms/bst-operations/
4. GeeksforGeeks. Tree Traversal Techniques. Diakses 13 Desember 2025, dari https://www.geeksforgeeks.org/dsa/tree-traversals-inorder-preorder-and-postorder/
