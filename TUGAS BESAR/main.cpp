#include <iostream>
using namespace std;

struct Menu {
    int kode_menu;
    char nama_menu[50];
    int harga;
    char kategori[20];
    int rating[5];

    Menu* left;
    Menu* right;
};

Menu* root = NULL;

void initBST() {
    root = NULL;
}

Menu* createMenuNode(int kode, const char nama[], int harga, const char kategori[]) {
    Menu* newNode = new Menu;

    newNode->kode_menu = kode;

    int i = 0;
    while (nama[i] != '\0') {
        newNode->nama_menu[i] = nama[i];
        i++;
    }
    newNode->nama_menu[i] = '\0';

    newNode->harga = harga;

    i = 0;
    while (kategori[i] != '\0') {
        newNode->kategori[i] = kategori[i];
        i++;
    }
    newNode->kategori[i] = '\0';

    for (i = 0; i < 5; i++) {
        newNode->rating[i] = 0;
    }

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Menu* insertBST(Menu* current, Menu* newNode) {
    if (current == NULL) {
        return newNode;
    }

    if (newNode->kode_menu < current->kode_menu) {
        current->left = insertBST(current->left, newNode);
    }
    else if (newNode->kode_menu > current->kode_menu) {
        current->right = insertBST(current->right, newNode);
    }
    else {
        cout << "\033[1;31m[ERROR] Kode menu sudah terdaftar! Insert dibatalkan.\033[0m\n";
    }

    return current;
}

Menu* searchBST(Menu* current, int targetKode) {
    if (current == NULL) {
        return NULL;
    }

    if (current->kode_menu == targetKode) {
        return current;
    }

    if (targetKode < current->kode_menu) {
        return searchBST(current->left, targetKode);
    }
    else {
        return searchBST(current->right, targetKode);
    }
}

Menu* findMin(Menu* node) {
    Menu* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Menu* deleteBST(Menu* root, int kode) {
    if (root == NULL) return root;

    if (kode < root->kode_menu) {
        root->left = deleteBST(root->left, kode);
    }
    else if (kode > root->kode_menu) {
        root->right = deleteBST(root->right, kode);
    }
    else {
        if (root->left == NULL) {
            Menu* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Menu* temp = root->left;
            delete root;
            return temp;
        }

        Menu* temp = findMin(root->right);

        root->kode_menu = temp->kode_menu;
        root->harga = temp->harga;
        
        int i = 0;
        while (temp->nama_menu[i] != '\0') {
            root->nama_menu[i] = temp->nama_menu[i];
            i++;
        }
        root->nama_menu[i] = '\0';

        i = 0;
        while (temp->kategori[i] != '\0') {
            root->kategori[i] = temp->kategori[i];
            i++;
        }
        root->kategori[i] = '\0';

        root->right = deleteBST(root->right, temp->kode_menu);
    }
    return root;
}

void inOrder(Menu* current) {
    if (current != NULL) {
        inOrder(current->left);
        cout << "\033[1;36m+------------------------------------------+\033[0m" << endl;
        cout << " \033[1;33mKode    : \033[1;37m" << current->kode_menu << "\033[0m" << endl;
        cout << " \033[1;33mNama    : \033[1;37m" << current->nama_menu << "\033[0m" << endl;
        cout << " \033[1;33mHarga   : \033[1;32mRp " << current->harga << "\033[0m" << endl;
        cout << " \033[1;33mKategori: \033[1;35m" << current->kategori << "\033[0m" << endl;
        cout << "\033[1;36m+------------------------------------------+\033[0m" << endl;
        inOrder(current->right);
    }
}

void preOrder(Menu* current) {
    if (current != NULL) {
        cout << "\033[1;36m+------------------------------------------+\033[0m" << endl;
        cout << " \033[1;33mKode    : \033[1;37m" << current->kode_menu << "\033[0m" << endl;
        cout << " \033[1;33mNama    : \033[1;37m" << current->nama_menu << "\033[0m" << endl;
        cout << " \033[1;33mHarga   : \033[1;32mRp " << current->harga << "\033[0m" << endl;
        cout << " \033[1;33mKategori: \033[1;35m" << current->kategori << "\033[0m" << endl;
        cout << "\033[1;36m+------------------------------------------+\033[0m" << endl;
        preOrder(current->left);
        preOrder(current->right);
    }
}

void postOrder(Menu* current) {
    if (current != NULL) {
        postOrder(current->left);
        postOrder(current->right);
        cout << "\033[1;36m+------------------------------------------+\033[0m" << endl;
        cout << " \033[1;33mKode    : \033[1;37m" << current->kode_menu << "\033[0m" << endl;
        cout << " \033[1;33mNama    : \033[1;37m" << current->nama_menu << "\033[0m" << endl;
        cout << " \033[1;33mHarga   : \033[1;32mRp " << current->harga << "\033[0m" << endl;
        cout << " \033[1;33mKategori: \033[1;35m" << current->kategori << "\033[0m" << endl;
        cout << "\033[1;36m+------------------------------------------+\033[0m" << endl;
    }
}

int main() {
    int pilihanUtama;
    int pilihanBST;

    initBST();

    do {
        cout << "\n\033[1;34m============================================\033[0m\n";
        cout << "\033[1;36m      S I S T E M   R E S T O R A N       \033[0m\n";
        cout << "\033[1;34m============================================\033[0m\n";
        cout << "\033[1;33m[1]\033[0m Menu Fine Dining (Database BST)\n";
        cout << "\033[1;33m[2]\033[0m Pelanggan VIP (Linked List)\n";
        cout << "\033[1;31m[0]\033[0m Exit Program\n";
        cout << "\033[1;34m--------------------------------------------\033[0m\n";
        cout << "Pilihan Anda >> ";
        cin >> pilihanUtama;

        switch (pilihanUtama) {

        case 1:
            do {
                cout << "\n\n\033[1;35m:::::::::  FINE DINING MANAGER  :::::::::\033[0m\n";
                cout << "\033[1;32m 1.\033[0m Insert Menu Baru\n";
                cout << "\033[1;32m 2.\033[0m Cari Menu (Searching)\n";
                cout << "\033[1;32m 3.\033[0m Update Data Menu\n";
                cout << "\033[1;31m 4.\033[0m Hapus Menu (Delete)\n";
                cout << "\033[1;36m 5.\033[0m Lihat Semua Menu (Traversal)\n";
                cout << "\033[1;36m 6.\033[0m Statistik Data\n";
                cout << "\033[1;33m 0.\033[0m Kembali\n";
                cout << "\033[1;35m:::::::::::::::::::::::::::::::::::::::::\033[0m\n";
                cout << "Aksi >> ";
                cin >> pilihanBST;

                switch (pilihanBST) {

                case 1: {
                    int kode, harga;
                    char nama[50];
                    char kategori[20];

                    cout << "\n\033[1;32m--- TAMBAH MENU BARU ---\033[0m\n";
                    cout << "Kode Menu (Angka) : ";
                    cin >> kode;
                    cin.ignore();

                    cout << "Nama Hidangan     : ";
                    cin.getline(nama, 50);

                    cout << "Harga (Rp)        : ";
                    cin >> harga;
                    cin.ignore();

                    cout << "Kategori          : ";
                    cin.getline(kategori, 20);

                    Menu* newMenu = createMenuNode(kode, nama, harga, kategori);
                    root = insertBST(root, newMenu);

                    cout << "\n\033[1;32m[SUKSES] Menu berhasil disimpan ke database.\033[0m\n";
                    break;
                }

                case 2: {
                    if (root == NULL) {
                        cout << "\n\033[1;31m[INFO] Database menu masih kosong.\033[0m\n";
                    } else {
                        int cariKode;
                        cout << "\n\033[1;34m--- PENCARIAN MENU ---\033[0m\n";
                        cout << "Masukkan Kode Menu : ";
                        cin >> cariKode;

                        Menu* hasil = searchBST(root, cariKode);

                        if (hasil != NULL) {
                            cout << "\n\033[1;32m[DITEMUKAN] Data tersedia:\033[0m\n";
                            cout << "\033[1;36m+------------------------------------------+\033[0m" << endl;
                            cout << " \033[1;33mKode    : \033[1;37m" << hasil->kode_menu << "\033[0m" << endl;
                            cout << " \033[1;33mNama    : \033[1;37m" << hasil->nama_menu << "\033[0m" << endl;
                            cout << " \033[1;33mHarga   : \033[1;32mRp " << hasil->harga << "\033[0m" << endl;
                            cout << " \033[1;33mKategori: \033[1;35m" << hasil->kategori << "\033[0m" << endl;
                            cout << "\033[1;36m+------------------------------------------+\033[0m" << endl;
                        } else {
                            cout << "\n\033[1;31m[404] Menu dengan kode " << cariKode << " TIDAK DITEMUKAN.\033[0m\n";
                        }
                    }
                    break;
                }

                case 3:
                    cout << "\n\033[1;33m[DEV] Fitur Update sedang dalam pengembangan.\033[0m\n";
                    break;

                case 4: {
                    if (root == NULL) {
                        cout << "\n\033[1;31m[INFO] Database menu masih kosong.\033[0m\n";
                    } else {
                        int hapusKode;
                        cout << "\n\033[1;31m--- HAPUS MENU ---\033[0m\n";
                        cout << "Masukkan Kode Menu : ";
                        cin >> hapusKode;

                        Menu* cek = searchBST(root, hapusKode);
                        if (cek == NULL) {
                            cout << "\033[1;31m[GAGAL] Menu tidak ditemukan.\033[0m\n";
                        } else {
                            root = deleteBST(root, hapusKode);
                            cout << "\033[1;32m[SUKSES] Menu dengan kode " << hapusKode << " telah dihapus.\033[0m\n";
                        }
                    }
                    break;
                }

                case 5: {
                    int pilihanTraversal;
                    cout << "\n\033[1;36m--- METODE TAMPILAN ---\033[0m\n";
                    cout << "[1] In-Order (Urut Kode Kecil -> Besar)\n";
                    cout << "[2] Pre-Order\n";
                    cout << "[3] Post-Order\n";
                    cout << "Pilih Tampilan >> ";
                    cin >> pilihanTraversal;

                    if (root == NULL) {
                        cout << "\n\033[1;31m[EMPTY] Belum ada data menu tersimpan!\033[0m\n";
                    } else {
                        cout << "\n\033[1;34m======= DAFTAR MENU =======\033[0m\n";
                        switch (pilihanTraversal) {
                        case 1:
                            inOrder(root);
                            break;
                        case 2:
                            preOrder(root);
                            break;
                        case 3:
                            postOrder(root);
                            break;
                        default:
                            cout << "\033[1;31mPilihan tidak valid!\033[0m\n";
                        }
                        cout << "\033[1;34m===========================\033[0m\n";
                    }
                    break;
                }

                case 0:
                    cout << "\n\033[1;33mKembali ke Dashboard Utama...\033[0m\n";
                    break;

                default:
                    cout << "\033[1;31mInput tidak valid.\033[0m\n";
                }

            } while (pilihanBST != 0);
            break;

        case 2:
            cout << "\n\033[1;33m[MLL] Modul Pelanggan VIP belum diaktifkan.\033[0m\n";
            break;

        case 0:
            cout << "\n\033[1;36mTerima kasih bos!\033[0m\n";
            cout << "\033[1;36mSemoga restoran semakin sukses!\033[0m\n";
            break;

        default:
            cout << "\033[1;31mPilihan tidak valid!\033[0m\n";
        }

    } while (pilihanUtama != 0);

    return 0;
}
