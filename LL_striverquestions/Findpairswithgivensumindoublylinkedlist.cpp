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

// 🔹 Two Pointer in Doubly Linked List (Sum = Target)

// Step 1: Move one pointer (right) to the tail of DLL.

// Step 2: Use left = head and right = tail.

// Step 3: While left != right && left->prev != right:

// If sum == target → store pair, move both pointers.

// If sum < target → move left = left->next.

// If sum > target → move right = right->prev.

// Stop when pointers meet or cross.

// TC = O(N) and SC = O(1).

// 🧩 Common Mistakes to Avoid:

// Don’t overshoot tail (while(right->next != NULL) not while(right != NULL)).

// Compare addresses, not data values.

// Handle NULL and single-node lists safely.