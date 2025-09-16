// Last updated: 9/16/2025, 9:53:03 AM
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        unordered_map<string, int>mp;
        for(int i = 0; i < n-9; i++){
            mp[s.substr(i, 10)]++;
        }
        vector<string>ans;
        for(auto &it : mp){
            if(it.second > 1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};