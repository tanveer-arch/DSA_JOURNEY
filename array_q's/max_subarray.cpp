***brute  force approach***
We will check for all subarrays and calculate their sums. If the sum equals k, we will update the maximum length.
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n=nums.size();
        int maxlen=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==k){
                    maxlen=max(maxlen,j-i+1);
                }
            }
        }
        return maxlen;
    }
};
***time complexity: O(n^2)***
***space complexity: O(1)***
---------------------------------------------------------------------------------------
***optimal approach using kadane's algorithm***
We will use Kadane's algorithm to find the maximum subarray sum. In this approach,
we will maintain a running sum and update the maximum sum whenever the running sum exceeds the current maximum. If the running sum becomes negative, we reset it to zero.
***intution:
A negative sum will only decrease the sum of any subarray that comes after it, so we reset the sum to zero when it becomes negative.


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int max=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            if(sum>max){
                max=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return max;
    }
};
***time complexity: O(n)***
***space complexity: O(1)***







