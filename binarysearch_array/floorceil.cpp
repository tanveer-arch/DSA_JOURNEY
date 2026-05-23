Floor of element in a sorted array is defined as the greatest element in the array that is smaller than or equal to a given key x.
     

The ceil of element in a sorted array is defined as the smallest element in the array that is greater than or equal to a given key x.

visualization of floor and ceil:
Consider the sorted array: [1, 2, 4, 6, 10]
If the key x is 5:
- The floor of 5 is 4 (the greatest element less than or equal to 5).
- The ceil of 5 is 6 (the smallest element greater than or equal to 5).

ceil is also called as ceiling value or least upper bound.

In this code, we implement a function to find both the floor and ceil of a given key x in a sorted array using binary search.


#include <bits/stdc++.h>
using namespace std;

class FloorCeilFinder {
public:
    // Function to find the floor of x
    int findFloor(int arr[], int n, int x) {
        int low = 0, high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] <= x) {
                ans = arr[mid];     // Potential floor
                low = mid + 1;      // Search right side
            } else {
                high = mid - 1;     // Search left side
            }
        }
        return ans;
    }

    // Function to find the ceiling of x
    int findCeil(int arr[], int n, int x) {
        int low = 0, high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= x) {
                ans = arr[mid];     // Potential ceil
                high = mid - 1;     // Search left side
            } else {
                low = mid + 1;      // Search right side
            }
        }
        return ans;
    }

    // Function to return both floor and ceil
    pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
        int f = findFloor(arr, n, x);
        int c = findCeil(arr, n, x);
        return make_pair(f, c);
    }
};

int main() {
    int arr[] = {3, 4, 4, 7, 8, 10};
    int n = 6, x = 5;
    FloorCeilFinder finder;
    pair<int, int> ans = finder.getFloorAndCeil(arr, n, x);
    cout << "The floor and ceil are: " << ans.first << " " << ans.second << endl;
    return 0;
}
//time complexity: O(log n) where n is the number of elements in the array
//space complexity: O(1)

//intuition:
The idea is to use binary search to efficiently find the floor and ceil of a given key x in a sorted array. For finding the floor, we look for the greatest element that is less than or equal to x by adjusting our search range based on comparisons. Similarly, for finding the ceil, we look for the smallest element that is greater than or equal to x. By maintaining potential answers during the search, we can return the correct floor and ceil values after the binary search completes.