// restoran mewah

#include <iostream>
#include <string>
using namespace std;

struct Node {
   int kode_menu;
   string nama_menu;
   int harga;
   string kategori;
   Node *left, *right;
};

Node *BST_create(int kode_menu, string nama_menu, int harga, string kategori) {
   Node *new_node = new Node();
   new_node->kode_menu = kode_menu;
   new_node->nama_menu = nama_menu;
   new_node->harga = harga;
   new_node->kategori = kategori;
   new_node->left = new_node->right = NULL;
   return new_node;
}

Node *BST_insert(Node *root, int kode_menu, string nama_menu, int harga, string kategori) {
   if (root == NULL) {
      return BST_create(kode_menu, nama_menu, harga, kategori);
   }

   if (kode_menu < root->kode_menu) {
      root->left = BST_insert(root->left, kode_menu, nama_menu, harga, kategori);
   } else if (kode_menu > root->kode_menu) {
      root->right = BST_insert(root->right, kode_menu, nama_menu, harga, kategori);
   }

   return root;
}

void pre_order(Node *root) {
   if (root != NULL) {
      cout << root->kode_menu << " - " << root->nama_menu << " - " << root->harga << " - " << root->kategori << endl;
      pre_order(root->left);
      pre_order(root->right);
   }
}

int main() {
   Node *root = NULL;

   cout << "test progres pertama" << endl;

   // hidangan mewah
   root = BST_insert(root, 1001, "lobster thermidor", 750000, "seafood");
   root = BST_insert(root, 1002, "truffle pasta", 500000, "pasta");
   root = BST_insert(root, 1003, "caviar", 1000000, "appetizer");
   root = BST_insert(root, 1004, "sushi", 600000, "japanese");
   root = BST_insert(root, 1005, "tiramisu", 200000, "dessert");
   pre_order(root);

   return 0;
}
