In this code, we implement a function to find the minimum element in a rotated sorted array using binary search.


class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
       
        while(low<=high){
        int mid=(low+high)/2;
        if(nums[low]<=nums[high]){
                return nums[low];
        }
        if(nums[mid]>=nums[low]){
            low=mid+1;
        }
        else{
            high=mid;
        }
        }
    return -1;
    }
};
//time complexity: O(log n) where n is the number of elements in the array
//space complexity: O(1)
//intuition:
The idea is to use binary search to efficiently find the minimum element in a rotated sorted array. We maintain two pointers, low and high, to represent the current search range. We calculate the mid index and check if the subarray from low to high is already sorted; if it is, the minimum element is at the low index. If not, we determine which half of the array is sorted. If the left half is sorted, we know the minimum must be in the right half, so we adjust the low pointer to mid + 1. If the right half is sorted, we adjust the high pointer to mid. This process continues until we find the minimum element.
//reasoning:
In a rotated sorted array, one half of the array is always sorted. By identifying which half is sorted, we can determine where the minimum element lies. If the left half is sorted, the minimum must be in the right half, and vice versa. This allows us to effectively narrow down our search range in each iteration, maintaining the logarithmic time complexity characteristic of binary search.