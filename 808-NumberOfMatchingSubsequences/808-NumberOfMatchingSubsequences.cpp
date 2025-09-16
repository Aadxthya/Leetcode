// Last updated: 9/16/2025, 9:50:49 AM
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0, n = s.size();
        unordered_map<string,int>mp;
        for(auto &word:words) mp[word]++;

        for (auto &it: mp) {
            int s_index = 0, word_index = 0;
            string word = it.first;
            int m = word.size();
            while (word_index < m && s_index < n) {
                if (word[word_index] == s[s_index]){
                    s_index++;
                    word_index++;
                }
                else s_index++;

            }
            if (word_index == m)
                count+=it.second;
        }
        return count;
    }
};