# 🍽️ **Manajemen Menu Fine Dining**

### *Quality & Customer Preference System*

---

## 👥 **1. Anggota Kelompok**

| NIM              | Nama                               |
| ---------------- | ---------------------------------- |
| **103112430182** | 'Aarif Rahmaan Jalaluddin Faqiih   |
| **103112430267** | Raden Aurel Aditya Kusumawaningyun |

---

## ⚙️ **2. Spesifikasi**

### 🔹 a. BST : menyimpan **Menu**

📦 **Node (record) `Menu`:**

* `kode_menu` : **int** (unik, key BST)
* `nama_menu` : **string**
* `harga` : **int**
* `kategori` : **string** (pilihan: **Signature**, **Premium**, **Seasonal**, **Vegan**)
* `rating[5]` : **int array**

  * index 0 → jumlah vote ★1
  * index 4 → jumlah vote ★5

---

### 🔹 b. MLL 1–N : menyimpan **Pelanggan VIP & Favorit Menu**

👤 **Parent list** = `Customer` (record):

* `customer_id` : **int** (unik)
* `nama` : **string**
* `membership` : **string** (pilihan : *Silver*, *Gold*, *Platinum*)

⭐ **Child list** = favorit/kunjungan menu → **`kode_menu` (int)**

* Child berupa tipe dasar (`int`) → mereferensikan kode menu dari BST.

---

## 🧩 **3. Fungsionalitas (wajib + tambahan)**

### 🟦 A. CRUD & Search (BST : Menu)

#### ✳️ **Create**

* Insert menu baru (`BST_insert` by `kode_menu`)
* Jika `kode_menu` belum ada → buat node baru
* Jika sudah ada → user dapat mengubah `nama`, `harga`, atau `kategori`

#### 🔍 **Read/Search**

* Cari by `kode_menu` (unik) → return 1 menu
* Cari by `nama_menu` → return 0..n match
* Filter by `kategori` → return list

#### 🛠️ **Update**

* Ubah `nama`, `harga`, `kategori`
* Tambah vote rating: input 1..5 → `rating[n-1]++`

#### 🗑️ **Delete**

* Hapus menu by `kode_menu` (BST delete)
* Jika dihapus, **child MLL yang menyimpan kode_menu perlu di-handle**
  (opsional: hapus referensi dari MLL)

---

### 🟩 B. CRUD (MLL : Customer & Favorites)

* **Create** : tambah customer baru
* **Read** : list customers & list favorite menu codes
* **Update** : tambah favorite (`kode_menu` int); hapus favorite
* **Delete** : hapus customer beserta semua child favorite

---

### 🟧 C. Traversal BST (tampil)

* In-order
* Pre-order
* Post-order
* Level-order *(opsional)*

---

### 🟨 D. Counting & Pengelolaan

* Total menu
* Total menu per kategori
* Total customers
* Total favorite entries per customer

---

### 🟥 E. Statistik (analisis di BST)

* Menu dengan **rata-rata rating tertinggi** & **terendah**
* Menu dengan **jumlah vote ★5 terbanyak**
* Menu dengan **harga tertinggi** & **terendah**
* Menampilkan menu yang memiliki **total vote == N**

---

## 📌 **4. Topik dan Detail**

### 🎯 **Judul**

**Manajemen Menu Fine Dining | Quality & Customer Preference System**

### 📂 **Detail data yang disimpan**

* `kode_menu` (**unik**), `nama_menu`, `harga`, `kategori` (**Signature**, **Premium**, **Seasonal**, **Vegan**), `rating[5]`

  * jika `kode_menu` belum ada → buat node baru
  * jika sudah ada → bisa menambahkan rating atau mengubah `harga`, `kategori`, atau `nama_menu`

---

### 🔗 **MLL (parent → child)**

* Parent = `Customer` (`{customer_id, nama, membership}`)
* Child = `kode_menu` (int) → list favorit/kunjungan

---

### 🌳 **View / Traversal (BST)**

* in-order
* pre-order
* post-order
* level-order

---

### 🔎 **Cari by**

* `kode_menu`
* `nama_menu`
* `kategori`

---

### 🗑️ **Hapus**

* Hapus menu by `kode_menu`

---

### 🧹 **Hapus (atribut) dari entitas tertentu**

* Hapus favorite (child) dari `Customer` tertentu
* Reset ratings dari satu `Menu` *(opsional)*

---

### 🧮 **Counting total**

* total menu
* total customers
* total menu per kategori

---

### 📊 **View berdasarkan & hitung**

* tampilkan menu berdasarkan kategori
* hitung jumlah menu tiap kategori

---

### 📈 **Menampilkan (statistik)**

* menu dengan rata-rata rating tertinggi & terendah
* menu dengan harga tertinggi & terendah

---

### ⭐ **Menampilkan menu dengan jumlah vote tertentu**

* contoh: semua menu dengan **total vote == N**
