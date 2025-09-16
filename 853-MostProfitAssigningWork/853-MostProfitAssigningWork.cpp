// Last updated: 9/16/2025, 9:50:45 AM
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> v;
        for(int i=0;i<difficulty.size();i++) {
            v.push_back({profit[i],difficulty[i]});
        }
        sort(v.begin(), v.end());
        sort(worker.begin(), worker.end());
        int i=v.size()-1,j=worker.size()-1,ans=0;
        while(i>=0 && j>=0) {
            while(j>=0 && worker[j]>=v[i].second) {
                ans+=v[i].first;
                j--;
            }
            i--;
        }
        return ans;
    }
};