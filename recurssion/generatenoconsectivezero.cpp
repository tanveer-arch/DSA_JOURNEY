# 💡 LeetCode 3211: Generate Binary Strings Without Adjacent Zeros

## 📝 1. Problem Statement
Given an integer `n`, return all valid binary strings of length `n`. 
A binary string is considered valid if it only contains `'0'`s and `'1'`s, and it **does not contain any adjacent zeros** (the substring `"00"` is strictly forbidden).

### 📌 The Rules:
1. 📏 **Length:** Every generated string must be exactly length `n`.
2. 🚫 **No "00":** You can have "11", "10", or "01", but never "00".
3. 🌳 **All Combinations:** You must return every single possible valid combination.

---

## 🧠 2. Intuition & Way of Thinking

This is a classic **Backtracking** problem. 
Instead of trying to magically generate full strings or using `for`/`while` loops, we use a **State-Space Tree**. We build the strings one character at a time from left to right, branching out into different possible universes based on our strict rules.

### 🎯 The Branching Strategy:
Look at the current string you are holding. You have two choices for the next character:
1. **Branch 1 (Add `'1'`):** Is there a rule against adding a `'1'`? No! You can *always* branch out and append a `"1"`.
2. **Branch 2 (Add `'0'`):** You can only append a `"0"` if it is perfectly safe. It is only safe if the string is currently **empty**, OR if the very last character is a **`'1'`**.

---

## 🚧 3. The Journey & Common Mistakes

Switching from "Iterative Thinking" to "Recursive/Backtracking Thinking" is tough. Here are the traps we fell into and fixed:

* 🌀 **Mistake 1: The `while` Loop Trap**
  * *What happened:* We tried to put a `while(curr_str.length() != n)` loop inside our recursive function to build the string. 
  * *The Fix:* In backtracking, **the recursion IS the loop.** You do not need `while` loops to build the string. You just make a recursive call with a slightly longer string, and the Call Stack naturally moves forward and "backtracks" for you.
* 📦 **Mistake 2: The Vector Pre-fill Bug**
  * *What happened:* We initialized our answer vector as `vector<string> result(n);`. This accidentally pre-filled the vector with `n` blank, empty strings (`["", "", ""]`). When the recursion pushed valid strings, they were added to the *end* of these blanks.
  * *The Fix:* Just initialize an empty bucket: `vector<string> result;`.

---

## 💻 4. Code Implementation

```cpp
class Solution {
public:
    // Helper function to build strings via Backtracking
    void generate_str(int n, string curr_str, vector<string> &result) {
        
        // Base Case: If the string has reached the target length, save it and stop.
        if(curr_str.length() == n){
            result.push_back(curr_str);
            return;
        }
        
        // Branch 1: We can ALWAYS safely add a '1'
        generate_str(n, curr_str + "1", result);
        
        // Branch 2: We can ONLY add a '0' if the string is empty or ends in '1'
        if(curr_str.empty() || curr_str.back() == '1'){
            generate_str(n, curr_str + "0", result);
        }
    }

    vector<string> validStrings(int n) {
        vector<string> result; // Empty bucket to hold answers
        string curr_str = "";  // Start with an empty string
        
        // Kick off the backtracking tree
        generate_str(n, curr_str, result);
        
        return result;
    }
};

time complexity: O(4^n / sqrt(n)) - This is the number of valid binary strings without adjacent zeros, which grows exponentially with n.
space complexity: O(4^n / sqrt(n)) - This is the number of valid binary strings without adjacent zeros, which grows exponentially with n, and also accounts for the space used by the result vector.
