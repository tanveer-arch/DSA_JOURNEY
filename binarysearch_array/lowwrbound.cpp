

The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.

The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.

brute force approach:
#include <bits/stdc++.h>
using namespace std;

// Class containing methods for array operations
class LowerBoundFinder {
public:
    // Function to find lower bound index
    int lowerBound(vector<int> arr, int n, int x) {
        // Traverse the array
        for (int i = 0; i < n; i++) {
            // If current element is greater than or equal to x
            if (arr[i] >= x) {
                return i;  // Return index of the first such element
            }
        }
        // If all elements are smaller than x
        return n;
    }
};

int main() {
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = arr.size();  // Size of the array
    int x = 9;           // Target value

    LowerBoundFinder finder;                  // Create object
    int ind = finder.lowerBound(arr, n, x);   // Find lower bound index

    cout << "The lower bound is the index: " << ind << "\n";

    return 0;
}
//time complexity: O(n) where n is the number of elements in the array
//space complexity: O(1)

//optimized approach using binary search
#include <bits/stdc++.h>
using namespace std;

// Class to find the lower bound index in an array
class LowerBoundFinder {
public:
    // Function to find the lower bound using binary search
    int lowerBound(vector<int> arr, int n, int x) {
        int low = 0;           // Start of search range
        int high = n - 1;      // End of search range
        int ans = n;           // Default to n (not found)

        // Binary search loop
        while (low <= high) {
            int mid = (low + high) / 2;  // Middle index

            if (arr[mid] >= x) {
                ans = mid;           // Store possible answer
                high = mid - 1;      // Try to find smaller index on left side
            } else {
                low = mid + 1;       // Move right if current element is less than x
            }
        }
        return ans;  // Return the index of the lower bound
    }
};

int main() {
    vector<int> arr = {3, 5, 8, 15, 19};  // Sorted input array
    int n = arr.size();                  // Size of array
    int x = 9;                           // Target value

    LowerBoundFinder finder;            // Create object of the class
    int ind = finder.lowerBound(arr, n, x);  // Call method to find lower bound

    cout << "The lower bound is the index: " << ind << "\n";  // Output the result
    return 0;
}
//time complexity: O(log n) where n is the number of elements in the array
//space complexity: O(1)
