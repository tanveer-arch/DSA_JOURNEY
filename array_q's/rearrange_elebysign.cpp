
variety 1


brute force:
In this approach, we first separate the positive and negative numbers into two different vectors. Then, we iterate through these vectors and place the elements back into the original array in an alternating fashion, ensuring that positive and negative numbers occupy even and odd indices respectively.
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       vector<int>v1;
       vector<int>v2;
       for(int i=0;i<nums.size();i++){
        if(nums[i]>0){
            v1.push_back(nums[i]);
        }
        else{
            v2.push_back(nums[i]);
        }
       }
      for(int i=0;i<nums.size()/2;i++){
        nums[2*i]=v1[i];
        nums[2*i+1]=v2[i];
      }
       return nums; 
    }
};

time complexity: O(n) space complexity: O(n)
but this approach takes two passes over the data and uses extra space for two additional vectors.

optimal:
In this approach, we maintain two pointers: one for the next position to place a positive number (starting at index 0) and another for the next position to place a negative number (starting at index 1). We iterate through the input array and place each positive number at the current positive pointer position and each negative number at the current negative pointer position, incrementing the respective pointers by 2 after each placement. This ensures that positive and negative numbers are placed in alternating positions in the result array.

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       
       int pos=0,neg=1;
       int n=nums.size();
             vector<int>v(n);
       for(int i=0;i<n;i++){
        if(nums[i]>0){
            v[pos]=nums[i];
            pos=pos+2;
        }
        else{
            v[neg]=nums[i];
            neg=neg+2;
        }
       }
       return v;
    }
};
time complexity: O(n) space complexity: O(n)
but this approach takes only one pass.

variety 2
In this approach, we first separate the positive and negative numbers into two different vectors. Then, we iterate through these vectors and place the elements back into the original array in an alternating fashion, ensuring that positive and negative numbers occupy even and odd indices respectively. If there are extra positive or negative numbers, they are placed at the end of the array.

// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        // code here
        vector<int>v1;
        vector<int>v2;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                v1.push_back(arr[i]);
            }
            else{
                v2.push_back(arr[i]);
            }
        }
        
        if(v1.size()>v2.size()){
            for(int i=0;i<v2.size();i++){
                arr[2*i]=v1[i];
                arr[2*i+1]=v2[i];
            }
            int index=v2.size()*2;
            for(int i=v2.size();i<v1.size();i++){
                arr[index]=v1[i];
                index++;
            }
        }
        else{
            for(int i=0;i<v1.size();i++){
                arr[2*i]=v1[i];
                arr[2*i+1]=v2[i];
            }
            int index=v1.size()*2;
            for(int i=v1.size();i<v2.size();i++){
                arr[index]=v2[i];
                index++;
            }
        }
        
    }
};
time complexity: O(n) space complexity: O(n)
how it is different from variety 1:
In variety 1, the problem guarantees an equal number of positive and negative integers, allowing for a perfect alternation between the two. In variety 2, there is no such guarantee, meaning that one type of integer (positive or negative) may outnumber the other. As a result, after alternating as much as possible, any remaining integers of the more abundant type are appended to the end of the array. This requires additional logic to handle the unequal counts, making the implementation slightly more complex than in variety 1.