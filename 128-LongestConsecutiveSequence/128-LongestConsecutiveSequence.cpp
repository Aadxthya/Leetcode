// Last updated: 9/16/2025, 9:53:41 AM
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());
        int maxStreak = 1, currentStreak = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) continue; // skip duplicates
            if (nums[i] == nums[i - 1] + 1) {
                currentStreak++;
            } else {
                maxStreak = max(maxStreak, currentStreak);
                currentStreak = 1;
            }
        }

        return max(maxStreak, currentStreak);
    }
};
