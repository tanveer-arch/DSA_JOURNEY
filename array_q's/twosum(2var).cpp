🧩 Two Sum — The 2 Varieties
🔹 Variety 1

👉 Does a pair exist whose sum = target?
Return true / false

🔹 Variety 2

👉 Return indices of the two numbers
(Original indices matter)
-----------------------------------------------------------------------------------------------------
***variety 2 code*********
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(mpp.find(target - nums[i]) != mpp.end()){
                return {i, mpp[target - nums[i]]};
            }
            mpp[nums[i]] = i;
        }
        return {-1, -1};
    }
};

Using map:

Time: O(n log n)

Space: O(n)

👉 If you replace map with unordered_map:

unordered_map<int,int> mpp;


Then:

Time: O(n) average

Space: O(n)

💡 Interview tip:
Say “unordered_map gives average O(1) lookup”
--------------------------------------------------------------------------------------------

⚠️ Two Pointer Approach — WHEN IS IT VALID?

Two pointer is optimal only if array is sorted.

❌ Problem:

Sorting changes indices → cannot return original indices directly

✅ Works for:

Variety 1 (existence check)

OR when indices don’t matter

sort(nums.begin(), nums.end());
int l = 0, r = n - 1;

while(l < r){
    int sum = nums[l] + nums[r];
    if(sum == target) return true;
    else if(sum < target) l++;
    else r--;
}


⏱️ Complexity:

O(n log n) (due to sort)

O(1) space