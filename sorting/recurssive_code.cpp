#include <iostream>
using namespace std;
#include <chrono>
using namespace std::chrono;


void bubbleSort(int arr[], int n) {
    // Base case
    if (n == 1)
        return;

    // One pass of bubble sort
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }

    // Recursive call for remaining array
    bubbleSort(arr, n - 1);
}

int main () {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 100000;
    }
    auto start = high_resolution_clock::now();
    bubbleSort(arr, n);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Time taken: " << duration.count() << " milliseconds" << endl;

    return 0;
}

