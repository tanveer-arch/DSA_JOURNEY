In this code, we implement a function to find a peak element in an array. A peak element is defined as an element that is greater than its neighbors. The approach uses binary search to efficiently locate a peak element.

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int low=1,high=n-2;
        if(n==1){
            return 0;
        }
        if(nums[0]>nums[1] ){
            return 0;
        }
        else if(nums[n-1]>nums[n-2]){
            return n-1;
        }
        else{
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;    
            }

            if(nums[mid]<nums[mid+1]){  
                low=mid+1;
            }
            else if(nums[mid]<nums[mid-1]){
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
The idea is to use binary search to efficiently find a peak element in the array. We maintain two pointers, low and high, to represent the current search range. We calculate the mid index and check if the element at mid is a peak by comparing it with its neighbors. If it is a peak, we return its index. If the element at mid is less than its right neighbor, it indicates that there is a peak in the right half of the array, so we adjust the low pointer to mid + 1. Conversely, if the element at mid is less than its left neighbor, there must be a peak in the left half, so we adjust the high pointer to mid - 1. This process continues until we find a peak element.
Visualization:
Consider the array [1, 3, 20, 4, 1, 0]. The peak element is 20 at index 2. The binary search will first check the middle element and determine which half to search next based on the comparisons with its neighbors, eventually leading to the peak element.
edge Cases:
1. Single element array: The only element is the peak. 
2. Peak at the beginning or end: The function checks these cases explicitly before entering the binary search loop.
3. Multiple peaks: The function will return the index of any one of the peak elements.
