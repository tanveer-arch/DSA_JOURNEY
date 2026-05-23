*****Binary search on sorted array******
#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Target found
        } 
        else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } 
        else {
            right = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}
int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = binarySearch(arr, n, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
//time complexity: O(log n)
//space complexity: O(1)

//intuition: The binary search algorithm works by repeatedly dividing the search interval in half. If the value of the target is less than the item in the middle of the interval, we narrow the interval to the lower half. Otherwise, we narrow it to the upper half. This process continues until the target value is found or the interval is empty.

recurssive approach
#include <iostream> 
using namespace std;
int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1; // Target not found
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid; // Target found
    } 
    else if (arr[mid] < target) {
        return binarySearch(arr, mid + 1, right, target); // Search in the right half
    } 
    else {
        return binarySearch(arr, left, mid - 1, target); // Search in the left half
    }
}
int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
//time complexity: O(log n)
//space complexity: O(log n) due to recursive call stack
//intuition: The recursive binary search algorithm works similarly to the iterative version, but it uses function calls to divide the search interval. Each recursive call narrows down the search space until the target is found or the base case is reached where the left index exceeds the right index, indicating that the target is not present in the array.