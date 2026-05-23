# 💡 GeeksforGeeks: Sort a Stack

## 📝 1. Problem Statement
Given a stack, the task is to sort it such that the **top of the stack contains the greatest element**.

### 📌 The Strict Rules:
1. 🧱 **Stack Operations Only:** You may only use `push()`, `pop()`, `top()`, and `empty()`.
2. 🚫 **No Cheating:** You cannot use arrays, vectors, or the built-in `sort()` function.
3. 🔄 **No Loops:** The optimal interview solution requires you to solve this entirely using **Recursion** (using the system's Call Stack as your temporary memory).

---

## 🧠 2. Intuition & Way of Thinking

This problem requires a complete shift in thinking because you don't have indices like an array. You can't just swap two elements in the middle. 

### 🎯 The Strategy: "Hold and Empty"
We must break the problem into two completely separate recursive tasks:
1. **The Emptier (`emptystack`):** Pop every single element off the stack, holding each one in a local variable until the stack is completely empty. 
2. **The Inserter (`insertsorted`):** Once the stack is empty (which technically means it is sorted!), start returning back up the recursion chain. Take each "held" variable and insert it into its correct sorted position.

> 💡 **The Magic of the Call Stack:** > When you declare `int a = st.top();` and then call the function again, `a` doesn't get overwritten. Every recursive call creates a *new* instance of `a`. The computer is doing the hard work of storing all your numbers for you!

---

## 🚧 3. The Journey & Common Mistakes

While arriving at this solution, we ran into a few classic recursive traps:

* 💥 **Mistake 1: The Missing Brake Pedal (SegFault)**
  * *What happened:* We recursively popped the stack but forgot to tell the function when to stop. It tried to `pop()` an empty stack and crashed.
  * *The Fix:* Always add a Base Case (`if(st.empty()) return;`) at the very top of recursive functions.
* 👻 **Mistake 2: The Disappearing Act (Data Loss)**
  * *What happened:* When inserting an element into a sorted stack, if the top element was bigger, we popped it to make room: `st.pop(); insertsorted();`. But we threw the popped element away! 
  * *The Fix:* You must *hold* the popped element in a variable (`int b = st.top(); st.pop();`), make the recursive call, and then `push(b)` back onto the stack so it isn't lost.

---

## 💻 4. Code Implementation

```cpp
class Solution {
public:
    // Helper 1: Inserts a single element into its correct sorted position
    void insertsorted(stack<int> &st, int element){
        // Base Case: If stack is empty OR we found the right spot
        if(st.empty() || st.top() < element){
            st.push(element);
            return;
        }
        else{
            // The top element is in the way. 
            // Hold it, pop it, insert our new element, then put the held one back.
            int b = st.top();
            st.pop();
            
            insertsorted(st, element);
            
            // Put the greater element back on top
            st.push(b);
        }
    }
    
    // Helper 2: Recursively empties the stack
    void emptystack(stack<int> &st){
        // Base Case: Stop when the stack is completely empty
        if(st.empty()){
            return;
        }
        
        // Hold the top element and pop it
        int a = st.top();
        st.pop();
        
        // Keep going until empty
        emptystack(st);
        
        // On the way back up, insert the held element into the newly sorted stack
        insertsorted(st, a);
    }
    
    // Main Function called by the platform
    void sortStack(stack<int> &st) {
        // Kick off the emptying process
        emptystack(st);
    }
};