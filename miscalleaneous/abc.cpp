#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to count nodes (for number of passes)
int getLength(ListNode* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Bubble Sort without do-while
void bubbleSort(ListNode* head) {
    if (head == NULL)
        return;

    int n = getLength(head);  // total nodes

    for (int i = 0; i < n - 1; i++) { // number of passes
        ListNode* curr = head;
        ListNode* nextNode = head->next;
        

        while (nextNode != NULL) {
            if (curr->val > nextNode->val) {
                // swap values
                int temp = curr->val;
                curr->val = nextNode->val;
                nextNode->val = temp;
               
            }
            curr = nextNode;
            nextNode = nextNode->next;
        }

        // if no swaps in a pass → already sorted
        
    }
}

// Print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// ---------------- MAIN ----------------
int main() {
    // Example: 4 → 2 → 1 → 3
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    cout << "Before Sorting: ";
    printList(head);

    bubbleSort(head);

    cout << "After Sorting: ";
    printList(head);

    return 0;
}
