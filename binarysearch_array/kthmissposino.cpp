In this code, we implement a solution to find the k-th missing positive integer from a sorted array of unique positive integers. The approach uses binary search to efficiently determine the position of the k-th missing number.

brute force approach:
1. Initialize a counter for missing numbers.
2. Iterate through the positive integers starting from 1.
3. For each integer, check if it is present in the array.
4. If it is not present, increment the missing counter.
5. When the missing counter reaches k, return the current integer.


// code
class Solution {
public:









optimized approach:

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if((arr[mid]-(mid+1))<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        // int x=k-(arr[high]-(high+1));
        return low+k;
    }
}; 
// time complexity: O(log n) where n is the number of elements in the array.
formula explanation:
1. For any index i in the array, the number of missing positive integers before arr[i] can be calculated as arr[i] - (i + 1).
2. We use binary search to find the largest index high such that the number of missing integers before arr[high] is less than k.
3. After the binary search, low will be positioned at the index where the k-th missing positive integer would fit in the array.
4. The k-th missing positive integer can then be found by adding k to low, which accounts for the missing numbers before the position low.