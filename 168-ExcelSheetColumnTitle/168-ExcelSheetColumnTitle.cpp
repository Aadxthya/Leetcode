// Last updated: 9/16/2025, 9:53:09 AM
class Solution {
    public:
        string convertToTitle(int n) {
            string ans = "";
            while(n) {
                char ch = ('A' + (n - 1) % 26);
                ans = ch + ans;
                n = (n - 1) / 26;
            }
            return ans;
        }
    };