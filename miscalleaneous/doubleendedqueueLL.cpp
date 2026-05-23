#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) {
        data = val;
        prev = next = nullptr;
    }
};


class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() {
        front = rear = nullptr;
    }

    // i. Insert at front
    void insertFront(int val) {
        Node* newNode = new Node(val);
        if (front == nullptr) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        cout << val << " inserted at front.\n";
    }

    // ii. Insert at rear
    void insertRear(int val) {
        Node* newNode = new Node(val);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        cout << val << " inserted at rear.\n";
    }

    // iii. Delete from front
    void deleteFront() {
        if (front == nullptr) {
            cout << "Deque is empty.\n";
            return;
        }
        Node* temp = front;
        cout << "Deleted element from front: " << front->data << endl;
        front = front->next;
        if (front != nullptr)
            front->prev = nullptr;
        else
            rear = nullptr; // If list becomes empty
        delete temp;
    }

    // iv. Delete from rear
    void deleteRear() {
        if (rear == nullptr) {
            cout << "Deque is empty.\n";
            return;
        }
        Node* temp = rear;
        cout << "Deleted element from rear: " << rear->data << endl;
        rear = rear->prev;
        if (rear != nullptr)
            rear->next = nullptr;
        else
            front = nullptr; // If list becomes empty
        delete temp;
    }

    // v. Display elements
    void display() {
        if (front == nullptr) {
            cout << "Deque is empty.\n";
            return;
        }
        Node* temp = front;
        cout << "Deque elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    Deque dq;
    int choice, val;

    while (true) {
        cout << "\n--- Double Ended Queue Menu ---\n";
        cout << "1. Insert Front\n";
        cout << "2. Insert Rear\n";
        cout << "3. Delete Front\n";
        cout << "4. Delete Rear\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            dq.insertFront(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            dq.insertRear(val);
            break;
        case 3:
            dq.deleteFront();
            break;
        case 4:
            dq.deleteRear();
            break;
        case 5:
            dq.display();
            break;
        case 6:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
