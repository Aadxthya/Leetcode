// Last updated: 9/16/2025, 9:54:21 AM
class Solution {
public:
// Function to find the subsets of the given array
vector<vector<int>> subsets(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> res;
    
    // Loop through all possible 
    // subsets using bit manipulation
    for (int i = 0; i < (1 << n); i++) {
        vector<int> subset;

        // Loop through all elements 
        // of the input array
        for (int j = 0; j < n; j++) {

            // Check if the jth bit is 
            // set in the current subset
            if ((i & (1 << j)) != 0) {

                // If the jth bit is set, add 
                // the jth element to the subset
                subset.push_back(arr[j]);
            }
        }
        
        // Push the subset into result
        res.push_back(subset);
    }
    
    return res;
}
};