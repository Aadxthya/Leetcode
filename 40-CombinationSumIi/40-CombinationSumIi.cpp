// Last updated: 9/16/2025, 9:55:02 AM
class Solution {
public:
    vector<vector<int>> ans; // To store all valid combinations

    void fnc(vector<int>& A, int B, vector<int>& v, int i) {
        // Base case: If the target sum is 0, add the current combination to the result
        if (B == 0) {
            ans.push_back(v);
            return;
        }

        // Loop through the candidates starting from index i
        for (int j = i; j < A.size(); ++j) {
            // Skip duplicates
            if (j > i && A[j] == A[j - 1]) continue;  // 1 , 1, 1 only enter the loop with last 1,,

            // If the current element exceeds the target, break the loop
            if (A[j] > B) break;

            // Include the current element in the combination
            v.push_back(A[j]);

            // Recursive call to find combinations with the updated target
            fnc(A, B - A[j], v, j + 1); // Move to the next index to avoid reuse

            // Backtrack by removing the last added element
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Sort the candidates to ensure combinations are generated in lexicographical order
        sort(candidates.begin(), candidates.end());

        vector<int> v; // Temporary vector to store current combination
        fnc(candidates, target, v, 0); // Start the recursive function
        return ans; // Return all valid combinations
    }
};
