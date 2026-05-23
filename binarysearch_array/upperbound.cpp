The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than the given key i.e. x.

The upper bound is the smallest index, ind, where arr[ind] > x.

brute force approach:
#include <bits/stdc++.h>
using namespace std;

// Class to find the upper bound index in an array
class UpperBoundFinder {
public:
    // Linear search method to find upper bound
    int upperBound(vector<int> &arr, int x, int n) {
        for (int i = 0; i < n; i++) {
            if (arr[i] > x) {
                return i; // First element strictly greater than x
            }
        }
        return n; // If no such element exists, return n
    }
};

int main() {
    vector<int> arr = {3, 5, 8, 9, 15, 19}; // Sorted input array
    int n = arr.size();                    // Size of the array
    int x = 9;                             // Target value

    UpperBoundFinder finder;              // Create object of class
    int ind = finder.upperBound(arr, x, n); // Call method

    cout << "The upper bound is the index: " << ind << "\n"; // Output result
    return 0;
}
//time complexity: O(n) where n is the number of elements in the array
//space complexity: O(1)

//optimized approach using binary search
#include <bits/stdc++.h>
using namespace std;

// Class to compute upper bound
class UpperBoundFinder {
public:
    // Function to find the upper bound using binary search
    int upperBound(vector<int> &arr, int x, int n) {
        int low = 0, high = n - 1;
        int ans = n;  // Default answer if x is >= all elements

        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid] > x) {
                ans = mid;        // Potential answer found
                high = mid - 1;   // Try to find smaller valid index on the left
            } else {
                low = mid + 1;    // Move right if mid is <= x
            }
        }
        return ans;  // Index of the first element > x
    }
};

int main() {
    vector<int> arr = {3, 5, 8, 9, 15, 19};  // Sorted input array
    int n = arr.size();                     // Size of the array
    int x = 9;                              // Target value

    UpperBoundFinder finder;               // Create object
    int ind = finder.upperBound(arr, x, n);  // Call method

    cout << "The upper bound is the index: " << ind << "\n";  // Output result
    return 0;
}
//time complexity: O(log n) where n is the number of elements in the array
//space complexity: O(1)
// intuition