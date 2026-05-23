In this code, we implement a solution to find the minimum number of days required to make a certain number of bouquets from flowers that bloom on specific days. The approach uses binary search to efficiently determine the optimal day.

brute force approach
1. Iterate through each day from the minimum to the maximum bloom day.
2. For each day, count how many bouquets can be made by checking consecutive bloomed flowers.
3. If the number of bouquets meets or exceeds the required number, return that day.
4. If no such day is found, return -1.
5. This approach has a time complexity of O(n * d), where n is the number of flowers and d is the range of days.


optimized approach
we can use binary search to find the minimum day required to make the bouquets.
why binary search?
1. The problem can be framed as a decision problem: "Can we make m bouquets by day x?"
2. The answer to this question is monotonic; if we can make m bouquets by day x, we can also make them by any day greater than x.
3. This monotonicity allows us to use binary search to efficiently find the minimum day.
4. ****there is a search range where at some it days it is possible to make m bouquets and at some days it is not possible to make m bouquets.*****




class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n=bloomDay.size();
        // long long x;
        // x=(long long)m*k;
        int maxe=INT_MIN,mine=INT_MAX;
        for(int i=0;i<n;i++){
            maxe=max(maxe,bloomDay[i]);
            mine=min(mine,bloomDay[i]);
        }
        if (1LL * m * k > n) return -1;

        
        int low=mine;
        int high=maxe;
        while(low<=high){
            int mid=low+(high-low)/2;
            int count=0,count1=0;
            for(int i=0;i<n;i++){
                if(mid>=bloomDay[i]){
                    count++;
                   
                    if(count==k){
                        count=0;
                        count1++;
                    }
                }
                else{
                    count=0;
                }
            }
            if(count1<m){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};
time complexity: O(n log d) where n is the number of flowers and d is the range of days (max bloom day - min bloom day).
intuition: We are searching for the minimum day x such that we can make at least m bouquets. By using binary search, we efficiently narrow down the possible days and check if we can make the required bouquets by that day.
reasoning: The binary search approach allows us to efficiently explore the range of days. By counting the number of bouquets that can be made by each mid day, we can determine whether to search higher or lower days, ultimately converging on the minimum viable day.

