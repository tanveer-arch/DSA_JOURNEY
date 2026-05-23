// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int,int>> result;
        Node* left=head;
        Node* right=head;
        while(right->next!=NULL){
            right=right->next;
        }
        
        while(right->data > left->data ){
            if(left->data+right->data>target){
                right=right->prev;
            }
            else if(left->data+right->data<target){
                left=left->next;
            }
            else{
                result.push_back({left->data,right->data});
                left=left->next;
                right=right->prev;
            }
        }
        return result;
    }
};