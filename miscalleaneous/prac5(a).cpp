#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int data) {
        // Use temp as a local pointer for navigation
        if (root == nullptr) {
            root = new Node(data);
            cout << "Value inserted at root." << endl;
            return;
        }

        Node* temp = root;
        while (true) {
            int c;
            cout << "Left/Right? (1/0): ";
            cin >> c;

            if (c == 1) {
                if (temp->left == nullptr) {
                    temp->left = new Node(data);
                    cout << "Value inserted at left." << endl;
                    break;
                } else {
                    temp = temp->left;
                }
            } else if (c == 0) {
                if (temp->right == nullptr) {
                    temp->right = new Node(data);
                    cout << "Value inserted at right." << endl;
                    break;
                } else {
                    temp = temp->right;
                }
            } else {
                cout << "Enter a valid input!!!" << endl;
            }
        }
    }

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << "  ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << "  ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << "  ";
    }

    void displayInorder() {
        inorder(root);
        cout << endl;
    }

    void displayPreorder() {
        preorder(root);
        cout << endl;
    }

    void displayPostorder() {
        postorder(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;

    while (true) {
        cout << "\n-------------------------TREE - Menu driven Program---------------------------\n";
        cout << "1. Insert Node\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Exit\n";
        int user;
        cout << "Enter your choice: ";
        cin >> user;

        if (user == 1) {
            int data;
            cout << "Enter the data to be inserted: ";
            cin >> data;
            tree.insert(data);
        } else if (user == 2) {
            tree.displayInorder();
        } else if (user == 3) {
            tree.displayPreorder();
        } else if (user == 4) {
            tree.displayPostorder();
        } else if (user == 5) {
            break;
        } else {
            cout << "Enter a valid input." << endl;
        }
    }

    return 0;
}
