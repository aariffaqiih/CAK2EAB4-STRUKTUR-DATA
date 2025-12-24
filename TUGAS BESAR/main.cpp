#include <iostream>
#include <string>
using namespace std;

struct Menu {
    int kode_menu;
    string nama_menu;
    int harga;
    string kategori;
    int rating[5];

    Menu* left;
    Menu* right;
};

Menu* root = nullptr;

void initBST() {
    root = nullptr;
};

bool isBSTEmpty() {
    return root == nullptr;
};

Menu *createMenu(
    int kode_menu,
    const string &nama_menu,
    int harga,
    const string &kategori
) {
    Menu* newNode = new Menu();

    newNode->kode_menu = kode_menu;
    newNode->nama_menu = nama_menu;
    newNode->harga = harga;
    newNode->kategori = kategori;

    for (int i = 0; i < 5; i++) {
        newNode->rating[i] = 0;
    }

    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
};

Menu* insertBST(
    Menu* current,
    Menu* newNode
) {
    if (current == nullptr) {
        return newNode;
    }

    if (newNode->kode_menu < current->kode_menu) {
        current->left = insertBST(current->left, newNode);
    }
    else if (newNode->kode_menu > current->kode_menu) {
        current->right = insertBST(current->right, newNode);
    }
    else {
        cout << "Kode menu sudah terdaftar! Insert dibatalkan.\n";
    }
    return current;
};

int main() {
    int pilihanUtama;
    int pilihanBST;
    int pilihanMLL;

    do {
        cout << "\n============================================\n";
        cout << " Selamat datang!\n";
        cout << "============================================\n";
        cout << "1. Manajemen Menu Makanan (BST)\n";
        cout << "2. Manajemen Pelanggan VIP (MLL)\n";
        cout << "0. Exit\n";
        cout << "Pilihan Anda: ";
        cin >> pilihanUtama;

        switch (pilihanUtama) {

        case 1:
            do {
                cout << "\n========== MANAJEMEN MENU (BST) ==========\n";
                cout << "1. Insert Menu\n";
                cout << "2. Search Menu\n";
                cout << "3. Update Menu\n";
                cout << "4. Delete Menu\n";
                cout << "5. Traversal Menu\n";
                cout << "6. Statistik Menu\n";
                cout << "7. Counting Menu\n";
                cout << "0. Kembali ke Menu Utama\n";
                cout << "Pilihan Anda: ";
                cin >> pilihanBST;

                switch (pilihanBST) {
                case 1:
                    cout << "[BST] Insert Menu (belum diimplementasikan)\n";
                    break;
                case 2:
                    cout << "[BST] Search Menu (belum diimplementasikan)\n";
                    break;
                case 3:
                    cout << "[BST] Update Menu (belum diimplementasikan)\n";
                    break;
                case 4:
                    cout << "[BST] Delete Menu (belum diimplementasikan)\n";
                    break;
                case 5:
                    cout << "[BST] Traversal Menu (belum diimplementasikan)\n";
                    break;
                case 6:
                    cout << "[BST] Statistik Menu (belum diimplementasikan)\n";
                    break;
                case 7:
                    cout << "[BST] Counting Menu (belum diimplementasikan)\n";
                    break;
                case 0:
                    cout << "Kembali ke Menu Utama...\n";
                    break;
                default:
                    cout << "Pilihan tidak valid!\n";
                }
            } while (pilihanBST != 0);
            break;

        case 2:
            do {
                cout << "\n====== MANAJEMEN PELANGGAN VIP (MLL) ======\n";
                cout << "1. Insert Customer\n";
                cout << "2. Search Customer\n";
                cout << "3. Tambah Aktivitas Customer\n";
                cout << "4. Hapus Aktivitas Customer\n";
                cout << "5. Delete Customer\n";
                cout << "6. Statistik Pelanggan\n";
                cout << "7. Counting Pelanggan\n";
                cout << "0. Kembali ke Menu Utama\n";
                cout << "Pilihan Anda: ";
                cin >> pilihanMLL;

                switch (pilihanMLL) {
                case 1:
                    cout << "[MLL] Insert Customer (belum diimplementasikan)\n";
                    break;
                case 2:
                    cout << "[MLL] Search Customer (belum diimplementasikan)\n";
                    break;
                case 3:
                    cout << "[MLL] Tambah Aktivitas (belum diimplementasikan)\n";
                    break;
                case 4:
                    cout << "[MLL] Hapus Aktivitas (belum diimplementasikan)\n";
                    break;
                case 5:
                    cout << "[MLL] Delete Customer (belum diimplementasikan)\n";
                    break;
                case 6:
                    cout << "[MLL] Statistik Pelanggan (belum diimplementasikan)\n";
                    break;
                case 7:
                    cout << "[MLL] Counting Pelanggan (belum diimplementasikan)\n";
                    break;
                case 0:
                    cout << "Kembali ke Menu Utama...\n";
                    break;
                default:
                    cout << "Pilihan tidak valid!\n";
                }
            } while (pilihanMLL != 0);
            break;

        case 0:
            cout << "\nTerima kasih Bos,\n";
            cout << "Semoga restoran fine dining Anda terus berjaya!\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihanUtama != 0);

    return 0;
};
