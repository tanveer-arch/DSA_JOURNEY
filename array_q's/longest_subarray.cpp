class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {

        int n = arr.size();

        // Map to store: prefix_sum -> first index where it appeared
        // We store FIRST occurrence only to maximize subarray length
        map<long long, int> mpp;

        long long sum = 0;   // prefix sum till current index
        int maxlen = 0;      // answer

        for(int i = 0; i < n; i++) {

            // Step 1: Add current element to prefix sum
            sum += arr[i];

            // Step 2: If prefix sum itself equals k,
            // then subarray [0...i] has sum k
            if(sum == k) {
                maxlen = max(maxlen, i + 1);
            }

            // Step 3: Check if (sum - k) exists in map
            // If yes, subarray from (mpp[sum-k] + 1) to i has sum k
            long long rem = sum - k;
            if(mpp.find(rem) != mpp.end()) {
                int len = i - mpp[rem];
                maxlen = max(maxlen, len);
            }

            // Step 4: Store prefix sum in map ONLY IF
            // it is not already present (store first occurrence)
            if(mpp.find(sum) == mpp.end()) {
                mpp[sum] = i;
            }
        }

        // Step 5: Return the maximum length found
        return maxlen;
    }
};

🔑 Ultra-Important Revision Points (⭐ Must Remember)

map.find(x) != map.end() → x exists

Store first occurrence of prefix sum only

Works for:

positive numbers

negative numbers

mixed arrays

Time: O(n log n)

Space: O(n)

🚀 Exam / Interview Tip

If interviewer asks:

“Why not update map every time?”

Answer:

Because earlier index gives longer subarray; overwriting destroys optimal length.

********optimal approach for positives only***************** 
we can use sliding window technique here as all numbers are positive.
In this approach, we will maintain a window defined by two pointers (left and right) and a running sum of the elements within that window. We will expand the right pointer to increase the sum and contract the left pointer to decrease the sum when it exceeds k. Whenever the sum equals k, we will update the maximum length of the subarray.
intution:
Since all numbers are positive, expanding the window will only increase the sum, and contracting it will decrease the sum. This allows us to efficiently find subarrays with the desired sum.

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {

        int n = arr.size();
        long long sum = 0;
        int maxlen = 0;
        int j = 0;   // left pointer

        for(int i = 0; i < n; i++) {

            // expand window
            sum += arr[i];

            // shrink window while sum is too large
            while(sum > k && j <= i) {
                sum -= arr[j];
                j++;
            }

            // valid window found
            if(sum == k) {
                maxlen = max(maxlen, i - j + 1);
            }
        }
        return maxlen;
    }
};

🧠 Sliding Window Logic (Write this in Notes)

Expand right pointer →
If sum exceeds k → shrink from left →
If sum equals k → update length