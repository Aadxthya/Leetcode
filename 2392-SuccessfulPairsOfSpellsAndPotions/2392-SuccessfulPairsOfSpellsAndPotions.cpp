// Last updated: 9/16/2025, 9:48:53 AM
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // Step 1: Sort potions for binary search
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> result;

        for (int spell : spells) {
            // Step 2: Find minimum potion needed using ceil(success / spell)
            long long threshold = (success + spell - 1) / spell;

            // Step 3: Use binary search to find first potion >= threshold
            int index = lower_bound(potions.begin(), potions.end(), threshold) - potions.begin();

            // Step 4: All potions from index to end are valid
            int count = m - index;
            result.push_back(count);
        }

        return result;
    }
};
