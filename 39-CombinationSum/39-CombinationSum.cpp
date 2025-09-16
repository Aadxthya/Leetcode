// Last updated: 9/16/2025, 9:55:03 AM
class Solution {
public:
    vector<vector<int>> ans; // To store all valid combinations

    void fnc(vector<int>& A, int B, vector<int>& v, int i) {
        // Base case: If the target sum is 0, add the current combination to the result
        if (B == 0) {
            ans.push_back(v);
            return;
        }

        // If the index exceeds the size of the array, return
        if (i == A.size()) return;

        // While there are elements left and the current element can contribute to the sum
        while (i < A.size() && B - A[i] >= 0) {
            // Include the current element in the combination
            v.push_back(A[i]);

            // Recursive call to find combinations with the updated target (B - A[i])
            fnc(A, B - A[i], v, i);

            // Backtrack by removing the last added element
            v.pop_back();

            // Move to the next index
            i++;
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Sort the candidates to ensure combinations are generated in lexicographical order
        sort(candidates.begin(), candidates.end());

        vector<int> v; // Temporary vector to store current combination
        fnc(candidates, target, v, 0); // Start the recursive function
        return ans; // Return all valid combinations
    }
};
