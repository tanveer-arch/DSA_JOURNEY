/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  Node* reverseList(Node* head) {
     
         Node* front=NULL;
       if(head==NULL || head->next==NULL){
        return head;
       }
       Node* newhead=reverseList(head->next);
       front=head->next;
       front->next=head;
       head->next=NULL;
        return newhead;
    }
    Node* addOne(Node* head) {
        // Your Code here
        Node* newhead=reverseList(head);
        Node* temp=newhead;
        // return head of list after adding one
        int carry=1;
        
      
        while(temp!=NULL){
             
            temp->data=carry+temp->data;
            
            if(temp->data>9){
                carry=1;
                temp->data=temp->data%10;
            
            }
            else{
                carry=0;
                break;
            }
            temp=temp->next;
        }
            if(carry){
                Node* newnode=new Node(carry);
                head=reverseList(newhead);
                newnode->next=head;
                return newnode;
                
            }
        
        head=reverseList(newhead);
        return head;
        
    }
};