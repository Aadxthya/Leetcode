// Last updated: 9/16/2025, 9:52:25 AM
class Solution {
public:

int maxProduct(vector<string>& words) {
    int n = words.size();
    vector<int> state(n, 0); // To store bitmasks for each word
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (char c : words[i]) {
            state[i] |= 1 << (c - 'a'); // Create bitmask for the word
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // Start j from i+1 to avoid duplicates
            if (!(state[i] & state[j])) { // Check if no common letters (bitwise AND)
                ans = max(ans, (int)(words[i].size() * words[j].size()));
            }
        }
    }

    return ans;
}
};