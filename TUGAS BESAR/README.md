# 🍽️ Manajemen Fine Dining

---

## 📖 Deskripsi Umum

Sistem **Manajemen Menu Fine Dining** adalah aplikasi terminal berbasis **C++** yang dirancang untuk merepresentasikan operasional **restoran kelas elite**, dengan fokus pada **kualitas menu** dan **manajemen pelanggan VIP**.

Sistem ini **secara sengaja memisahkan** pengelolaan:

* **Menu makanan** menggunakan **Binary Search Tree (BST)**
* **Pelanggan VIP** menggunakan **Multi Linked List (MLL) 1–N**

Kedua struktur data **berdiri sendiri secara independen**, tanpa relasi apa pun, untuk menekankan **pemahaman konsep struktur data murni**, bukan sekadar hubungan antar entitas.

---

## 🌳 Modul 1: Manajemen Menu (BST)

### 📦 Node Menu (Record)

| Atribut         | Tipe      | Keterangan                             |
| --------------- | --------- | -------------------------------------- |
| `kode_menu`     | int       | ID unik menu (key BST)                 |
| `nama_menu`     | string    | Nama menu                              |
| `harga`         | int       | Harga premium                          |
| `kategori`      | string    | Signature / Premium / Seasonal / Vegan |
| `rating[5]`     | int array | Distribusi rating pelanggan            |
| `left`, `right` | pointer   | Anak kiri & kanan BST                  |

### 🔍 Perspektif Teori

* BST memberikan **pencarian efisien O(log n)**
* Data terurut otomatis
* Cocok untuk menu dengan pertumbuhan dinamis

---

## ⚙️ Fungsionalitas BST

### 🔴 CRUD + Search

* Insert menu berdasarkan `kode_menu`
* Update nama, harga, kategori
* Delete menu
* Search berdasarkan:

  * kode menu
  * nama menu
  * kategori

### 🟡 Traversal

* In-order -> tampilan menu terurut
* Pre-order -> struktur dapur
* Post-order -> evaluasi menu

### 🟢 Pengelolaan & Statistik

* Total menu
* Total menu per kategori
* Menu termahal & termurah
* Menu dengan rating tertinggi & terendah

---

## 👤 Modul 2: Manajemen Pelanggan VIP (MLL 1–N)

### 👑 Parent: Customer (Record)

| Atribut       | Tipe    | Keterangan               |
| ------------- | ------- | ------------------------ |
| `customer_id` | int     | ID unik pelanggan        |
| `nama`        | string  | Nama pelanggan           |
| `membership`  | string  | Silver / Gold / Platinum |
| `firstChild`  | pointer | Awal list aktivitas      |
| `next`        | pointer | Customer berikutnya      |

### 📌 Child: Aktivitas (Tipe Dasar)

| Atribut       | Tipe    |
| ------------- | ------- |
| id_reservasi  | int     |
| `next`        | pointer |

### 🔍 Perspektif Teori

* Parent dan child **berbeda tipe**
* Relasi 1–N
* Traversal linear sederhana

---

## ⚙️ Fungsionalitas MLL

### 🔵 CRUD + Search

* Insert customer
* Tambah / hapus data aktivitas
* Delete customer
* Search customer berdasarkan ID / nama

### 🟣 Pengelolaan

* Total pelanggan
* Total aktivitas per pelanggan
* Pelanggan paling aktif
* Pelanggan paling pasif
