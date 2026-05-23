#include <iostream>
using namespace std;

int main() {
    int n, key;

    cout << "Enter number of elements in array: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            index = i;
            break;
        }
    }

    if (index != -1)
        cout << "Element " << key << " found at index " << index << "." << endl;
    else
        cout << "Element " << key << " not found in the array." << endl;

    return 0;
}
