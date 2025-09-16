// Last updated: 9/16/2025, 9:49:29 AM
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        
        auto canAchievePenalty = [&](int x) {
            int operations = 0;
            for (int num : nums) {
                if (num > x) {
                    operations += (num - 1) / x; // Calculate number of operations required
                }
            }
            return operations <= maxOperations;
        };
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canAchievePenalty(mid)) {
                right = mid; // Try for a smaller penalty
            } else {
                left = mid + 1; // Increase the penalty
            }
        }
        
        return left;
    }
};
