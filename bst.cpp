#include <iostream>
#include <string>
using namespace std;

class node {
public:
    string keyword;
    string meaning;
    node* left;
    node* right;

    node(string key, string val) {
        keyword = key;
        meaning = val;
        left = right = NULL;
    }
};

class Dictionary {
public:
    node* root;
    Dictionary() {
        root = NULL;
    }

    node* insert(node* root, string key, string val) {
        if (!root) return new node(key, val);
        if (key < root->keyword)
            root->left = insert(root->left, key, val);
        else if (key > root->keyword)
            root->right = insert(root->right, key, val);
        else
            cout << "Keyword already exists!\n";
        return root;
    }

    void inorder(node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->keyword << " : " << root->meaning << endl;
        inorder(root->right);
    }

    void reverseInorder(node* root) {
        if (!root) return;
        reverseInorder(root->right);
        cout << root->keyword << " : " << root->meaning << endl;
        reverseInorder(root->left);
    }

    node* search(node* root, string key, int& comparisons) {
        comparisons++;
        if (!root) return NULL;
        if (root->keyword == key) return root;
        else if (key < root->keyword)
            return search(root->left, key, comparisons);
        else
            return search(root->right, key, comparisons);
    }

    node* findMin(node* root) {
        while (root->left) root = root->left;
        return root;
    }

    node* deleteNode(node* root, string key) {
        if (!root) return NULL;
        if (key < root->keyword)
            root->left = deleteNode(root->left, key);
        else if (key > root->keyword)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left && !root->right) {
                delete root;
                return NULL;
            } else if (!root->left || !root->right) {
                node* temp = root->left ? root->left : root->right;
                delete root;
                return temp;
            } else {
                node* succ = findMin(root->right);
                root->keyword = succ->keyword;
                root->meaning = succ->meaning;
                root->right = deleteNode(root->right, succ->keyword);
            }
        }
        return root;
    }
};

int main() {
    Dictionary dict;
    int choice;

    do {
        cout << "\nDictionary Menu:\n";
        cout << "1. Add Keyword\n2. Display (Ascending)\n3. Display (Descending)\n4. Search Keyword\n5. Update Meaning\n6. Delete Keyword\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string key, val;
                cout << "Enter keyword: ";
                cin >> key;
                cout << "Enter meaning: ";
                cin.ignore();
                getline(cin, val);
                dict.root = dict.insert(dict.root, key, val);
                break;
            }
            case 2: { 
                cout << "\nDictionary in Ascending Order:\n";
                dict.inorder(dict.root);
                break;
            }
            case 3: { 
                cout << "\nDictionary in Descending Order:\n";
                dict.reverseInorder(dict.root);
                break;
            }
            case 4: { 
                string key;
                cout << "Enter keyword to search: ";
                cin >> key;
                int comparisons = 0;
                node* result = dict.search(dict.root, key, comparisons);
                if (result)
                    cout << "Found! Meaning: " << result->meaning << "\nComparisons: " << comparisons << endl;
                else
                    cout << "Keyword not found!\nComparisons: " << comparisons << endl;
                    break;
            }
            case 5: {
                string key, newMeaning;
                cout << "Enter keyword to update: ";
                cin >> key;
                int comparisons = 0;
                node* res = dict.search(dict.root, key, comparisons);
                if (res) {
                    cout << "Current Meaning: " << res->meaning << endl;
                    cout << "Enter new meaning: ";
                    cin.ignore();
                    getline(cin, newMeaning);
                    res->meaning = newMeaning;
                    cout << "Updated successfully.\n";
                } else {
                    cout << "Keyword not found.\n";
                }
                break;
            }
            case 6: {
                string key;
                cout << "Enter keyword to delete: ";
                cin >> key;
                dict.root = dict.deleteNode(dict.root, key);
                cout << "Deleted successfully (if existed).\n";
                break;
            }
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid option.\n";
        }
    } while (choice != 0);

    return 0;
}
