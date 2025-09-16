// Last updated: 9/16/2025, 9:54:43 AM
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n = nums.size();
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
            vector<int> temp = nums[0];
        for(int i = 1; i < n;i++){
                if(temp[1] >= nums[i][0]){
                    temp[1] = max(temp[1],nums[i][1]);
                }
                else{
                    ans.push_back(temp);
                    temp = nums[i];
                }
        }
        ans.push_back(temp);
        return ans;
    }
};