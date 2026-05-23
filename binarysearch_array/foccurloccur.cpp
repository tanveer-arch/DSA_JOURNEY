In this code, we implement a function to find the first and last occurrence of a target value in a sorted array using binary search.
we define two helper functions, lowerbound and upperbound, to find the first index where the target appears and the first index where an element greater than the target appears, respectively. The main function, searchRange, uses these helper functions to determine the range of indices for the target value.

class Solution {
public:
    int lowerbound(vector<int>& nums,int n,int k){
        int low=0;
        int high=n-1;
        int lb=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=k){
                lb=mid;
                high=mid-1;
            }
            else{
            low=mid+1;
        }
        }
        return lb;
    }

    int upperbound(vector<int>& nums,int n,int k){
        int low=0;
        int high=n-1;
        int ub=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(nums[mid]>k){
                ub=mid;
                high=mid-1;
            }
            else{
            low=mid+1;
        }
        }
        return ub;
    }
   
    vector<int> searchRange(vector<int>& nums, int target) {
           
            int n=nums.size();
            int lb=lowerbound(nums,n,target);
            int ub=upperbound(nums,n,target);
            if(lb==n || nums[lb]!=target ){
                return {-1,-1};
            }
            
    return {lb,ub-1};

    }
};
//time complexity: O(log n) where n is the number of elements in the array
//space complexity: O(1)
//intuition:
The idea is to use binary search to efficiently find the first and last occurrences of the target value
in the sorted array. The lowerbound function finds the first index where the target appears by searching for the smallest index where the element is greater than or equal to the target. The upperbound function finds the first index where an element greater than the target appears. By subtracting one from the result of upperbound, we get the last occurrence of the target. If the lowerbound index is equal to the size of the array or if the element at that index is not equal to the target, it means the target is not present in the array, and we return {-1, -1}. Otherwise, we return the range [lowerbound, upperbound - 1].


approach using separate first and last occurrence functions:
In this approach, we define two separate functions, firstoccur and lastoccur, to find the first and last occurrences of the target value in the sorted array using binary search. The main function, searchRange, calls these two functions and returns their results as a vector.


class Solution {
public:
    int firstoccur(vector<int>& nums,int n,int k){
        int low=0;
        int high=n-1;
        int fo=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==k){
                fo=mid;
                high=mid-1;
            }
            else if(nums[mid]>k){
                high=mid-1;
            }
            else{
            low=mid+1;
        }
        }
        return fo;
    }

    int lastoccur(vector<int>& nums,int n,int k){
        int low=0;
        int high=n-1;
        int lo=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(nums[mid]==k){
                lo=mid;
                low=mid+1;
            }
            else if(nums[mid]>k){
                high=mid-1;
            }
            else{
            low=mid+1;
        }
        }
        return lo;
    }
   
    vector<int> searchRange(vector<int>& nums, int target) {
           
            int n=nums.size();
            int fo=firstoccur(nums,n,target);
            int lo=lastoccur(nums,n,target);
           
            
    return {fo,lo};

    }
};
//time complexity: O(log n) where n is the number of elements in the array
//space complexity: O(1)
//intuition:
The idea is to use binary search to efficiently find the first and last occurrences of the target value
in the sorted array. The firstoccur function finds the first index where the target appears by searching for the smallest index where the element is equal to the target. The lastoccur function finds the last index where the target appears by searching for the largest index where the element is equal to the target. If the target is not found, both functions return -1. The main function, searchRange, calls these two functions and returns their results as a vector.