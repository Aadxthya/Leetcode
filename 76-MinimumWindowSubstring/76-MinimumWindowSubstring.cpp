// Last updated: 9/16/2025, 9:54:23 AM
class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        // Base case: if input is invalid or impossible to have a window, return empty
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        // ASCII map to store frequency of each character in t
        std::vector<int> map(128, 0);
        int count = t.length();            // total characters we need to find in window
        int start = 0, end = 0;            // sliding window pointers
        int minLen = INT_MAX;              // length of minimum window found
        int startIndex = 0;                // start index of the minimum window

        // Build the frequency map for all characters in t
        for (char c : t) {
            map[c]++;
        }

        // Expand the window by moving 'end'
        while (end < s.length()) {
            // If the character at 'end' exists in t, decrease 'count'
            // Always decrement map[s[end]] to account for every character in s
            if (map[s[end++]]-- > 0) {
                count--;
            }

            // When all characters are matched (count == 0), try to shrink the window from 'start'
            while (count == 0) {
                // Update the minimum window if the current one is smaller
                if (end - start < minLen) {
                    startIndex = start;
                    minLen = end - start;
                }
                // Increment map for the character at 'start' (since we are about to remove it)
                // If that character is necessary (i.e., map[] becomes > 0), increase 'count'
                if (map[s[start++]]++ == 0) {
                    count++;
                }
            }
        }

        // Return the smallest window if found; otherwise an empty string
        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};
