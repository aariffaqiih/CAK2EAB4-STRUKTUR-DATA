#include <iostream>
#include <string>

using namespace std;

#define RESET  "\033[0m"
#define BOLD   "\033[1m"

#define RED    "\033[38;2;255;112;112m"
#define GREEN  "\033[38;2;112;255;112m"
#define YELLOW "\033[38;2;255;255;112m"
#define CYAN   "\033[38;2;112;255;255m"

string formatRupiah(int harga);

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
        cout << RED << "Kode sudah terdaftar! Insert dibatalkan.\n" << RESET;
    }
    return current;
};

Menu* searchBST(
    Menu* current,
    int kode_menu
) {
    if (current == nullptr) {
        return current;
    }

    if (kode_menu == current->kode_menu) {
        return current;
    }
    else if (kode_menu < current->kode_menu) {
        return searchBST(current->left, kode_menu);
    }
    else {
        return searchBST(current->right, kode_menu);
    }
};

bool addRating(Menu* menu, int ratingValue) {
    if (menu == nullptr) {
        return false;
    }

    if (ratingValue < 1 || ratingValue > 5) {
        return false;
    }

    menu->rating[ratingValue - 1]++;
    return true;
};

void printRating(const int rating[5]) {
    int totalVote = 0;
    int totalScore = 0;

    for (int i = 0; i < 5; i++) {
        totalVote += rating[i];
        totalScore += rating[i] * (i + 1);
    }

    cout << YELLOW << "Rating    : " << RESET;
    if (totalVote == 0) {
        cout << RED << "Belum ada rating\n" << RESET;
    } else {
        double average = static_cast<double>(totalScore) / totalVote;
        cout << YELLOW << average << " / 5 (" << totalVote << " vote)" << RESET << "\n";
    }
};

void inOrderTraversal(Menu* current) {
    if (current == nullptr) {
        return;
    }

    inOrderTraversal(current->left);

    cout << "Kode Menu : " << RESET << current->kode_menu << endl;
    cout << "Nama      : " << RESET << current->nama_menu << endl;
    cout << GREEN << "Harga     : " << RESET << GREEN << formatRupiah(current->harga) << RESET << endl;
    cout << "Kategori  : " << RESET << current->kategori << endl;
    printRating(current->rating);
    cout << "\n";

    inOrderTraversal(current->right);
};

void preOrderTraversal(Menu* current) {
    if (current == nullptr) {
        return;
    }

    cout << "Kode Menu : " << RESET << current->kode_menu << endl;
    cout << "Nama      : " << RESET << current->nama_menu << endl;
    cout << GREEN << "Harga     : " << RESET << GREEN << formatRupiah(current->harga) << RESET << endl;
    cout << "Kategori  : " << RESET << current->kategori << endl;
    printRating(current->rating);
    cout << "\n";

    preOrderTraversal(current->left);
    preOrderTraversal(current->right);
};

void postOrderTraversal(Menu* current) {
    if (current == nullptr) {
        return;
    }

    postOrderTraversal(current->left);
    postOrderTraversal(current->right);

    cout << "Kode Menu : " << RESET << current->kode_menu << endl;
    cout <<"Nama      : " << RESET << current->nama_menu << endl;
    cout << GREEN << "Harga     : " << RESET << GREEN << formatRupiah(current->harga) << RESET << endl;
    cout << "Kategori  : " << RESET << current->kategori << endl;
    printRating(current->rating);
    cout << " \n";
};

void findMaxPrice(Menu* current, Menu*& maxMenu) {
    if (current == nullptr) {
        return;
    }

    findMaxPrice(current->left, maxMenu);

    if (maxMenu == nullptr || current->harga > maxMenu->harga) {
        maxMenu = current;
    }

    findMaxPrice(current->right, maxMenu);
};

void showHighestPrice() {
    if (isBSTEmpty()) {
        cout << RED << "BST kosong! Tidak ada menu.\n" << RESET;
        return;
    }

    Menu* maxMenu = nullptr;
    findMaxPrice(root, maxMenu);

    if (maxMenu != nullptr) {
        cout << GREEN << BOLD;
        cout << "\n+---------------------+\n";
        cout << "|    Menu Termahal    |\n";
        cout << "+---------------------+\n";
        cout << RESET;
        cout << "Kode Menu : " << RESET << maxMenu->kode_menu << endl;
        cout << "Nama      : " << RESET << maxMenu->nama_menu << endl;
        cout << GREEN << "Harga     : " << RESET << GREEN << formatRupiah(maxMenu->harga) << RESET << endl;
        cout << "Kategori  : " << RESET << maxMenu->kategori << endl;
        printRating(maxMenu->rating);
    }
};

void findHighestAverageRating(
    Menu* current,
    Menu*& bestMenu,
    double& bestAverage
) {
    if (current == nullptr) {
        return;
    }

    findHighestAverageRating(current->left, bestMenu, bestAverage);

    int totalVote = 0;
    int totalScore = 0;

    for (int i = 0; i < 5; i++) {
        totalVote += current->rating[i];
        totalScore += current->rating[i] * (i + 1);
    }

    if (totalVote > 0) {
        double average = static_cast<double>(totalScore) / totalVote;

        if (bestMenu == nullptr || average > bestAverage) {
            bestAverage = average;
            bestMenu = current;
        }
    }

    findHighestAverageRating(current->right, bestMenu, bestAverage);
};

void showBestMenu() {
    if (isBSTEmpty()) {
        cout << RED << "BST kosong! Tidak ada menu.\n" << RESET;
        return;
    }

    Menu* bestMenu = nullptr;
    double bestAverage = 0.0;

    findHighestAverageRating(root, bestMenu, bestAverage);

    if (bestMenu == nullptr) {
        cout << RED << "Belum ada menu yang memiliki rating.\n" << RESET;
        return;
    }

    cout << GREEN << BOLD;
    cout << "\n+--------------------+\n";
    cout << "|    Menu Terbaik    |\n";
    cout << "+--------------------+\n";
    cout << RESET;
    cout << "Kode Menu : " << RESET << bestMenu->kode_menu << endl;
    cout << "Nama      : " << RESET << bestMenu->nama_menu << endl;
    cout << GREEN << "Harga     : " << RESET << GREEN << formatRupiah(bestMenu->harga) << RESET << endl;
    cout << "Kategori  : " << RESET << bestMenu->kategori << endl;
    printRating(bestMenu->rating);
};

void loadDummyDataBST() {
    int kode_menu[3] = {
        101, 113, 127
    };

    string nama_menu[3] = {
        "Truffle Risotto", "Wagyu Steak", "Lobster Thermidor"
    };

    int harga[3] = {
        250000, 450000, 600000
    };

    string kategori[3] = {
        "Signature", "Premium", "Premium"
    };

    for (int i = 0; i < 3; i++) {
        if (searchBST(root, kode_menu[i]) == nullptr) {
            Menu* dummy = createMenu(
                kode_menu[i],
                nama_menu[i],
                harga[i],
                kategori[i]
            );
            root = insertBST(root, dummy);
        }
    }
};

void loadDummyRatingBST(Menu* current) {
    if (current == nullptr) {
        return;
    }

    loadDummyRatingBST(current->left);

    int totalVote = (current->kode_menu % 37) + 83;

    for (int i = 0; i < totalVote; i++) {
        int simulatedRating = ((current->kode_menu + i * 7) % 5) + 3;
        addRating(current, simulatedRating);
    }

    loadDummyRatingBST(current->right);
}

string formatRupiah(int harga) {
    string s = to_string(harga);
    int len = s.length();

    for (int i = len - 3; i > 0; i -= 3) {
        s.insert(i, ".");
    }

    return "Rp " + s;
};

int main() {
    int pilihanUtama;
    int pilihanBST;
    int pilihanMLL;

    initBST();
    loadDummyDataBST();
    loadDummyRatingBST(root);

    do {
        cout << CYAN << BOLD;
        cout << "\n+--------------------------------+\n";
        cout << "|    Selamat Datang, Manager!    |\n";
        cout << "+--------------------------------+\n";
        cout << RESET;
        cout << CYAN << "1. " << RESET << "Manajemen Menu Makanan (BST)\n";
        cout << CYAN << "2. " << RESET << "Manajemen Pelanggan VIP (MLL)\n";
        cout << RED  << "0. Exit\n" << RESET;
        cout << BOLD << "Pilihan : " << RESET;
        cin >> pilihanUtama;

        switch (pilihanUtama) {

        case 1:
            do {
                cout << CYAN << BOLD;
                cout << "\n+--------------------------+\n";
                cout << "|    Manajemen Menu BST    |\n";
                cout << "+--------------------------+\n";
                cout << RESET;
                cout << "1. Insert Menu\n";
                cout << "2. Search Menu\n";
                cout << "3. Update Menu\n";
                cout << "4. Delete Menu\n";
                cout << "5. Traversal Menu\n";
                cout << "6. Menu Termahal\n";
                cout << "7. Menu Terbaik\n";
                cout << "8. Counting Menu\n";
                cout << "9. Beri Rating Menu\n";
                cout << RED << "0. Kembali\n" << RESET;
                cout << BOLD << "Pilihan : " << RESET;
                cin >> pilihanBST;

                switch (pilihanBST) {

                case 1: {
                    int kode_menu;
                    string nama_menu;
                    int harga;
                    string kategori;

                    cout << "Kode Menu : ";
                    cin >> kode_menu;
                    cin.ignore();

                    if (searchBST(root, kode_menu) != nullptr) {
                        cout << RED << "Kode menu sudah terdaftar! Insert dibatalkan.\n" << RESET;
                        break;
                    }

                    cout << "Nama Menu : ";
                    getline(cin, nama_menu);

                    cout << "Harga     : ";
                    cin >> harga;
                    cin.ignore();

                    cout << "Kategori  : ";
                    getline(cin, kategori);

                    Menu* newMenu = createMenu(kode_menu, nama_menu, harga, kategori);
                    root = insertBST(root, newMenu);

                    cout << GREEN << "Menu berhasil ditambahkan!\n" << RESET;
                    break;
                };

                case 2: {
                    if (isBSTEmpty()) {
                        cout << RED << "BST kosong! Tidak ada menu untuk dicari.\n" << RESET;
                        break;
                    }

                    int kode_menu;
                    cout << "Kode Menu yang dicari : ";
                    cin >> kode_menu;

                    Menu* foundMenu = searchBST(root, kode_menu);

                    if (foundMenu == nullptr) {
                        cout << RED << "Menu dengan kode " << kode_menu << " tidak ditemukan.\n" << RESET;
                    }
                    else {
                        cout << GREEN << BOLD;
                        cout << "\n+----------------------+\n";
                        cout << "|    Menu Ditemukan    |\n";
                        cout << "+----------------------+\n";
                        cout << RESET;
                        cout << "Kode Menu : " << RESET << foundMenu->kode_menu << endl;
                        cout << "Nama      : " << RESET << foundMenu->nama_menu << endl;
                        cout << GREEN << "Harga     : " << RESET << GREEN << formatRupiah(foundMenu->harga) << RESET << endl;
                        cout << "Kategori  : " << RESET << foundMenu->kategori << endl;
                    }
                    break;
                };

                case 3:
                    cout << "[BST] Update Menu (belum diimplementasikan)\n";
                    break;

                case 4:
                    cout << "[BST] Delete Menu (belum diimplementasikan)\n";
                    break;

                case 5: {
                    if (isBSTEmpty()) {
                        cout << "BST kosong! Tidak ada menu untuk ditampilkan.\n";
                        break;
                    }

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
                    break;
                };

                case 6:
                    showHighestPrice();
                    break;

                case 7:
                    showBestMenu();
                    break;

                case 8:
                    cout << "[BST] Counting Menu (belum diimplementasikan)\n";
                    break;

                case 9: {
                    if (isBSTEmpty()) {
                        cout << RED << "BST kosong! Tidak ada menu untuk diberi rating.\n" << RESET;
                        break;
                    }

                    int kode_menu;
                    int ratingValue;

                    cout << "Kode Menu : ";
                    cin >> kode_menu;

                    Menu* menuToRate = searchBST(root, kode_menu);
                    if (menuToRate == nullptr) {
                        cout << RED << "Menu dengan kode " << kode_menu << " tidak ditemukan.\n" << RESET;
                        break;
                    }

                    cout << "Masukkan rating (1-5) : ";
                    cin >> ratingValue;

                    if (addRating(menuToRate, ratingValue)) {
                        cout << GREEN << "Terima kasih! Rating berhasil ditambahkan.\n" << RESET;
                    }
                    else {
                        cout << YELLOW << "Rating tidak valid! Harus antara 1 sampai 5.\n" << RESET;
                    }

                    break;
                };

                case 0:
                    cout << "Kembali ke Menu Utama...\n";
                    break;

                default:
                    cout << RED << "Pilihan tidak valid!\n" << RESET;
                }
            } while (pilihanBST != 0);
            break;

        case 2:
            do {
                cout << CYAN << BOLD;
                cout << "\n+-------------------------------+\n";
                cout << "|    Manajemen Pelanggan MLL    |\n";
                cout << "+-------------------------------+\n";
                cout << RESET;
                cout << "1. Insert Customer\n";
                cout << "2. Search Customer\n";
                cout << "3. Tambah Aktivitas Customer\n";
                cout << "4. Hapus Aktivitas Customer\n";
                cout << "5. Delete Customer\n";
                cout << "6. Statistik Pelanggan\n";
                cout << "7. Counting Pelanggan\n";
                cout << RED << "0. Kembali\n" << RESET;
                cout << BOLD << "Pilihan : " << RESET;
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
                    cout << GREEN << "Kembali ke Menu Utama...\n" << RESET;
                    break;

                default:
                    cout << RED << "Pilihan tidak valid!\n" << RESET;
                }
            } while (pilihanMLL != 0);
            break;

        case 0:
            cout << GREEN;
            cout << "\nTerima kasih,\n";
            cout << "Semoga restoran terus berjaya!\n";
            cout << RESET;
            break;

        default:
            cout << RED << "Pilihan tidak valid!\n" << RESET;
        }

    } while (pilihanUtama != 0);

    return 0;
};
