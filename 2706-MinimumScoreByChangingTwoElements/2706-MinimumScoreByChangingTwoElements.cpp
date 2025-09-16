// Last updated: 9/16/2025, 9:48:31 AM
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return min(nums[n-1]-nums[2], min(nums[n-2]-nums[1], nums[n-3]-nums[0]));
    }
};