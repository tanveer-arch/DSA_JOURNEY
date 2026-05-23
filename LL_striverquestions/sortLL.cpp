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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // 1. Copy values into a vector
        vector<int> vals;
        ListNode* temp = head;
        while (temp) {
            vals.push_back(temp->val);
            temp = temp->next;
        }

        // 2. Sort the vector
        sort(vals.begin(), vals.end());

        // 3. Put sorted values back into the list
        temp = head;
        int i = 0;
        while (temp) {
            temp->val = vals[i++];
            temp = temp->next;
        }

        return head;
    }
};

// optimal approach (mergesort  technique)

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
    ListNode* findmid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* mergelist(ListNode* list1,ListNode* list2){
        ListNode* dummynode=new ListNode(-1);
        ListNode* temp=dummynode;
        while(list1 && list2){
            if(list1->val<list2->val){
                temp->next=list1;
                temp=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
        }
            if(list1){
                temp->next=list1;
            }
            else{
                temp->next=list2;
            }
            return dummynode->next;
        
    }
    ListNode* sortList(ListNode* head) {
        if (head==NULL || head->next==NULL) return head;
        ListNode* middle=findmid(head);
        ListNode* lefthead=head;
        ListNode* righthead=middle->next;
        middle->next=NULL;
        lefthead=sortList(lefthead);
        righthead=sortList(righthead);
        return mergelist(lefthead,righthead);
       
    }
};

// 🧾 Sort Linked List — Notes
// 🔹 Concept:
// Sort a linked list in O(n log n) time and O(1) space using Merge Sort.
// 🔹 Key Learnings:
// 1. Finding the Middle:
// Use the slow and fast pointer technique to find the middle of the list.
// 2. Dividing the List:
// Split the list into two halves at the middle.
// 3. Recursive Sorting:
// Recursively sort both halves of the list.
// 4. Merging Sorted Lists:
// Merge the two sorted halves back together.
// 5. Base Case:
// If the list is empty or has one node, it is already sorted.
// 🔹 Complexity:
// Time Complexity: O(n log n), where n is the number of nodes in the list.
// Space Complexity: O(1) (ignoring recursion stack space).
