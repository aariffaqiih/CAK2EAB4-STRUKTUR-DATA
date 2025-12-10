#include <iostream>
#include <string>
using namespace std;

struct node {
   int menu_code;
   string menu_name;
   int price;
   string category;
   int rating[5];
   node * left, * right;
};

node * bst_create(int menu_code, string menu_name, int price, string category) {
   node * new_node = new node();

   new_node -> menu_code = menu_code;
   new_node -> menu_name = menu_name;
   new_node -> price = price;
   new_node -> category = category;
   for (int i = 0; i < 5; i++) {
      new_node -> rating[i] = 0;
   }

   new_node -> left = NULL;
   new_node -> right = NULL;

   return new_node;
}

node * bst_insert(node * root, int menu_code, string menu_name, int price, string category) {
   if (root == NULL) {
      return bst_create(menu_code, menu_name, price, category);
   }

   if (menu_code < root -> menu_code) {
      root -> left = bst_insert(root -> left, menu_code, menu_name, price, category);
   } else if (menu_code > root -> menu_code) {
      root -> right = bst_insert(root -> right, menu_code, menu_name, price, category);
   } else {
      cout << "[error] duplicate menu_code detected: " << menu_code << endl;
   }

   return root;
}

void bst_print_ratings(int rating[]) {
   cout << "(";
   for (int i = 0; i < 5; i++) {
      cout << rating[i];
      if (i < 4) cout << ", ";
   }
   cout << ")";
}

void bst_pre_order(node * root) {
   if (root != NULL) {
      cout <<
         root -> menu_code << " - " <<
         root -> menu_name << " - " <<
         root -> price << " - " <<
         root -> category << " - ";
         bst_print_ratings(root -> rating);
      cout << endl;

      bst_pre_order(root -> left);
      bst_pre_order(root -> right);
   }
}

void bst_in_order(node * root) {
   if (root != NULL) {
      bst_in_order(root -> left);

      cout <<
         root -> menu_code << " - " <<
         root -> menu_name << " - " <<
         root -> price << " - " <<
         root -> category << " - ";
         bst_print_ratings(root -> rating);
      cout << endl;

      bst_in_order(root -> right);
   }
}

void bst_post_order(node * root) {
   if (root != NULL) {
      bst_post_order(root -> left);
      bst_post_order(root -> right);

      cout <<
         root -> menu_code << " - " <<
         root -> menu_name << " - " <<
         root -> price << " - " <<
         root -> category << " - ";
         bst_print_ratings(root -> rating);
      cout << endl;
   }
}

node * bst_search(node * root, int menu_code) {
   if (root == NULL || root -> menu_code == menu_code) {
      return root;
   }

   if (menu_code < root -> menu_code) {
      return bst_search(root -> left, menu_code);
   }

   return bst_search(root -> right, menu_code);
}

node * bst_smallest(node * root) {
   node * current = root;
   while (current && current -> left != NULL) {
      current = current -> left;
   }
   return current;
}

node * bst_delete(node * root, int menu_code) {
   if (root == NULL) {
      return root;
   }

   if (menu_code < root -> menu_code) {
      root -> left = bst_delete(root -> left, menu_code);
   } else if (menu_code > root -> menu_code) {
      root -> right = bst_delete(root -> right, menu_code);
   } else {
      if (root -> left == NULL) {
         node * temp = root -> right;
         delete root;
         return temp;
      }
      else if (root -> right == NULL) {
         node * temp = root -> left;
         delete root;
         return temp;
      }

      node * temp = bst_smallest(root -> right);

      root->menu_code = temp->menu_code;
      root->menu_name = temp->menu_name;
      root->price = temp->price;
      root->category = temp->category;
      for (int i = 0; i < 5; i++) {
         root->rating[i] = temp->rating[i];
      }

      root->right = bst_delete(root->right, temp->menu_code);
   }

   return root;
}

int main() {
   node * root = NULL;

   root = bst_insert(root, 1001, "wagyu striploin a5", 850000, "signature");
   root = bst_insert(root, 1002, "black truffle risotto", 420000, "premium");
   root = bst_insert(root, 1003, "lobster bisque", 380000, "signature");
   root = bst_insert(root, 1004, "pumpkin veloute", 210000, "seasonal");
   root = bst_insert(root, 1005, "vegan mushroom steak", 240000, "vegan");   

   cout << "----- pre-order traversal" << endl;
   bst_pre_order(root);
   cout << endl;

   cout << "----- in-order traversal" << endl;
   bst_in_order(root);
   cout << endl;

   cout << "----- post-order traversal" << endl;
   bst_post_order(root);
   cout << endl;

   cout << "----- searching 1003" << endl;
   int search_code = 1003;
   node * search_result = bst_search(root, search_code);
   if (search_result != NULL) {
      cout << "found " << search_result -> menu_code << " " << search_result -> menu_name << endl;
   } else {
      cout << "menu item with code " << search_code << " not found." << endl;
   }
   cout << endl;

   cout << "----- deleting 1002" << endl;
   root = bst_delete(root, 1002);
   bst_in_order(root);

   return 0;
}
