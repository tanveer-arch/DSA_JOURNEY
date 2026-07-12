# LeetCode 151 – Reverse Words in a String

## Problem

Given a string `s`, reverse the order of the words.

### Requirements

* Remove leading spaces.
* Remove trailing spaces.
* Reduce multiple spaces between words to a single space.

---

# Approach 1: Brute Force (My Initial Idea)

## Intuition

* Traverse the string from left to right.
* Read one complete word.
* Insert each newly found word at the beginning of the answer.

Example:

```
Input:
the sky is blue

Read:
the
sky
is
blue

Answer:
the
sky the
is sky the
blue is sky the
```

---

## Algorithm

1. Traverse from left to right.
2. Skip spaces.
3. Read one complete word.
4. If the answer is not empty, insert one space after the current word.
5. Insert the current word at the beginning of the answer.
6. Repeat.

---

## Brute Force Code

```cpp
// Brute Force Approach
// Read each word from left to right and keep
// inserting it at the beginning of the answer.

class Solution {
public:
    string reverseWords(string s) {

        string ans = "";

        for (int i = 0; i < s.size(); i++) {

            // Skip spaces
            while (i < s.size() && s[i] == ' ')
                i++;

            string word = "";

            // Read one complete word
            while (i < s.size() && s[i] != ' ') {
                word += s[i];
                i++;
            }

            if (!word.empty()) {

                if (ans.empty())
                    ans = word;
                else
                    ans = word + " " + ans;
            }
        }

        return ans;
    }
};

// Time Complexity : O(n²)
// Space Complexity : O(n)
```

---

## Why is it O(n²)?

Every iteration performs

```cpp
ans = word + " " + ans;
```

Prepending creates a new string every time and copies the previous answer.

Example:

```
1 character copied
4 characters copied
8 characters copied
13 characters copied
...
```

Total work becomes

```
1 + 2 + 3 + ... + n

= O(n²)
```

---

# Observation

The expensive operation is

```cpp
word + ans
```

Question:

**Can we avoid inserting at the beginning?**

Yes.

Instead of moving words,
move the pointer.

---

# Optimal Approach

## Key Observation

Scan the string from **right to left**.

The first word encountered from the end is already the first word of the final answer.

Example

```
Input

the sky is blue

Scanning backwards

blue
is
sky
the

Output

blue is sky the
```

No reversing is required.

---

## Algorithm

1. Start from the last character.
2. Skip trailing spaces.
3. Mark the end of the word.
4. Move left until a space or beginning.
5. Mark the start.
6. If answer is not empty, append one space.
7. Copy the current word.
8. Repeat.

---

## Dry Run

```
Input

"  hello   world  "
```

Iteration 1

```
world

ans = "world"
```

Iteration 2

```
hello

ans = "world hello"
```

Done.

---

## Optimal Code

```cpp
// Optimal Approach
// Traverse from right to left and directly
// append each word to the answer.

class Solution {
public:
    string reverseWords(string s) {

        int n = s.size();

        string ans = "";

        int start, end;

        for (int i = n - 1; i >= 0; i--) {

            // Skip trailing or multiple spaces
            while (i >= 0 && s[i] == ' ')
                i--;

            if (i < 0)
                break;

            // End of current word
            end = i;

            // Find beginning of current word
            while (i >= 0 && s[i] != ' ')
                i--;

            start = i + 1;

            // Add one space between words
            if (!ans.empty())
                ans += " ";

            // Copy the current word
            for (int j = start; j <= end; j++)
                ans += s[j];
        }

        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)
```

---

# Complexity Comparison

| Approach                     | Time  | Space |
| ---------------------------- | ----- | ----- |
| Brute Force                  | O(n²) | O(n)  |
| Optimal (Right-to-Left Scan) | O(n)  | O(n)  |

---

# Common Mistakes

### 1. Forgetting to skip multiple spaces

Wrong

```cpp
if(s[i]==' ')
```

Correct

```cpp
while(i>=0 && s[i]==' ')
```

---

### 2. Out-of-bounds access

Wrong

```cpp
while(s[i]!=' ')
```

Correct

```cpp
while(i>=0 && s[i]!=' ')
```

---

### 3. Adding an extra trailing space

Wrong

```cpp
ans += " ";
```

Correct

```cpp
if(!ans.empty())
    ans += " ";
```

---

### 4. Forgetting to stop after skipping all spaces

```cpp
if(i<0)
    break;
```

---

# Key Learning

Whenever you write

```cpp
result = something + result;
```

ask yourself:

> **Am I repeatedly copying the entire answer?**

If yes, the algorithm may degrade to **O(n²)**.

Instead, try one of these strategies:

* Traverse from the opposite direction.
* Append to the end instead of inserting at the beginning.
* Use data structures that support efficient front insertion when appropriate (e.g., deque or list), though they may not always be the best fit.

This problem teaches an important optimization pattern: **avoid repeatedly prepending to `std::string`; prefer appending or scanning in reverse whenever possible.**
