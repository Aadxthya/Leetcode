// Last updated: 9/16/2025, 9:49:08 AM
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long res = 1, curr = 1;
        for(int i = 1, n = prices.size(); i < n; ++i){
            if(prices[i - 1] - prices[i] == 1) ++curr;
            else curr = 1;
            res += curr;
        }
        return res;
    }
};