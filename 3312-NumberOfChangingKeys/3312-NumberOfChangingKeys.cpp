// Last updated: 9/16/2025, 9:48:17 AM
class Solution {
public:
    int countKeyChanges(string s) {
        char c = s[0];
        int count = 0;
        for (int i = 1; i < s.length(); i++) {
            char b = s[i];
            // Compare ignoring case
            if (!(b == c || b == c + 32 || b == c - 32)) {
                c = b;
                count++;
            }
        }
        return count;
    }
};
