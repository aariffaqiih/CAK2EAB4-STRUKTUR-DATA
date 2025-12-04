## 📝 **Sistem Manajemen Menu Restoran**


# 👥 **Anggota Kelompok**

| NIM              | Nama                               |
| ---------------- | ---------------------------------- |
| **103112430182** | 'Aarif Rahmaan Jalaluddin Faqiih   |
| **103112430267** | Raden Aurel Aditya Kusumawaningyun |

---

# 🍽️ **Sistem Manajemen Menu Restoran Mewah**

Proyek ini mengelola data menu pada restoran mewah dengan dua struktur utama:

* **BST (Binary Search Tree)**
  Menyimpan data menu dengan key berupa `kode_menu`.
  Cocok untuk operasi pencarian cepat dan terstruktur.

* **MLL (Multi Linked List)**
  Mengelola sekumpulan "tag" pada setiap menu, misalnya:
  `"spicy"`, `"chef's favorite"`, `"limited"`, `"premium pick"`.
  
---

# 📦 **Struktur Data**

## **1. BST — Data Menu**

Setiap node BST menyimpan record dengan atribut:

| Atribut     | Tipe Data | Deskripsi                                                    |
| ----------- | --------- | ------------------------------------------------------------ |
| `kode_menu` | int       | **Key unik**, digunakan sebagai acuan dalam BST              |
| `nama_menu` | string    | Nama hidangan dalam restoran                                 |
| `harga`     | int       | Harga menu                                                   |
| `kategori`  | string    | Salah satu dari: `Signature`, `Premium`, `Seasonal`, `Vegan` |
| `rating[5]` | int array | Statistik jumlah vote ⭐1 sampai ⭐5                        |

---

## **2. MLL — Tag Menu**

Struktur MLL dirancang sebagai hubungan **1–N**:

* **Parent:** Data menu (record)
* **Child:** Tag (string)

Setiap menu dapat memiliki banyak tag tambahan seperti:

* `"recommended"`
* `"best seller"`
* `"spicy"`
* `"chef's favorite"`

---

# 🔧 **Fungsionalitas Program**

## **A. CRUD**

* Tambah menu (insert BST berdasarkan `kode_menu`)
* Edit `nama`, `harga`, `kategori`
* Tambah rating: menambah vote ⭐1–⭐5
* Tambah tag ke menu (insert child MLL)
* Hapus menu (delete BST node)
* Hapus tag pada menu tertentu

---

## **B. Search**

* Cari menu berdasarkan:

  * `kode_menu`
  * `nama_menu`
  * `kategori` (menghasilkan lebih dari satu menu)

---

## **C. Traversal BST**

* In-order
* Pre-order
* Post-order

---

## **D. Counting**

* Total menu
* Total menu dalam kategori tertentu
* Total tag pada menu tertentu

---

## **E. Statistik (Analisis BST + Rating)**

* Menu dengan rating rata-rata tertinggi
* Menu dengan rating rata-rata terendah
* Menu dengan jumlah vote ⭐5 terbanyak
* Menu dengan harga tertinggi
* Menu dengan harga terendah
