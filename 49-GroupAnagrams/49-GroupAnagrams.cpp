// Last updated: 9/16/2025, 9:54:51 AM
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        vector<vector<string>> result;
        for(string s : strs){
            string key = s;
            sort(key.begin(), key.end());
            mpp[key].push_back(s);



        }

        for(auto& [_, group] : mpp){
            result.push_back(group);
        }
        return result;
    }
};