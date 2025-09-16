// Last updated: 9/16/2025, 9:52:12 AM
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();

        // peak  = length of longest wiggle subsequence ending with an "up" difference
        // valley = length of longest wiggle subsequence ending with a "down" difference
        int peak = 1, valley = 1;

        for (int i = 1; i < size; ++i) {
            if (nums[i] > nums[i - 1]) 
                peak = valley + 1;  // current difference is "up", extend last "down" subsequence
            else if (nums[i] < nums[i - 1]) 
                valley = peak + 1;  // current difference is "down", extend last "up" subsequence
            // if equal, do nothing (no wiggle)
        }

        // The result is the max of sequences ending with "up" or "down"
        return max(peak, valley);
    }
};
