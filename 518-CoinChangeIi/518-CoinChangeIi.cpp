// Last updated: 9/16/2025, 9:51:39 AM
class Solution
{
public:
    int change(int targetAmount, vector<int>& coins)
    {
        vector<long long> dp(targetAmount + 1, 0);
        dp[0] = 1;
        for (auto coin : coins)
        {
            for (int amount = coin; amount <= targetAmount; amount++)
            {
                dp[amount] += dp[amount - coin];
                if(dp[amount] > INT_MAX) dp[amount] = 0;
            }
        }
        return dp[targetAmount];
    }
};

