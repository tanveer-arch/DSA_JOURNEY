#include <iostream>
using namespace std;

int binarySearchDescending(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        // since array is in descending order
        if (arr[mid] > key)
            low = mid + 1;   // go right (smaller elements)
        else
            high = mid - 1;  // go left (larger elements)
    }

    return -1;  // key not found
}

int main() {
    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements in descending order: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearchDescending(arr, n, key);

    if (result != -1)
        cout << "Element " << key << " found at index " << result << "." << endl;
    else
        cout << "Element " << key << " not found in the list." << endl;

    return 0;
}
