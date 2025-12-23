# 🍽️ Manajemen Menu Fine Dining

### *An Elite Culinary Management System*

---

## 📖 Deskripsi Umum

Sistem **Manajemen Menu Fine Dining** adalah aplikasi terminal berbasis **C++** yang dirancang untuk merepresentasikan operasional **restoran kelas elite**, dengan fokus pada **kualitas menu** dan **manajemen pelanggan VIP**.

Sistem ini **secara sengaja memisahkan** pengelolaan:

* **Menu makanan** menggunakan **Binary Search Tree (BST)**
* **Pelanggan VIP** menggunakan **Multi Linked List (MLL) 1–N**

Kedua struktur data **berdiri sendiri secara independen**, tanpa relasi apa pun, untuk menekankan **pemahaman konsep struktur data murni**, bukan sekadar hubungan antar entitas.

---

## 🏛️ Filosofi Desain Sistem (High-End Architecture)

Pada restoran fine dining kelas dunia:

* **Menu** adalah entitas premium yang berdiri sendiri
* **Pelanggan VIP** adalah aset eksklusif dengan histori tersendiri
* Tidak semua data perlu saling terhubung — **kejelasan struktur lebih penting daripada kompleksitas semu**

Pendekatan ini mencerminkan:

* Desain sistem bersih (clean architecture)
* Modularitas
* Skalabilitas operasional restoran elite

---

# 🌳 Modul 1 — Manajemen Menu (BST)

## 🎯 Tujuan Bisnis

Mengelola menu restoran eksklusif dengan standar tinggi:

* Konsistensi kualitas
* Analisis performa menu
* Pengambilan keputusan strategis (harga, kategori, kualitas)

---

## 🧠 Struktur Data (BST)

### 📦 Node Menu (Record)

| Atribut         | Tipe      | Keterangan                             |
| --------------- | --------- | -------------------------------------- |
| `kode_menu`     | int       | ID unik menu (key BST)                 |
| `nama_menu`     | char[]    | Nama menu                              |
| `harga`         | int       | Harga premium                          |
| `kategori`      | char[]    | Signature / Premium / Seasonal / Vegan |
| `rating[5]`     | int array | Distribusi rating pelanggan            |
| `left`, `right` | pointer   | Anak kiri & kanan BST                  |

### 🔍 Perspektif Teori

* BST memberikan **pencarian efisien O(log n)**
* Data terurut otomatis
* Cocok untuk menu dengan pertumbuhan dinamis

---

## ⚙️ Fungsionalitas BST

### 🟦 CRUD + Search

* Insert menu berdasarkan `kode_menu`
* Update nama, harga, kategori
* Delete menu
* Search berdasarkan:

  * kode menu
  * nama menu
  * kategori

### 🟧 Traversal

* In-order → tampilan menu terurut (standar fine dining)
* Pre-order → struktur dapur
* Post-order → evaluasi menu

### 🟨 Pengelolaan & Statistik

* Total menu
* Total menu per kategori
* Menu termahal & termurah
* Menu dengan rating tertinggi & terendah
* Menu dengan total vote tertentu

### 💼 Nilai Bisnis

* Menentukan menu andalan
* Menyusun menu seasonal
* Evaluasi kualitas chef

---

# 👤 Modul 2 — Manajemen Pelanggan VIP (MLL 1–N)

## 🎯 Tujuan Bisnis

Mengelola pelanggan eksklusif secara profesional:

* Loyalitas
* Aktivitas kunjungan
* Segmentasi VIP

---

## 🧠 Struktur Data (MLL 1–N)

### 👑 Parent: Customer (Record)

| Atribut       | Tipe    | Keterangan               |
| ------------- | ------- | ------------------------ |
| `customer_id` | int     | ID unik pelanggan        |
| `nama`        | char[]  | Nama pelanggan           |
| `membership`  | char[]  | Silver / Gold / Platinum |
| `firstChild`  | pointer | Awal list aktivitas      |
| `next`        | pointer | Customer berikutnya      |

### 📌 Child: Aktivitas (Tipe Dasar)

| Atribut       | Tipe    |
| ------------- | ------- |
| nilai numerik | int     |
| `next`        | pointer |

> Child **tidak merepresentasikan menu apa pun**, hanya data numerik aktivitas.

### 🔍 Perspektif Teori

* Parent dan child **berbeda tipe** (syarat MLL terpenuhi)
* Relasi 1–N
* Traversal linear sederhana

---

## ⚙️ Fungsionalitas MLL

### 🟩 CRUD + Search

* Insert customer
* Tambah / hapus data aktivitas
* Delete customer
* Search customer berdasarkan ID / nama

### 🟨 Pengelolaan

* Total pelanggan
* Total aktivitas per pelanggan
* Pelanggan paling aktif
* Pelanggan paling pasif

### 💼 Nilai Bisnis

* Analisis loyalitas pelanggan
* Segmentasi layanan eksklusif
* Dasar program premium & personal service
