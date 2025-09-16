// Last updated: 9/16/2025, 9:50:28 AM
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int maxSum = nums[0], curMax = 0;
        int minSum = nums[0], curMin = 0;

        for (int num : nums) {
            curMax = max(num, curMax + num);
            maxSum = max(maxSum, curMax);

            curMin = min(num, curMin + num);
            minSum = min(minSum, curMin);

            total += num;
        }

        // If all numbers are negative, total == minSum, so total - minSum = 0, which is invalid
        if (maxSum < 0) return maxSum;

        return max(maxSum, total - minSum);
    }
};
