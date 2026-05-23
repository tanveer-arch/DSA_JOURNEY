In this code, we implement a solution to find the minimum eating speed required for Koko to finish all the banana piles within a given number of hours. The approach uses binary search to efficiently determine the optimal speed.



blinking concepts
1. Binary Search on Answer Space
 - find the minimum speed K such that Koko can eat all bananas in H hours.
    - search space is from 1 to max(piles)
    - for each mid speed, calculate total hours needed
2. Ceiling Division
    - to calculate hours needed for each pile, we use ceiling division: hours = ceil(pile / speed)
    - this is implemented using (pile + speed - 1) / speed for integer division
3. Optimization Problem
    - the problem is framed as an optimization problem where we minimize the eating speed while satisfying the time constraint.

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxele=piles[0];
        for(int i=0;i<n;i++){
            if(maxele<piles[i]){
                maxele=piles[i];
            }
        }

        int low=1;
        int high=maxele;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long  totalsum=0;
            for(int i=0;i<n;i++){
                totalsum=totalsum+(int)ceil((double)piles[i]/(double)mid);
            }
            if(totalsum<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }

};
time complexity: O(n log m) where n is the number of piles and m is the maximum number of bananas in a pile.
intuition: We are searching for the minimum speed K such that Koko can finish all bananas in H hours. By using binary search, we efficiently narrow down the possible speeds and check if Koko can finish in time at each speed.
reasoning: The binary search approach allows us to efficiently explore the range of possible eating speeds. By calculating the total hours needed for each mid speed, we can determine whether to search higher or lower speeds, ultimately converging on the minimum viable speed.
