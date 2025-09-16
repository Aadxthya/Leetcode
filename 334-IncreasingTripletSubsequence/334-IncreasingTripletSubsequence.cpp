// Last updated: 9/16/2025, 9:52:19 AM
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;      // Smallest number found so far
        int second = INT_MAX;     // Second smallest number > first

        for (int num : nums) {
            if (num <= first) {
                // Found a smaller or equal value for first
                first = num;
            } else if (num <= second) {
                // num > first, so it's a candidate for second
                second = num;
            } else {
                // Found num > second, so triplet (first < second < num)
                return true;
            }
        }

        return false;  // No such triplet found
    }
};
