# LeetCode 14 – Longest Common Prefix

## Problem

Given an array of strings, return the **longest common prefix** among all strings.

If there is no common prefix, return an empty string `""`.

---

# Intuition

The common prefix always starts from the **first character**.

Instead of comparing every string with every other string, compare **all strings with the first string** character by character.

If every string has the same character at the current index, it belongs to the common prefix.

The moment:

* any string becomes shorter, or
* any character differs,

the common prefix ends.

---

# Example

Input

```text
["flower","flow","flight"]
```

Comparison

```
Index 0

flower -> f
flow   -> f
flight -> f

Common Prefix = "f"

------------------------

Index 1

flower -> l
flow   -> l
flight -> l

Common Prefix = "fl"

------------------------

Index 2

flower -> o
flow   -> o
flight -> i

Mismatch

Answer = "fl"
```

---

# Algorithm

1. Take the first string as the reference.
2. Traverse every character of the first string.
3. Store the current character.
4. Compare that character with every other string.
5. If:

   * current index exceeds the length of any string, return the answer.
   * characters differ, return the answer.
6. Otherwise append the character to the answer.
7. Continue until the first string ends.

---

# Dry Run

Input

```text
["dog","dove","door"]
```

```
Index 0

d
d
d

Answer = "d"

-----------------

Index 1

o
o
o

Answer = "do"

-----------------

Index 2

g
v
o

Mismatch

Return "do"
```

---

# Accepted Code

```cpp
// Vertical Scanning Approach
// Compare every character of the first string
// with all the remaining strings.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int n = strs.size();
        string ans = "";

        for (int i = 0; i < strs[0].size(); i++) {

            char current = strs[0][i];

            for (int j = 0; j < n; j++) {

                // Current string is shorter
                if (i >= strs[j].size())
                    return ans;

                // Character mismatch
                if (strs[j][i] != current)
                    return ans;
            }

            ans += current;
        }

        return ans;
    }
};
```

---

# Time Complexity

Let

* **n** = number of strings
* **m** = length of the shortest string (or maximum prefix checked)

Outer loop

```
m
```

Inner loop

```
n
```

Overall

```
Time Complexity = O(n × m)
```

---

# Space Complexity

```
Output Space = O(m)
```

because the answer string stores the common prefix.

```
Auxiliary Space = O(1)
```

No additional data structures are used.

---

# Common Mistakes

### ❌ Comparing every pair of strings

```
str1 vs str2
str1 vs str3
str2 vs str3
...
```

This is unnecessary.

Instead, compare every string only with the first string.

---

### ❌ Forgetting the shorter string case

Wrong

```cpp
strs[j][i]
```

Correct

```cpp
if(i >= strs[j].size())
    return ans;
```

This prevents accessing an invalid index.

---

### ❌ Continuing after a mismatch

The first mismatch immediately ends the common prefix.

Return the answer immediately.

---

# Key Observation

The longest common prefix grows **left to right**.

Therefore, the first mismatch determines the answer.

There is no need to compare complete strings.

---

# Pattern Learned

This problem follows the **Vertical Scanning** pattern.

Instead of processing one string completely, process **one character position across all strings**.

Use this pattern whenever:

* Multiple strings need to be compared.
* The answer depends on the earliest mismatch.
* You need the longest common prefix, common starting pattern, or shared sequence.
