/*
class Node {
public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int cycleStart(Node* head) {
        // code here
        Node* temp=head;
        map<Node*,int>mpp;
        while(temp!=NULL){
            mpp[temp]++;
            if(mpp[temp]>1){
                return temp->data;
            }
            temp=temp->next;
        }
        return -1;
    }
};




// ***optional approach using Floyd's Cycle Detection Algorithm***
/*class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    int cycleStart(Node* head) {
        // code here
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
            while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
            }
            return slow->data;
            }
        }
        return -1;
       
       
    }
};