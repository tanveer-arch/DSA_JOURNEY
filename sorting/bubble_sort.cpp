#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void bubble_sort(int arr[], int n){
    for (int i = n - 1; i >= 1; i--) {
        for(int j = 0; j <= i - 1; j++) {
            if(arr[j] > arr[j+1]) {     
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main () {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 100000;
    }

    auto start = high_resolution_clock::now();
    bubble_sort(arr, n);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Time taken: " << duration.count() << " milliseconds" << endl;

    return 0;
}

// recursive code   



