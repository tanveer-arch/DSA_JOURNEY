/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* tail=head;
        ListNode* prev=NULL;
        ListNode* temp=head;
        int count=1;
         if(tail==NULL || tail->next==NULL){
                return head;
            }
        while(temp->next!=NULL){
            count++;
            temp=temp->next;
        }
        
        if(k){
        k=k%count;
        }
        int tailcount=count-k;
                   
        while(tailcount-1){
            tail=tail->next;
            tailcount--;
        }
        temp->next=head;
        head=tail->next;
        tail->next=NULL;
        
    
        
    return head;
}
};

// 🧠 Key Takeaways to Write in Your Notes
// 🔹 1. “Rotate” ≠ “Shift one by one”

// 👉 Avoid naive O(k * n) solutions — think in terms of connecting and breaking the list.

// 🔹 2. Make list circular (temporarily)

// Form a loop (tail->next = head), then simply cut it at the correct position.

// 🔹 3. Find the new tail position:

// Formula → newTailIndex = length - (k % length) - 1
// → newHead = newTail->next

// 🔹 4. Handle base & edge cases:

// Empty list (head == NULL)

// Single node

// k == 0 or k % length == 0 → no change needed

// 🔹 5. Pointer safety:

// Always ensure:

// You traverse only when node exists (temp->next != NULL)

// You break the list (tail->next = NULL) after forming the correct connection

// 🔹 6. Pattern recognition:

// This rotation pattern repeats in:

// Array rotation problems

// Circular linked list problems

// Queue rotations

// → So mastering this helps across topics