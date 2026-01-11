#include "resto.h"

// ==================== BST MENU ====================
void menuBST() {
    int pilihanBST;
    do {
        clearScreen();
        cout << CYAN << BOLD;
        cout << "\n+=============================================+\n";
        cout << "|       MANAJEMEN MENU MAKANAN (BST)        |\n";
        cout << "+=============================================+\n";
        cout << RESET;
        cout << "1.  Tambah Menu Baru\n";
        cout << "2.  Hapus Menu\n";
        cout << "3.  Cari Menu (by Kode)\n";
        cout << "4.  Cari Menu (by Nama)\n";
        cout << "5.  Cari Menu (by Kategori)\n";
        cout << "6.  Update Menu\n";
        cout << "7.  Tampilkan Semua Menu (3 Traversal)\n";
        cout << "8.  Hitung Jumlah Menu\n";
        cout << "9.  Beri Rating Menu\n";
        cout << "10. Tampilkan Menu Termahal\n";
        cout << "11. Tampilkan Menu Termurah\n";
        cout << "12. Tampilkan Menu Rating Tertinggi\n";
        cout << "13. Tampilkan Menu Rating Terendah\n";
        cout << "14. Load Dummy Data\n";
        cout << RED << "0.  Kembali\n" << RESET;
        cout << BOLD << "Pilihan : " << RESET;
        cin >> pilihanBST;
        cin.ignore();

        switch (pilihanBST) {
            case 1: {
                clearScreen();
                cout << "\n--- Tambah Menu Baru ---\n";
                int kode, harga;
                string nama, kategori;
                cout << "Kode Menu: "; cin >> kode;
                cin.ignore();
                cout << "Nama Menu: "; getline(cin, nama);
                cout << "Harga: "; cin >> harga;
                cin.ignore();
                cout << "Kategori: "; getline(cin, kategori);
                
                if (searchBST(root, kode) == nullptr) {
                    Menu* newMenu = createMenu(kode, nama, harga, kategori);
                    root = insertBST(root, newMenu);
                    cout << GREEN << "Menu berhasil ditambahkan!\n" << RESET;
                } else {
                    cout << RED << "Kode menu sudah ada!\n" << RESET;
                }
                pauseScreen();
                break;
            }

            case 2: {
                clearScreen();
                cout << "\n--- Hapus Menu ---\n";
                if (isBSTEmpty()) { 
                    cout << RED << "BST Kosong.\n" << RESET; 
                    pauseScreen();
                    break; 
                }
                int kode;
                cout << "Kode Menu yang akan dihapus: "; cin >> kode;
                bool isDeleted = false;
                root = deleteMenuBST(root, kode, isDeleted);
                if (isDeleted) cout << GREEN << "Menu berhasil dihapus.\n" << RESET;
                else cout << RED << "Menu tidak ditemukan.\n" << RESET;
                pauseScreen();
                break;
            }

            case 3: {
                clearScreen();
                cout << "\n--- Cari Menu by Kode ---\n";
                if (isBSTEmpty()) { 
                    cout << RED << "BST Kosong.\n" << RESET; 
                    pauseScreen();
                    break; 
                }
                int kode;
                cout << "Masukkan Kode Menu: "; cin >> kode;
                Menu* result = searchBST(root, kode);
                if (result) {
                    cout << GREEN << "Menu ditemukan:\n" << RESET;
                    cout << "Kode Menu : " << result->kode_menu << endl;
                    cout << "Nama      : " << BOLD << result->nama_menu << RESET << endl;
                    cout << GREEN << "Harga     : " << formatRupiah(result->harga) << RESET << endl;
                    cout << "Kategori  : " << result->kategori << endl;
                    printRating(result->rating);
                } else {
                    cout << RED << "Menu tidak ditemukan.\n" << RESET;
                }
                pauseScreen();
                break;
            }

            case 4: {
                clearScreen();
                cout << "\n--- Cari Menu by Nama ---\n";
                if (isBSTEmpty()) { 
                    cout << RED << "BST Kosong.\n" << RESET; 
                    pauseScreen();
                    break; 
                }
                string keyword;
                cout << "Masukkan keyword nama: "; getline(cin, keyword);
                bool found = false;
                cout << "\nHasil Pencarian:\n";
                searchByNameBST(root, keyword, found);
                if (!found) cout << RED << "Tidak ditemukan menu dengan keyword tersebut.\n" << RESET;
                pauseScreen();
                break;
            }

            case 5: {
                clearScreen();
                cout << "\n--- Cari Menu by Kategori ---\n";
                if (isBSTEmpty()) { 
                    cout << RED << "BST Kosong.\n" << RESET; 
                    pauseScreen();
                    break; 
                }
                string kategori;
                cout << "Masukkan kategori: "; getline(cin, kategori);
                int count = 0;
                cout << "\nMenu dalam kategori '" << kategori << "':\n";
                searchByCategoryBST(root, kategori, count);
                if (count == 0) cout << RED << "Tidak ada menu dalam kategori tersebut.\n" << RESET;
                else cout << "\nTotal: " << count << " menu\n";
                pauseScreen();
                break;
            }

            case 6: {
                clearScreen();
                cout << "\n--- Update Menu ---\n";
                if (isBSTEmpty()) { 
                    cout << RED << "BST Kosong.\n" << RESET; 
                    pauseScreen();
                    break; 
                }
                int kode;
                cout << "Masukkan Kode Menu yang akan diupdate: "; cin >> kode;
                Menu* target = searchBST(root, kode);
                if (target) {
                    updateMenuBST(target);
                } else {
                    cout << RED << "Menu tidak ditemukan.\n" << RESET;
                }
                pauseScreen();
                break;
            }

            case 7: {
                clearScreen();
                cout << "\n--- Tampilkan Semua Menu ---\n";
                if (isBSTEmpty()) { 
                    cout << RED << "BST Kosong.\n" << RESET; 
                } else {

                    int pilihanTraversal;
                    cout << YELLOW << BOLD;
                    cout << "\n+------------------------------+\n";
                    cout << "|    Pilih Metode Traversal    |\n";
                    cout << "+------------------------------+\n";
                    cout << RESET;
                    cout << "1. In-Order\n";
                    cout << "2. Pre-Order\n";
                    cout << "3. Post-Order\n";
                    cout << "Pilihan : ";
                    cin >> pilihanTraversal;

                    cout << GREEN << BOLD;
                    cout << "\n+-----------------------+\n";
                    cout << "|    Hasil Traversal    |\n";
                    cout << "+-----------------------+\n";
                    cout << RESET;

                    if (pilihanTraversal == 1) {
                        inOrderTraversal(root);
                    }
                    else if (pilihanTraversal == 2) {
                        preOrderTraversal(root);
                    }
                    else if (pilihanTraversal == 3) {
                        postOrderTraversal(root);
                    }
                    else {
                        cout << RED << "Pilihan traversal tidak valid!\n" << RESET;
                    }
                }
                pauseScreen();
                break;
            }

            case 8: {
                clearScreen();
                cout << "\n--- Counting Menu ---\n";
                cout << "Total Menu di Database: " << BOLD << countTotalMenu(root) << RESET << " item.\n";
                cout << "Ingin hitung per kategori? (y/n): ";
                char ans; cin >> ans; cin.ignore();
                if(ans == 'y' || ans == 'Y') {
                    string kat; cout << "Masukkan nama kategori: "; getline(cin, kat);
                    int count = countMenuByCategory(root, kat);
                    cout << "Jumlah menu " << kat << ": " << BOLD << count << RESET << endl;
                }
                pauseScreen();
                break;
            }

            case 9: {
                clearScreen();
                cout << "\n--- Beri Rating Menu ---\n";
                if (isBSTEmpty()) { 
                    cout << RED << "BST Kosong.\n" << RESET; 
                    pauseScreen();
                    break; 
                }
                int kode, rat;
                cout << "Kode Menu: "; cin >> kode;
                Menu* m = searchBST(root, kode);
                if(m){
                    cout << "Rating (1-5): "; cin >> rat;
                    if(addRating(m, rat)) cout << GREEN << "Terima kasih! Rating berhasil.\n" << RESET;
                    else cout << YELLOW << "Rating tidak valid (1-5).\n" << RESET;
                } else cout << RED << "Menu tak ditemukan.\n" << RESET;
                pauseScreen();
                break;
            }

            case 10: {
                clearScreen();
                cout << "\n--- Menu Termahal ---\n";
                showHighestPrice();
                pauseScreen();
                break;
            }

            case 11: {
                clearScreen();
                cout << "\n--- Menu Termurah ---\n";
                showLowestPrice();
                pauseScreen();
                break;
            }

            case 12: {
                clearScreen();
                cout << "\n--- Menu Rating Tertinggi ---\n";
                showBestMenu();
                pauseScreen();
                break;
            }

            case 13: {
                clearScreen();
                cout << "\n--- Menu Rating Terendah ---\n";
                showWorstMenu();
                pauseScreen();
                break;
            }

            case 14: {
                clearScreen();
                loadDummyDataBST();
                loadDummyRatingBST(root);
                cout << GREEN << "Dummy data berhasil dimuat.\n" << RESET;
                pauseScreen();
                break;
            }

            case 0:
                cout << "Kembali ke Menu Utama...\n";
                break;

            default:
                cout << RED << "Pilihan tidak valid!\n" << RESET;
                pauseScreen();
        }
    } while (pilihanBST != 0);
}

// ==================== MLL MENU ====================
void menuMLL() {
    int pilihanMLL;
    do {
        clearScreen();
        cout << BLUE << BOLD;
        cout << "\n+=============================================+\n";
        cout << "|           MANAJEMEN PELANGGAN VIP          |\n";
        cout << "+=============================================+\n";
        cout << RESET;
        cout << "1.  Tambah Customer\n";
        cout << "2.  Tampilkan Semua Customer\n";
        cout << "3.  Cari Customer (by ID)\n";
        cout << "4.  Cari Customer (by Nama)\n";
        cout << "5.  Tambah Aktivitas Customer\n";
        cout << "6.  Hapus Aktivitas Customer\n";
        cout << "7.  Hapus Semua Aktivitas Customer\n";
        cout << "8.  Hapus Customer\n";
        cout << "9.  Tampilkan Aktivitas Customer\n";
        cout << "10. Hitung Total Customer\n";
        cout << "11. Hitung Aktivitas per Customer\n";
        cout << "12. Customer Paling Aktif\n";
        cout << "13. Customer Paling Pasif\n";
        cout << "14. Total Aktivitas Sistem\n";
        cout << RED << "0.  Kembali\n" << RESET;
        cout << BOLD << "Pilihan : " << RESET;
        cin >> pilihanMLL;
        cin.ignore();

        switch (pilihanMLL) {
            case 1: {
                clearScreen();
                cout << "\n--- Tambah Customer Baru ---\n";
                int id;
                string nama, membership;
                cout << "ID Customer: "; cin >> id; cin.ignore();
                cout << "Nama Customer: "; getline(cin, nama);
                cout << "Membership (Platinum/Gold/Silver): "; getline(cin, membership);
                MLL_InsertCustomer(id, nama, membership);
                pauseScreen();
                break;
            }

            case 2: {
                clearScreen();
                MLL_ShowCustomers();
                pauseScreen();
                break;
            }

            case 3: {
                clearScreen();
                cout << "\n--- Cari Customer by ID ---\n";
                int id;
                cout << "Masukkan ID Customer: "; cin >> id;
                Customer* cust = searchCustomer(id);
                if (cust) {
                    cout << GREEN << "✓ Customer ditemukan:\n" << RESET;
                    cout << "ID: " << cust->id << "\n";
                    cout << "Nama: " << BOLD << cust->nama << RESET << "\n";
                    cout << "Membership: " << cust->membership << "\n";
                    int actCount = MLL_CountActivitiesPerCustomer(id);
                    if (actCount >= 0) {
                        cout << "Jumlah Aktivitas: " << actCount << "\n";
                    }
                } else {
                    cout << RED << "✗ Customer dengan ID " << id << " tidak ditemukan.\n" << RESET;
                }
                pauseScreen();
                break;
            }

            case 4: {
                clearScreen();
                cout << "\n--- Cari Customer by Nama ---\n";
                string nama;
                cout << "Masukkan Nama (atau sebagian nama): "; getline(cin, nama);
                searchCustomerByName(nama);
                pauseScreen();
                break;
            }

            case 5: {
                clearScreen();
                cout << "\n--- Tambah Aktivitas Customer ---\n";
                int id, nilai;
                cout << "ID Customer: "; cin >> id;
                // Validasi customer ada
                if (!isCustomerExist(id)) {
                    cout << RED << "Customer dengan ID " << id << " tidak ditemukan.\n" << RESET;
                    pauseScreen();
                    break;
                }
                cout << "Nilai Aktivitas: "; cin >> nilai;
                MLL_AddActivity(id, nilai);
                pauseScreen();
                break;
            }

            case 6: {
                clearScreen();
                cout << "\n--- Hapus Aktivitas Customer ---\n";
                int id, nilai;
                cout << "ID Customer: "; cin >> id;
                // Validasi customer ada
                if (!isCustomerExist(id)) {
                    cout << RED << "Customer dengan ID " << id << " tidak ditemukan.\n" << RESET;
                    pauseScreen();
                    break;
                }
                cout << "Nilai Aktivitas yang dihapus: "; cin >> nilai;
                MLL_RemoveActivity(id, nilai);
                pauseScreen();
                break;
            }

            case 7: {
                clearScreen();
                cout << "\n--- Hapus Semua Aktivitas Customer ---\n";
                int id;
                cout << "ID Customer: "; cin >> id;
                // Validasi customer ada
                if (!isCustomerExist(id)) {
                    cout << RED << "Customer dengan ID " << id << " tidak ditemukan.\n" << RESET;
                    pauseScreen();
                    break;
                }
                MLL_DeleteAllActivities(id);
                pauseScreen();
                break;
            }

            case 8: {
                clearScreen();
                cout << "\n--- Hapus Customer ---\n";
                int id;
                cout << "ID Customer yang dihapus: "; cin >> id;
                // Validasi customer ada
                if (!isCustomerExist(id)) {
                    cout << RED << "Customer dengan ID " << id << " tidak ditemukan.\n" << RESET;
                    pauseScreen();
                    break;
                }
                MLL_DeleteCustomer(id);
                pauseScreen();
                break;
            }

            case 9: {
                clearScreen();
                cout << "\n--- Aktivitas Customer ---\n";
                int id;
                cout << "ID Customer: "; cin >> id;
                // Validasi customer ada
                if (!isCustomerExist(id)) {
                    cout << RED << "Customer dengan ID " << id << " tidak ditemukan.\n" << RESET;
                    pauseScreen();
                    break;
                }
                MLL_ShowFavoritesPerCustomer(id);
                pauseScreen();
                break;
            }

            case 10: {
                clearScreen();
                cout << "\n--- Hitung Total Customer ---\n";
                int total = MLL_CountTotalCustomers();
                cout << "Total Customer: " << BOLD << total << RESET << " orang\n";
                pauseScreen();
                break;
            }

            case 11: {
                clearScreen();
                cout << "\n--- Hitung Aktivitas per Customer ---\n";
                int id;
                cout << "ID Customer: "; cin >> id;
                // Validasi customer ada
                if (!isCustomerExist(id)) {
                    cout << RED << "Customer dengan ID " << id << " tidak ditemukan.\n" << RESET;
                    pauseScreen();
                    break;
                }
                int count = MLL_CountActivitiesPerCustomer(id);
                if (count >= 0) {
                    cout << "Jumlah Aktivitas: " << BOLD << count << RESET << " item\n";
                }
                pauseScreen();
                break;
            }

            case 12: {
                clearScreen();
                cout << "\n--- Customer Paling Aktif ---\n";
                MLL_FindMostActiveCustomer();
                pauseScreen();
                break;
            }

            case 13: {
                clearScreen();
                cout << "\n--- Customer Paling Pasif ---\n";
                MLL_FindLeastActiveCustomer();
                pauseScreen();
                break;
            }

            case 14: {
                clearScreen();
                cout << "\n--- Total Aktivitas Sistem ---\n";
                int total = MLL_CountTotalActivities();
                cout << "Total Aktivitas Seluruh Customer: " << BOLD << total << RESET << " item\n";
                pauseScreen();
                break;
            }

            case 0:
                cout << "Kembali ke Menu Utama...\n";
                break;

            default:
                cout << RED << "Pilihan tidak valid!\n" << RESET;
                pauseScreen();
        }
    } while (pilihanMLL != 0);
}

// ==================== MAIN FUNCTION ====================
int main() {
    int pilihanUtama;

    // Initialize data structures
    initBST();
    initMLL();
    
    // Load dummy data
    loadDummyDataBST();
    loadDummyRatingBST(root);
    loadDummyDataMLL();

    do {
        clearScreen();
        cout << CYAN << BOLD;
        cout << "\n+=============================================+\n";
        cout << "|         SISTEM MANAJEMEN RESTORAN          |\n";
        cout << "|                RESTOCRAFT                  |\n";
        cout << "+=============================================+\n";
        cout << RESET;
        cout << CYAN << "1. " << RESET << "Manajemen Menu Makanan (Binary Search Tree)\n";
        cout << CYAN << "2. " << RESET << "Manajemen Pelanggan VIP (Multi Linked List)\n";
        cout << RED  << "0. Exit\n" << RESET;
        cout << BOLD << "Pilihan : " << RESET;
        cin >> pilihanUtama;

        switch (pilihanUtama) {
            case 1:
                menuBST();
                break;
            case 2:
                menuMLL();
                break;
            case 0:
                cout << GREEN << "\nTerima kasih telah menggunakan sistem manajemen restoran RestoCraft!\n" << RESET;
                cout << YELLOW << "Program akan keluar...\n" << RESET;
                break;
            default:
                cout << RED << "Pilihan tidak valid!\n" << RESET;
                pauseScreen();
        }
    } while (pilihanUtama != 0);

    return 0;
}