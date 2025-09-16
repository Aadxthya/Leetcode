// Last updated: 9/16/2025, 9:50:02 AM
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        

        vector<tuple<int , int , int >> jobs;
        int n = startTime.size();
    

        for (int i = 0; i < n; ++i) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());
        vector<pair<int, int>> dp = {{0, 0}};



        for(auto&[e,s,t]: jobs){

            int l = 0;
            int r = dp.size() - 1;
            while(l<=r){
                int m = (l + r )/2;
                if (dp[m].first <= s) l = m + 1;
                else r = m - 1;
            }

        int profitnow = dp[r].second + t;
        if(profitnow > dp.back().second){
            dp.push_back({e, profitnow});
        }
        }


    return dp.back().second;
        
    }
};