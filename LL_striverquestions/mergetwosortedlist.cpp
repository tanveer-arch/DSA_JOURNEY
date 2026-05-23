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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* dummynode=new ListNode(-1,NULL);
         ListNode* temp=dummynode;
    
        while(temp1!=NULL && temp2!=NULL){
        
            if(temp1->val<=temp2->val){
                temp->next=temp1;
                temp=temp1;
                temp1=temp1->next;
                }
                else{
                temp->next=temp2;
                temp=temp2;
                temp2=temp2->next;
                }
        }
                if(temp1){
                 temp->next=temp1;
            }
        
            else{
                temp->next=temp2;
            }
            
            return dummynode->next;       
    }
};

🧾 Merge Two Sorted Linked Lists — Notes
🔹 Concept:

Merge two sorted linked lists into one sorted list.

Must be done in-place (no new list creation except dummy node).

🔹 Key Learnings:

Use a dummy node to simplify edge cases for the head.

Maintain a pointer (temp) to track the current end of the merged list.

Compare current nodes of both lists → attach the smaller one.

Always move both temp and the pointer of the chosen node forward.

After one list finishes, link the remaining part of the other list.

Return the next of dummy node as the new head.

Handles cases where one or both lists are empty automatically.

🔹 Complexity:

Time: O(n + m) → each list traversed once.

Space: O(1) → only pointer manipulation, no extra data structure.

🔹 Intuition:

Treat the merging like the merge step of merge sort.

Dummy node acts as a temporary start so we don’t lose head reference.

Always maintain connection continuity and avoid overwriting links