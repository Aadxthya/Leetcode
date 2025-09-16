// Last updated: 9/16/2025, 9:50:41 AM
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        if (n < 3) return 0;  // A mountain must have at least 3 elements
        
        int longest = 0;

        for (int i = 1; i < n - 1; ++i) {
            // Check if A[i] is a peak
            if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
                // Expand left
                int left = i;
                while (left > 0 && A[left] > A[left - 1]) {
                    --left;
                }

                // Expand right
                int right = i;
                while (right < n - 1 && A[right] > A[right + 1]) {
                    ++right;
                }

                // Calculate the length of the mountain
                int currentMountainLength = right - left + 1;
                longest = max(longest, currentMountainLength);

                // Move i to the end of the current mountain to avoid redundant checks
                i = right;
            }
        }

        return longest;
    }
};
