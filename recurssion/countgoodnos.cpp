# 💡 LeetCode 1922: Count Good Numbers

## 📝 1. Problem Statement
A digit string is considered **good** if the digits at even indices are **even** (`0, 2, 4, 6, 8`) and the digits at odd indices are **prime** (`2, 3, 5, 7`). 

Given an integer `n`, return the total number of good digit strings of length `n`. 
Since the answer can be massive, return it modulo `10^9 + 7`.

### 📌 The Rules:
1. 🔵 **Even Indices (0, 2, 4...):** 5 possible choices (`0, 2, 4, 6, 8`).
2. 🔴 **Odd Indices (1, 3, 5...):** 4 possible choices (`2, 3, 5, 7`).
3. 🗜️ **Modulo Limit:** `n` can be up to `10^15`. You must return the answer modulo `1000000007` to prevent integer overflow.

---

## 🧠 2. Intuition & Way of Thinking

This is a **Combinatorics (Math) + Systems Optimization** problem. 

**The Combinatorics:**
If `n = 4`, we have 2 even indices and 2 odd indices. 
The total combinations would simply be: `5 * 4 * 5 * 4`, which is `(5^2) * (4^2)`.
Generally, for length `n`, there are `ceil(n/2)` even positions and `floor(n/2)` odd positions.

> ⚠️ **The Trap:**
> The logical trap here is the massive constraint: `n = 10^15`. 
> 1. You cannot use the built-in `pow()` function because it uses floating-point math (`double`) and will lose precision.
> 2. You cannot use a standard `for` loop to multiply because looping a quadrillion times will cause a **Time Limit Exceeded (TLE)** error.
> 3. You cannot wait until the end to apply the modulo, or your 64-bit integer will overflow and crash.

### 🎯 The Solution Strategy:
We must write our own custom exponentiation function using **Binary Exponentiation**, which calculates powers in `O(log n)` time by halving the exponent at each step. We must also apply `% MOD` during *every single multiplication* to keep the numbers strictly under the 64-bit limit.

---

## 🚀 3. Arriving at the Approach (Brute to Optimal)

### 🐢 The "Brute / Naive" Approach (Linear Power)
We figure out the math `(5^even_count) * (4^odd_count)`. We write a custom function with a `while(exp > 0)` loop that multiplies the base one by one and applies the modulo.
* *Why it fails:* A linear loop takes `O(N)` time. For `10^15`, the loop runs 1,000,000,000,000,000 times. The server will time out.

### 🏆 The Optimal Approach (Binary Exponentiation)
Instead of multiplying one by one, we use the rule of exponents: `x^10 = (x^2)^5`. 
If the exponent is even, we square the base and cut the exponent in half. If the exponent is odd, we multiply our result by the base and subtract 1 from the exponent. This cuts the math from 10^15 steps down to roughly **50 steps**!

---

## 💻 4. Code Implementation

```cpp
class Solution {
public:
long long mod=1000000007;
    long long power(long long base,long long exp){
        long long result=1;
        
        while(exp>0){
            if(exp%2==1){
                result=(result*base) % mod;
                exp=exp-1;
            }
            else{
                exp=exp/2;
                base=(base*base)%mod;
            }
        }
        return result;
    }

    int countGoodNumbers(long long n) {
       long long result;
        if(n%2==0){
            result=(power(5,(n/2))*power(4,(n/2)))%mod;
        }
        else{
            n=n-1;
            result=(power(5,(n/2))*power(4,(n/2))*5)%mod;
        }
        return result;
    }
};