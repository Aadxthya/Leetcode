// Last updated: 9/16/2025, 9:51:48 AM
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        // Sort based on the end point
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int arrows = 1;
        int end = points[0][1];
        for(const auto& balloon : points) {
            if(balloon[0] > end) {
                arrows++;
                end = balloon[1];
            }
        }
        return arrows;
    }
};
