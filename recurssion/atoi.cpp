# 💡 LeetCode 8: String to Integer (atoi)

## 📝 1. Problem Statement
Implement the `myAtoi(string s)` function, which converts a string to a **32-bit signed integer** (similar to C/C++'s `atoi` function).

### 📌 The Rules (in strict order):
1. 🌬️ **Whitespace:** Ignore any leading whitespace (`' '`).
2. ➕ **Sign:** Check if the next character is `'-'` or `'+'`. Assume positive if neither is present.
3. 🔢 **Conversion:** Read integers until a non-digit character is reached or the end of the string is reached. Ignore the rest of the string.
4. 🗜️ **Rounding/Clamping:** If the integer is out of the 32-bit signed integer range `[-2^31, 2^31 - 1]`, clamp it to remain in range.

---

## 🧠 2. Intuition & Way of Thinking

Unlike standard algorithmic problems (like sliding window or dynamic programming), this problem is a **String Parsing / State Machine** problem. The difficulty lies entirely in handling edge cases and strict system constraints (32-bit limit).

> ⚠️ **The Trap:**
> The most common mistake is trying to do everything inside one massive `for` loop with a dozen boolean flags (`hasSign`, `hasStarted`, etc.). This makes the code unreadable, highly complex, and extremely prone to edge-case failures.

### 🎯 The Solution Strategy:
Process the string in distinct, chronological phases using a single index pointer (`i`):
* **Phase 1:** Fast-forward through spaces.
* **Phase 2:** Check for exactly one sign (`+` or `-`).
* **Phase 3:** Process digits sequentially and build the number mathematically.

---

## 🚀 3. Arriving at the Approach (Brute to Optimal)

### 🐢 The "Brute / Naive" Approach (Using 64-bit Integers)
The easiest way to solve this is to use a `long long` (64-bit) integer to store the result. You just do `result = (result * 10) + digit`. Because a `long long` is massive, it will never crash. After adding the digit, you simply check if `result > INT_MAX` and clamp it.
* *Why it's not optimal for interviews:* The problem explicitly states: *"Assume we are dealing with an environment that could **only** store integers within the 32-bit signed integer range."* A strict interviewer will fail the 64-bit approach.

### 🏆 The Optimal Approach (Strict 32-bit Environment)
To strictly stay within 32-bit limits, we cannot multiply `result * 10` if the result is already huge—it will cause an integer overflow crash before we can even check it. 
Instead of checking `(result * 10) > INT_MAX` *after* the math, we use algebra to check **before** we multiply:
* We check: `result > INT_MAX / 10`
* If `result == INT_MAX / 10`, we must also ensure the last digit being added is not greater than `7` (since `INT_MAX` is `2147483647`).

---

## 💻 4. Code Implementation (Recursive Approach)

*Note: While Iterative is the standard approach, we implemented this using a Recursive Accumulator pattern, which cleanly separates the "setup" from the "math" phase.*

```cpp
class Solution {
public:
    // Helper function to handle the digit processing and math
    int recurr(int i, int sign, string s, int result) {
        
        // Base Case 1: End of string
        if (s[i] == '\0') {
            return result * sign;
        }
        
        // Base Case 2: Encountered a non-digit character
        if (!isdigit(s[i])) {
            return result * sign;
        }

        // --- OVERFLOW PREVENTION CHECK ---
        // We must check if multiplying by 10 will crash a 32-bit int BEFORE doing it.
        // INT_MAX is 2147483647. INT_MAX / 10 is 214748364.
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (s[i] - '0') > 7)) {
            if (sign == 1) {
                return INT_MAX;
            }
            return INT_MIN; // Handles negative overflow perfectly
        }
        
        // Safe to do the math: shift digits left and add the new integer digit
        result = (10 * result) + (s[i] - '0');
        
        // Tail recursion to the next character
        return recurr(i + 1, sign, s, result);
    }

    int myAtoi(string s) {
        int i = 0;
        int result = 0;
        
        // Phase 1: Skip leading whitespace
        while (s[i] == ' ') {
            i++;
        }
        
        // Phase 2: Handle signs
        int sign;
        if (s[i] == '-') {
            sign = -1;
            i++; // Move past the sign so recursion starts on a number
        } else if (s[i] == '+') {
            sign = 1;
            i++; 
        } else {
            sign = 1; // Default to positive if no sign exists
        }
        
        // Phase 3: Start recursive digit processing
        return recurr(i, sign, s, result);
    }
};



## approach 2 usinng long long to store the result and then check for overflow after the math:


class Solution {
public:

    int recurr(int i,int sign,string s,long long result){
        
        if(s[i]=='\0'){
            return result*sign;
        }
        if(!isdigit(s[i])){
            return result*sign;
        }

        
        
        result=(10*result)+(s[i]-'0');

        if(result>INT_MAX && sign==1){
            return INT_MAX;
        }
        if((result*sign)<INT_MIN && sign==-1){
            return INT_MIN;
        }
       return  recurr(i+1,sign,s,result);
    }
    int myAtoi(string s) {
        int i=0;
        long long result=0;
     while(s[i]==' '){
        i++;
     }
     int sign;
     if(s[i]=='-'){
        sign=-1;
        i++;
     }
     else if(s[i]=='+'){
        sign=1;
        i++;
     }
     else{
        sign=1;
        
     }
   return recurr(i,sign,s,result);
    }
};

iterative approach:
class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        long long result=0;
     while(s[i]==' '){
        i++;
     }
     int sign;
     if(s[i]=='-'){
        sign=-1;
        i++;
     }
     else if(s[i]=='+'){
        sign=1;
        i++;
     }
     else{
        sign=1;
        
     }
     while(s[i]!='\0' && isdigit(s[i])){
         result=(10*result)+(s[i]-'0');
         if(result>INT_MAX && sign==1){
            return INT_MAX;
        }
        if((result*sign)<INT_MIN && sign==-1){
            return INT_MIN;
        }
         i++;
     }
   return result*sign;
    }
};

time complexity: O(n) where n is the length of the input string.
space complexity: O(1) for the iterative approach, O(n) for the recursive approach due to the call stack.
