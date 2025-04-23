#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node() {
        data = 0;
        left = right = NULL;
    }
};
void create(Node*& root, int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->left = temp->right = NULL;
    if (root == NULL) {
        cout << "Inserted " << value << " at root." << endl;
        root = temp;
    } else {
        Node* current = root;
        while (current != NULL) {
            if (current->data > value) {
                if (current->left == NULL) {
                    cout << "Inserted " << value << " to left of " << current->data << endl;
                    current->left = temp;
                    return;
                }
                current = current->left;
            } else {
                if (current->right == NULL) {
                    cout << "Inserted " << value << " to right of " << current->data << endl;
                    current->right = temp;
                    return;
                }
                current = current->right;
            }
        }
    }
}
void update(Node*& root, int oldValue, int newValue) {
    if (root->data == oldValue) {
        root->data = newValue;
    } else {
        Node* current = root;
        while (current != NULL) {
            if (current->data == oldValue) {
                current->data = newValue;
                return;
            } else if (current->data > oldValue) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        cout << "Old value not found" << endl;
    }
}
void deleteNode(Node*& root, int value) {
    if (root->data == value) {
        delete root;
        root = NULL;
    } else {
        Node* current = root, *prev = root;
        while (current != NULL) {
            if (current->data == value) {
                // To delete node pointed by current
                if (current->left == NULL) {
                    if (current->right == NULL) {
                        if (prev->left == current) {
                            prev->left = NULL;
                        } else {
                            prev->right = NULL;
                        }
                        delete current;
                    } else {
                        current->data = current->right->data;
                        delete current->right;
                    }
                } else {
                    if (current->right == NULL) {
                        current->data = current->left->data;
                        delete current->left;
                    } else {
                        cout << "Inorder successor." << endl;
                    }
                }
                return;
            } else if (current->data > value) {
                prev = current;
                current = current->left;
            } else {
                prev = current;
                current = current->right;
            }
        }
        cout << "Old value not found" << endl;
    }
}
void recursiveDisplay(Node*& node) {
    if (node == NULL) {
        return;
    } else {
        recursiveDisplay(node->left);
        cout << node->data << " ";
        recursiveDisplay(node->right);
    }
}
void display(Node*& root) {
    if (root == NULL) {
        cout << "Binary search tree is empty." << endl;
        return;
    } else {
        cout << "Binary search tree is: ";
        recursiveDisplay(root->left);
        cout << root->data << " ";
        recursiveDisplay(root->right);
    }
    cout << endl;
}
int main() {
    int n, x;
    cout << "Enter how many numbers: ";
    cin >> n;
    int i = 0;
    Node* root = NULL;
    while (i < n) {
        cout << "Enter value " << (i + 1) << ": ";
        cin >> x;
        create(root, x);
        i++;
    }
    int choice;
    do {
        cout << "1. Insert new value\n2. Update a value\n3. Delete a value\n4. Display all values\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Enter value to insert: ";
                cin >> x;
                create(root, x);
                break;
            }
            case 2: {
                int oldValue, newValue;
                cout << "Enter old value: ";
                cin >> oldValue;
                cout << "Enter new value: ";
                cin >> newValue;
                update(root, oldValue, newValue);
                break;
            }
            case 3: {
                cout << "Enter value to delete: ";
                cin >> x;
                deleteNode(root, x);
                break;
            }
            case 4: {
                cout << "All nodes in binary search tree: ";
                display(root);
                break;
            }
            case 5: {
                cout << "Exiting the program" << endl;
                break;
            }
        }
    } while (choice != 5);
    return 0;
}