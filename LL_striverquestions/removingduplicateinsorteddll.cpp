/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        Node* temp=head;
        Node* nextnode=temp->next;
        
        while(temp!=NULL && temp->next!=NULL){
             Node* nextnode=temp->next;
             while(nextnode!=NULL && temp->data==nextnode->data){
                 nextnode=nextnode->next;
             }
             temp->next=nextnode;
             if(nextnode){
                 nextnode->prev=temp;
             }
             temp=temp->next;
        }
        
    return head;
        }
};


// 🧠 Takeaways for Your Notes

// Write these points down 👇

// 🔹 When removing duplicates in a sorted Doubly Linked List:

// Use two pointers (temp, nextnode) — one stays on the current node, another skips ahead to find the next distinct value.

// Always check for NULL before accessing .data.

// When reconnecting:

// temp->next = nextnode;

// if (nextnode) nextnode->prev = temp;

// Always consider duplicates at the end — make sure the list can safely terminate (temp->next = NULL).

// Time Complexity: O(N)
// Space Complexity: O(1)

// Never move both pointers in the same iteration — let the inner loop skip, then move temp once after adjustment.

// Ideal for sorted DLLs; for unsorted ones, use hashing instead.