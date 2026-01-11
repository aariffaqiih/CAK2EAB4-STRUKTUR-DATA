#include "resto.h"

// ==================== GLOBAL VARIABLES ====================
Menu* root = nullptr;

// ==================== UTILITY FUNCTIONS ====================
string formatRupiah(int harga) {
    string s = to_string(harga);
    int len = s.length();

    for (int i = len - 3; i > 0; i -= 3) {
        s.insert(i, ".");
    }

    return "Rp " + s;
};

void clearScreen() {
    // Untuk Windows
    #ifdef _WIN32
        system("cls");
    // Untuk Linux/Mac
    #else
        system("clear");
    #endif
}

void pauseScreen() {
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

// ==================== BST FUNCTIONS IMPLEMENTATION ====================

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

Menu* minValueNode(Menu* node) {
    Menu* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Menu* deleteMenuBST(Menu* root, int kode_menu, bool &isDeleted) {
    if (root == nullptr) return root;

    if (kode_menu < root->kode_menu) {
        root->left = deleteMenuBST(root->left, kode_menu, isDeleted);
    }
    else if (kode_menu > root->kode_menu) {
        root->right = deleteMenuBST(root->right, kode_menu, isDeleted);
    }
    else {
        isDeleted = true;

        if (root->left == nullptr) {
            Menu* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Menu* temp = root->left;
            delete root;
            return temp;
        }

        Menu* temp = minValueNode(root->right);

        root->kode_menu = temp->kode_menu;
        root->nama_menu = temp->nama_menu;
        root->harga = temp->harga;
        root->kategori = temp->kategori;
        for(int i=0; i<5; i++) root->rating[i] = temp->rating[i];

        root->right = deleteMenuBST(root->right, temp->kode_menu, isDeleted);
    }
    return root;
}

void searchByNameBST(Menu* current, string keyword, bool &found) {
    if (current == nullptr) return;

    if (current->nama_menu.find(keyword) != string::npos) {
        found = true;
        cout << "- " << BOLD << current->nama_menu << RESET 
             << " (Kode: " << current->kode_menu << ") | " 
             << formatRupiah(current->harga) << endl;
    }

    searchByNameBST(current->left, keyword, found);
    searchByNameBST(current->right, keyword, found);
}

void searchByCategoryBST(Menu* current, string kategori, int &count) {
    if (current == nullptr) return;

    searchByCategoryBST(current->left, kategori, count);

    if (current->kategori == kategori) {
        count++;
        cout << "- " << current->nama_menu 
             << " (" << formatRupiah(current->harga) << ")\n";
    }

    searchByCategoryBST(current->right, kategori, count);
}

void updateMenuBST(Menu* target) {
    int pilihanUpdate;
    cout << "\nMenu Ditemukan: " << BOLD << target->nama_menu << RESET << endl;
    cout << "Apa yang ingin diubah?\n";
    cout << "1. Nama Menu\n2. Harga\n3. Kategori\n";
    cout << "Pilihan: "; cin >> pilihanUpdate;
    cin.ignore();

    switch(pilihanUpdate) {
        case 1:
            cout << "Masukkan Nama Baru: ";
            getline(cin, target->nama_menu);
            break;
        case 2:
            cout << "Masukkan Harga Baru: ";
            cin >> target->harga;
            cin.ignore();
            break;
        case 3:
            cout << "Masukkan Kategori Baru: ";
            getline(cin, target->kategori);
            break;
        default:
            cout << RED << "Batal update.\n" << RESET;
            return;
    }
    cout << GREEN << "Data berhasil diperbarui.\n" << RESET;
}

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

int countTotalMenu(Menu* current) {
    if (current == nullptr) return 0;
    return 1 + countTotalMenu(current->left) + countTotalMenu(current->right);
}

int countMenuByCategory(Menu* current, string cat) {
    if (current == nullptr) return 0;
    int match = (current->kategori == cat) ? 1 : 0;
    return match + countMenuByCategory(current->left, cat) + countMenuByCategory(current->right, cat);
}

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

void findMinPrice(Menu* current, Menu*& minMenu) {
    if (current == nullptr) return;
    findMinPrice(current->left, minMenu);
    if (minMenu == nullptr || current->harga < minMenu->harga) {
        minMenu = current;
    }
    findMinPrice(current->right, minMenu);
}

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

void findLowestAverageRating(Menu* current, Menu*& worstMenu, double& worstAverage) {
    if (current == nullptr) return;
    findLowestAverageRating(current->left, worstMenu, worstAverage);

    int totalVote = 0;
    int totalScore = 0;
    for (int i = 0; i < 5; i++) {
        totalVote += current->rating[i];
        totalScore += current->rating[i] * (i + 1);
    }
    if (totalVote > 0) {
        double average = static_cast<double>(totalScore) / totalVote;
        if (worstMenu == nullptr || average < worstAverage) {
            worstAverage = average;
            worstMenu = current;
        }
    }
    findLowestAverageRating(current->right, worstMenu, worstAverage);
}

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

void showLowestPrice() {
    if (isBSTEmpty()) { cout << RED << "Data Kosong.\n" << RESET; return; }
    Menu* minMenu = nullptr;
    findMinPrice(root, minMenu);
    if (minMenu) {
        cout << GREEN << BOLD << "Menu Termurah: " << RESET << minMenu->nama_menu 
             << " (" << formatRupiah(minMenu->harga) << ")\n";
    }
}

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

void showWorstMenu() {
    if (isBSTEmpty()) { cout << RED << "Data Kosong.\n" << RESET; return; }
    Menu* worstMenu = nullptr;
    double worstAvg = 6.0;
    findLowestAverageRating(root, worstMenu, worstAvg);
    if(worstMenu) {
        cout << RED << BOLD << "Menu Rating Terendah: " << RESET << worstMenu->nama_menu 
             << " (" << worstAvg << "/5)\n";
    } else {
        cout << YELLOW << "Belum ada menu yang memiliki rating.\n" << RESET;
    }
}

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
};