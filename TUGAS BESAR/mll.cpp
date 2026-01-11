#include "resto.h"

// ==================== GLOBAL VARIABLES ====================
Customer* headCustomer = nullptr;

// ==================== MLL FUNCTIONS IMPLEMENTATION ====================

void initMLL() {
    headCustomer = nullptr;
}

Customer* createCustomer(int id, string nama, string membership) {
    Customer* c = new Customer;
    c->id = id;
    c->nama = nama;
    c->membership = membership;
    c->firstChild = nullptr;
    c->next = nullptr;
    return c;
}

ChildAktivitas* createChild(int nilai) {
    ChildAktivitas* c = new ChildAktivitas;
    c->nilai = nilai;
    c->next = nullptr;
    return c;
}

Customer* searchCustomer(int id) {
    Customer* temp = headCustomer;
    while (temp) {
        if (temp->id == id) return temp;
        temp = temp->next;
    }
    return nullptr;
}

bool isCustomerExist(int id) {
    return searchCustomer(id) != nullptr;
}

void MLL_InsertCustomer(int id, string nama, string membership) {
    // Cek duplikat ID
    if (searchCustomer(id)) {
        cout << RED << "Error: ID customer sudah terdaftar!\n" << RESET;
        return;
    }
    
    Customer* newCust = createCustomer(id, nama, membership);
    
    if (!headCustomer) {
        headCustomer = newCust;
    } else {
        Customer* temp = headCustomer;
        while (temp->next) temp = temp->next;
        temp->next = newCust;
    }
    cout << GREEN << "Customer berhasil ditambahkan.\n" << RESET;
}

void MLL_ShowCustomers() {
    if (!headCustomer) {
        cout << RED << "Tidak ada data customer.\n" << RESET;
        return;
    }
    
    cout << PURPLE << BOLD << "\n--- Daftar Customer VIP ---\n" << RESET;
    Customer* temp = headCustomer;
    while (temp) {
        cout << "\nID: " << temp->id << endl;
        cout << "Nama: " << BOLD << temp->nama << RESET << endl;
        cout << "Membership: " << temp->membership << endl;
        
        // Hitung aktivitas
        int actCount = MLL_CountActivitiesPerCustomer(temp->id);
        cout << "Jumlah Aktivitas: " << actCount << endl;
        
        temp = temp->next;
    }
}

void searchCustomerByName(string nama) {
    Customer* temp = headCustomer;
    bool found = false;
    
    cout << PURPLE << BOLD << "\n--- Hasil Pencarian Customer ---\n" << RESET;
    
    while (temp) {
        // Ubah kedua string menjadi lowercase untuk pencarian case-insensitive
        string tempNamaLower = temp->nama;
        string namaLower = nama;
        transform(tempNamaLower.begin(), tempNamaLower.end(), tempNamaLower.begin(), ::tolower);
        transform(namaLower.begin(), namaLower.end(), namaLower.begin(), ::tolower);
        
        if (tempNamaLower.find(namaLower) != string::npos) {
            found = true;
            cout << GREEN << "✓ " << RESET << "ID: " << temp->id 
                 << " | Nama: " << BOLD << temp->nama << RESET
                 << " | Membership: " << temp->membership << endl;
                 
            // Hitung jumlah aktivitas
            ChildAktivitas* act = temp->firstChild;
            int count = 0;
            while (act) {
                count++;
                act = act->next;
            }
            cout << "   Aktivitas: " << count << " item\n";
        }
        temp = temp->next;
    }
    
    if (!found) {
        cout << RED << "Customer dengan nama \"" << nama << "\" tidak ditemukan.\n" << RESET;
    }
}

void MLL_AddActivity(int customerID, int nilai) {
    Customer* cust = searchCustomer(customerID);
    if (!cust) {
        cout << RED << "Customer tidak ditemukan.\n" << RESET;
        return;
    }

    ChildAktivitas* newAct = createChild(nilai);
    if (!cust->firstChild) {
        cust->firstChild = newAct;
    } else {
        ChildAktivitas* temp = cust->firstChild;
        while (temp->next) temp = temp->next;
        temp->next = newAct;
    }
    cout << GREEN << "Aktivitas berhasil ditambahkan.\n" << RESET;
}

void MLL_RemoveActivity(int customerID, int nilai) {
    Customer* cust = searchCustomer(customerID);
    if (!cust || !cust->firstChild) {
        cout << RED << "Data aktivitas tidak ditemukan.\n" << RESET;
        return;
    }

    ChildAktivitas* curr = cust->firstChild;
    ChildAktivitas* prev = nullptr;

    while (curr && curr->nilai != nilai) {
        prev = curr;
        curr = curr->next;
    }

    if (!curr) {
        cout << RED << "Aktivitas tidak ditemukan.\n" << RESET;
        return;
    }

    if (!prev) cust->firstChild = curr->next;
    else prev->next = curr->next;

    delete curr;
    cout << GREEN << "Aktivitas berhasil dihapus.\n" << RESET;
}

void MLL_DeleteAllActivities(int customerID) {
    Customer* cust = searchCustomer(customerID);
    if (!cust) {
        cout << RED << "Customer tidak ditemukan.\n" << RESET;
        return;
    }

    ChildAktivitas* act = cust->firstChild;
    int count = 0;
    
    while (act) {
        ChildAktivitas* temp = act;
        act = act->next;
        delete temp;
        count++;
    }
    
    cust->firstChild = nullptr;
    cout << GREEN << "Berhasil menghapus " << count << " aktivitas dari customer ID " << customerID << ".\n" << RESET;
}

void MLL_DeleteCustomer(int id) {
    if (!headCustomer) {
        cout << RED << "Tidak ada customer.\n" << RESET;
        return;
    }

    Customer* curr = headCustomer;
    Customer* prev = nullptr;

    while (curr && curr->id != id) {
        prev = curr;
        curr = curr->next;
    }

    if (!curr) {
        cout << RED << "Customer tidak ditemukan.\n" << RESET;
        return;
    }

    // Hapus semua aktivitas customer
    ChildAktivitas* act = curr->firstChild;
    int activityCount = 0;
    while (act) {
        ChildAktivitas* tempAct = act;
        act = act->next;
        delete tempAct;
        activityCount++;
    }

    if (!prev) {
        headCustomer = curr->next;
    } else {
        prev->next = curr->next;
    }

    delete curr;
    cout << GREEN << "Customer berhasil dihapus beserta " << activityCount << " aktivitas.\n" << RESET;
}

int MLL_CountTotalCustomers() {
    int count = 0;
    Customer* temp = headCustomer;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

int MLL_CountActivitiesPerCustomer(int customerID) {
    Customer* cust = searchCustomer(customerID);
    if (!cust) {
        return -1; // Return -1 jika customer tidak ditemukan
    }
    
    int count = 0;
    ChildAktivitas* act = cust->firstChild;
    while (act) {
        count++;
        act = act->next;
    }
    return count;
}

void MLL_FindMostActiveCustomer() {
    if (!headCustomer) {
        cout << RED << "Tidak ada customer.\n" << RESET;
        return;
    }
    
    Customer* mostActive = nullptr;
    int maxActivities = -1;
    
    Customer* temp = headCustomer;
    while (temp) {
        int activityCount = 0;
        ChildAktivitas* act = temp->firstChild;
        while (act) {
            activityCount++;
            act = act->next;
        }
        
        if (activityCount > maxActivities) {
            maxActivities = activityCount;
            mostActive = temp;
        }
        
        temp = temp->next;
    }
    
    if (mostActive) {
        cout << GREEN << BOLD << "Customer Paling Aktif:\n" << RESET;
        cout << "Nama: " << mostActive->nama 
             << " (ID: " << mostActive->id 
             << ", Membership: " << mostActive->membership << ")\n";
        cout << "Jumlah Aktivitas: " << maxActivities << endl;
    }
}

void MLL_FindLeastActiveCustomer() {
    if (!headCustomer) {
        cout << RED << "Tidak ada customer.\n" << RESET;
        return;
    }
    
    Customer* leastActive = nullptr;
    int minActivities = 1000000; // Angka besar sebagai nilai awal
    
    Customer* temp = headCustomer;
    while (temp) {
        int activityCount = 0;
        ChildAktivitas* act = temp->firstChild;
        while (act) {
            activityCount++;
            act = act->next;
        }
        
        if (activityCount < minActivities) {
            minActivities = activityCount;
            leastActive = temp;
        }
        
        temp = temp->next;
    }
    
    if (leastActive) {
        cout << YELLOW << BOLD << "Customer Paling Pasif:\n" << RESET;
        cout << "Nama: " << leastActive->nama 
             << " (ID: " << leastActive->id 
             << ", Membership: " << leastActive->membership << ")\n";
        cout << "Jumlah Aktivitas: " << minActivities << endl;
    }
}

int MLL_CountTotalActivities() {
    int total = 0;
    Customer* temp = headCustomer;
    
    while (temp) {
        ChildAktivitas* act = temp->firstChild;
        while (act) {
            total++;
            act = act->next;
        }
        temp = temp->next;
    }
    return total;
}

void MLL_ShowFavoritesPerCustomer(int customerID) {
    Customer* cust = searchCustomer(customerID);
    if (!cust) {
        cout << RED << "Customer tidak ditemukan.\n" << RESET;
        return;
    }
    
    cout << "\nAktivitas Customer " << cust->nama << " (ID: " << cust->id << "):\n";
    
    ChildAktivitas* act = cust->firstChild;
    if (!act) {
        cout << YELLOW << "Belum ada aktivitas.\n" << RESET;
        return;
    }
    
    int count = 1;
    while (act) {
        cout << count << ". Nilai: " << act->nilai << endl;
        act = act->next;
        count++;
    }
}

void loadDummyDataMLL() {
    int ids[3] = {1001, 1002, 1003};
    string names[3] = {"John Doe", "Jane Smith", "Robert Johnson"};
    string memberships[3] = {"Platinum", "Gold", "Silver"};
    
    for (int i = 0; i < 3; i++) {
        if (!searchCustomer(ids[i])) {
            Customer* dummy = createCustomer(ids[i], names[i], memberships[i]);
            
            // Tambahkan beberapa aktivitas dummy
            for (int j = 0; j < 5; j++) {
                ChildAktivitas* act = createChild((i + j) * 10);
                if (!dummy->firstChild) {
                    dummy->firstChild = act;
                } else {
                    ChildAktivitas* temp = dummy->firstChild;
                    while (temp->next) temp = temp->next;
                    temp->next = act;
                }
            }
            
            // Insert ke list
            if (!headCustomer) {
                headCustomer = dummy;
            } else {
                Customer* temp = headCustomer;
                while (temp->next) temp = temp->next;
                temp->next = dummy;
            }
        }
    }
}