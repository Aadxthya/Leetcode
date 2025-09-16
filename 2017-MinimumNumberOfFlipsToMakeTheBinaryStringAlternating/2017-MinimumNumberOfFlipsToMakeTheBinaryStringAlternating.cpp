// Last updated: 9/16/2025, 9:49:23 AM
class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        int tmp = 0;
        // tmp: assume starting with '0'.
        for (int i = 0; i < n; ++i) {
            tmp += (s[i] - '0') ^ (i & 1);
        }
        int ans = min(tmp, n - tmp);
        // If n mod 2 == 0, no need to slide window.
        if ((n & 1) == 0) return ans;
        for (int h = 1; h < n; ++h) {
            int t = h - 1;
            tmp = n - tmp + ((s[t] - '0') << 1) - 1;
            ans = min(ans, min(tmp, n - tmp));
        }
        return ans;
    }
};