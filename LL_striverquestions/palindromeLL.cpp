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
     
         ListNode* front=NULL;
       if(head==NULL || head->next==NULL){
        return head;
       }
       ListNode* newhead=reverseList(head->next);
       front=head->next;
       front->next=head;
       head->next=NULL;
        return newhead;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
       ListNode* slow=head;
       ListNode* fast=head;
       while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
       }
       ListNode* newhead=reverseList(slow->next);
       
       ListNode* first=head;
       ListNode* second=newhead;
       while(second!=NULL){
        if(first->val!=second->val){
            reverseList(newhead);
            return false;
        }
        else{
            first=first->next;
            second=second->next;
        }
       }
       reverseList(newhead);
       return true;

    }
};