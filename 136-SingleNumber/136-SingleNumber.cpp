// Last updated: 9/16/2025, 9:53:33 AM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans =0;
        for(int i =0; i<nums.size(); i++){
            ans = ans ^ nums[i];
        }

        return ans;
    }
};