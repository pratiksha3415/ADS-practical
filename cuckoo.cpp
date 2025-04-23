#include <iostream>
#include <climits>
using namespace std;

const int VER = 2; // Number of hash tables
int MAXN; // Size of the hash table
int hashtable[VER][100]; // Hash table with multiple slots
int pos[VER]; // Stores the positions for hash table entries

void initTable() {
    for (int i = 0; i < VER; i++)
        for (int j = 0; j < MAXN; j++)
            hashtable[i][j] = INT_MIN; // Initialize all slots to INT_MIN (empty)
}

int hashFunction(int function, int key) {
    if (function == 1) 
        return key % MAXN; // First hash function: modulus operation
    else 
        return (key / MAXN) % MAXN; // Second hash function: division-based modulus operation
}

void place(int key, int tableID, int count, int maxAttempts) {
    if (count >= maxAttempts) {
        cout << "Cycle detected for key " << key << ". Rehash required!" << endl;
        return;
    }
    for (int i = 0; i < VER; i++)
        pos[i] = hashFunction(i + 1, key); // Calculate hash positions

    for (int i = 0; i < VER; i++) {
        if (hashtable[i][pos[i]] == key) return; // Check if the key is already present
    }

    if (hashtable[tableID][pos[tableID]] != INT_MIN) { // If slot is occupied
        int displacedKey = hashtable[tableID][pos[tableID]];
        hashtable[tableID][pos[tableID]] = key; // Place the new key
        place(displacedKey, (tableID + 1) % VER, count + 1, maxAttempts); // Rehash the displaced key
    } else {
        hashtable[tableID][pos[tableID]] = key; // Place the key in the table
    }
}

void printTable() {
    cout << "Hash Tables:" << endl;
    for (int i = 0; i < VER; i++) {
        for (int j = 0; j < MAXN; j++) {
            if (hashtable[i][j] == INT_MIN)
                cout << "- "; // Empty slot
            else
                cout << hashtable[i][j] << " "; // Print key
        }
        cout << endl;
    }
}

void cuckooHashing(int keys[], int n) {
    initTable();
    for (int i = 0; i < n; i++) {
        place(keys[i], 0, 0, n); // Insert keys into the hash table
    }
    printTable(); // Print the hash table after insertion
}

int main() {
    cout << "Enter the number of keys: ";
    int n;
    cin >> n;
    MAXN = n; // Set MAXN to the number of keys
    int keys[n]; // Array to hold the keys

    cout << "Enter the keys:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> keys[i]; // Read keys from the user
    }

    cuckooHashing(keys, n); // Perform cuckoo hashing with the input keys

    return 0;
}
