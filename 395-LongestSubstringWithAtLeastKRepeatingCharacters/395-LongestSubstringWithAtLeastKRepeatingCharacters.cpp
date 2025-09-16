// Last updated: 9/16/2025, 9:52:03 AM
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        int maxLen = 0;
        
        // Iterate over different numbers of unique characters (1 to 26)
        for (int uniqueTarget = 1; uniqueTarget <= 26; uniqueTarget++) {
            // Sliding window variables
            vector<int> freq(26, 0);  // Frequency array for characters
            int start = 0, end = 0;   // Start and end of the sliding window
            int unique = 0;           // Count of unique characters in the window
            int countAtLeastK = 0;    // Count of characters with at least k frequency
            
            while (end < n) {
                // Expand the window: add character s[end]
                if (freq[s[end] - 'a'] == 0) unique++;
                freq[s[end] - 'a']++;
                if (freq[s[end] - 'a'] == k) countAtLeastK++;
                end++;
                
                // Shrink the window if unique characters exceed the target
                while (unique > uniqueTarget) {
                    if (freq[s[start] - 'a'] == k) countAtLeastK--;
                    freq[s[start] - 'a']--;
                    if (freq[s[start] - 'a'] == 0) unique--;
                    start++;
                }
                
                // Check if the current window has exactly 'uniqueTarget' unique characters
                // and each character appears at least 'k' times
                if (unique == uniqueTarget && unique == countAtLeastK) {
                    maxLen = max(maxLen, end - start);
                }
            }
        }
        
        return maxLen;
    }
};