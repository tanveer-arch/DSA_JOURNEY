# 💡 GeeksforGeeks: Reverse a Stack

## 📝 1. Problem Statement
Given a stack, the task is to reverse the elements of the stack.

### 📌 The Strict Rules:
1. 🧱 **Stack Operations Only:** You may only use standard operations: `push()`, `pop()`, `top()`, and `empty()`.
2. 🚫 **No Cheating:** You cannot use an extra array, string, or queue to hold the elements. 
3. 🔄 **No Loops:** The optimal solution must be done entirely using **Recursion**.

---

## 🧠 2. Intuition & Way of Thinking

Since we cannot use loops or arrays, we must rely on the **System Call Stack** to act as our temporary memory. This problem follows the exact same "Hold and Empty" recursive pattern as sorting a stack, but with a different insertion rule.

### 🎯 The Strategy: "Empty and Sink"
1. **The Emptier (`emptystack`):** Recursively pop every element off the stack, holding them in local variables until the stack is completely empty. 
2. **The Sinker (`insertatbottom`):** As the recursion unwinds, take each held variable and push it all the way to the **very bottom** of the current stack. 

---

## 🚧 3. The Journey & Common Mistakes

This problem looks simple but has some classic logic traps:

* 👻 **Mistake 1: The Rebuild Trap**
  * *What happened:* If you pop an element, call `emptystack`, and then immediately `push(a)` when it returns, you just rebuild the exact same stack! The first element popped goes back on bottom, and the top goes back on top.
  * *The Fix:* You must use a second helper function to explicitly force the returned element to the absolute bottom of the stack.
* 🚦 **Mistake 2: The Traffic Jam in `insertatbottom`**
  * *What happened:* When trying to insert the new element (`ele`) at the bottom, we held the top element (`b`), but then accidentally pushed `ele` right away! This blocked the path, and we ended up trying to push `b` underneath `ele`.
  * *The Fix:* We must let the VIP pass! Hold `b`, pop it, **make the recursive call to let `ele` keep sinking**, and only push `b` back on *after* `ele` has safely reached the bottom.

---

## 💻 4. Code Implementation

```cpp
class Solution {
public:
    // Helper 1: Forces a single element to the very bottom of the stack
    void insertatbottom(stack<int> &st, int ele){
        // Base Case: The stack is empty, meaning we reached the bottom!
        if(st.empty()){
            st.push(ele);
            return;
        }
        
        // Hold the current top element to clear the path
        int b = st.top();
        st.pop();
        
        // Let our target element keep sinking down
        insertatbottom(st, ele);
        
        // After the target is safely at the bottom, put the held element back on top
        st.push(b);
    }
    
    // Helper 2: Recursively empties the stack, holding elements in the call stack
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
        
        // On the way back up, take the held element and force it to the bottom
        insertatbottom(st, a);
    }
    
    // Main Function called by the platform
    void reverseStack(stack<int> &st) {
        // Kick off the emptying process
        emptystack(st);
    }
};

time complexity: O(n^2) in the worst case, because for each of the n elements, we may have to pop and push up to n elements in `insertatbottom`.
space complexity: O(n) due to the recursive call stack holding up to n elements in the worst case.
