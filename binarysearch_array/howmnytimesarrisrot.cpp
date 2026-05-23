In this code, we implement a function to find the number of times a sorted array has been rotated. The number of rotations is equal to the index of the minimum element in the rotated array.



class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[low]<=arr[high]){
                return low;
            }
            if(arr[mid]>=arr[low]){
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
The idea is to use binary search to efficiently find the index of the minimum element in a rotated sorted array. We maintain two pointers, low and high, to represent the current search range. We calculate the mid index and check if the subarray from low to high is already sorted; if it is, the minimum element is at the low index. If not, we determine which half of the array is sorted. If the left half is sorted, we know the minimum must be in the right half, so we adjust the low pointer to mid + 1. If the right half is sorted, we adjust the high pointer to mid. This process continues until we find the minimum element.