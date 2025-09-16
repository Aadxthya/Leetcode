// Last updated: 9/16/2025, 9:51:38 AM
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;
        int subu = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i] == 0 ? -1 : 1; 
            if (sum == 0) {
                subu = i + 1;
            } else if (mp.find(sum) != mp.end()) {
                subu = max(subu, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return subu;
    }
};