// Last updated: 9/16/2025, 9:51:42 AM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();
        int res = 0;
        int cntOfOnes = 0;

        for(int i = 0; i < n; i++) {

            if(nums[i] == 1) {
                cntOfOnes += 1;
            }

            res = max(res, cntOfOnes);

            if(nums[i] == 0) {
                cntOfOnes = 0;
            }

        }

        return res;
    }
};