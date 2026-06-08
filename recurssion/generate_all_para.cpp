# 💡 LeetCode 22: Generate Parentheses

## 📝 1. Problem Statement
Given `n` pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

### 📌 The Rules:
1. 📏 **Length:** If you have `n` pairs, every valid string will be exactly `2 * n` characters long.
2. ⚖️ **Well-Formed:** Every closing bracket `)` must have a matching preceding opening bracket `(`.
3. 🌳 **All Combinations:** You must return every single possible valid sequence.

---

## 🧠 2. Intuition & Way of Thinking

This is a **Backtracking** problem, but with a twist. 
Unlike generating binary strings where we only care about the *very last* character added, parentheses require us to track the **global state** of our string. 

### 🎯 The Strategy: "Counting State"
To know if it is legal to add a `(` or a `)`, we must count exactly how many of each we have used so far. We add two state variables to our recursive function: `co` (Count Open) and `cc` (Count Close).

1. **Branch 1 (Add `(`):** We can add an open bracket as long as we haven't used up our allowance of `n` brackets (`co < n`).
2. **Branch 2 (Add `)`):** We can ONLY add a close bracket if there are strictly more open brackets waiting to be closed than there are close brackets currently in the string (`co > cc`).

---

## 🚧 3. The Journey & Common Mistakes

While building the backtracking tree, we ran into three classic C++ and logic traps:

* 🧮 **Mistake 1: The Post-Increment Trap (`co++`)**
  * *What happened:* When making the recursive call, we used `co++`. In C++, post-increment evaluates the *current* value first, passes it to the function, and increments later. This caused an infinite loop/wrong state.
  * *The Fix:* Pass the mathematical expression `co + 1` instead.
* ⚖️ **Mistake 2: The Closing Rule (`co >= cc`)**
  * *What happened:* We allowed adding a closing bracket if `co >= cc`. But if the string is perfectly balanced (e.g., `co = 1, cc = 1`), adding another `)` creates `())`, which is invalid!
  * *The Fix:* You must have *strictly more* open brackets waiting. The rule must be `co > cc`.
* 👻 **Mistake 3: The Ghost Vector (Pass by Value)**
  * *What happened:* Our helper function signature was `void generatepara(..., vector<string> result, ...)`. Because we forgot the `&`, C++ created a brand new, temporary copy of the vector for every recursive branch. The original vector stayed completely empty.
  * *The Fix:* Pass by reference: `vector<string>& result`.

---

## 💻 4. Code Implementation

```cpp
class Solution {
public:
    // Recursive backtracking helper function
    void generatepara(string currstr, int n, vector<string>& result, int co, int cc) {
        
        // Base Case: The string has reached the maximum possible length (n pairs = 2*n length)
        if (currstr.length() == 2 * n) {
            result.push_back(currstr);
            return;
        }
        
        // Branch 1: Add an Open Bracket '('
        // Allowed if the string is empty OR we haven't hit our 'n' limit yet
        if (currstr.empty() || co < n) {
            generatepara(currstr + "(", n, result, co + 1, cc);
        }
        
        // Branch 2: Add a Close Bracket ')'
        // Allowed ONLY if we have more open brackets waiting to be closed
        if (co > cc) {
            generatepara(currstr + ")", n, result, co, cc + 1);
        }
    }

    // Main Function called by the platform
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string currstr = "";
        int co = 0; // Count Open
        int cc = 0; // Count Close
        
        // Kick off the backtracking tree
        generatepara(currstr, n, result, co, cc);
        
        return result;
    }
};

time complexity: O(4^n / sqrt(n)) - This is the number of valid parentheses combinations, which grows exponentially with n.
space complexity: O(4^n / sqrt(n)) - This is the number of valid parentheses combinations, which grows exponentially with n, and also accounts for the space used by the result vector.
