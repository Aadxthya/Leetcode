// Last updated: 9/16/2025, 9:54:31 AM
class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n + 1, -1);
        return climb(n, memo);
    }

    int climb(int n, vector<int>& memo) {
        if (n <= 2) return n;
        if (memo[n] != -1) return memo[n];
        return memo[n] = climb(n - 1, memo) + climb(n - 2, memo);
    }
};