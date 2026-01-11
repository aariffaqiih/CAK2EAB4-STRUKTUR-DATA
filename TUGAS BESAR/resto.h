#ifndef TUBES_H
#define TUBES_H

#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

#define RESET  "\033[0m"
#define BOLD   "\033[1m"

#define RED    "\033[38;2;255;112;112m"
#define GREEN  "\033[38;2;112;255;112m"
#define YELLOW "\033[38;2;255;255;112m"
#define CYAN   "\033[38;2;112;255;255m"

#define BLUE    "\033[38;2;112;112;255m"
#define PURPLE  "\033[38;2;200;112;255m"

// ==================== BST STRUCTURE (MENU MAKANAN) ====================
struct Menu {
    int kode_menu;
    string nama_menu;
    int harga;
    string kategori;
    int rating[5];

    Menu* left;
    Menu* right;
};

// ==================== MLL STRUCTURE (CUSTOMER VIP) ====================
struct ChildAktivitas {
    int nilai;
    ChildAktivitas* next;
};

struct Customer {
    int id;
    string nama;
    string membership;
    ChildAktivitas* firstChild;
    Customer* next;
};

// ==================== GLOBAL VARIABLES ====================
extern Menu* root;
extern Customer* headCustomer;

// ==================== UTILITY FUNCTIONS ====================
string formatRupiah(int harga);
void clearScreen();
void pauseScreen();

// ==================== BST FUNCTIONS ====================
void initBST();
bool isBSTEmpty();
Menu* createMenu(int kode_menu, const string &nama_menu, int harga, const string &kategori);
Menu* insertBST(Menu* current, Menu* newNode);
Menu* searchBST(Menu* current, int kode_menu);
Menu* minValueNode(Menu* node);
Menu* deleteMenuBST(Menu* root, int kode_menu, bool &isDeleted);
void searchByNameBST(Menu* current, string keyword, bool &found);
void searchByCategoryBST(Menu* current, string kategori, int &count);
void updateMenuBST(Menu* target);
bool addRating(Menu* menu, int ratingValue);
void printRating(const int rating[5]);
int countTotalMenu(Menu* current);
int countMenuByCategory(Menu* current, string cat);
void inOrderTraversal(Menu* current);
void preOrderTraversal(Menu* current);
void postOrderTraversal(Menu* current);
void findMaxPrice(Menu* current, Menu*& maxMenu);
void findMinPrice(Menu* current, Menu*& minMenu);
void findHighestAverageRating(Menu* current, Menu*& bestMenu, double& bestAverage);
void findLowestAverageRating(Menu* current, Menu*& worstMenu, double& worstAverage);
void showHighestPrice();
void showLowestPrice();
void showBestMenu();
void showWorstMenu();
void loadDummyDataBST();
void loadDummyRatingBST(Menu* current);
void menuBST();

// ==================== MLL FUNCTIONS ====================
void initMLL();
Customer* createCustomer(int id, string nama, string membership);
ChildAktivitas* createChild(int nilai);
void searchCustomerByName(string nama);
void MLL_AddActivity(int customerID, int nilai);
void MLL_RemoveActivity(int customerID, int nilai);
void MLL_DeleteAllActivities(int customerID);
void MLL_DeleteCustomer(int id);
int MLL_CountTotalCustomers();
int MLL_CountActivitiesPerCustomer(int customerID);
void MLL_FindMostActiveCustomer();
void MLL_FindLeastActiveCustomer();
int MLL_CountTotalActivities();
Customer* searchCustomer(int id);
void MLL_InsertCustomer(int id, string nama, string membership);
void MLL_ShowCustomers();
bool isCustomerExist(int id);
void MLL_ShowFavoritesPerCustomer(int customerID);
void loadDummyDataMLL();
void menuMLL();

#endif