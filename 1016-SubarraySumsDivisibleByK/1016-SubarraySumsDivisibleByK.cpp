// Last updated: 9/16/2025, 9:50:19 AM
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;  // prefix sum 0 has occurred once
        int prefixSum = 0, count = 0;

        for (int num : nums) {
            prefixSum += num;
            int remainder = prefixSum % k;

            // Handle negative remainders by adjusting
            if (remainder < 0) remainder += k;

            // If remainder seen before, add to count
            if (freq.find(remainder) != freq.end()) {
                count += freq[remainder];
            }

            freq[remainder]++;
        }

        return count;
    }
};
