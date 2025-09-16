// Last updated: 9/16/2025, 9:50:15 AM
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> count(26);
        for(auto &ch : words[0]) count[ch - 'a']++;

        for(auto &s: words){
            vector<int> freq(26);
            for(auto &ch: s){
                freq[ch - 'a']++;
            }

            for(int i=0; i<26; i++){
                count[i] = min(count[i], freq[i]);
            }
        }

        vector<string> res;
        for(int i=0; i<26; i++){
            int k = count[i];
            while(k--)
                res.push_back(string(1, i + 'a'));
        }
        return res;
    }
};