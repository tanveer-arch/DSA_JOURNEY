In this code, we implement a function to count the number of subarrays in a given array that sum up to a specified value k.

brute force approach:In this approach, we use two nested loops to consider all possible subarrays of the input array. For each subarray, we calculate the sum and check if it equals k. If it does, we increment our count.

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum=sum+nums[j];
                if(sum==k){
                    count++;
                }
            }
        }
        return count;
    }
};
time complexity: O(n^2)
space complexity: O(1)

optimized approach:In this approach, we use a hash map to store the frequency of prefix sums encountered while iterating through the array. For each element, we update the prefix sum and check if there exists a prefix sum that, when subtracted from the current prefix sum, equals k. If such a prefix sum exists, we add its frequency to our count. This allows us to find the number of subarrays summing to k in linear time. 

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mpp;
        int prefixsum=0;
        mpp[0]=1;
        int count=0;
        for(int i=0;i<n;i++){
            prefixsum=prefixsum+nums[i];
           
            if(mpp.find(prefixsum-k)!=mpp.end()){
                    count=count+mpp[prefixsum-k];
                }
                 mpp[prefixsum]++;
                 
            }
        
       return count;
            }
};
time complexity: O(n*logn) due to map operations but can be reduced to O(n) using unordered_map
space complexity: O(n)
intuition:
The idea is to use a hash map to keep track of the cumulative sums (prefix sums) we have seen so far. For each new element in the array, we update the current prefix sum and check if there is a previous prefix sum that, when subtracted from the current prefix sum, equals k. If such a prefix sum exists, it means there is a subarray that sums to k, and we can add the count of such prefix sums to our result. This approach allows us to efficiently count the number of subarrays with sum k in a single pass through the array.
