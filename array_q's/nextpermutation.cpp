In this problem, we need to find the next lexicographical permutation of a given array of numbers. The approach involves identifying a pivot point where the sequence starts decreasing, swapping it with the smallest number larger than it to its right, and then reversing the sequence after the pivot to get the next permutation.

class Solution {
public:
   
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int index=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
            index=i;
            break;
            }
        }
        if(index==-1){
            reverse(nums.begin(),nums.end());
            return ;
        }

        for(int i=n-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[index],nums[i]);
                break;
            }
        }
        reverse(nums.begin()+index+1,nums.end());
    }
};

time complexity: O(n)
space complexity: O(1)

intuition:
1. Traverse from the end of the array to find the first decreasing element. This element is called the pivot.
2. If no such element is found, it means the array is in descending order. In this case, reverse the entire array to get the smallest permutation.
3. If a pivot is found, traverse from the end again to find the first element that is greater than the pivot. Swap these two elements.
4. Finally, reverse the sub-array to the right of the pivot to get the next permutation

