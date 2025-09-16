// Last updated: 9/16/2025, 9:50:05 AM
class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps = 0;
        int curr = capacity;

        for (int i = 0; i < plants.size(); i++) {
            if (curr < plants[i]) {
                // Go back to river and return
                steps += 2 * i;
                curr = capacity;
            }

            curr -= plants[i];
            steps++;  // Step to this plant
        }

        return steps;
    }
};
