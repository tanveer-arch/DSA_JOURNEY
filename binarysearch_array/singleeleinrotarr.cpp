In this code, we implement a function to find the single element in a sorted array where every other element appears exactly twice. The approach uses binary search to efficiently locate the unique element.


    class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            int n=nums.size();
            int low=1,high=n-2;
            if(n==1){
                return nums[0];
            }
            if(nums[0]!=nums[1]){
                return nums[0];
            }
            if(nums[n-1]!=nums[n-2]){
                return nums[n-1];
            }

            while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }

            if(mid%2==0){
                if(nums[mid]==nums[mid-1]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(nums[mid]==nums[mid-1]){
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
The idea is to use binary search to efficiently find the single non-duplicate element in a sorted   array. We maintain two pointers, low and high, to represent the current search range. We calculate the mid index and check if the element at mid is the unique element by comparing it with its neighbors. If it is not unique, we determine which half of the array to search next based on the properties of the indices and their corresponding values. If mid is even and equals the previous element, the unique element must be in the left half; otherwise, it is in the right half. If mid is odd and equals the previous element, the unique element is in the right half; otherwise, it is in the left half. This process continues until we find the unique element.
