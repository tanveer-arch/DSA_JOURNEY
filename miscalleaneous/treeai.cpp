#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Root pointer
Node* root = nullptr;

// Function to insert node dynamically
void insert(Node* temp, int data) {
    if (root == nullptr) { // Empty tree
        root = new Node(data);
        cout << "Value inserted at root.\n";
        return;
    }

    int c;
    cout << "At node " << temp->data << ", go Left(1) or Right(0)? ";
    cin >> c;

    if (c == 1) {
        if (temp->left == nullptr) {
            temp->left = new Node(data);
            cout << "Value inserted at left of " << temp->data << ".\n";
        } else {
            insert(temp->left, data);
        }
    } else if (c == 0) {
        if (temp->right == nullptr) {
            temp->right = new Node(data);
            cout << "Value inserted at right of " << temp->data << ".\n";
        } else {
            insert(temp->right, data);
        }
    } else {
        cout << "Invalid input! Enter 1 for left or 0 for right.\n";
        insert(temp, data);
    }
}

// Traversals
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Main function
int main() {
    int choice, data;

    while (true) {
        cout << "\n------------------------- TREE - Menu -------------------------\n";
        cout << "1. Insert Node\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                insert(root, data);
                break;
            case 2:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 4:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid input! Try again.\n";
        }
    }

    return 0;
}
