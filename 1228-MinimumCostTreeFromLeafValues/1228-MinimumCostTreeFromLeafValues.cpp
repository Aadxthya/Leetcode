// Last updated: 9/16/2025, 9:50:10 AM
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int cost = 0;
        stack<int>stk;

        for(int num : arr){
            while(!stk.empty() && stk.top() <= num){
                int x = stk.top();
                stk.pop();

                if(stk.empty()){
                    cost += x * num;
                } else {
                    cost += x * min(stk.top(), num);
                }
            }

            stk.push(num);
        }

        while(stk.size() > 1){
            int x = stk.top();
            stk.pop();
            cost += x * stk.top();
        }

        return cost;
    }
};