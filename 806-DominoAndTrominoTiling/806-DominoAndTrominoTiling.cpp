// Last updated: 9/16/2025, 9:50:50 AM
class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1e9 + 7;
        if (n == 1) return 1;
        if (n == 2) return 2;

        vector<long long> dp(n + 1), partial(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        partial[0] = 0;
        partial[1] = 0;
        partial[2] = 1;

        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2] + 2 * partial[i - 1]) % MOD;
            partial[i] = (partial[i - 1] + dp[i - 2]) % MOD;
        }

        return dp[n];
    }
};
