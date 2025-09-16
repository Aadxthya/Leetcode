// Last updated: 9/16/2025, 9:55:13 AM

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int ind1 = -1;
        int ind2 = -1;
        int n = nums.size();
        
        // step 1: find the breaking point
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind1 = i;
                break;
            }
        }
        
        // if there is no breaking point
        if (ind1 == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            // step 2: find next greater element and swap with ind2
            for (int i = n - 1; i >= 0; i--) {
                if (nums[i] > nums[ind1]) {
                    ind2 = i;
                    break;
                }
            }
            
            std::swap(nums[ind1], nums[ind2]);
            // step 3: reverse the rest of the right half
            reverse(nums.begin() + ind1 + 1, nums.end());
        }
    }
};
