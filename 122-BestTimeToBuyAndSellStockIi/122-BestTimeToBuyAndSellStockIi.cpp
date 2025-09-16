// Last updated: 9/16/2025, 9:53:46 AM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for(int i=0;i<prices.size()-1;i++)
        {
            if(prices[i]<prices[i+1])
                profit+=prices[i+1]-prices[i];
        }
     return profit;   
    }
   
};