In this code, we implement a function to search for a target value in a rotated sorted array using binary search.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && nums[mid]>=target){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(nums[mid]<=target && nums[high]>=target){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            }
            return -1;
        }
    
};
//time complexity: O(log n) where n is the number of elements in the array
//space complexity: O(1)
//intuition:
The idea is to use binary search to efficiently find the target value in a rotated sorted array. We maintain two pointers, low and high, to represent the current search range. We calculate the mid index and check if the middle element is equal to the target. If it is, we return the mid index. If not, we determine which half of the array is sorted. If the left half is sorted, we check if the target lies within that range; if it does, we adjust the high pointer to mid - 1, otherwise, we adjust the low pointer to mid + 1. If the right half is sorted, we perform a similar check and adjust the pointers accordingly. This process continues until we either find the target or exhaust the search range.

reasoning:
In a rotated sorted array, one half of the array is always sorted. By identifying which half is sorted, we can determine whether the target lies within that half or the other half. This allows us to effectively narrow down our search range in each iteration, maintaining the logarithmic time complexity characteristic of binary search.