// Last updated: 9/16/2025, 9:49:31 AM
class Solution {
public:
    int minimumLength(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right && s[left] == s[right]) {
            char ch = s[left];
            while (left <= right && s[left] == ch) {
                left++;
            }
            while (right >= left && s[right] == ch) {
                right--;
            }
        }

        return right - left + 1;
    }
};