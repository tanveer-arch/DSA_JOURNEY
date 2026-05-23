/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* curr=head;
        Node* last=NULL;
        while(curr!=NULL){
         last=curr->prev;
         curr->prev=curr->next;
         curr->next=last;
         curr=curr->prev;
        }
        head=last->prev;
        return head;
    }
};