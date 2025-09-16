// Last updated: 9/16/2025, 9:54:44 AM
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int targetNumIndex = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (targetNumIndex <= i + nums[i]) {
                targetNumIndex = i;
            }
        }
        return targetNumIndex == 0;
    }
};