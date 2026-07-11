# Remove Outermost Parentheses (My Approach)

## Intuition

* A valid parentheses string may consist of multiple **primitive** valid strings.
* Traverse the string and count the number of opening and closing parentheses.
* Whenever `openingCount == closingCount`, one primitive string has ended.
* For every primitive:

  * Ignore its first `'('` and last `')'`.
  * Append only the characters between them to the answer.
* Reset the counters and start processing the next primitive.

---

## Algorithm

1. Initialize:

   * `start = 0` (starting index of the current primitive)
   * `openingCount = 0`
   * `closingCount = 0`
   * `answer = ""`
2. Traverse the string from left to right.
3. For every character:

   * If `'('`, increment `openingCount`.
   * Else, increment `closingCount`.
4. When `openingCount == closingCount`:

   * The current primitive is from `start` to `i`.
   * Copy characters from `start + 1` to `i - 1` into `answer`.
   * Set `start = i + 1`.
   * Reset both counters to `0`.
5. Return `answer`.

---

## Time Complexity

* **O(n)**
* Every character is visited once, and every required character is copied once.

## Space Complexity

* **O(n)**
* Extra space is used only for the output string.

---

## Key Observation

Whenever the number of opening and closing parentheses becomes equal, a complete primitive string has been found. Removing the first and last parentheses of each primitive and concatenating the remaining characters gives the required answer.

---

## Common Mistakes

* ❌ Using `erase()` on the original string while iterating (indices shift).
* ❌ Storing only the ending index of the last primitive.
* ❌ Forgetting to update `start = i + 1` after processing a primitive.
* ❌ Forgetting to reset the opening and closing counters.
* ✅ Build a new answer string instead of modifying the original string.

---

## Code

```cpp
class Solution {
public:
    string removeOuterParentheses(string s) {
        int start = 0;
        int openingCount = 0;
        int closingCount = 0;
        string answer = "";

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(')
                openingCount++;
            else
                closingCount++;

            if (openingCount == closingCount) {

                // Copy only the inner part of the current primitive
                for (int j = start + 1; j < i; j++)
                    answer += s[j];

                start = i + 1;
                openingCount = 0;
                closingCount = 0;
            }
        }

        return answer;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
```
