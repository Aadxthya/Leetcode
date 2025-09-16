// Last updated: 9/16/2025, 9:53:18 AM
class Solution {
public:
    string reverseWords(string s) {
        string result = "", word = "";
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            if (s[i] != ' ') {
                word += s[i];
            } else if (!word.empty()) {
                result = word + " " + result;
                word = "";
            }
        }

        if (!word.empty()) {
            result = word + " " + result;
        }

        // Remove trailing space at the end if exists
        if (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};
