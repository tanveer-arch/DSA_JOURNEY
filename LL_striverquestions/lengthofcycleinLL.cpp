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
    int lengthOfLoop(Node *head) {
        // code here
        int count=0;
       
        Node* fast=head;
        Node* slow=head;
        
        while(fast!=NULL && fast->next!=NULL){
            
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                while(slow->next!=fast){
                count++;
                slow=slow->next;
                }
                return count+1;
            }
            }
            return 0;
        }
        
    
};


// ***another approach***
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
    int lengthOfLoop(Node *head) {
        // code here
        int count=0;
        map<Node*,int>mpp;
        Node* temp=head;
        int value=0;
        while(temp!=NULL){
            count++;
           
            if(mpp.find(temp)!=mpp.end()){
                value=mpp[temp];
                return count-value;
            }
             mpp[temp]=count;
            temp=temp->next;
            
        }
        return 0;
    }
};