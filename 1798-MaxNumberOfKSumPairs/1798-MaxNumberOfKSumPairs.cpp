// Last updated: 9/16/2025, 9:49:33 AM
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int pairCount = 0;

        for (int num : nums) {
            int complement = k - num;

            // If complement exists in map and there are occurrences available
            if (freq[complement] > 0) {
                pairCount++;  // We can form a valid pair
                freq[complement]--;  // Decrement complement frequency
            } else {
                freq[num]++;  // Otherwise, add the current number to the map
            }
        }

        return pairCount;
    }
};
