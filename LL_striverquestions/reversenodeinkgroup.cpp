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
ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        // ListNode* curr=head;
        while(temp!=NULL){
            ListNode* curr=temp->next;
            temp->next=prev;
            prev=temp;
            temp=curr; 
        }
        head=prev;
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* knode=temp;
        ListNode* newhead=NULL;
        ListNode* nxtnode=NULL;
        ListNode* prev=NULL;
        while(knode!=NULL){
        for(int i=0;i<k-1;i++){
            if(knode){
            knode=knode->next;
            }
        }
        if(knode){
        nxtnode=knode->next;
        knode->next=NULL;
        
        if(temp==head){
       newhead= reverseList(temp);
       prev=temp;
        }
        else{
         prev->next=reverseList(temp);
         prev=temp;
        }
       temp=nxtnode;
       knode=temp;
        }
        else{
            prev->next=temp;
        }
        }
    return newhead;
        
    }
};

//
// 🧠 Conceptual Takeaways
// 1️⃣ Linked List Pointer Manipulation

// You practiced deep pointer control — next, prev, head, and temporary nodes.

// Learned the difference between:

// temp → used for traversal

// prev → used for reconnecting reversed parts

// knode → used to locate the end of the current group

// nxtnode → stores the start of the next segment

// You handled cutting and reconnecting sublists — a crucial pattern in many linked list problems.

// 2️⃣ Safe Traversal and Null Handling

// The bug you fixed (knode = knode->next on NULL) taught you an essential principle:

// ✅ Always check for NULL before accessing .next or .prev.

// This principle applies to every linked list problem — it prevents 90% of runtime crashes.

// 3️⃣ Reversing a Sublist

// You separated the reversal logic into a clean helper function reverseList().
// This improves modularity and readability.

// You learned how to reverse only a section of the list, not the whole thing —
// by disconnecting it (knode->next = NULL) before reversal.

// 4️⃣ Reconnecting Reversed Parts

// After reversing each k-group, you had to:

// Connect the previous group’s tail (prev) to the newly reversed head.

// Update prev to the tail of the current reversed group (which was originally temp).

// ✅ This technique of breaking → reversing → reconnecting is a powerful recurring pattern.

// 5️⃣ Handling Edge Cases

// You correctly handled:

// The first group (where newhead must be updated).

// The last incomplete group, which must remain unchanged.

// The case where k = 1 or the list is empty (head == NULL).

// These edge-case conditions are essential for clean, production-level linked list code.

// ⚙️ Technical/Complexity Insights
// Aspect	Description
// Time Complexity	O(n) — each node is visited and reversed exactly once
// Space Complexity	O(1) — iterative in-place reversal
// Key Idea	Reverse every contiguous group of size k
// 🧩 Common Mistakes You Avoided / Fixed

// ❌ Not checking knode for NULL → fixed with condition inside loop.

// ❌ Forgetting to reconnect prev->next after reversal → handled properly.

// ❌ Modifying the list without isolating segments (knode->next = NULL) → now correct.

// 🔁 How to Recall This in Future Revisions

// Here’s a short mnemonic-style revision summary 👇

// “Find – Cut – Reverse – Connect – Move”

// Find the k-th node (knode).

// Cut the list at that node (knode->next = NULL).

// Reverse that small sublist.

// Connect the reversed part back to previous/next.

// Move to the next segment.

// That 5-step sequence applies to many advanced LL questions:

// Reverse Nodes in k-Groups

// Reverse Between m and n

// Reverse Alternate k-Groups

// Rotate Linked List

// 🏁 Final Tip

// When revising, focus on:

// Pointer safety (NULL checks)

// Correct segment isolation (knode->next = NULL)

// Proper reconnection of prev and next

// Maintaining a clean modular structure (reverseList() helper)
//