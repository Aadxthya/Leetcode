// Last updated: 9/16/2025, 9:48:11 AM
class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
    priority_queue<pair<int, char>> cuts;
    for (int cost : horizontalCut) {
        cuts.push({cost, 'H'});
    }
    for (int cost : verticalCut) {
        cuts.push({cost, 'V'});
    }
    
    int horizontal_pieces = 1;
    int vertical_pieces = 1;
    
    long long total_cost = 0;
    
    while (!cuts.empty()) {
        auto cut = cuts.top();
        cuts.pop();
        
        int cost = cut.first;
        char cut_type = cut.second;
        if (cut_type == 'H') {
            total_cost += (long long)(cost) * vertical_pieces;
            horizontal_pieces++;
        } else {
            total_cost += (long long)(cost) * horizontal_pieces;
            vertical_pieces++;
        }
    }

    return total_cost;
    }
};