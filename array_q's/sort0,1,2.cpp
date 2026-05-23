*** Brute Force Approach (Counting Sort) ***
We count the number of 0s, 1s and 2s in the array and then overwrite the array accordingly. 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int count0=0;
        int count1=0;
        int count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count0++;
            }
            else if(nums[i]==1){
                count1++;
            }
            else{
                count2++;
            }
        }

        for(int i=0;i<count0;i++){
            nums[i]=0;
        }
        for(int i=count0;i<count0+count1;i++){
            nums[i]=1;
        }
        for(int i=count0+count1;i<count0+count1+count2;i++){
            nums[i]=2;
        }
    }
};

time complexity: O(n)
space complexity: O(1)
but requires two passes over the array. so we will use dutch national flag algorithm which requires only one pass.

*** Optimal Approach (Dutch National Flag Algorithm)*** 
We divide the array into 4 regions using 3 pointers:

[    0s      |    1s      |   unknown   |    2s      ]
          ↑   ↑          ↑ ↑           ↑ ↑          ↑
0   to  low-1 low    mid-1 mid      high high+1    n-1

🔹 If nums[mid] == 0
swap(nums[low], nums[mid]);
low++;
mid++;

🔹 If nums[mid] == 1
mid++;

🔹 If nums[mid] == 2
swap(nums[mid], nums[high]);
high--;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0,mid=0,high=n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};

***time complexity: O(n)***
***space complexity: O(1)***


