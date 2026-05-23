#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (arr[low] == arr[high]) {
            if (arr[low] == key) return low;
            else return -1;
        }

        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]);

        if (arr[pos] == key)
            return pos;

        if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}

int main() {
    int n, key;

    cout << "Enter number of elements in sorted array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements in ascending order: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    int index = interpolationSearch(arr, n, key);

    if (index != -1)
        cout << "Element " << key << " found at index " << index << "." << endl;
    else
        cout << "Element " << key << " not found in the array." << endl;

    return 0;
}
