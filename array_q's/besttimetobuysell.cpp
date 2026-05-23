In this problem, we are given an array where the ith element represents the price of a stock on day i. We need to determine the maximum profit that can be achieved by buying and selling the stock once. The approach involves iterating through the array while keeping track of the minimum price encountered so far and calculating the potential profit at each step. If the potential profit exceeds the maximum profit recorded, we update it.

int maxProfit(int* prices, int pricesSize) {
    int buy=prices[0];
    int maxprofit=0;
    for(int i=0;i<pricesSize;i++){
        if(prices[i]<buy){
            buy=prices[i];
           }
           else{
        if( prices[i]-buy>maxprofit){
            maxprofit=prices[i]-buy;
        }
          
          }
    }

return maxprofit;
}

time complexity: O(n)
space complexity: O(1)