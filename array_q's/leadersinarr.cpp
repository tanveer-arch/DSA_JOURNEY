In an array, an element is called a "leader" if it is greater than or equal to all the elements to its right side. The rightmost element is always a leader.

brute-force approach:
1. For each element in the array, check all the elements to its right. 


class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int n=arr.size();
        // int flag=0;
        vector<int>v;
        for(int i=0;i<n;i++){
            int flag=0;
            for(int j=i+1;j<n;j++){
                if(arr[i]<arr[j]){
                     flag=1;
                    break;
                }
            }
            if(flag==0){
                v.push_back(arr[i]);
            }
        }
        return v;
    }
};

//time complexity: O(n^2)
//space complexity: O(1)

optimal approach:
1. Traverse the array from right to left, keeping track of the maximum element seen so far

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int n=arr.size();
        // int flag=0;
        vector<int>v;
        int max=arr[n-1];
        for(int i=n-1;i>=0;i--){
            if(max<=arr[i]){
                max=arr[i];
                v.push_back(max);
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
};

//time complexity: O(n)
//space complexity: O(1)
//intuition:
1. Start from the rightmost element and initialize it as the maximum.   
2. Traverse the array from right to left. For each element, if it is greater than or equal to the current maximum, it is a leader. Update the maximum accordingly.
------------------------------------------------------------------------------


variety 2 : Replace every element with the greatest element on its right side. Since there is no element to the right of the last element, replace it with -1.

brutre-force approach:
1. For each element in the array, check all the elements to its right to find the maximum element and replace it.

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            int max=arr[i+1];
            for(int j=i+1;j<n;j++){
              if(arr[j]>max){
                max=arr[j];
              }
              
            }
            arr[i]=max;
        }
        arr[n-1]=-1;
        return arr;
    }
};
//time complexity: O(n^2)
//space complexity: O(1)

optimal approach:
in this approach, we traverse the array from right to left, keeping track of the maximum element seen so far.



class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        
        int maxRight = arr[n - 1];   // stores greatest element on right
        arr[n - 1] = -1;             // last element always becomes -1
        
        for (int i = n - 2; i >= 0; i--) {
            int current = arr[i];    // save original value
            arr[i] = maxRight;       // replace with max on right
            
            if (current > maxRight) {
                maxRight = current;  // update max using original value
            }
        }
        
        return arr;
    }
};
//time complexity: O(n)
//space complexity: O(1)
//intuition:
1. Start from the rightmost element and initialize it as the maximum. Replace the last element with -1.   
2. Traverse the array from right to left. For each element, replace it with the current maximum, then update the maximum if the original value of the element is greater than the current maximum.
