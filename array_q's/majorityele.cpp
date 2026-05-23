in this question, we are given an array of size n and we need to find the majority element in the array.

*** Brute Force Approach (Using Hash Map) ***
We count the frequency of each element using a map and then find the element with maximum frequency.


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        for(auto value:nums){
          m[value]++;
        }
        int maxf=0,maxele=0;
        for(auto p:m){
        if(p.second>maxf){
            maxf=p.second;
            maxele=p.first;
        }
        }
        return maxele;
    }
};



*** Optimal Approach (Boyer-Moore Voting Algorithm) ***
We maintain a count of the current candidate for majority element. and whenever the count becomes zero, we change the candidate to the current element. Finally, we need to confirm if the candidate is indeed the majority element by counting its occurrences.


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ele=nums[0];
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele){
                count++;
            }
            else{
                count--;
                if(!count){
                    ele=nums[i];
                    count++;
                }
            }
        }
        count=0;

        for(int i=0;i<n;i++){
            if(nums[i]==ele){
                count++;
            }
        }
        if(count>n/2){
            return ele;
        }
        else{
            return -1;
        }
        
    }
};
// time complexity: O(n)
// space complexity: O(1)
// works only when majority element is guaranteed to be present
// otherwise we need to do a second pass to confirm
// as done above
// in that case time complexity remains O(n)
// space complexity: O(1)
// exam / interview tip:
// Always confirm the candidate by counting its occurrences
// if majority element is not guaranteed to be present  

