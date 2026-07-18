# LeetCode 1903 – Largest Odd Number in String

## Problem

Given a numeric string `num`, return the **largest-valued odd integer (as a string)** that is a **non-empty substring** of `num`.

If no odd integer exists, return an empty string.

---

# Intuition

A number is **odd** only if its **last digit is odd**.

To obtain the **largest** odd substring:

* We should keep as many digits as possible from the beginning.
* Therefore, find the **rightmost odd digit**.
* Return the substring from index `0` to that odd digit.

---

# Example

Input

```text
"3542708"
```

Traverse from the end

```text
8  ❌ Even
0  ❌ Even
7  ✅ Odd
```

Return

```text
35427
```

because removing any digit from the front would only make the number smaller.

---

# Algorithm

1. Start traversing from the last character.
2. Check whether the current digit is odd.
3. If an odd digit is found:

   * Return the substring from index `0` to the current index.
4. If no odd digit is found, return an empty string.

---

# Dry Run

Input

```text
4206352
```

Traversal

```text
2 ❌
5 ✅
```

Return

```text
420635
```

---

# Accepted Code

```cpp
// Traverse from right to left.
// The first odd digit found from the end
// gives the largest odd substring.

class Solution {
public:
    string largestOddNumber(string num) {

        int n = num.size();

        for (int i = n - 1; i >= 0; i--) {

            // Check if current digit is odd
            if ((num[i] - '0') % 2 == 1)
                return num.substr(0, i + 1);
        }

        return "";
    }
};
```

---

# Time Complexity

Worst Case

```text
24682468
```

Every digit is checked once.

```text
Time Complexity = O(n)
```

---

# Space Complexity

The scan itself uses

```text
O(1)
```

The returned substring requires

```text
O(n)
```

in the worst case.

Interview notation:

```text
Auxiliary Space = O(1)

Output Space = O(n)
```

---

# Why is this Optimal?

To determine whether an odd substring exists, we may need to inspect every digit.

Therefore,

```text
Lower Bound = O(n)
```

Since our algorithm also runs in

```text
O(n)
```

it is **optimal**.

---

# Common Mistakes

### ❌ Traversing from the beginning

Example

```text
12345
```

Stopping at the first odd digit gives

```text
1
```

But the largest odd substring is

```text
12345
```

Always traverse **from the end**.

---

### ❌ Checking every possible substring

Generating all substrings results in

```text
O(n²)
```

or worse.

This is unnecessary because only the **last digit** determines whether a number is odd.

---

### ❌ Forgetting that characters are digits

Instead of

```cpp
num[i] % 2
```

prefer

```cpp
(num[i] - '0') % 2
```

This converts the character into its numeric value and makes the intent explicit.

---

# Key Observation

A number is odd **iff its last digit is odd**.

Therefore, the answer is simply the **longest prefix ending at the rightmost odd digit**.

---

# Pattern Learned

This problem teaches an important DSA pattern:

> **Identify the minimum property that determines the answer.**

Here, instead of analyzing the entire number, we only care about **one digit**:

```text
The last digit.
```

Recognizing this property immediately reduces the solution to a simple linear scan.

Whenever a problem asks about:

* Odd/Even number
* Divisibility
* Last digit properties

always ask:

> **Can the answer be determined by looking at only the last few digits instead of the entire number?**
