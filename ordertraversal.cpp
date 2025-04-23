#include <iostream>
#include <stack>
using namespace std;
class Node {
    public:
    string data;
    Node* left;
    Node* right;
    Node() {
        data = "";
        left = right = NULL;
    }
};
bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return true;
    }
    return false;
}
Node* constructExpTree(string exp) {
    stack<Node*> st;
    Node* node;
    for (int i = 0; i < exp.length(); i++) {
        if (isOperator(exp[i])) {
            node = new Node();
            node->data = exp[i]; // Create operator node
            node->left = st.top();
            st.pop();
            node->right = st.top();
            st.pop();
            // Push new node on top of stack
            st.push(node);
        } else {
            node = new Node();
            node->data = string(1, exp[i]);
            st.push(node);
        }
    }
    return st.top();
}
void inOrderTraversalRecursive(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversalRecursive(root->left);
    cout << root->data << " ";
    inOrderTraversalRecursive(root->right);
}
void inOrderTraversal(Node* root) {
    stack<Node*> st;
    Node* current = root;

    while (current != nullptr || !st.empty()) {
        // Traverse left subtree
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }
        // Process node
        current = st.top();
        st.pop();
        cout << current->data << " ";

        // Traverse right subtree
        current = current->right;
    }
}
int main() {
    string exp;
    cout << "Enter postorder expression: ";
    cin >> exp;
    Node* root = constructExpTree(exp);
    cout << "Inorder traversal\nRecursive: ";
    inOrderTraversalRecursive(root);
    cout << "\nNon-recursive: ";
    inOrderTraversal(root);
    return 0;
}
