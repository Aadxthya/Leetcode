// Last updated: 9/16/2025, 9:50:39 AM
class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        int n = nums.size();
        if(n %k) 
            return false;
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++)
            mp[nums[i]]++;
        while(!mp.empty()){
            int minValue = INT_MAX;
            for(auto it : mp)
                minValue = min(minValue, it.first);
            
            for(int i = minValue; i < minValue + k ; i++){
                if(mp.find(i) == mp.end() || mp[i] <= 0)
                    return false;
                mp[i]--;
                if(mp[i] == 0)
                    mp.erase(i);
            }
        }
        return true;
    }
};