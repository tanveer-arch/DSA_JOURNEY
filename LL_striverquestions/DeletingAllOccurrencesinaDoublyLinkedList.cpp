// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        Node* temp=*head_ref;
      
        while(temp!=NULL){
            if(temp->data==x){
                
                  Node* todelete=temp;
                
                if(temp->prev==NULL){
                    *head_ref=temp->next;
                    if(temp->next){
                        temp->next->prev=NULL;
                    }
                }
                
                else {
                    if(temp->next){
                temp->next->prev=temp->prev;
                temp->prev->next=temp->next;
                    }
                    else{
                        temp->prev->next=temp->next;
                    }
            }
            
            temp=temp->next;
            delete todelete;
            }
            else{
            temp=temp->next;
            }
        }
        return ;
    }
};

// 🧾 Takeaways — Deleting All Occurrences in a Doubly Linked List
// ⚙️ 1. Understanding the Problem

// You need to delete all nodes having value x in a doubly linked list.

// Each node has both next and prev pointers, so you must update two links whenever a node is removed.

// The head node itself can also be deleted — hence the need for a double pointer (Node** head_ref).

// 🧠 2. Why use Node** head_ref

// When you pass the head by pointer-to-pointer,
// you can directly modify the original head inside the function (e.g., when the first node is deleted).

// Example:

// *head_ref = (*head_ref)->next;


// ensures that changes reflect in the calling function too.

// 🧩 3. Key Cases to Handle

// Deleting the head node

// Update *head_ref to point to the next node.

// Set next->prev = NULL.

// Deleting a middle node

// Link previous and next nodes together:

// temp->prev->next = temp->next;
// temp->next->prev = temp->prev;


// Deleting the last node

// Just set temp->prev->next = NULL.

// When list becomes empty

// The loop ends gracefully since temp becomes NULL.

// 🔄 4. Safe Pointer Movement

// Always save the next node before deletion (to avoid accessing freed memory).

// Node* nextNode = temp->next;
// delete temp;
// temp = nextNode;


// You correctly handled this by adjusting traversal carefully.

// 🚫 5. Common Mistakes You Avoided / Fixed

// ❌ Forgetting to move temp when node not deleted → infinite loop.

// ❌ Accessing temp->next after deleting temp → dangling pointer crash.

// ❌ Not updating head when first node deleted.

// ✅ You properly fixed all these.

// 📈 6. Complexity

// Time: O(n) — each node is visited once.

// Space: O(1) — in-place modification.

// 💡 7. Intuitive Flow Summary

// Traverse through the list using temp.

// If node matches x, detach it safely by reconnecting neighbors.

// Adjust the head if needed.

// Delete the node and continue traversal.