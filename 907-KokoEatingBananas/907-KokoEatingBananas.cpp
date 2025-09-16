// Last updated: 9/16/2025, 9:50:34 AM
class Solution {
public:
    int findmax(vector<int> arr) {
        int max = INT_MIN; // Correct initialization
        for (int i = 0; i < arr.size(); i++) {
            max = std::max(max, arr[i]); // Correct max usage
        }
        return max; // Move return outside the loop
    }

    int hourlyrate(vector<int> bro, int brooo) {
        int n = bro.size();
        int summ = 0;
        for (int i = 0; i < n; i++) {
            summ += ceil((double)bro[i] / brooo); // Correct ceiling computation
        }
        return summ;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1; // Speeds must be at least 1, not 0
        int high = findmax(piles);

        while (low < high) { // Correct binary search condition
            int mid = (high + low) / 2;
            int looo = hourlyrate(piles, mid);

            if (looo > h) { // Correct condition to adjust binary search bounds
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low; // Return the minimum speed
    }
};
