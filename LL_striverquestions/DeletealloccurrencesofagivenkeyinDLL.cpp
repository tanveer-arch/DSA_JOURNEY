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
// Each node has both next and prev pointers, so you must update two links whenever a node
// is removed.
// The head node itself can also be deleted — hence the need for a double pointer (Node
// ** head_ref).
// 🧠 2. Why use Node** head_ref
// When the head node needs to be deleted, you must update the head pointer itself.
// Using Node** head_ref allows you to modify the original head pointer passed from the
// calling function.
// If you used Node* head, changes to head inside the function would not reflect outside.
// Example:
// *head_ref = (*head_ref)->next;
// ensures that changes reflect in the calling function too.
// 🔄 3. Deletion Logic
// When you find a node with data == x:
// If it's the head node (temp->prev == NULL):
// Update *head_ref to point to the next node.
// If it's a middle or last node:
// Re-link the previous and next nodes to bypass the current node.
// temp->prev->next = temp->next;
// if (temp->next) temp->next->prev = temp->prev;
// 🔄 4. Safe Pointer Movement  
// After deletion, move temp to the next node before deleting the current node to avoid
// accessing freed memory.
// Always save the next node before deletion (to avoid accessing freed memory).
// temp = temp->next;
// delete todelete;
// This ensures you don't lose the reference to the rest of the list after deletion.
// 🧩 5. Key Cases to Handle
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


