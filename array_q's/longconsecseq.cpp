

brute-force approach:(linear search)
1. For each element in the array, check for the next consecutive elements by incrementing the value and checking if it exists in the array.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int maxc=0;
        for(int i=0;i<n;i++){
            int count=0;
            int val=nums[i];
            while(find(nums.begin(),nums.end(),val)!=nums.end()){
                count++;
                val++;
            }
            maxc=max(count,maxc);
        }
        return maxc;
    }
};
//time complexity: O(n^2) in worst case
//space complexity: O(1)

better approach:(using sorting)
1. Sort the array first. Then, iterate through the sorted array to find the longest consecutive sequence.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int maxc=1;
        int count=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) continue; // skip duplicates
            else if(nums[i]==nums[i-1]+1){
                count++;
            }
            else{
                maxc=max(count,maxc);
                count=1;
            }
        }
        maxc=max(count,maxc);
        return maxc;
    }
};
//time complexity: O(n log n) due to sorting + O(n) for traversal
//space complexity: O(1)
intuition:
1. Sort the array to bring consecutive numbers together.
2. Traverse the sorted array, counting consecutive numbers and updating the maximum count when a break in the sequence is found.






optimal approach:
In the optimal approach, we use an unordered set to store the elements of the array for O(1) average time complexity lookups. We then iterate through each element in the set and check if it is the start of a sequence (i.e., the previous number is not in the set). If it is, we count how many consecutive numbers exist starting from that number and update the maximum count found.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int num : nums) {
            numSet.insert(num);
        }

        int maxLength = 0;

        for (int num : numSet) {
            // Check if it's the start of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentLength = 1;

                // Count the length of the sequence
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentLength++;
                }

                maxLength = max(maxLength, currentLength);
            }
        }

        return maxLength;
    }
};
//time complexity: O(n) on average
//space complexity: O(n)
//intuition:
1. Use an unordered set to store all elements for O(1) lookups.
2. For each element, check if it is the start of a sequence by verifying that the previous number is not in the set.
3. If it is the start, count the length of the consecutive sequence and update the maximum length found.
















