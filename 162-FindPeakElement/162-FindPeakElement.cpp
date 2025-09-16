// Last updated: 9/16/2025, 9:53:13 AM
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid + 1]) {
                // Peak is on the left
                right = mid;
            } else {
                // Peak is on the right
                left = mid + 1;
            }
        }

        // left == right is the peak
        return left;
    }
};
