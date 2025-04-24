#include <iostream>
using namespace std;

class HashTable {
    int table[10][2];  // 2D array with 10 slots, each holding 2 values: [key, chained_key]
    string stuNames[10];  // Array to store student names
    int size = 10;

public:
    // Constructor to initialize the table with -1 (indicating empty slots)
    HashTable() {
        for (int i = 0; i < size; i++) {
            table[i][0] = -1;  // Initialize first column with -1
            table[i][1] = -1;  // Initialize second column with -1
            stuNames[i] = "";  // Initialize student names with empty strings
        }
    }

    // Hash function to calculate index
    int hashFunction(int stuID) {
        return stuID % size;
    }

    void insert(int stuID, string stuName) {
        int index = hashFunction(stuID); 

        for (int i = 0; i < size; i++) {
            int probeIndex = (index + i) % size;

            // If the first column is empty, insert the stu
            if (table[probeIndex][0] == -1) {
                table[probeIndex][0] = stuID;
                stuNames[probeIndex] = stuName;
                cout << "Inserted " << stuName << " at index " << probeIndex << endl;
                return;
            }
            // If there is already a stu, chain the new stu in the second column
            else if (table[probeIndex][0] != -1 && table[probeIndex][1] == -1) {
                table[probeIndex][1] = stuID;
                cout << "Inserted " << stuName << " at index " << probeIndex << " (chaining)" << endl;
                return;
            }
            // If the second column is occupied, keep probing
            else {
                index = (index + 1) % size;
            }
        }
        cout << "Hash table is full. Cannot insert stu " << stuName << endl;
    }

    // Function to search for a stu by ID
    void search(int stuID) {
        int index = hashFunction(stuID);

        for (int i = 0; i < size; i++) {
            int probeIndex = (index + i) % size;
            if (table[probeIndex][0] == stuID) {
                cout << "Stu " << stuID << " found at index " << probeIndex << ": " << stuNames[probeIndex] << endl;
                return;
            } else if (table[probeIndex][1] == stuID) {
                cout << "Stu " << stuID << " found at index " << probeIndex << ": (chaining) " << stuNames[probeIndex] << endl;
                return;
            }
        }
        cout << "Stu " << stuID << " not found." << endl;
    }

    // Function to display the hash table
    void display() {
        cout << "Stu Catalog (Index: [Stu ID, Name]): \n";
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": ";
            if (table[i][0] != -1) {
                cout << table[i][0] << ", " << stuNames[i];
            } else {
                cout << "[Empty]";
            }

            cout << endl;
        }
    }
};

int main() {
    HashTable hashTable;

    int choice;
    while (true) {
        cout << "\nStu Management Menu: \n";
        cout << "1. Insert Stu\n";
        cout << "2. Search Stu\n";
        cout << "3. Display Stu Catalog\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int stuID;
            string stuName;
            cout << "Enter Stu ID: ";
            cin >> stuID;
            cout << "Enter Stu Name: ";
            cin.ignore();
            getline(cin, stuName);
            hashTable.insert(stuID, stuName);
        }
        else if (choice == 2) {
            int stuID;
            cout << "Enter Stu ID to search: ";
            cin >> stuID;
            hashTable.search(stuID);
        }
        else if (choice == 3) {
            hashTable.display();
        }
        else if (choice == 4) {
            cout << "Exiting program...\n";
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
