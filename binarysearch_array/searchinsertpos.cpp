search insert position in a sorted array
#include <iostream>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        int ans=nums.size();
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]>=target){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};
int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    Solution solution;
    int index = solution.searchInsert(nums, target);

    cout << "The target should be inserted at index: " << index << endl;

    return 0;
}
//time complexity: O(log n) where n is the number of elements in the array
//space complexity: O(1)

intuition:
The idea is to use binary search to efficiently find the position where the target should be inserted in the sorted array. We maintain two pointers, left and right, to represent the current search range. We calculate the mid index and compare the middle element with the target. If the middle element is greater than or equal to the target, we update our answer to mid and move the right pointer to mid - 1 to search in the left half. If the middle element is less than the target, we move the left pointer to mid + 1 to search in the right half. This process continues until the left pointer exceeds the right pointer. The final answer will be the index where the target should be inserted.
