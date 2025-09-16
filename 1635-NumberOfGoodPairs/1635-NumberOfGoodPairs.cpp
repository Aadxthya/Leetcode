// Last updated: 9/16/2025, 3:47:41 PM
class Solution {
public:
        int numIdenticalPairs(vector<int>& A) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int x: A) {
        ans += cnt[x]++;
        }
        return ans;
    }
};