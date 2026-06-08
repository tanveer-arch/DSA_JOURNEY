# 💡 LeetCode 78: Subsets (Power Set)

## 📝 1. Problem Statement
Given an integer array `nums` of unique elements, return all possible subsets (the power set).
The solution set must **not** contain duplicate subsets. Return the solution in any order.

### 📌 The Rules:
1. 📏 **Length:** Subsets can range from length `0` (the empty set `[]`) to length `n` (the full array).
2. 🔀 **Choices:** Every element in the array has exactly two possibilities: it is either *in* the subset, or it is *out* of the subset.

---

## 🧠 2. Intuition & Way of Thinking

This is the quintessential **Backtracking** problem. 

### 🎯 The Strategy: "The Buffet Line"
Imagine you are walking down a buffet line with a single plate (your `curr` subset). The `nums` array represents the items on the table. 
For **every single item** you step in front of, you have exactly two choices:
1. **Branch 1 (Pick it):** Put the item on your plate and move to the next item.
2. **Branch 2 (Skip it):** Do *not* put the item on your plate, and move to the next item.

**The Base Case:** You do not stop when you reach a certain number of subsets. You stop when you reach the **end of the buffet line** (when your index `i == nums.size()`). At that point, whatever is on your plate is a valid subset!

---

## 🚧 3. The Journey & Common Mistakes

This problem introduced the concept of **State Management** in recursion.

* 🛑 **Mistake 1: The Wrong Base Case**
  * *What happened:* We tried to stop the recursion when `result.size() == pow(2, n)`. 
  * *The Fix:* In backtracking, we make decisions item-by-item. The recursion must stop when we have made a decision for every item (i.e., `i == n`).
* 🍽️ **Mistake 2: The Disappearing Plate**
  * *What happened:* We declared `vector<int> curr;` *inside* the helper function. This created a brand new, empty plate every time we took a step, deleting all our previous choices.
  * *The Fix:* Pass `vector<int>& curr` into the function by reference so all branches share the exact same plate.
* 🧹 **Mistake 3: Forgetting to Clean Up (`pop_back`)**
  * *What happened:* Because all recursive branches share the **exact same memory address** for the `curr` plate, if we "Pick" an item, it stays on the plate forever!
  * *The Fix:* When a branch finishes exploring the "Pick" universe, we must use `curr.pop_back()` to take the item *off* the plate before we travel down the "Skip" universe.

---

## 💻 4. Code Implementation

```cpp
class Solution {
public:
    // Helper function to build the subsets via Backtracking
    void powerset(vector<int>& nums, vector<vector<int>>& result, vector<int>& curr, int i, int n) {
        
        // Base Case: We have reached the end of the array (the end of the buffet line)
        if (i == n) {
            // Take a snapshot of whatever is currently on our plate and save it
            result.push_back(curr);
            return;
        }

        // --- BRANCH 1: PICK IT ---
        curr.push_back(nums[i]);               // Put the item on the plate
        powerset(nums, result, curr, i + 1, n); // Go explore the rest of the items

        // --- BRANCH 2: SKIP IT ---
        curr.pop_back();                       // Clean up the plate (Backtrack!)
        powerset(nums, result, curr, i + 1, n); // Go explore the rest of the items WITHOUT it
    }

    // Main Function called by the platform
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result; // Bucket for all our subsets
        vector<int> curr;           // Our shared plate
        int n = nums.size();
        int i = 0;                  // Start at the 0th item
        
        // Kick off the backtracking tree
        powerset(nums, result, curr, i, n);
        
        return result;
    }
};

time complexity: O(n * 2^n) - There are 2^n subsets, and copying each subset to the result takes O(n) time in the worst case.
space complexity: O(n) - The maximum depth of the recursion is n, and the `curr` vector can hold up to n elements in the worst case. The result vector also takes O(n * 2^n) space, but we typically focus on the auxiliary space used by the recursion stack and temporary variables.