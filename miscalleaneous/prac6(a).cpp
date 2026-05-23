    #include <iostream>
    #include <string>
    using namespace std;

    // Node class for each phone book entry
    class Node {
    public:
        string name;
        string phone;
        Node *left, *right;

        Node(string n, string p) {
            name = n;
            phone = p;
            left = right = NULL;
        }
    };

    // PhoneBook class using Binary Search Tree
    class PhoneBook {
    private:
        Node *root;

        // Insert a new contact
        Node* insert(Node *root, string name, string phone) {
            if (root == NULL)
                return new Node(name, phone);

            if (name < root->name)
                root->left = insert(root->left, name, phone);
            else if (name > root->name)
                root->right = insert(root->right, name, phone);
            else
                cout << "Contact with this name already exists!\n";

            return root;
        }

        // Find smallest node (used during deletion)
        Node* findMin(Node *root) {
            while (root->left != NULL)
                root = root->left;
            return root;
        }

        // Delete a contact
        Node* remove(Node *root, string name) {
            if (root == NULL) {
                cout << "Contact not found!\n";
                return NULL;
            }

            if (name < root->name)
                root->left = remove(root->left, name);
            else if (name > root->name)
                root->right = remove(root->right, name);
            else {
                // Found node to delete
                if (root->left == NULL && root->right == NULL) {
                    delete root;
                    return NULL;
                }
                else if (root->left == NULL) {
                    Node *temp = root->right;
                    delete root;
                    return temp;
                }
                else if (root->right == NULL) {
                    Node *temp = root->left;
                    delete root;
                    return temp;
                }
                else {
                    Node *temp = findMin(root->right);
                    root->name = temp->name;
                    root->phone = temp->phone;
                    root->right = remove(root->right, temp->name);
                }
            }
            return root;
        }

        // Search a contact
        Node* search(Node *root, string name) {
            if (root == NULL || root->name == name)
                return root;

            if (name < root->name)
                return search(root->left, name);
            else
                return search(root->right, name);
        }

        // Print in ascending order
        void inorder(Node *root) {
            if (root == NULL)
                return;
            inorder(root->left);
            cout << root->name << " : " << root->phone << endl;
            inorder(root->right);
        }

        // Print in descending order
        void reverseInorder(Node *root) {
            if (root == NULL)
                return;
            reverseInorder(root->right);
            cout << root->name << " : " << root->phone << endl;
            reverseInorder(root->left);
        }

    public:
        PhoneBook() {
            root = NULL;
        }

        void addContact(string name, string phone) {
            root = insert(root, name, phone);
        }

        void deleteContact(string name) {
            root = remove(root, name);
        }

        void searchContact(string name) {
            Node *res = search(root, name);
            if (res == NULL)
                cout << "Contact not found!\n";
            else
                cout << "Phone number of " << name << " is: " << res->phone << endl;
        }

        void displayAscending() {
            cout << "\nPhone Book (Ascending Order):\n";
            inorder(root);
        }

        void displayDescending() {
            cout << "\nPhone Book (Descending Order):\n";
            reverseInorder(root);
        }
    };

    // ------------------- MAIN PROGRAM -------------------
    int main() {
        PhoneBook pb;
        int choice;
        string name, phone;

        while (true) {
            cout << "\n========== PHONE BOOK MENU ==========\n";
            cout << "1. Add new contact\n";
            cout << "2. Delete contact\n";
            cout << "3. Search contact\n";
            cout << "4. Display contacts (Ascending)\n";
            cout << "5. Display contacts (Descending)\n";
            cout << "0. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter name: ";
                    cin >> name;
                    cout << "Enter phone number: ";
                    cin >> phone;
                    pb.addContact(name, phone);
                    break;

                case 2:
                    cout << "Enter name to delete: ";
                    cin >> name;
                    pb.deleteContact(name);
                    break;

                case 3:
                    cout << "Enter name to search: ";
                    cin >> name;
                    pb.searchContact(name);
                    break;

                case 4:
                    pb.displayAscending();
                    break;

                case 5:
                    pb.displayDescending();
                    break;

                case 0:
                    cout << "Exiting program... Goodbye!\n";
                    return 0;

                default:
                    cout << "Invalid choice! Try again.\n";
            }
        }
    }
