// Last updated: 9/16/2025, 9:55:47 AM
#include <unordered_set>
#include <string>
#include <algorithm> // for max function

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> sett;  // Need std:: for unordered_set
        int left = 0;
        int ans = 0;
        int right = 0;  // Initialize to 0
        int n = s.size();  // Fix: s.size() is a method

        while (right < n) {
            if (sett.find(s[right]) == sett.end()) {  // Fix comparison
                sett.insert(s[right]);
                right++;
                ans = std::max(right - left, ans);  // Fix: Add std::max and semicolon
            } else {
                sett.erase(s[left]);  // Fix: Use erase for unordered_set
                left++;
            }
        }
        return ans;
    }
};
