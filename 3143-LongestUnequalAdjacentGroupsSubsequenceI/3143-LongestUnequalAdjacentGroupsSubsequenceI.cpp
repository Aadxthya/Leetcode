// Last updated: 9/16/2025, 9:48:19 AM
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res;
        int prevGroup = -1;  // Set to invalid initially

        for (int i = 0; i < words.size(); i++) {
            if (groups[i] != prevGroup) {
                res.push_back(words[i]);
                prevGroup = groups[i];
            }
        }

        return res;
    }
};
